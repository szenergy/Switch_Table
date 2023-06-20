/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  dsPIC33EV256GM106
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    IO_PLACEHOLDER_SetHigh();
    </code>

*/
#define IO_PLACEHOLDER_SetHigh()          (_LATA4 = 1)
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    IO_PLACEHOLDER_SetLow();
    </code>

*/
#define IO_PLACEHOLDER_SetLow()           (_LATA4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA4, using LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    IO_PLACEHOLDER_Toggle();
    </code>

*/
#define IO_PLACEHOLDER_Toggle()           (_LATA4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = IO_PLACEHOLDER_GetValue();
    </code>

*/
#define IO_PLACEHOLDER_GetValue()         _RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    IO_PLACEHOLDER_SetDigitalInput();
    </code>

*/
#define IO_PLACEHOLDER_SetDigitalInput()  (_TRISA4 = 1)
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    IO_PLACEHOLDER_SetDigitalOutput();
    </code>

*/
#define IO_PLACEHOLDER_SetDigitalOutput() (_TRISA4 = 0)
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    IO_LED1_SetHigh();
    </code>

*/
#define IO_LED1_SetHigh()          (_LATA7 = 1)
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    IO_LED1_SetLow();
    </code>

*/
#define IO_LED1_SetLow()           (_LATA7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA7, using LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    IO_LED1_Toggle();
    </code>

*/
#define IO_LED1_Toggle()           (_LATA7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = IO_LED1_GetValue();
    </code>

*/
#define IO_LED1_GetValue()         _RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    IO_LED1_SetDigitalInput();
    </code>

*/
#define IO_LED1_SetDigitalInput()  (_TRISA7 = 1)
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    IO_LED1_SetDigitalOutput();
    </code>

*/
#define IO_LED1_SetDigitalOutput() (_TRISA7 = 0)
/**
  @Summary
    Sets the GPIO pin, RA8, high using LATA8.

  @Description
    Sets the GPIO pin, RA8, high using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 high (1)
    IO_RELAY_NC_SetHigh();
    </code>

*/
#define IO_RELAY_NC_SetHigh()          (_LATA8 = 1)
/**
  @Summary
    Sets the GPIO pin, RA8, low using LATA8.

  @Description
    Sets the GPIO pin, RA8, low using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 low (0)
    IO_RELAY_NC_SetLow();
    </code>

*/
#define IO_RELAY_NC_SetLow()           (_LATA8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA8, using LATA8.

  @Description
    Toggles the GPIO pin, RA8, using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA8
    IO_RELAY_NC_Toggle();
    </code>

*/
#define IO_RELAY_NC_Toggle()           (_LATA8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA8.

  @Description
    Reads the value of the GPIO pin, RA8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA8
    postValue = IO_RELAY_NC_GetValue();
    </code>

*/
#define IO_RELAY_NC_GetValue()         _RA8
/**
  @Summary
    Configures the GPIO pin, RA8, as an input.

  @Description
    Configures the GPIO pin, RA8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an input
    IO_RELAY_NC_SetDigitalInput();
    </code>

*/
#define IO_RELAY_NC_SetDigitalInput()  (_TRISA8 = 1)
/**
  @Summary
    Configures the GPIO pin, RA8, as an output.

  @Description
    Configures the GPIO pin, RA8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an output
    IO_RELAY_NC_SetDigitalOutput();
    </code>

*/
#define IO_RELAY_NC_SetDigitalOutput() (_TRISA8 = 0)
/**
  @Summary
    Sets the GPIO pin, RA9, high using LATA9.

  @Description
    Sets the GPIO pin, RA9, high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 high (1)
    IO_HAZARD_SetHigh();
    </code>

*/
#define IO_HAZARD_SetHigh()          (_LATA9 = 1)
/**
  @Summary
    Sets the GPIO pin, RA9, low using LATA9.

  @Description
    Sets the GPIO pin, RA9, low using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 low (0)
    IO_HAZARD_SetLow();
    </code>

*/
#define IO_HAZARD_SetLow()           (_LATA9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA9, using LATA9.

  @Description
    Toggles the GPIO pin, RA9, using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA9
    IO_HAZARD_Toggle();
    </code>

*/
#define IO_HAZARD_Toggle()           (_LATA9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA9.

  @Description
    Reads the value of the GPIO pin, RA9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA9
    postValue = IO_HAZARD_GetValue();
    </code>

*/
#define IO_HAZARD_GetValue()         _RA9
/**
  @Summary
    Configures the GPIO pin, RA9, as an input.

  @Description
    Configures the GPIO pin, RA9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an input
    IO_HAZARD_SetDigitalInput();
    </code>

*/
#define IO_HAZARD_SetDigitalInput()  (_TRISA9 = 1)
/**
  @Summary
    Configures the GPIO pin, RA9, as an output.

  @Description
    Configures the GPIO pin, RA9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an output
    IO_HAZARD_SetDigitalOutput();
    </code>

*/
#define IO_HAZARD_SetDigitalOutput() (_TRISA9 = 0)
/**
  @Summary
    Sets the GPIO pin, RB14, high using LATB14.

  @Description
    Sets the GPIO pin, RB14, high using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB14 high (1)
    IO_LED2_SetHigh();
    </code>

*/
#define IO_LED2_SetHigh()          (_LATB14 = 1)
/**
  @Summary
    Sets the GPIO pin, RB14, low using LATB14.

  @Description
    Sets the GPIO pin, RB14, low using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB14 low (0)
    IO_LED2_SetLow();
    </code>

*/
#define IO_LED2_SetLow()           (_LATB14 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB14, using LATB14.

  @Description
    Toggles the GPIO pin, RB14, using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB14
    IO_LED2_Toggle();
    </code>

