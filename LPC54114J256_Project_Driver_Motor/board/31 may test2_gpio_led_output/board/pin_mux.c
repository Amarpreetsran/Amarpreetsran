/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: LPC54114J256
package_id: LPC54114J256BD64
mcu_data: ksdk2_0
processor_version: 5.0.1
board: LPCXpresso54114
pin_labels:
- {pin_num: '15', pin_signal: PIO1_1/SWO/SCT0_OUT4/FC5_SSEL2/FC4_TXD_SCL_MISO/ADC0_4, label: 'J1[15]/P1_1-FC5_SSEL2', identifier: S2}
- {pin_num: '57', pin_signal: PIO1_14/FC2_RXD_SDA_MOSI/SCT0_OUT7/FC7_TXD_SCL_MISO_WS, label: 'J2[1]/P1_14-SCTO7', identifier: D2}
- {pin_num: '60', pin_signal: PIO0_20/FC5_RXD_SDA_MOSI/FC0_SCK/CTIMER3_CAP0, label: 'J1[13]/U5[5]/P0_20-FC5_RXD_SDA_MOSI', identifier: SPI_FLASH_MOSI;SPEED1;S1}
- {pin_num: '62', pin_signal: PIO1_15/PDM0_CLK/SCT0_OUT5/CTIMER1_CAP3/FC7_CTS_SDA_SSEL0, label: 'J1[17]/P1_15-SCTO5-FC7_CTS', identifier: D1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm4, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI, pin_signal: PIO0_0/FC0_RXD_SDA_MOSI/FC3_CTS_SDA_SSEL0/CTIMER0_CAP0/SCT0_OUT3, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: '32', peripheral: FLEXCOMM0, signal: TXD_SCL_MISO, pin_signal: PIO0_1/FC0_TXD_SCL_MISO/FC3_RTS_SCL_SSEL1/CTIMER0_CAP1/SCT0_OUT1, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: '11', peripheral: GPIO, signal: 'PIO0, 29', pin_signal: PIO0_29/FC1_RXD_SDA_MOSI/SCT0_OUT2/CTIMER0_MAT3/CTIMER0_CAP1/CTIMER0_MAT1/ADC0_0, mode: pullUp,
    invert: disabled, glitch_filter: disabled, open_drain: disabled}
  - {pin_num: '30', peripheral: GPIO, signal: 'PIO1, 10', pin_signal: PIO1_10/FC6_TXD_SCL_MISO_WS/SCT0_OUT4/FC1_SCK/USB0_FRAME, mode: pullUp, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: '29', peripheral: GPIO, signal: 'PIO1, 9', pin_signal: PIO1_9/FC3_RXD_SDA_MOSI/CTIMER0_CAP2/USB0_UP_LED, mode: pullUp, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: '38', peripheral: GPIO, signal: 'PIO0, 4', pin_signal: PIO0_4/FC0_SCK/FC3_SSEL2/CTIMER0_CAP2, mode: pullUp, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: '2', peripheral: GPIO, signal: 'PIO0, 24', pin_signal: PIO0_24/FC1_CTS_SDA_SSEL0/CTIMER0_CAP1/CTIMER0_MAT0, invert: disabled, glitch_filter: disabled,
    i2c_slew: gpio, i2c_drive: low, i2c_filter: enabled}
  - {pin_num: '13', peripheral: GPIO, signal: 'PIO0, 31', pin_signal: PIO0_31/PDM0_CLK/FC2_CTS_SDA_SSEL0/CTIMER2_CAP2/CTIMER0_CAP3/CTIMER0_MAT3/ADC0_2, mode: pullUp,
    invert: disabled, glitch_filter: disabled, open_drain: disabled}
  - {pin_num: '60', peripheral: GPIO, signal: 'PIO0, 20', pin_signal: PIO0_20/FC5_RXD_SDA_MOSI/FC0_SCK/CTIMER3_CAP0, identifier: S1, direction: INPUT}
  - {pin_num: '15', peripheral: GPIO, signal: 'PIO1, 1', pin_signal: PIO1_1/SWO/SCT0_OUT4/FC5_SSEL2/FC4_TXD_SCL_MISO/ADC0_4, direction: INPUT}
  - {pin_num: '62', peripheral: GPIO, signal: 'PIO1, 15', pin_signal: PIO1_15/PDM0_CLK/SCT0_OUT5/CTIMER1_CAP3/FC7_CTS_SDA_SSEL0, direction: INPUT}
  - {pin_num: '57', peripheral: GPIO, signal: 'PIO1, 14', pin_signal: PIO1_14/FC2_RXD_SDA_MOSI/SCT0_OUT7/FC7_TXD_SCL_MISO_WS, direction: INPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M4F */
void BOARD_InitPins(void)
{
    /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);
    /* Enables the clock for the GPIO1 module */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    gpio_pin_config_t S1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_20 (pin 60)  */
    GPIO_PinInit(BOARD_INITPINS_S1_GPIO, BOARD_INITPINS_S1_PORT, BOARD_INITPINS_S1_PIN, &S1_config);

    gpio_pin_config_t S2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_1 (pin 15)  */
    GPIO_PinInit(BOARD_INITPINS_S2_GPIO, BOARD_INITPINS_S2_PORT, BOARD_INITPINS_S2_PIN, &S2_config);

    gpio_pin_config_t D2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_14 (pin 57)  */
    GPIO_PinInit(BOARD_INITPINS_D2_GPIO, BOARD_INITPINS_D2_PORT, BOARD_INITPINS_D2_PIN, &D2_config);

    gpio_pin_config_t D1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_15 (pin 62)  */
    GPIO_PinInit(BOARD_INITPINS_D1_GPIO, BOARD_INITPINS_D1_PORT, BOARD_INITPINS_D1_PIN, &D1_config);

    const uint32_t port0_pin0_config = (/* Pin is configured as FC0_RXD_SDA_MOSI */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN0 (coords: 31) is configured as FC0_RXD_SDA_MOSI */
    IOCON_PinMuxSet(IOCON, 0U, 0U, port0_pin0_config);

    const uint32_t port0_pin1_config = (/* Pin is configured as FC0_TXD_SCL_MISO */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN1 (coords: 32) is configured as FC0_TXD_SCL_MISO */
    IOCON_PinMuxSet(IOCON, 0U, 1U, port0_pin1_config);

    IOCON->PIO[0][20] = ((IOCON->PIO[0][20] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT020 (pin 60) is configured as PIO0_20. */
                         | IOCON_PIO_FUNC(PIO020_FUNC_ALT0)

                         /* Select Analog/Digital mode.
                          * : Digital mode. */
                         | IOCON_PIO_DIGIMODE(PIO020_DIGIMODE_DIGITAL));

    const uint32_t port0_pin24_config = (/* Pin is configured as PIO0_24 */
                                         IOCON_PIO_FUNC0 |
                                         /* GPIO mode */
                                         IOCON_PIO_I2CSLEW_GPIO |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Low drive: 4 mA */
                                         IOCON_PIO_I2CDRIVE_LOW |
                                         /* I2C 50 ns glitch filter enabled */
                                         IOCON_PIO_I2CFILTER_EN);
    /* PORT0 PIN24 (coords: 2) is configured as PIO0_24 */
    IOCON_PinMuxSet(IOCON, 0U, 24U, port0_pin24_config);

    const uint32_t LED_RED = (/* Pin is configured as PIO0_29 */
                              IOCON_PIO_FUNC0 |
                              /* Selects pull-up function */
                              IOCON_PIO_MODE_PULLUP |
                              /* Input function is not inverted */
                              IOCON_PIO_INV_DI |
                              /* Enables digital function */
                              IOCON_PIO_DIGITAL_EN |
                              /* Input filter disabled */
                              IOCON_PIO_INPFILT_OFF |
                              /* Open drain is disabled */
                              IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: 11) is configured as PIO0_29 */
    IOCON_PinMuxSet(IOCON, BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_LED_RED_PIN, LED_RED);

    const uint32_t SW2 = (/* Pin is configured as PIO0_31 */
                          IOCON_PIO_FUNC0 |
                          /* Selects pull-up function */
                          IOCON_PIO_MODE_PULLUP |
                          /* Input function is not inverted */
                          IOCON_PIO_INV_DI |
                          /* Enables digital function */
                          IOCON_PIO_DIGITAL_EN |
                          /* Input filter disabled */
                          IOCON_PIO_INPFILT_OFF |
                          /* Open drain is disabled */
                          IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN31 (coords: 13) is configured as PIO0_31 */
    IOCON_PinMuxSet(IOCON, BOARD_INITPINS_SW2_PORT, BOARD_INITPINS_SW2_PIN, SW2);

    const uint32_t port0_pin4_config = (/* Pin is configured as PIO0_4 */
                                        IOCON_PIO_FUNC0 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN4 (coords: 38) is configured as PIO0_4 */
    IOCON_PinMuxSet(IOCON, 0U, 4U, port0_pin4_config);

    IOCON->PIO[1][1] = ((IOCON->PIO[1][1] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT11 (pin 15) is configured as PIO1_1. */
                        | IOCON_PIO_FUNC(PIO11_FUNC_ALT0)

                        /* Select Analog/Digital mode.
                         * : Digital mode. */
                        | IOCON_PIO_DIGIMODE(PIO11_DIGIMODE_DIGITAL));

    const uint32_t LED_GREEN = (/* Pin is configured as PIO1_10 */
                                IOCON_PIO_FUNC0 |
                                /* Selects pull-up function */
                                IOCON_PIO_MODE_PULLUP |
                                /* Input function is not inverted */
                                IOCON_PIO_INV_DI |
                                /* Enables digital function */
                                IOCON_PIO_DIGITAL_EN |
                                /* Input filter disabled */
                                IOCON_PIO_INPFILT_OFF |
                                /* Standard mode, output slew rate control is enabled */
                                IOCON_PIO_SLEW_STANDARD |
                                /* Open drain is disabled */
                                IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN10 (coords: 30) is configured as PIO1_10 */
    IOCON_PinMuxSet(IOCON, BOARD_INITPINS_LED_GREEN_PORT, BOARD_INITPINS_LED_GREEN_PIN, LED_GREEN);

    IOCON->PIO[1][14] = ((IOCON->PIO[1][14] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT114 (pin 57) is configured as PIO1_14. */
                         | IOCON_PIO_FUNC(PIO114_FUNC_ALT0)

                         /* Select Analog/Digital mode.
                          * : Digital mode. */
                         | IOCON_PIO_DIGIMODE(PIO114_DIGIMODE_DIGITAL));

    IOCON->PIO[1][15] = ((IOCON->PIO[1][15] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT115 (pin 62) is configured as PIO1_15. */
                         | IOCON_PIO_FUNC(PIO115_FUNC_ALT0)

                         /* Select Analog/Digital mode.
                          * : Digital mode. */
                         | IOCON_PIO_DIGIMODE(PIO115_DIGIMODE_DIGITAL));

    const uint32_t LED_BLUE = (/* Pin is configured as PIO1_9 */
                               IOCON_PIO_FUNC0 |
                               /* Selects pull-up function */
                               IOCON_PIO_MODE_PULLUP |
                               /* Input function is not inverted */
                               IOCON_PIO_INV_DI |
                               /* Enables digital function */
                               IOCON_PIO_DIGITAL_EN |
                               /* Input filter disabled */
                               IOCON_PIO_INPFILT_OFF |
                               /* Standard mode, output slew rate control is enabled */
                               IOCON_PIO_SLEW_STANDARD |
                               /* Open drain is disabled */
                               IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN9 (coords: 29) is configured as PIO1_9 */
    IOCON_PinMuxSet(IOCON, BOARD_INITPINS_LED_BLUE_PORT, BOARD_INITPINS_LED_BLUE_PIN, LED_BLUE);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
