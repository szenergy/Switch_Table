/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

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


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"
#include "../user.h"

/**
 Section: File specific functions
*/
void (*CN_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void){
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;
    LATF = 0x0000;
    LATG = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x1E13;
    TRISB = 0x1FFF;
    TRISC = 0x3EFF;
    TRISD = 0x0140;
    TRISE = 0xA000;
    TRISF = 0x0003;
    TRISG = 0x0380;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0100;
    CNPDB = 0x2010;
    CNPDC = 0x0020;
    CNPDD = 0x0000;
    CNPDE = 0x8000;
    CNPDF = 0x0000;
    CNPDG = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;
    CNPUD = 0x0000;
    CNPUE = 0x0000;
    CNPUF = 0x0000;
    CNPUG = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;
    ODCE = 0x0000;
    ODCF = 0x0000;
    ODCG = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x1C03;
    ANSELB = 0x0003;
    ANSELC = 0x0217;
    ANSELE = 0x2000;
    ANSELG = 0x0300;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPOR8bits.RP69R = 0x000E;    //RD5->ECAN1:C1TX
    RPINR26bits.C1RXR = 0x0046;    //RD6->ECAN1:C1RX

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
    
    /****************************************************************************
     * Interrupt On Change: any
     ***************************************************************************/
    CNENAbits.CNIEA8 = 1;    //Pin : RA8
    CNENAbits.CNIEA9 = 1;    //Pin : RA9
    CNENBbits.CNIEB4 = 1;    //Pin : RB4
    CNENBbits.CNIEB5 = 1;    //Pin : RB5
    CNENBbits.CNIEB6 = 1;    //Pin : RB6
    CNENBbits.CNIEB7 = 1;    //Pin : RB7
    CNENBbits.CNIEB8 = 1;    //Pin : RB8
    CNENBbits.CNIEB9 = 1;    //Pin : RB9
    CNENCbits.CNIEC10 = 1;    //Pin : RC10
    CNENCbits.CNIEC11 = 1;    //Pin : RC11
    CNENCbits.CNIEC13 = 1;    //Pin : RC13
    CNENCbits.CNIEC3 = 1;    //Pin : RC3
    CNENCbits.CNIEC5 = 1;    //Pin : RC5
    CNENCbits.CNIEC6 = 1;    //Pin : RC6
    CNENCbits.CNIEC7 = 1;    //Pin : RC7
    CNENDbits.CNIED8 = 1;    //Pin : RD8
    CNENEbits.CNIEE15 = 1;    //Pin : RE15
    CNENGbits.CNIEG7 = 1;    //Pin : RG7
    
    /* Initialize IOC Interrupt Handler*/
    CN_SetInterruptHandler(&CN_CallBack);
    
    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS1bits.CNIF = 0; //Clear CNI interrupt flag
    IEC1bits.CNIE = 1; //Enable CNI interrupt
}

void __attribute__ ((weak)) CN_CallBack(void){
    
    //debounce_timestamp = debounce_ms_counter;
//if(!VcuState_A.MC_OW && IO_MC_OW_GetValue()){
//        flags.mc_override_changed_to_1 = true;
//    }else if(VcuState_A.MC_OW && !IO_MC_OW_GetValue()){
//        flags.mc_override_changed_to_0 = true;
//    }
//    if(VcuState_A.LAP != IO_LAP_GetValue()){
//        flags.new_lap = true;
//        flags.first_lap_started = true;
//    }

//if(!VcuState_A.FN2 && IO_FN2_GetValue()){
//    if(!flags.fn2_on){
//        flags.fn2_on = true;
//        IO_LED1_SetHigh(); //uncomment after testing
//    }else{
//        flags.fn2_on = false;
//        IO_LED1_SetLow(); //uncomment after testing
//    }
//}
flags.port_status_update = true;
flags.debounce_protected_port_status_update = true;
debounce_ms_counter = 0;
}

void CN_SetInterruptHandler(void (* InterruptHandler)(void)){ 
    IEC1bits.CNIE = 0; //Disable CNI interrupt
    CN_InterruptHandler = InterruptHandler; 
    IEC1bits.CNIE = 1; //Enable CNI interrupt
}

void CN_SetIOCInterruptHandler(void *handler){ 
    CN_SetInterruptHandler(handler);
}

/* Interrupt service routine for the CNI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _CNInterrupt ( void ){
    if(IFS1bits.CNIF == 1)
    {
        if(CN_InterruptHandler) 
        { 
            CN_InterruptHandler(); 
        }
        
        // Clear the flag
        IFS1bits.CNIF = 0;
    }
}