*/
#define IO_LED2_Toggle()           (_LATB14 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB14.

  @Description
    Reads the value of the GPIO pin, RB14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB14
    postValue = IO_LED2_GetValue();
    </code>

*/
#define IO_LED2_GetValue()         _RB14
/**
  @Summary
    Configures the GPIO pin, RB14, as an input.

  @Description
    Configures the GPIO pin, RB14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB14 as an input
    IO_LED2_SetDigitalInput();
    </code>

*/
#define IO_LED2_SetDigitalInput()  (_TRISB14 = 1)
/**
  @Summary
    Configures the GPIO pin, RB14, as an output.

  @Description
    Configures the GPIO pin, RB14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB14 as an output
    IO_LED2_SetDigitalOutput();
    </code>

*/
#define IO_LED2_SetDigitalOutput() (_TRISB14 = 0)
/**
  @Summary
    Sets the GPIO pin, RB15, high using LATB15.

  @Description
    Sets the GPIO pin, RB15, high using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 high (1)
    IO_LED3_SetHigh();
    </code>

*/
#define IO_LED3_SetHigh()          (_LATB15 = 1)
/**
  @Summary
    Sets the GPIO pin, RB15, low using LATB15.

  @Description
    Sets the GPIO pin, RB15, low using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 low (0)
    IO_LED3_SetLow();
    </code>

*/
#define IO_LED3_SetLow()           (_LATB15 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB15, using LATB15.

  @Description
    Toggles the GPIO pin, RB15, using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB15
    IO_LED3_Toggle();
    </code>

*/
#define IO_LED3_Toggle()           (_LATB15 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB15.

  @Description
    Reads the value of the GPIO pin, RB15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB15
    postValue = IO_LED3_GetValue();
    </code>

*/
#define IO_LED3_GetValue()         _RB15
/**
  @Summary
    Configures the GPIO pin, RB15, as an input.

  @Description
    Configures the GPIO pin, RB15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an input
    IO_LED3_SetDigitalInput();
    </code>

*/
#define IO_LED3_SetDigitalInput()  (_TRISB15 = 1)
/**
  @Summary
    Configures the GPIO pin, RB15, as an output.

  @Description
    Configures the GPIO pin, RB15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an output
    IO_LED3_SetDigitalOutput();
    </code>

*/
#define IO_LED3_SetDigitalOutput() (_TRISB15 = 0)
/**
  @Summary
    Sets the GPIO pin, RB2, high using LATB2.

  @Description
    Sets the GPIO pin, RB2, high using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 high (1)
    IO_RB2_SetHigh();
    </code>

*/
#define IO_RB2_SetHigh()          (_LATB2 = 1)
/**
  @Summary
    Sets the GPIO pin, RB2, low using LATB2.

  @Description
    Sets the GPIO pin, RB2, low using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 low (0)
    IO_RB2_SetLow();
    </code>

*/
#define IO_RB2_SetLow()           (_LATB2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB2, using LATB2.

  @Description
    Toggles the GPIO pin, RB2, using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB2
    IO_RB2_Toggle();
    </code>

*/
#define IO_RB2_Toggle()           (_LATB2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB2.

  @Description
    Reads the value of the GPIO pin, RB2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB2
    postValue = IO_RB2_GetValue();
    </code>

*/
#define IO_RB2_GetValue()         _RB2
/**
  @Summary
    Configures the GPIO pin, RB2, as an input.

  @Description
    Configures the GPIO pin, RB2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an input
    IO_RB2_SetDigitalInput();
    </code>

*/
#define IO_RB2_SetDigitalInput()  (_TRISB2 = 1)
/**
  @Summary
    Configures the GPIO pin, RB2, as an output.

  @Description
    Configures the GPIO pin, RB2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an output
    IO_RB2_SetDigitalOutput();
    </code>

*/
#define IO_RB2_SetDigitalOutput() (_TRISB2 = 0)
/**
  @Summary
    Sets the GPIO pin, RB3, high using LATB3.

  @Description
    Sets the GPIO pin, RB3, high using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 high (1)
    IO_RB3_SetHigh();
    </code>

*/
#define IO_RB3_SetHigh()          (_LATB3 = 1)
/**
  @Summary
    Sets the GPIO pin, RB3, low using LATB3.

  @Description
    Sets the GPIO pin, RB3, low using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 low (0)
    IO_RB3_SetLow();
    </code>

*/
#define IO_RB3_SetLow()           (_LATB3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB3, using LATB3.

  @Description
    Toggles the GPIO pin, RB3, using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB3
    IO_RB3_Toggle();
    </code>

*/
#define IO_RB3_Toggle()           (_LATB3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB3.

  @Description
    Reads the value of the GPIO pin, RB3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB3
    postValue = IO_RB3_GetValue();
    </code>

