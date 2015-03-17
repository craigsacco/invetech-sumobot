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

int main()
{
    halInit();
    chSysInit();

    if (initSDCard()) {
        testSDCard();
    }

    return 0;
}
