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
- {pin_num: '13', pin_signal: PIO0_31/PDM0_CLK/FC2_CTS_SDA_SSEL0/CTIMER2_CAP2/CTIMER0_CAP3/CTIMER0_MAT3/ADC0_2, label: 'J2[17]/J3[2]/P1[7]/U3[4]/SW2/P0_31-PDM0_CLK-ISP0_EN',
  identifier: SW2;speed1}
- {pin_num: '15', pin_signal: PIO1_1/SWO/SCT0_OUT4/FC5_SSEL2/FC4_TXD_SCL_MISO/ADC0_4, label: 'J1[15]/P1_1-FC5_SSEL2', identifier: speed2}
- {pin_num: '43', pin_signal: PIO0_8/FC2_RXD_SDA_MOSI/SCT0_OUT1/CTIMER0_MAT3, label: 'J2[15]/P0_8-FC2_RXD_SDA_MOSI', identifier: speed2}
- {pin_num: '44', pin_signal: PIO0_9/FC2_TXD_SCL_MISO/SCT0_OUT2/CTIMER3_CAP0/FC3_CTS_SDA_SSEL0, label: 'J2[13]/P0_9-FC2_TXD_SCL_MISO', identifier: direction1}
- {pin_num: '57', pin_signal: PIO1_14/FC2_RXD_SDA_MOSI/SCT0_OUT7/FC7_TXD_SCL_MISO_WS, label: 'J2[1]/P1_14-SCTO7', identifier: direction2}
- {pin_num: '60', pin_signal: PIO0_20/FC5_RXD_SDA_MOSI/FC0_SCK/CTIMER3_CAP0, label: 'J1[13]/U5[5]/P0_20-FC5_RXD_SDA_MOSI', identifier: SPI_FLASH_MOSI;direction1}
- {pin_num: '62', pin_signal: PIO1_15/PDM0_CLK/SCT0_OUT5/CTIMER1_CAP3/FC7_CTS_SDA_SSEL0, label: 'J1[17]/P1_15-SCTO5-FC7_CTS', identifier: speed1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
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
  - {pin_num: '62', peripheral: GPIO, signal: 'PIO1, 15', pin_signal: PIO1_15/PDM0_CLK/SCT0_OUT5/CTIMER1_CAP3/FC7_CTS_SDA_SSEL0, direction: INPUT}
  - {pin_num: '15', peripheral: GPIO, signal: 'PIO1, 1', pin_signal: PIO1_1/SWO/SCT0_OUT4/FC5_SSEL2/FC4_TXD_SCL_MISO/ADC0_4, direction: INPUT}
  - {pin_num: '60', peripheral: GPIO, signal: 'PIO0, 20', pin_signal: PIO0_20/FC5_RXD_SDA_MOSI/FC0_SCK/CTIMER3_CAP0, identifier: direction1, direction: INPUT}
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

    gpio_pin_config_t direction1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_20 (pin 60)  */
    GPIO_PinInit(BOARD_INITPINS_direction1_GPIO, BOARD_INITPINS_direction1_PORT, BOARD_INITPINS_direction1_PIN, &direction1_config);

    gpio_pin_config_t speed2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_1 (pin 15)  */
    GPIO_PinInit(BOARD_INITPINS_speed2_GPIO, BOARD_INITPINS_speed2_PORT, BOARD_INITPINS_speed2_PIN, &speed2_config);

    gpio_pin_config_t direction2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_14 (pin 57)  */
    GPIO_PinInit(BOARD_INITPINS_direction2_GPIO, BOARD_INITPINS_direction2_PORT, BOARD_INITPINS_direction2_PIN, &direction2_config);

    gpio_pin_config_t speed1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_15 (pin 62)  */
    GPIO_PinInit(BOARD_INITPINS_speed1_GPIO, BOARD_INITPINS_speed1_PORT, BOARD_INITPINS_speed1_PIN, &speed1_config);

    IOCON->PIO[0][20] = ((IOCON->PIO[0][20] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT020 (pin 60) is configured as PIO0_20. */
                         | IOCON_PIO_FUNC(PIO020_FUNC_ALT0)

                         /* Select Analog/Digital mode.
                          * : Digital mode. */
                         | IOCON_PIO_DIGIMODE(PIO020_DIGIMODE_DIGITAL));

    IOCON->PIO[1][1] = ((IOCON->PIO[1][1] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT11 (pin 15) is configured as PIO1_1. */
                        | IOCON_PIO_FUNC(PIO11_FUNC_ALT0)

                        /* Select Analog/Digital mode.
                         * : Digital mode. */
                        | IOCON_PIO_DIGIMODE(PIO11_DIGIMODE_DIGITAL));

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
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