*/
#define IO_RB3_GetValue()         _RB3
/**
  @Summary
    Configures the GPIO pin, RB3, as an input.

  @Description
    Configures the GPIO pin, RB3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an input
    IO_RB3_SetDigitalInput();
    </code>

*/
#define IO_RB3_SetDigitalInput()  (_TRISB3 = 1)
/**
  @Summary
    Configures the GPIO pin, RB3, as an output.

  @Description
    Configures the GPIO pin, RB3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an output
    IO_RB3_SetDigitalOutput();
    </code>

*/
#define IO_RB3_SetDigitalOutput() (_TRISB3 = 0)
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    IO_BRAKE_SetHigh();
    </code>

*/
#define IO_BRAKE_SetHigh()          (_LATB4 = 1)
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    IO_BRAKE_SetLow();
    </code>

*/
#define IO_BRAKE_SetLow()           (_LATB4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB4, using LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    IO_BRAKE_Toggle();
    </code>

*/
#define IO_BRAKE_Toggle()           (_LATB4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = IO_BRAKE_GetValue();
    </code>

*/
#define IO_BRAKE_GetValue()         _RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    IO_BRAKE_SetDigitalInput();
    </code>

*/
#define IO_BRAKE_SetDigitalInput()  (_TRISB4 = 1)
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    IO_BRAKE_SetDigitalOutput();
    </code>

*/
#define IO_BRAKE_SetDigitalOutput() (_TRISB4 = 0)
/**
  @Summary
    Sets the GPIO pin, RB5, high using LATB5.

  @Description
    Sets the GPIO pin, RB5, high using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 high (1)
    IO_ACC_SetHigh();
    </code>

*/
#define IO_ACC_SetHigh()          (_LATB5 = 1)
/**
  @Summary
    Sets the GPIO pin, RB5, low using LATB5.

  @Description
    Sets the GPIO pin, RB5, low using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 low (0)
    IO_ACC_SetLow();
    </code>

*/
#define IO_ACC_SetLow()           (_LATB5 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB5, using LATB5.

  @Description
    Toggles the GPIO pin, RB5, using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB5
    IO_ACC_Toggle();
    </code>

*/
#define IO_ACC_Toggle()           (_LATB5 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB5.

  @Description
    Reads the value of the GPIO pin, RB5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB5
    postValue = IO_ACC_GetValue();
    </code>

*/
#define IO_ACC_GetValue()         _RB5
/**
  @Summary
    Configures the GPIO pin, RB5, as an input.

  @Description
    Configures the GPIO pin, RB5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an input
    IO_ACC_SetDigitalInput();
    </code>

*/
#define IO_ACC_SetDigitalInput()  (_TRISB5 = 1)
/**
  @Summary
    Configures the GPIO pin, RB5, as an output.

  @Description
    Configures the GPIO pin, RB5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an output
    IO_ACC_SetDigitalOutput();
    </code>

*/
#define IO_ACC_SetDigitalOutput() (_TRISB5 = 0)
/**
  @Summary
    Sets the GPIO pin, RB6, high using LATB6.

  @Description
    Sets the GPIO pin, RB6, high using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB6 high (1)
    IO_DRIVE_SetHigh();
    </code>

*/
#define IO_DRIVE_SetHigh()          (_LATB6 = 1)
/**
  @Summary
    Sets the GPIO pin, RB6, low using LATB6.

  @Description
    Sets the GPIO pin, RB6, low using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB6 low (0)
    IO_DRIVE_SetLow();
    </code>

*/
#define IO_DRIVE_SetLow()           (_LATB6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB6, using LATB6.

  @Description
    Toggles the GPIO pin, RB6, using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB6
    IO_DRIVE_Toggle();
    </code>

*/
#define IO_DRIVE_Toggle()           (_LATB6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB6.

  @Description
    Reads the value of the GPIO pin, RB6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB6
    postValue = IO_DRIVE_GetValue();
    </code>

*/
#define IO_DRIVE_GetValue()         _RB6
/**
  @Summary
    Configures the GPIO pin, RB6, as an input.

  @Description
    Configures the GPIO pin, RB6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB6 as an input
    IO_DRIVE_SetDigitalInput();
    </code>

*/
#define IO_DRIVE_SetDigitalInput()  (_TRISB6 = 1)
/**
  @Summary
    Configures the GPIO pin, RB6, as an output.

  @Description
    Configures the GPIO pin, RB6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB6 as an output
    IO_DRIVE_SetDigitalOutput();
    </code>

*/
#define IO_DRIVE_SetDigitalOutput() (_TRISB6 = 0)
/**
  @Summary
    Sets the GPIO pin, RB7, high using LATB7.

  @Description
    Sets the GPIO pin, RB7, high using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 high (1)
    IO_TS_R_SetHigh();
    </code>

*/
#define IO_TS_R_SetHigh()          (_LATB7 = 1)
/**
  @Summary
    Sets the GPIO pin, RB7, low using LATB7.

  @Description
    Sets the GPIO pin, RB7, low using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 low (0)
    IO_TS_R_SetLow();
    </code>

*/
#define IO_TS_R_SetLow()           (_LATB7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB7, using LATB7.

  @Description
    Toggles the GPIO pin, RB7, using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB7
    IO_TS_R_Toggle();
    </code>

