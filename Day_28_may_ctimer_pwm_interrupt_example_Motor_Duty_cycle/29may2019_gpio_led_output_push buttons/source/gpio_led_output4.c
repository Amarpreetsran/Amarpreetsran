/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define  APP_BOARD_TEST_LED_PORT 1U
#define  APP_BOARD_TEST_LED_PIN 10U


#define BOARD_INITPINS_SPI_FLASH_MOSI_PORT 1U
#define BOARD_INITPINS_SPI_FLASH_MOSI_PIN 10U

#define BOARD_INITPINS_SP1_PORT 1U
#define BOARD_INITPINS_SP1_PIN 10U

#define BOARD_INITPINS_DR1_PORT 1U
#define BOARD_INITPINS_DR1_PIN 10U

#define BOARD_INITPINS_DR2_PORT 1U
#define BOARD_INITPINS_DR2_PIN 10U

#define SWITCHB BOARD_SW1_GPIO_PORT
#define SWITCHP BOARD_SW1_GPIO_PIN

#define SM1 BOARD_SW2_GPIO_PORT
#define SMP1 BOARD_SW2_GPIO_PIN

#define DM1 BOARD_SW3_GPIO_PORT
#define DMP1 BOARD_SW3_GPIO_PIN

#define DM2 BOARD_SW4_GPIO_PORT
#define DMP2 BOARD_SW4_GPIO_PIN




