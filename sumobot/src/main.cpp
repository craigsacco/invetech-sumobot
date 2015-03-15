#include <ch.h>
#include <hal.h>
#include <ff.h>

int main()
{
    chSysInit();
    halInit();

    sdcStart(&SDCD1, NULL);

    FRESULT res;
    DIR dir;
    FILINFO fileinfo;
    res = f_opendir(&dir, "/");
    if (res == FR_OK) {
        for (;;) {
            res = f_readdir(&dir, &fileinfo);
            if (res != FR_OK || fileinfo.fname[0] == 0) {
                break;
            }
        }
    }

    return 0;
}