*/
#define IO_TS_R_Toggle()           (_LATB7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB7.

  @Description
    Reads the value of the GPIO pin, RB7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB7
    postValue = IO_TS_R_GetValue();
    </code>

*/
#define IO_TS_R_GetValue()         _RB7
/**
  @Summary
    Configures the GPIO pin, RB7, as an input.

  @Description
    Configures the GPIO pin, RB7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an input
    IO_TS_R_SetDigitalInput();
    </code>

*/
#define IO_TS_R_SetDigitalInput()  (_TRISB7 = 1)
/**
  @Summary
    Configures the GPIO pin, RB7, as an output.

  @Description
    Configures the GPIO pin, RB7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an output
    IO_TS_R_SetDigitalOutput();
    </code>

*/
#define IO_TS_R_SetDigitalOutput() (_TRISB7 = 0)
/**
  @Summary
    Sets the GPIO pin, RB8, high using LATB8.

  @Description
    Sets the GPIO pin, RB8, high using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 high (1)
    IO_SPEED_CONROL_SetHigh();
    </code>

*/
#define IO_SPEED_CONROL_SetHigh()          (_LATB8 = 1)
/**
  @Summary
    Sets the GPIO pin, RB8, low using LATB8.

  @Description
    Sets the GPIO pin, RB8, low using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 low (0)
    IO_SPEED_CONROL_SetLow();
    </code>

*/
#define IO_SPEED_CONROL_SetLow()           (_LATB8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB8, using LATB8.

  @Description
    Toggles the GPIO pin, RB8, using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB8
    IO_SPEED_CONROL_Toggle();
    </code>

*/
#define IO_SPEED_CONROL_Toggle()           (_LATB8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB8.

  @Description
    Reads the value of the GPIO pin, RB8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB8
    postValue = IO_SPEED_CONROL_GetValue();
    </code>

*/
#define IO_SPEED_CONROL_GetValue()         _RB8
/**
  @Summary
    Configures the GPIO pin, RB8, as an input.

  @Description
    Configures the GPIO pin, RB8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an input
    IO_SPEED_CONROL_SetDigitalInput();
    </code>

*/
#define IO_SPEED_CONROL_SetDigitalInput()  (_TRISB8 = 1)
/**
  @Summary
    Configures the GPIO pin, RB8, as an output.

  @Description
    Configures the GPIO pin, RB8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an output
    IO_SPEED_CONROL_SetDigitalOutput();
    </code>

*/
#define IO_SPEED_CONROL_SetDigitalOutput() (_TRISB8 = 0)
/**
  @Summary
    Sets the GPIO pin, RB9, high using LATB9.

  @Description
    Sets the GPIO pin, RB9, high using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 high (1)
    IO_FN2_SetHigh();
    </code>

*/
#define IO_FN2_SetHigh()          (_LATB9 = 1)
/**
  @Summary
    Sets the GPIO pin, RB9, low using LATB9.

  @Description
    Sets the GPIO pin, RB9, low using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 low (0)
    IO_FN2_SetLow();
    </code>

*/
#define IO_FN2_SetLow()           (_LATB9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB9, using LATB9.

  @Description
    Toggles the GPIO pin, RB9, using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB9
    IO_FN2_Toggle();
    </code>

*/
#define IO_FN2_Toggle()           (_LATB9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB9.

  @Description
    Reads the value of the GPIO pin, RB9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB9
    postValue = IO_FN2_GetValue();
    </code>

*/
#define IO_FN2_GetValue()         _RB9
/**
  @Summary
    Configures the GPIO pin, RB9, as an input.

  @Description
    Configures the GPIO pin, RB9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an input
    IO_FN2_SetDigitalInput();
    </code>

*/
#define IO_FN2_SetDigitalInput()  (_TRISB9 = 1)
/**
  @Summary
    Configures the GPIO pin, RB9, as an output.

  @Description
    Configures the GPIO pin, RB9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an output
    IO_FN2_SetDigitalOutput();
    </code>

*/
#define IO_FN2_SetDigitalOutput() (_TRISB9 = 0)
/**
  @Summary
    Sets the GPIO pin, RC10, high using LATC10.

  @Description
    Sets the GPIO pin, RC10, high using LATC10.

  @Preconditions
    The RC10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC10 high (1)
    IO_TS_L_SetHigh();
    </code>

*/
#define IO_TS_L_SetHigh()          (_LATC10 = 1)
/**
  @Summary
    Sets the GPIO pin, RC10, low using LATC10.

  @Description
    Sets the GPIO pin, RC10, low using LATC10.

  @Preconditions
    The RC10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC10 low (0)
    IO_TS_L_SetLow();
    </code>

*/
#define IO_TS_L_SetLow()           (_LATC10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC10, using LATC10.

  @Description
    Toggles the GPIO pin, RC10, using LATC10.

  @Preconditions
    The RC10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC10
    IO_TS_L_Toggle();
    </code>

*/
#define IO_TS_L_Toggle()           (_LATC10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC10.

  @Description
    Reads the value of the GPIO pin, RC10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC10
    postValue = IO_TS_L_GetValue();
    </code>

