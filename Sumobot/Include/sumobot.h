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
#define MP3_CODEC_nCS_PORT              GPIOB
#define MP3_CODEC_nCS_PIN               12
#define MP3_CODEC_DREQ_PORT             GPIOA
#define MP3_CODEC_DREQ_PIN              7
#define MP3_CODEC_nRESET_PORT           GPIOA
#define MP3_CODEC_nRESET_PIN            5
#define MP3_CODEC_nDCS_PORT             GPIOA
#define MP3_CODEC_nDCS_PIN              4

#define MP3_CODEC_nCS_GET()             (palReadPad(MP3_CODEC_nCS_PORT, MP3_CODEC_nCS_PIN))
#define MP3_CODEC_DREQ_GET()            (palReadPad(MP3_CODEC_DREQ_PORT, MP3_CODEC_DREQ_PIN))
#define MP3_CODEC_nRESET_GET()          (palReadPad(MP3_CODEC_nRESET_PORT, MP3_CODEC_nRESET_PIN))
#define MP3_CODEC_nDCS_GET()            (palReadPad(MP3_CODEC_nDCS_PORT, MP3_CODEC_nDCS_PIN))

#define MP3_CODEC_nCS_SET(on)           palWritePad(MP3_CODEC_nCS_PORT, MP3_CODEC_nCS_PIN, on ? 1 : 0)
#define MP3_CODEC_nRESET_SET(on)        palWritePad(MP3_CODEC_nRESET_PORT, MP3_CODEC_nRESET_PIN, on ? 1 : 0)
#define MP3_CODEC_nDCS_SET(on)          palWritePad(MP3_CODEC_nDCS_PORT, MP3_CODEC_nDCS_PIN, on ? 1 : 0)

#endif // SUMOBOT_H

