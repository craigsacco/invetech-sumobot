#include <ch.h>
#include <hal.h>
#include <ff.h>

bool initSDCard()
{
    static SDCConfig config { .dummy = 0 };
    static SDCDriver* driver = &SDCD1;
    sdcStart(driver, &config);

    return (sdcConnect(driver) == CH_SUCCESS);
}

bool testSDCard()
{
    FATFS fs;
    FRESULT res;
    DIR dir;
    FILINFO fileinfo;

    res = f_mount(0, &fs);
    if (res == FR_OK) {
        res = f_opendir(&dir, "0:/");
        if (res == FR_OK) {
            while (1) {
                res = f_readdir(&dir, &fileinfo);
                if (res == FR_OK) {
                    if (fileinfo.fname[0] == 0) {
                        return true;
                    }
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