*/
#define IO_TS_L_GetValue()         _RC10
/**
  @Summary
    Configures the GPIO pin, RC10, as an input.

  @Description
    Configures the GPIO pin, RC10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC10 as an input
    IO_TS_L_SetDigitalInput();
    </code>

*/
#define IO_TS_L_SetDigitalInput()  (_TRISC10 = 1)
/**
  @Summary
    Configures the GPIO pin, RC10, as an output.

  @Description
    Configures the GPIO pin, RC10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC10 as an output
    IO_TS_L_SetDigitalOutput();
    </code>

*/
#define IO_TS_L_SetDigitalOutput() (_TRISC10 = 0)
/**
  @Summary
    Sets the GPIO pin, RC13, high using LATC13.

  @Description
    Sets the GPIO pin, RC13, high using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 high (1)
    IO_LAP_SetHigh();
    </code>

*/
#define IO_LAP_SetHigh()          (_LATC13 = 1)
/**
  @Summary
    Sets the GPIO pin, RC13, low using LATC13.

  @Description
    Sets the GPIO pin, RC13, low using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 low (0)
    IO_LAP_SetLow();
    </code>

*/
#define IO_LAP_SetLow()           (_LATC13 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC13, using LATC13.

  @Description
    Toggles the GPIO pin, RC13, using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC13
    IO_LAP_Toggle();
    </code>

*/
#define IO_LAP_Toggle()           (_LATC13 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC13.

  @Description
    Reads the value of the GPIO pin, RC13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC13
    postValue = IO_LAP_GetValue();
    </code>

*/
#define IO_LAP_GetValue()         _RC13
/**
  @Summary
    Configures the GPIO pin, RC13, as an input.

  @Description
    Configures the GPIO pin, RC13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an input
    IO_LAP_SetDigitalInput();
    </code>

*/
#define IO_LAP_SetDigitalInput()  (_TRISC13 = 1)
/**
  @Summary
    Configures the GPIO pin, RC13, as an output.

  @Description
    Configures the GPIO pin, RC13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an output
    IO_LAP_SetDigitalOutput();
    </code>

*/
#define IO_LAP_SetDigitalOutput() (_TRISC13 = 0)
/**
  @Summary
    Sets the GPIO pin, RC3, high using LATC3.

  @Description
    Sets the GPIO pin, RC3, high using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 high (1)
    IO_LIGHTS_SetHigh();
    </code>

*/
#define IO_LIGHTS_SetHigh()          (_LATC3 = 1)
/**
  @Summary
    Sets the GPIO pin, RC3, low using LATC3.

  @Description
    Sets the GPIO pin, RC3, low using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 low (0)
    IO_LIGHTS_SetLow();
    </code>

*/
#define IO_LIGHTS_SetLow()           (_LATC3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC3, using LATC3.

  @Description
    Toggles the GPIO pin, RC3, using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC3
    IO_LIGHTS_Toggle();
    </code>

*/
#define IO_LIGHTS_Toggle()           (_LATC3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC3.

  @Description
    Reads the value of the GPIO pin, RC3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC3
    postValue = IO_LIGHTS_GetValue();
    </code>

*/
#define IO_LIGHTS_GetValue()         _RC3
/**
  @Summary
    Configures the GPIO pin, RC3, as an input.

  @Description
    Configures the GPIO pin, RC3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an input
    IO_LIGHTS_SetDigitalInput();
    </code>

*/
#define IO_LIGHTS_SetDigitalInput()  (_TRISC3 = 1)
/**
  @Summary
    Configures the GPIO pin, RC3, as an output.

  @Description
    Configures the GPIO pin, RC3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an output
    IO_LIGHTS_SetDigitalOutput();
    </code>

*/
#define IO_LIGHTS_SetDigitalOutput() (_TRISC3 = 0)
/**
  @Summary
    Sets the GPIO pin, RC4, high using LATC4.

  @Description
    Sets the GPIO pin, RC4, high using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC4 high (1)
    POT_FOOT_SetHigh();
    </code>

*/
#define POT_FOOT_SetHigh()          (_LATC4 = 1)
/**
  @Summary
    Sets the GPIO pin, RC4, low using LATC4.

  @Description
    Sets the GPIO pin, RC4, low using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC4 low (0)
    POT_FOOT_SetLow();
    </code>

*/
#define POT_FOOT_SetLow()           (_LATC4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC4, using LATC4.

  @Description
    Toggles the GPIO pin, RC4, using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC4
    POT_FOOT_Toggle();
    </code>

*/
#define POT_FOOT_Toggle()           (_LATC4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC4.

  @Description
    Reads the value of the GPIO pin, RC4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC4
    postValue = POT_FOOT_GetValue();
    </code>

