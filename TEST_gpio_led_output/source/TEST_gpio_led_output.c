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
#define BOARD_INITPINS_SPEED_PORT 1U
#define BOARD_INITPINS_SPEED_PIN 10U
#define SPEEDB BOARD_SW2_GPIO_PORT
#define SPEEDP BOARD_SW2_GPIO_PIN


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

    /* Init SW GPIO PORT. */
    GPIO_PortInit(GPIO, SPEEDB);

    /* Init output LED GPIO. */
    GPIO_PortInit(GPIO, BOARD_INITPINS_SPEED_PORT);
    GPIO_PinInit(GPIO, BOARD_INITPINS_SPEED_PORT, BOARD_INITPINS_SPEED_PIN, &led_config);
    GPIO_PinWrite(GPIO, BOARD_INITPINS_SPEED_PORT, BOARD_INITPINS_SPEED_PIN, 1);

    /* Port masking */
    GPIO_PortMaskedSet(GPIO, BOARD_INITPINS_SPEED_PORT, 0x0000FFFF);
    GPIO_PortMaskedWrite(GPIO, BOARD_INITPINS_SPEED_PORT, 0xFFFFFFFF);
    port_state = GPIO_PortRead(GPIO, SPEEDB);
    PRINTF("\r\n Standard port read: %x\r\n", port_state);
    port_state = GPIO_PortMaskedRead(GPIO, SPEEDB);
    PRINTF("\r\n Masked port read: %x\r\n", port_state);

    while (1)
    {
        port_state = GPIO_PortRead(GPIO, SPEEDB);
        if (!(port_state & (1 << SPEEDP)))
        {
            PRINTF("\r\n Port state: %x\r\n", port_state);
            GPIO_PortToggle(GPIO, BOARD_INITPINS_SPEED_PORT, 1u << BOARD_INITPINS_SPEED_PIN);
        }
        delay();
    }
}