/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
void delay(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 100000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    uint32_t port_state = 0;

    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput, 0,
    };

    /* Board pin, clock, debug console init */
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    /* enable clock for GPIO*/
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n GPIO Driver example\r\n");
    PRINTF("\r\n The LED is taking turns to shine.\r\n");

    /* Init SW1 GPIO PORT. */
    GPIO_PortInit(GPIO, SWITCHB);

    /* Init SW2 GPIO PORT. */
    GPIO_PortInit(GPIO, SM1);

    /* Init SW3 GPIO PORT. */
    GPIO_PortInit(GPIO, DM1);

    /* Init SW4 GPIO PORT. */
      GPIO_PortInit(GPIO, DM2);

    /* Init output MOSI. */
    GPIO_PortInit(GPIO,  BOARD_INITPINS_SPI_FLASH_MOSI_PORT);
    GPIO_PinInit(GPIO,  BOARD_INITPINS_SPI_FLASH_MOSI_PORT,  BOARD_INITPINS_SPI_FLASH_MOSI_PIN, &led_config);
    GPIO_PinWrite(GPIO,  BOARD_INITPINS_SPI_FLASH_MOSI_PORT,  BOARD_INITPINS_SPI_FLASH_MOSI_PIN, 1);


    /* Init output SP1. */
    GPIO_PortInit(GPIO,  BOARD_INITPINS_SP1_PORT);
    GPIO_PinInit(GPIO,  BOARD_INITPINS_SP1_PORT,  BOARD_INITPINS_SP1_PIN, &led_config);
    GPIO_PinWrite(GPIO,   BOARD_INITPINS_SP1_PORT,  BOARD_INITPINS_SP1_PIN, 1);

    /* Init output DR1. */
    GPIO_PortInit(GPIO,  BOARD_INITPINS_DR1_PORT);
        GPIO_PinInit(GPIO,  BOARD_INITPINS_DR1_PORT,  BOARD_INITPINS_DR1_PIN, &led_config);
        GPIO_PinWrite(GPIO,   BOARD_INITPINS_DR1_PORT,  BOARD_INITPINS_DR1_PIN, 1);

        /* Init output DR2. */
          GPIO_PortInit(GPIO,  BOARD_INITPINS_DR2_PORT);
              GPIO_PinInit(GPIO,  BOARD_INITPINS_DR2_PORT,  BOARD_INITPINS_DR2_PIN, &led_config);
              GPIO_PinWrite(GPIO,   BOARD_INITPINS_DR2_PORT,  BOARD_INITPINS_DR2_PIN, 1);


    /* Port masking SW1 */
    GPIO_PortMaskedSet(GPIO,  BOARD_INITPINS_SPI_FLASH_MOSI_PORT, 0x0000FFFF);
    GPIO_PortMaskedWrite(GPIO,  BOARD_INITPINS_SPI_FLASH_MOSI_PORT, 0xFFFFFFFF);
    port_state = GPIO_PortRead(GPIO, SWITCHB);
    PRINTF("\r\n Standard port read: %x\r\n", port_state);
    port_state = GPIO_PortMaskedRead(GPIO, SWITCHB);
    PRINTF("\r\n Masked port read: %x\r\n", port_state);

    /* Port masking SW2 */
    GPIO_PortMaskedSet(GPIO,  BOARD_INITPINS_SP1_PORT, 0x0000FFFF);
       GPIO_PortMaskedWrite(GPIO,  BOARD_INITPINS_SP1_PORT, 0xFFFFFFFF);
       port_state = GPIO_PortRead(GPIO, SM1);
       PRINTF("\r\n Standard port read: %x\r\n", port_state);
       port_state = GPIO_PortMaskedRead(GPIO, SM1);
       PRINTF("\r\n Masked port read: %x\r\n", port_state);

      /* Port masking SW3 */
          GPIO_PortMaskedSet(GPIO,  BOARD_INITPINS_DR1_PORT, 0x0000FFFF);
             GPIO_PortMaskedWrite(GPIO,  BOARD_INITPINS_DR1_PORT, 0xFFFFFFFF);
             port_state = GPIO_PortRead(GPIO, DM1);
             PRINTF("\r\n Standard port read: %x\r\n", port_state);
             port_state = GPIO_PortMaskedRead(GPIO, DM1);
             PRINTF("\r\n Masked port read: %x\r\n", port_state);


             /* Port masking SW4 */
                     GPIO_PortMaskedSet(GPIO,  BOARD_INITPINS_DR2_PORT, 0x0000FFFF);
                        GPIO_PortMaskedWrite(GPIO,  BOARD_INITPINS_DR2_PORT, 0xFFFFFFFF);
                        port_state = GPIO_PortRead(GPIO, DM2);
                        PRINTF("\r\n Standard port read: %x\r\n", port_state);
                        port_state = GPIO_PortMaskedRead(GPIO, DM2);
                        PRINTF("\r\n Masked port read: %x\r\n", port_state);

    while (1)
    {
        port_state = GPIO_PortRead(GPIO, SWITCHB);
        if (!(port_state & (1 << SWITCHP)))
        {
            PRINTF("\r\n Port state: %x\r\n", port_state);
            GPIO_PortToggle(GPIO,  BOARD_INITPINS_SPI_FLASH_MOSI_PORT, 1u <<  BOARD_INITPINS_SPI_FLASH_MOSI_PIN);
        }
        delay();

        port_state = GPIO_PortRead(GPIO, SM1);
        if (!(port_state & (1 << SMP1)))
              {
                  PRINTF("\r\n Port state: %x\r\n", port_state);
                  GPIO_PortToggle(GPIO,  BOARD_INITPINS_SP1_PORT, 1u <<  BOARD_INITPINS_SP1_PIN);
              }
              delay();

              port_state = GPIO_PortRead(GPIO, DM1);
                     if (!(port_state & (1 << DMP1)))
                           {
                               PRINTF("\r\n Port state: %x\r\n", port_state);
                               GPIO_PortToggle(GPIO,  BOARD_INITPINS_DR1_PORT, 1u <<  BOARD_INITPINS_DR1_PIN);
                           }
                           delay();

                           port_state = GPIO_PortRead(GPIO, DM2);
                                              if (!(port_state & (1 << DMP2)))
                                                    {
                                                        PRINTF("\r\n Port state: %x\r\n", port_state);
                                                        GPIO_PortToggle(GPIO,  BOARD_INITPINS_DR2_PORT, 1u <<  BOARD_INITPINS_DR2_PIN);
                                                    }
                                                    delay();
    }
}