*/
#define POT_FOOT_GetValue()         _RC4
/**
  @Summary
    Configures the GPIO pin, RC4, as an input.

  @Description
    Configures the GPIO pin, RC4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC4 as an input
    POT_FOOT_SetDigitalInput();
    </code>

*/
#define POT_FOOT_SetDigitalInput()  (_TRISC4 = 1)
/**
  @Summary
    Configures the GPIO pin, RC4, as an output.

  @Description
    Configures the GPIO pin, RC4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC4 as an output
    POT_FOOT_SetDigitalOutput();
    </code>

*/
#define POT_FOOT_SetDigitalOutput() (_TRISC4 = 0)
/**
  @Summary
    Sets the GPIO pin, RC5, high using LATC5.

  @Description
    Sets the GPIO pin, RC5, high using LATC5.

  @Preconditions
    The RC5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC5 high (1)
    IO_AUT_SetHigh();
    </code>

*/
#define IO_AUT_SetHigh()          (_LATC5 = 1)
/**
  @Summary
    Sets the GPIO pin, RC5, low using LATC5.

  @Description
    Sets the GPIO pin, RC5, low using LATC5.

  @Preconditions
    The RC5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC5 low (0)
    IO_AUT_SetLow();
    </code>

*/
#define IO_AUT_SetLow()           (_LATC5 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC5, using LATC5.

  @Description
    Toggles the GPIO pin, RC5, using LATC5.

  @Preconditions
    The RC5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC5
    IO_AUT_Toggle();
    </code>

*/
#define IO_AUT_Toggle()           (_LATC5 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC5.

  @Description
    Reads the value of the GPIO pin, RC5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC5
    postValue = IO_AUT_GetValue();
    </code>

*/
#define IO_AUT_GetValue()         _RC5
/**
  @Summary
    Configures the GPIO pin, RC5, as an input.

  @Description
    Configures the GPIO pin, RC5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC5 as an input
    IO_AUT_SetDigitalInput();
    </code>

*/
#define IO_AUT_SetDigitalInput()  (_TRISC5 = 1)
/**
  @Summary
    Configures the GPIO pin, RC5, as an output.

  @Description
    Configures the GPIO pin, RC5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC5 as an output
    IO_AUT_SetDigitalOutput();
    </code>

*/
#define IO_AUT_SetDigitalOutput() (_TRISC5 = 0)
/**
  @Summary
    Sets the GPIO pin, RC6, high using LATC6.

  @Description
    Sets the GPIO pin, RC6, high using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC6 high (1)
    IO_MC_OW_SetHigh();
    </code>

*/
#define IO_MC_OW_SetHigh()          (_LATC6 = 1)
/**
  @Summary
    Sets the GPIO pin, RC6, low using LATC6.

  @Description
    Sets the GPIO pin, RC6, low using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC6 low (0)
    IO_MC_OW_SetLow();
    </code>

*/
#define IO_MC_OW_SetLow()           (_LATC6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC6, using LATC6.

  @Description
    Toggles the GPIO pin, RC6, using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC6
    IO_MC_OW_Toggle();
    </code>

*/
#define IO_MC_OW_Toggle()           (_LATC6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC6.

  @Description
    Reads the value of the GPIO pin, RC6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC6
    postValue = IO_MC_OW_GetValue();
    </code>

*/
#define IO_MC_OW_GetValue()         _RC6
/**
  @Summary
    Configures the GPIO pin, RC6, as an input.

  @Description
    Configures the GPIO pin, RC6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC6 as an input
    IO_MC_OW_SetDigitalInput();
    </code>

*/
#define IO_MC_OW_SetDigitalInput()  (_TRISC6 = 1)
/**
  @Summary
    Configures the GPIO pin, RC6, as an output.

  @Description
    Configures the GPIO pin, RC6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC6 as an output
    IO_MC_OW_SetDigitalOutput();
    </code>

*/
#define IO_MC_OW_SetDigitalOutput() (_TRISC6 = 0)
/**
  @Summary
    Sets the GPIO pin, RC7, high using LATC7.

  @Description
    Sets the GPIO pin, RC7, high using LATC7.

  @Preconditions
    The RC7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC7 high (1)
    IO_DC_ENABLE_SetHigh();
    </code>

*/
#define IO_DC_ENABLE_SetHigh()          (_LATC7 = 1)
/**
  @Summary
    Sets the GPIO pin, RC7, low using LATC7.

  @Description
    Sets the GPIO pin, RC7, low using LATC7.

  @Preconditions
    The RC7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC7 low (0)
    IO_DC_ENABLE_SetLow();
    </code>

*/
#define IO_DC_ENABLE_SetLow()           (_LATC7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC7, using LATC7.

  @Description
    Toggles the GPIO pin, RC7, using LATC7.

  @Preconditions
    The RC7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC7
    IO_DC_ENABLE_Toggle();
    </code>

*/
#define IO_DC_ENABLE_Toggle()           (_LATC7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC7.

  @Description
    Reads the value of the GPIO pin, RC7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC7
    postValue = IO_DC_ENABLE_GetValue();
    </code>

