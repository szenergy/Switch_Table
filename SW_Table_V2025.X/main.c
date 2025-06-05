 /* File:   main.c
 * Author: SZEnergy_Electro
 *
 * Function description for the control module:
 * CAN message (@50Hz-->20ms timer) as VCU State ( ID = x129 ) about the following informations:
 * Switch signal processing for:
 *      Reverse Direction for MC
 *      Hazard signal
 *      DC_Enable
 *      Lights
 *      Brake
 *      MC Command overwrite
 *      AUTONOM Enable to myRio (inverted signal, as GND should mean ON)
 *      
 * Signal processing for:
 *      
 *      Shell relay - differential sign!
 *      FF_1        - Option for Future Functions
 *      
 * 12bit ADC for:
 *      Analog potmeter - foot
 * 
 * Measured current consumption @48VDC - 4,9 mA
 * Calculated power = 0,2352 W
 * 
 * Added Sleeping - Level: Idle
 * Measured current consumption @48VDC - 2,3 mA
 * Calculated power = 0,1104 W
 *
 *  DOZE = the bandgap and system oscillators continue to operate, 
 *  while only the CPU and PFM are affected.
 *  the CPU executes only one instruction cycle out of every N cycles as 
 *  NO Idle, but DOZE 
 *  Measured current consumption @48VDC - 2,7 mA
 *  Calculated power = 0,1296 W
 * 
 * Created on 2020. april 14., 10:40
 * Created by Peter Gulyas
 */

#include "mcc_generated_files/system.h"
#include "user.h"
#include "mcc_generated_files/tmr1.h"

// Main application
int main(void){
    // Initialize the device
    SYSTEM_Initialize();
    // Start CAN communication
    CAN1_TransmitEnable();
    CAN1_ReceiveEnable();
    CAN1_OperationModeSet(CAN_CONFIGURATION_MODE);
    // Initialize all Status related variables
    VariableInit();
    // Start Timer -> Start all interrupt based Status update and communication functions
    TMR1_Start();
//    uint32_t cnt2 = 0;
    
#ifdef DEBUG_IO
    IO_DRIVE_SetDigitalInput();
    IO_LED1_SetHigh();
    IO_LED2_SetHigh();
    IO_LED3_SetHigh();
    IO_LED4_SetHigh();
    IO_BUZZ_SetHigh();
#else
#endif  
    
    while (1){
        ClrWdt();
//        CLKDIVbits.ROI = 0;      // Interrupts not removing the CPU from DOZE mode
            
#ifdef DEBUG_SERVO
        if(VcuState_A.WIPER == 1){
            PTCON = 0x8000;
            IO_WIPER_CONV_EN_SetHigh();
            PDC2 = WIPER_LIMIT_RIGHT;
        }
        
        if(VcuState_A.WIPER == 0){
            IO_WIPER_CONV_EN_SetLow();
            PTCON = 0x0000;
        }
        
#else
        if(flags.wiper_on || VcuState_A.WIPER == 1){
            PMD1bits.PWMMD = 0;
            PWM_Initialize();
            PDC2 = WIPER_LIMIT_RIGHT;            
            WiperActions();         
        }else{            
            PMD1bits.PWMMD = 1;
        }
#endif
        
        if(flags.can_process_rec_msg == true){
            CanMessageCheck();
            flags.can_process_rec_msg = false;
        }
        if(flags.mc_command_update_and_send == true && VcuState_A.AUT == false){
            if(!VcuState_A.MC_OW){
                PotConversion();
                StateMachineUpdate();
                if(current_state != Neutral){
                    if(current_state == Automatic_Acc || current_state == Automatic_Dec){
                        CalculateSpeed();
                        CalculateMCRef();
//                        conversion.ADC_Word = 1023;
                    }
                    RateLimiter();
//                    McCommandUpdate();
                    CanMcCommand();
                }
            }else{
               PotConversion();
//               McCommandUpdate();
               //CanMcCommand();
            }
            flags.mc_command_update_and_send = false;
        }else{
           // PotConversion();
            
        }
        
        if(flags.can_vcu_state == true){
//            while((C1TR01CONbits.TXREQ0 == 1) | (C1TR01CONbits.TXABT0 == 1));
            CanVcuState();
//            CanMcCommand();
            flags.can_vcu_state = false;
        }
       
        if(flags.port_status_update == true){
            PortStatusUpdate();
            flags.port_status_update = false;
        }
       

        if(CAN1_IsRXErrorPassive() || CAN1_IsTXErrorPassive()){
            //IO_LED2_SetHigh(); //uncomment after testing
        }else{
            //IO_LED2_SetLow(); //uncomment after testing
        }

        GoToSleep();
        ReturnFromSleep();
    }
}
// END - Main application

/**
 End of File
*/