#include <ch.h>
#include <hal.h>
#include <ff.h>
#include <sumobot.h>

bool initSDCard()
{
    static SDCConfig config { .dummy = 0 };
    sdcStart(&SDIO_DRIVER, &config);

    return (sdcConnect(&SDIO_DRIVER) == CH_SUCCESS);
}

bool testSDCard()
{
    FATFS fs;
    FRESULT res;
    DIR dir;
    FILINFO fileinfo;

    res = f_mount(&fs, "/", 1);
    if (res == FR_OK) {
        res = f_opendir(&dir, "0:/");
        if (res == FR_OK) {
            while (1) {
                res = f_readdir(&dir, &fileinfo);
                if (res == FR_OK) {
                    if (fileinfo.fname[0] == 0) {
                        return true;
                    }
                    // TODO: do something :-)
                }
                else {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
    else {
        return false;
    }
}

extern const uint8_t TestAudioData[];
extern const uint32_t TestAudioSize;
uint8_t MP3TxData[32];
uint8_t MP3RxData[32];

bool exchangeMP3Data(size_t length)
{
    //spiAcquireBus(&MP3_CODEC_DRIVER);
    spiSelect(&MP3_CODEC_DRIVER);
    spiExchange(&MP3_CODEC_DRIVER, length, MP3TxData, MP3RxData);
    spiUnselect(&MP3_CODEC_DRIVER);
    //spiReleaseBus(&MP3_CODEC_DRIVER);

    return true;
}

static constexpr uint8_t VS1003_VS_WRITE = 0x02;
static constexpr uint8_t VS1003_VS_READ = 0x03;

void waitForMP3DREQ()
{
    while (MP3_CODEC_DREQ_GET() == 0);
}

bool writeMP3Register(uint8_t reg, uint16_t data)
{
    waitForMP3DREQ();
    MP3_CODEC_nDCS_SET(TRUE);
    MP3TxData[0] = VS1003_VS_WRITE; // write command
    MP3TxData[1] = reg; // register
    MP3TxData[2] = static_cast<uint8_t>((data >> 8) & 0xff); // MSB
    MP3TxData[3] = static_cast<uint8_t>(data & 0xff); // LSB
    return exchangeMP3Data(4);
}

uint16_t readMP3Register(uint8_t reg)
{
    waitForMP3DREQ();
    MP3_CODEC_nDCS_SET(TRUE);
    MP3TxData[0] = VS1003_VS_READ; // write command
    MP3TxData[1] = reg; // register
    MP3TxData[2] = 0xff; // dummy
    MP3TxData[3] = 0xff; // dummy
    if (!exchangeMP3Data(4)) {
        return 0;
    }
    uint16_t data = (static_cast<uint16_t>(MP3RxData[2]) << 8) +
                    MP3RxData[3];
    return data;
}

static constexpr uint8_t VS1003_CMD_DECODE_TIME = 0x04;
static constexpr uint8_t VS1003_CMD_MODE = 0x00;
static constexpr uint8_t VS1003_CMD_CLOCKF = 0x03;
static constexpr uint8_t VS1003_CMD_AUDATA = 0x05;
static constexpr uint8_t VS1003_CMD_VOLUME = 0x0b;

bool testMP3Codec()
{
    // toggle reset for 1ms
    MP3_CODEC_nRESET_SET(FALSE);
    chThdSleepMilliseconds(1);
    MP3_CODEC_nRESET_SET(TRUE);

    // set auxilliary lines before setting up SPI
    MP3_CODEC_nCS_SET(TRUE);
    MP3_CODEC_nDCS_SET(TRUE);

    // configure and start SPI
    // - full duplex (default)
    // - master mode (enabled by spi_lld_init())
    // - 8-bits per word (default)
    // - low clock polarity (default)
    // - first-edge clock phase (default)
    // - software-based slave management (enabled by spi_lld_init())
    // - baud-rate prescaler of F(aph)/32 (SPI_CR1_BR_2)
    // - first-bit is MSB (default)
    // - CRC polynomial of 7
    static SPIConfig config {
        .end_cb = nullptr,
        .ssport = MP3_CODEC_nCS_PORT,
        .sspad = MP3_CODEC_nCS_PIN,
        .cr1 = SPI_CR1_BR_2,
    };
    MP3_CODEC_DRIVER.spi->CRCPR = 7;
    spiStart(&MP3_CODEC_DRIVER, &config);

    // reset IC
    chThdSleepMilliseconds(20);
    MP3TxData[0] = 0xff; exchangeMP3Data(1); // send frame sync
    MP3_CODEC_nCS_SET(TRUE);
    MP3_CODEC_nDCS_SET(TRUE);
    waitForMP3DREQ();
    chThdSleepMilliseconds(20);

    // perform soft reset
    waitForMP3DREQ();
    MP3TxData[0] = 0xff; exchangeMP3Data(1); // send frame sync
    uint16_t data;
    do {
        writeMP3Register(VS1003_CMD_MODE, 0x0804);
        chThdSleepMilliseconds(2);
        data = readMP3Register(VS1003_CMD_MODE);
    } while (data != 0x0800); // reset bit clear
    do {
        writeMP3Register(VS1003_CMD_CLOCKF, 0x9800);
        chThdSleepMilliseconds(2);
        data = readMP3Register(VS1003_CMD_CLOCKF);
    } while (data != 0x9800);
    do {
        writeMP3Register(VS1003_CMD_AUDATA, 0xbb81);
        chThdSleepMilliseconds(2);
        data = readMP3Register(VS1003_CMD_AUDATA);
    } while (data != 0xbb81);
    writeMP3Register(VS1003_CMD_VOLUME, 0x2020);
    writeMP3Register(VS1003_CMD_DECODE_TIME, 0x0000);
    writeMP3Register(VS1003_CMD_DECODE_TIME, 0x0000);
    MP3_CODEC_nDCS_SET(FALSE);
    MP3TxData[0] = 0xff;
    exchangeMP3Data(1); // send frame sync four times
    exchangeMP3Data(1);
    exchangeMP3Data(1);
    exchangeMP3Data(1);
    MP3_CODEC_nDCS_SET(TRUE);
    chThdSleepMilliseconds(20);

    // perform sine test
    writeMP3Register(VS1003_CMD_MODE, 0x0820);
    while (1) {
        for (size_t x = 0x21; x <= 0x24; x++) {
            // emit sine wave
            waitForMP3DREQ();
            MP3_CODEC_nDCS_SET(FALSE);
            MP3TxData[0] = 0x53;
            MP3TxData[1] = 0xef;
            MP3TxData[2] = 0x6e;
            MP3TxData[3] = x;
            MP3TxData[4] = 0x00;
            MP3TxData[5] = 0x00;
            MP3TxData[6] = 0x00;
            MP3TxData[7] = 0x00;
            exchangeMP3Data(8);
            MP3_CODEC_nDCS_SET(TRUE);
            chThdSleepMilliseconds(250);

            // exit
            waitForMP3DREQ();
            MP3_CODEC_nDCS_SET(FALSE);
            MP3TxData[0] = 0x45;
            MP3TxData[1] = 0x78;
            MP3TxData[2] = 0x69;
            MP3TxData[3] = 0x74;
            MP3TxData[4] = 0x00;
            MP3TxData[5] = 0x00;
            MP3TxData[6] = 0x00;
            MP3TxData[7] = 0x00;
            exchangeMP3Data(8);
            MP3_CODEC_nDCS_SET(TRUE);
            chThdSleepMilliseconds(250);
        }
    }

    /*
    // send data!!!
    MP3_CODEC_nDCS_SET(FALSE);
    spiSelect(&MP3_CODEC_DRIVER);
    uint32_t offset = 0;
    while (offset < TestAudioSize) {
        uint32_t length = TestAudioSize - offset;
        length = (length < 32 ? length : 32);
        waitForMP3DREQ();
        spiSend(&MP3_CODEC_DRIVER, length, TestAudioData + offset);
        offset += length;
    }
    spiUnselect(&MP3_CODEC_DRIVER);
    MP3_CODEC_nDCS_SET(TRUE);
    */

    return true;
}

int main()
{
    halInit();
    chSysInit();

    /*
    if (initSDCard()) {
        testSDCard();
    }
    */

    testMP3Codec();

    return 0;
}
