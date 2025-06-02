/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
// Configuration defines
#define M_PI                               3.14159265358979323846
#define EMA_A                       (float)0.4 //analog láb gaz_pot 
#define ZERO_REF                    (uint16_t)2600
#define MAX_REF                     (uint16_t)2825
#define STEP                        (uint16_t)(MAX_REF-ZERO_REF)/20
#define RATE_LIMIT_UP               (uint16_t)51 //motor reference limit per 50ms
#define RATE_LIMIT_DOWN             (uint16_t)500
#define DEBOUNCE_TIME_MS            (uint8_t)2
#define WIPER_PERIOD                (uint16_t)1000 //time in ms
#define WIPER_STEP                  (uint16_t)(WIPER_PERIOD/101)   //servo 1 step time
#define SPEED_MULT_FACTOR           (double)(M_PI*0.5586*3.6)/60

//#define DEBUG_IO

//#define DEBUG_SERVO
//PWM input clock: 40MHz / 16 = 2.500.000
//PWM period = 50.000 = 20ms
#define SERVO_MIN                   (uint16_t)5000  // = 1ms
#define SERVO_MAX                   (uint16_t)10000 // = 2ms
#define SERVO_CENTER                (uint16_t)7500  // = 1.5ms
// +/-10° =  1800?
//#define WIPER_LIMIT_RIGHT           (uint16_t)11600     //11800 old wiper control
//#define WIPER_LIMIT_LEFT            (uint16_t)16000     //16000 
#define WIPER_WINDSCREEN_CENTER     (uint16_t)12100     //15800


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