*/
#define IO_DC_ENABLE_GetValue()         _RC7
/**
  @Summary
    Configures the GPIO pin, RC7, as an input.

  @Description
    Configures the GPIO pin, RC7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC7 as an input
    IO_DC_ENABLE_SetDigitalInput();
    </code>

*/
#define IO_DC_ENABLE_SetDigitalInput()  (_TRISC7 = 1)
/**
  @Summary
    Configures the GPIO pin, RC7, as an output.

  @Description
    Configures the GPIO pin, RC7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC7 as an output
    IO_DC_ENABLE_SetDigitalOutput();
    </code>

*/
#define IO_DC_ENABLE_SetDigitalOutput() (_TRISC7 = 0)
/**
  @Summary
    Sets the GPIO pin, RC8, high using LATC8.

  @Description
    Sets the GPIO pin, RC8, high using LATC8.

  @Preconditions
    The RC8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC8 high (1)
    IO_BUZZ_SetHigh();
    </code>

*/
#define IO_BUZZ_SetHigh()          (_LATC8 = 1)
/**
  @Summary
    Sets the GPIO pin, RC8, low using LATC8.

  @Description
    Sets the GPIO pin, RC8, low using LATC8.

  @Preconditions
    The RC8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC8 low (0)
    IO_BUZZ_SetLow();
    </code>

*/
#define IO_BUZZ_SetLow()           (_LATC8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC8, using LATC8.

  @Description
    Toggles the GPIO pin, RC8, using LATC8.

  @Preconditions
    The RC8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC8
    IO_BUZZ_Toggle();
    </code>

*/
#define IO_BUZZ_Toggle()           (_LATC8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC8.

  @Description
    Reads the value of the GPIO pin, RC8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC8
    postValue = IO_BUZZ_GetValue();
    </code>

*/
#define IO_BUZZ_GetValue()         _RC8
/**
  @Summary
    Configures the GPIO pin, RC8, as an input.

  @Description
    Configures the GPIO pin, RC8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC8 as an input
    IO_BUZZ_SetDigitalInput();
    </code>

*/
#define IO_BUZZ_SetDigitalInput()  (_TRISC8 = 1)
/**
  @Summary
    Configures the GPIO pin, RC8, as an output.

  @Description
    Configures the GPIO pin, RC8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC8 as an output
    IO_BUZZ_SetDigitalOutput();
    </code>

*/
#define IO_BUZZ_SetDigitalOutput() (_TRISC8 = 0)
/**
  @Summary
    Sets the GPIO pin, RD8, high using LATD8.

  @Description
    Sets the GPIO pin, RD8, high using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 high (1)
    IO_REVERSE_SetHigh();
    </code>

*/
#define IO_REVERSE_SetHigh()          (_LATD8 = 1)
/**
  @Summary
    Sets the GPIO pin, RD8, low using LATD8.

  @Description
    Sets the GPIO pin, RD8, low using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 low (0)
    IO_REVERSE_SetLow();
    </code>

*/
#define IO_REVERSE_SetLow()           (_LATD8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD8, using LATD8.

  @Description
    Toggles the GPIO pin, RD8, using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD8
    IO_REVERSE_Toggle();
    </code>

*/
#define IO_REVERSE_Toggle()           (_LATD8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD8.

  @Description
    Reads the value of the GPIO pin, RD8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD8
    postValue = IO_REVERSE_GetValue();
    </code>

*/
#define IO_REVERSE_GetValue()         _RD8
/**
  @Summary
    Configures the GPIO pin, RD8, as an input.

  @Description
    Configures the GPIO pin, RD8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an input
    IO_REVERSE_SetDigitalInput();
    </code>

*/
#define IO_REVERSE_SetDigitalInput()  (_TRISD8 = 1)
/**
  @Summary
    Configures the GPIO pin, RD8, as an output.

  @Description
    Configures the GPIO pin, RD8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an output
    IO_REVERSE_SetDigitalOutput();
    </code>

*/
#define IO_REVERSE_SetDigitalOutput() (_TRISD8 = 0)
/**
  @Summary
    Sets the GPIO pin, RE14, high using LATE14.

  @Description
    Sets the GPIO pin, RE14, high using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE14 high (1)
    IO_AUT_LIGHT_SetHigh();
    </code>

*/
#define IO_AUT_LIGHT_SetHigh()          (_LATE14 = 1)
/**
  @Summary
    Sets the GPIO pin, RE14, low using LATE14.

  @Description
    Sets the GPIO pin, RE14, low using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE14 low (0)
    IO_AUT_LIGHT_SetLow();
    </code>

*/
#define IO_AUT_LIGHT_SetLow()           (_LATE14 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE14, using LATE14.

  @Description
    Toggles the GPIO pin, RE14, using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE14
    IO_AUT_LIGHT_Toggle();
    </code>

*/
#define IO_AUT_LIGHT_Toggle()           (_LATE14 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE14.

  @Description
    Reads the value of the GPIO pin, RE14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE14
    postValue = IO_AUT_LIGHT_GetValue();
    </code>

