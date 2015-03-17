#ifndef SUMOBOT_H
#define SUMOBOT_H

#include <hal.h>

#define OPEN207Z_LED1_PORT              GPIOH
#define OPEN207Z_LED1_PIN               2
#define OPEN207Z_LED2_PORT              GPIOH
#define OPEN207Z_LED2_PIN               3
#define OPEN207Z_LED3_PORT              GPIOI
#define OPEN207Z_LED3_PIN               8
#define OPEN207Z_LED4_PORT              GPIOI
#define OPEN207Z_LED4_PIN               10

#define OPEN207Z_LED1_GET()             palReadPad(OPEN207Z_LED1_PORT, OPEN207Z_LED1_PIN)
#define OPEN207Z_LED2_GET()             palReadPad(OPEN207Z_LED2_PORT, OPEN207Z_LED2_PIN)
#define OPEN207Z_LED3_GET()             palReadPad(OPEN207Z_LED3_PORT, OPEN207Z_LED3_PIN)
#define OPEN207Z_LED4_GET()             palReadPad(OPEN207Z_LED4_PORT, OPEN207Z_LED4_PIN)

#define OPEN207Z_LED1_SET(on)           palWritePad(OPEN207Z_LED1_PORT, OPEN207Z_LED1_PIN, on ? 1 : 0)
#define OPEN207Z_LED2_SET(on)           palWritePad(OPEN207Z_LED2_PORT, OPEN207Z_LED2_PIN, on ? 1 : 0)
#define OPEN207Z_LED3_SET(on)           palWritePad(OPEN207Z_LED3_PORT, OPEN207Z_LED3_PIN, on ? 1 : 0)
#define OPEN207Z_LED4_SET(on)           palWritePad(OPEN207Z_LED4_PORT, OPEN207Z_LED4_PIN, on ? 1 : 0)

#define OPEN207Z_KEY1_PORT              GPIOA
#define OPEN207Z_KEY1_PIN               0
#define OPEN207Z_KEY2_PORT              GPIOF
#define OPEN207Z_KEY2_PIN               10

#define OPEN207Z_KEY1_GET()             (palReadPad(OPEN207Z_KEY1_PORT, OPEN207Z_KEY1_PIN) == 0) // active-low
#define OPEN207Z_KEY2_GET()             (palReadPad(OPEN207Z_KEY2_PORT, OPEN207Z_KEY2_PIN) == 0) // active-low

#define SDIO_DRIVER                     SDCD1
#define SDIO_CHIP_DETECT_PORT           GPIOG
#define SDIO_CHIP_DETECT_PIN            8

#define SDIO_CHIP_DETECT_GET()          (palReadPad(SDIO_CHIP_DETECT_PORT, SDIO_CHIP_DETECT_PIN) == 0) // active-low

#define MP3_CODEC_DRIVER                SPID2
#define MP3_CODEC_CHIP_SELECT_PORT      GPIOB
#define MP3_CODEC_CHIP_SELECT_PIN       12
#define MP3_CODEC_OREQ_PORT             GPIOA
#define MP3_CODEC_OREQ_PIN              7
#define MP3_CODEC_RESET_PORT            GPIOA
#define MP3_CODEC_RESET_PIN             5
#define MP3_CODEC_DCS_PORT              GPIOA
#define MP3_CODEC_DCS_PIN               4

#define MP3_CODEC_CHIP_SELECT_GET()     (palReadPad(MP3_CODEC_CHIP_SELECT_PORT, MP3_CODEC_CHIP_SELECT_PIN) == 0) // active-low
#define MP3_CODEC_OREQ_GET()            palReadPad(MP3_CODEC_OREQ_PORT, MP3_CODEC_OREQ_PIN)
#define MP3_CODEC_RESET_GET()           (palReadPad(MP3_CODEC_RESET_PORT, MP3_CODEC_RESET_PIN) == 0) // active-low
#define MP3_CODEC_DCS_GET()             (palReadPad(MP3_CODEC_DCS_PORT, MP3_CODEC_DCS_PIN) == 0) // active-low

#define MP3_CODEC_CHIP_SELECT_SET(on)   palWritePad(MP3_CODEC_CHIP_SELECT_PORT, MP3_CODEC_CHIP_SELECT_PIN, on ? 0 : 1) // active-low
#define MP3_CODEC_RESET_SET(on)         palWritePad(MP3_CODEC_RESET_PORT, MP3_CODEC_RESET_PIN, on ? 0 : 1) // active-low
#define MP3_CODEC_DCS_SET(on)           palWritePad(MP3_CODEC_DCS_PORT, MP3_CODEC_DCS_PIN, on ? 0 : 1) // active-low

#endif // SUMOBOT_H

