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
#define APP_BOARD_TEST_LED_PORT 1U
#define APP_BOARD_TEST_LED_PIN 10U
#define APP_SW_PORT BOARD_SW1_GPIO_PORT
#define APP_SW_PIN  BOARD_SW1_GPIO_PIN

#define S1_TEST_LED_PORT 0U
#define S1_TEST_LED_PIN 20U

#define S2_TEST_LED_PORT 1U
#define S2_TEST_LED_PIN 1U

#define D1_TEST_LED_PORT 1U
#define D1_TEST_LED_PIN 15U

#define D2_TEST_LED_PORT 1U
#define D2_TEST_LED_PIN 14U

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
    uint32_t port_stateS_1 = 0;
    uint32_t port_stateS_2 = 0;
    uint32_t port_stateS_3 = 0;
    uint32_t port_stateS_4 = 0;

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

    /* Init SW GPIO PORT. */
    GPIO_PortInit(GPIO, S1_TEST_LED_PORT);
    GPIO_PortInit(GPIO, S2_TEST_LED_PORT);
    GPIO_PortInit(GPIO, D1_TEST_LED_PORT);
    GPIO_PortInit(GPIO, D2_TEST_LED_PORT);

    /* Init output LED GPIO. */
    GPIO_PortInit(GPIO, APP_BOARD_TEST_LED_PORT);
    GPIO_PinInit(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, &led_config);
    GPIO_PinWrite(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, 1);

    /* Port masking */
    GPIO_PortMaskedSet(GPIO, APP_BOARD_TEST_LED_PORT, 0x0000FFFF);
    GPIO_PortMaskedWrite(GPIO, APP_BOARD_TEST_LED_PORT, 0xFFFFFFFF);

    port_state = GPIO_PortRead(GPIO, APP_SW_PORT);
    port_stateS_1 = GPIO_PortRead(GPIO, S1_TEST_LED_PORT);
    port_stateS_2 = GPIO_PortRead(GPIO, S2_TEST_LED_PORT);
    port_stateS_3 = GPIO_PortRead(GPIO, D1_TEST_LED_PORT);
    port_stateS_4 = GPIO_PortRead(GPIO, D2_TEST_LED_PORT);



    PRINTF("\r\n Standard port read: %x\r\n", port_state);
    PRINTF("\r\n Standard port read: %x\r\n", port_stateS_1);
    PRINTF("\r\n Standard port read: %x\r\n", port_stateS_2);
    PRINTF("\r\n Standard port read: %x\r\n", port_stateS_3);
    PRINTF("\r\n Standard port read: %x\r\n", port_stateS_4);

    port_state = GPIO_PortMaskedRead(GPIO, APP_SW_PORT);
    port_state = GPIO_PortMaskedRead(GPIO, S1_TEST_LED_PORT);
    port_state = GPIO_PortMaskedRead(GPIO, S2_TEST_LED_PORT);
    port_state = GPIO_PortMaskedRead(GPIO, D1_TEST_LED_PORT);
    port_state = GPIO_PortMaskedRead(GPIO, D2_TEST_LED_PORT);

    PRINTF("\r\n Masked port read: %x\r\n", port_state);

    while (1)
    {
        port_state = GPIO_PortRead(GPIO, APP_SW_PORT);
        if (!(port_state & (1 << APP_SW_PIN)))
        {
            PRINTF("\r\n Port state: %x\r\n", port_state);
            GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
        }

        port_stateS_1 = GPIO_PortRead(GPIO, S1_TEST_LED_PORT);
               if (!(port_stateS_1 & (1 << S1_TEST_LED_PIN)))
               {
                   PRINTF("\r\n Port state: %x\r\n", port_stateS_1);
                   GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
               }

               port_stateS_2 = GPIO_PortRead(GPIO, S2_TEST_LED_PORT);
                      if (!(port_stateS_2 & (1 << S2_TEST_LED_PIN)))
                      {
                          PRINTF("\r\n Port state: %x\r\n", port_stateS_2);
                          GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
                      }

                      port_stateS_3 = GPIO_PortRead(GPIO, D1_TEST_LED_PORT);
                             if (!(port_stateS_3 & (1 << D1_TEST_LED_PIN)))
                             {
                                 PRINTF("\r\n Port state: %x\r\n", port_stateS_3);
                                 GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
                             }

                             port_stateS_4 = GPIO_PortRead(GPIO, D2_TEST_LED_PORT);
                                    if (!(port_stateS_4 & (1 << D2_TEST_LED_PIN)))
                                    {
                                        PRINTF("\r\n Port state: %x\r\n", port_stateS_4);
                                        GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
                                    }
        delay();
    }
}