*/
#define IO_AUT_LIGHT_GetValue()         _RE14
/**
  @Summary
    Configures the GPIO pin, RE14, as an input.

  @Description
    Configures the GPIO pin, RE14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE14 as an input
    IO_AUT_LIGHT_SetDigitalInput();
    </code>

*/
#define IO_AUT_LIGHT_SetDigitalInput()  (_TRISE14 = 1)
/**
  @Summary
    Configures the GPIO pin, RE14, as an output.

  @Description
    Configures the GPIO pin, RE14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE14 as an output
    IO_AUT_LIGHT_SetDigitalOutput();
    </code>

*/
#define IO_AUT_LIGHT_SetDigitalOutput() (_TRISE14 = 0)
/**
  @Summary
    Sets the GPIO pin, RE15, high using LATE15.

  @Description
    Sets the GPIO pin, RE15, high using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 high (1)
    IO_RELAY_NO_SetHigh();
    </code>

*/
#define IO_RELAY_NO_SetHigh()          (_LATE15 = 1)
/**
  @Summary
    Sets the GPIO pin, RE15, low using LATE15.

  @Description
    Sets the GPIO pin, RE15, low using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 low (0)
    IO_RELAY_NO_SetLow();
    </code>

*/
#define IO_RELAY_NO_SetLow()           (_LATE15 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE15, using LATE15.

  @Description
    Toggles the GPIO pin, RE15, using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE15
    IO_RELAY_NO_Toggle();
    </code>

*/
#define IO_RELAY_NO_Toggle()           (_LATE15 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE15.

  @Description
    Reads the value of the GPIO pin, RE15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE15
    postValue = IO_RELAY_NO_GetValue();
    </code>

*/
#define IO_RELAY_NO_GetValue()         _RE15
/**
  @Summary
    Configures the GPIO pin, RE15, as an input.

  @Description
    Configures the GPIO pin, RE15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an input
    IO_RELAY_NO_SetDigitalInput();
    </code>

*/
#define IO_RELAY_NO_SetDigitalInput()  (_TRISE15 = 1)
/**
  @Summary
    Configures the GPIO pin, RE15, as an output.

  @Description
    Configures the GPIO pin, RE15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an output
    IO_RELAY_NO_SetDigitalOutput();
    </code>

*/
#define IO_RELAY_NO_SetDigitalOutput() (_TRISE15 = 0)
/**
  @Summary
    Sets the GPIO pin, RG6, high using LATG6.

  @Description
    Sets the GPIO pin, RG6, high using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG6 high (1)
    IO_LED4_SetHigh();
    </code>

*/
#define IO_LED4_SetHigh()          (_LATG6 = 1)
/**
  @Summary
    Sets the GPIO pin, RG6, low using LATG6.

  @Description
    Sets the GPIO pin, RG6, low using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG6 low (0)
    IO_LED4_SetLow();
    </code>

*/
#define IO_LED4_SetLow()           (_LATG6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG6, using LATG6.

  @Description
    Toggles the GPIO pin, RG6, using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG6
    IO_LED4_Toggle();
    </code>

*/
#define IO_LED4_Toggle()           (_LATG6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG6.

  @Description
    Reads the value of the GPIO pin, RG6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG6
    postValue = IO_LED4_GetValue();
    </code>

*/
#define IO_LED4_GetValue()         _RG6
/**
  @Summary
    Configures the GPIO pin, RG6, as an input.

  @Description
    Configures the GPIO pin, RG6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG6 as an input
    IO_LED4_SetDigitalInput();
    </code>

*/
#define IO_LED4_SetDigitalInput()  (_TRISG6 = 1)
/**
  @Summary
    Configures the GPIO pin, RG6, as an output.

  @Description
    Configures the GPIO pin, RG6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG6 as an output
    IO_LED4_SetDigitalOutput();
    </code>

*/
#define IO_LED4_SetDigitalOutput() (_TRISG6 = 0)
/**
  @Summary
    Sets the GPIO pin, RG7, high using LATG7.

  @Description
    Sets the GPIO pin, RG7, high using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 high (1)
    IO_PGOOD_SetHigh();
    </code>

*/
#define IO_PGOOD_SetHigh()          (_LATG7 = 1)
/**
  @Summary
    Sets the GPIO pin, RG7, low using LATG7.

  @Description
    Sets the GPIO pin, RG7, low using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 low (0)
    IO_PGOOD_SetLow();
    </code>

*/
#define IO_PGOOD_SetLow()           (_LATG7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG7, using LATG7.

  @Description
    Toggles the GPIO pin, RG7, using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG7
    IO_PGOOD_Toggle();
    </code>

*/
#define IO_PGOOD_Toggle()           (_LATG7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG7.

  @Description
    Reads the value of the GPIO pin, RG7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG7
    postValue = IO_PGOOD_GetValue();
    </code>

*/
#define IO_PGOOD_GetValue()         _RG7
/**
  @Summary
    Configures the GPIO pin, RG7, as an input.

  @Description
    Configures the GPIO pin, RG7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an input
    IO_PGOOD_SetDigitalInput();
    </code>

*/
#define IO_PGOOD_SetDigitalInput()  (_TRISG7 = 1)
/**
  @Summary
    Configures the GPIO pin, RG7, as an output.

  @Description
    Configures the GPIO pin, RG7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an output
    IO_PGOOD_SetDigitalOutput();
    </code>

*/
#define IO_PGOOD_SetDigitalOutput() (_TRISG7 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33EV256GM106
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

/**
  @Summary
    Callback for IOC Pins.

  @Description
    This routine is callback for IOC Pins.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetInterruptHandler(&CN_CallBack);
    </code>
*/
void CN_CallBack(void);

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetInterruptHandler(&CN_CallBack);
    </code>
*/
void CN_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetIOCInterruptHandler(&CN_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse CN_SetInterruptHandler instead."))) CN_SetIOCInterruptHandler(void *handler);

#endif
