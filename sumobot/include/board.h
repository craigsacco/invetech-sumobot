#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for Waveshare Open407I-C Development Board
 */

/*
 * Board identifier.
 */
#define BOARD_OPEN407IC_DEV
#define BOARD_NAME                  "Open407I-C Development Board"


/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   300

/*
 * MCU type as defined in the ST header.
 */
#define STM32F40_41xxx

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << ((n % 8) * 4))

/*
 * GPIOA setup:
 *
 * PA0 - KEY1 Button                (digital output)
 * PA13 - SWDIO                     (alternate 0)
 * PA14 - SWCLK                     (alternate 0)
 */
#define VAL_GPIOA_MODER             (PIN_MODE_OUTPUT(0) |          \
                                     PIN_MODE_ALTERNATE(13) |      \
                                     PIN_MODE_ALTERNATE(14))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(0) |          \
                                     PIN_OTYPE_PUSHPULL(13) |      \
                                     PIN_OTYPE_PUSHPULL(14))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_2M(0) |         \
                                     PIN_OSPEED_100M(13) |         \
                                     PIN_OSPEED_100M(14))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(0) |         \
                                     PIN_PUPDR_FLOATING(13) |      \
                                     PIN_PUPDR_FLOATING(14))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(0) |            \
                                     PIN_ODR_HIGH(13) |            \
                                     PIN_ODR_HIGH(14))
#define VAL_GPIOA_AFRL              (0)
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(13, 0) |          \
                                     PIN_AFIO_AF(14, 0))

/*
 * GPIOB setup:
 *
 * PB3  - SWO                       (alternate 0)
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ALTERNATE(3))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(3))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_100M(3))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(3))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(3))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(3, 0))
#define VAL_GPIOB_AFRH              (0)

/*
 * GPIOC setup:
 *
 * PC8  - SDIO_D0                   (alternate 12)
 * PC9  - SDIO_D1                   (alternate 12)
 * PC10 - SDIO_D2                   (alternate 12)
 * PC11 - SDIO_D3                   (alternate 12)
 * PC12 - SDIO_CLK                  (alternate 12)
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ALTERNATE(8) | \
                                     PIN_MODE_ALTERNATE(9) | \
                                     PIN_MODE_ALTERNATE(10) | \
                                     PIN_MODE_ALTERNATE(11) | \
                                     PIN_MODE_ALTERNATE(12))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(8) | \
                                     PIN_OTYPE_PUSHPULL(9) | \
                                     PIN_OTYPE_PUSHPULL(10) | \
                                     PIN_OTYPE_PUSHPULL(11) | \
                                     PIN_OTYPE_PUSHPULL(12))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_50M(8) | \
                                     PIN_OSPEED_50M(9) | \
                                     PIN_OSPEED_50M(10) | \
                                     PIN_OSPEED_50M(11) | \
                                     PIN_OSPEED_50M(12))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(8) | \
                                     PIN_PUPDR_FLOATING(9) | \
                                     PIN_PUPDR_FLOATING(10) | \
                                     PIN_PUPDR_FLOATING(11) | \
                                     PIN_PUPDR_FLOATING(12))
#define VAL_GPIOC_ODR               (0)
#define VAL_GPIOC_AFRL              (0)
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(8, 12) | \
                                     PIN_AFIO_AF(9, 12) | \
                                     PIN_AFIO_AF(10, 12) | \
                                     PIN_AFIO_AF(11, 12) | \
                                     PIN_AFIO_AF(12, 12))

/*
 * GPIOD setup:
 *
 * PD2  - SDIO_CMD                  (alternate 12)
 */
#define VAL_GPIOD_MODER             (PIN_MODE_ALTERNATE(2))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(2))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_50M(2))
#define VAL_GPIOD_PUPDR             (0)
#define VAL_GPIOD_ODR               (PIN_PUPDR_FLOATING(12))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(2, 12))
#define VAL_GPIOD_AFRH              (0)

/*
 * GPIOE setup:
 */
#define VAL_GPIOE_MODER             (0)
#define VAL_GPIOE_OTYPER            (0)
#define VAL_GPIOE_OSPEEDR           (0)
#define VAL_GPIOE_PUPDR             (0)
#define VAL_GPIOE_ODR               (0)
#define VAL_GPIOE_AFRL              (0)
#define VAL_GPIOE_AFRH              (0)

/*
 * GPIOF setup:
 *
 * PF10 - KEY2 Button               (digital input /w pull-up)
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(10))
#define VAL_GPIOF_OTYPER            (0)
#define VAL_GPIOF_OSPEEDR           (0)
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_PULLUP(10))
#define VAL_GPIOF_ODR               (0)
#define VAL_GPIOF_AFRL              (0)
#define VAL_GPIOF_AFRH              (0)

/*
 * GPIOG setup:
 *
 * PG8  - SDIO chip detect          (digital input /w pull-down)
 */
#define VAL_GPIOG_MODER             (PIN_MODE_INPUT(8))
#define VAL_GPIOG_OTYPER            (0)
#define VAL_GPIOG_OSPEEDR           (0)
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_PULLDOWN(8))
#define VAL_GPIOG_ODR               (0)
#define VAL_GPIOG_AFRL              (0)
#define VAL_GPIOG_AFRH              (0)

/*
 * GPIOH setup:
 *
 * PH2  - LED1 LED                  (digital output /w pull-down)
 * PH3  - LED2 LED                  (digital output /w pull-down)
 */
#define VAL_GPIOH_MODER             (PIN_MODE_OUTPUT(2) | \
                                     PIN_MODE_OUTPUT(3))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(2) | \
                                     PIN_OTYPE_PUSHPULL(3))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_2M(2) | \
                                     PIN_OSPEED_2M(3))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_PULLDOWN(2) | \
                                     PIN_PUPDR_PULLDOWN(3))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(2) | \
                                     PIN_ODR_HIGH(3))
#define VAL_GPIOH_AFRL              (0)
#define VAL_GPIOH_AFRH              (0)

/*
 * GPIOI setup:
 *
 * PH8  - LED3 LED                  (digital output /w pull-down)
 * PH10 - LED4 LED                  (digital output /w pull-down)
 */
#define VAL_GPIOI_MODER             (PIN_MODE_OUTPUT(8) | \
                                     PIN_MODE_OUTPUT(10))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(8) | \
                                     PIN_OTYPE_PUSHPULL(10))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_2M(8) | \
                                     PIN_OSPEED_2M(10))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_PULLDOWN(8) | \
                                     PIN_PUPDR_PULLDOWN(10))
#define VAL_GPIOI_ODR               (PIN_ODR_HIGH(8) | \
                                     PIN_ODR_HIGH(10))
#define VAL_GPIOI_AFRL              (0)
#define VAL_GPIOI_AFRH              (0)


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
