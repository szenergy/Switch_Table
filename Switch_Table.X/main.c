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
 * Measured current consumption @48VDC - 5,8 mA
 * Calculated power = 0,2784 W
 * 
 * Not-used modules OFF:
 * @48VDC - 5,4 mA
 * Calculated power = 0,2592 W
 * 
 * CLK reduced to 40MHz:
 * @48VDC - 4,2 mA
 * Calculated power = 0,2016 W
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
    flags.pgood = IO_PGOOD_GetValue();
//    uint32_t cnt2 = 0;
    
//    IO_DRIVE_SetDigitalInput();
//    IO_LED1_SetHigh();
//    IO_LED2_SetHigh();
//    IO_LED3_SetHigh();
//    IO_LED4_SetHigh();
//    IO_BUZZ_SetHigh();
    while (1){
        ClrWdt();
        if(flags.can_process_rec_msg == true){
            CanMessageCheck();
            flags.can_process_rec_msg = false;
        }
        
        if(flags.mc_command_update_and_send == true && VcuState_B.AUT == false){
            if(!VcuState_A.MC_OW){
                PotConversion();
                StateMachineUpdate();
                if(current_state != Neutral){
                    if(current_state == Automatic_Acc || current_state == Automatic_Dec){
//                        CalculateMCRef();
                        conversion.ADC_Word = 1023;
                    }
                    RateLimiter();
//                    McCommandUpdate();
                    CanMcCommand();
                }
            }else{
               PotConversion();
//               McCommandUpdate();
               CanMcCommand();
            }
            flags.mc_command_update_and_send = false;
        }
        
        if(flags.can_vcu_state == true){
//            while((C1TR01CONbits.TXREQ0 == 1) | (C1TR01CONbits.TXABT0 == 1));
            CanVcuState();
            flags.can_vcu_state = false;
        }
       
        if(flags.port_status_update == true){
            PortStatusUpdate();
            flags.port_status_update = false;
        }
       
        if(flags.debounce_protected_port_status_update == true && (debounce_ms_counter >= DEBOUNCE_TIME_MS)){
            DebounceProtectedPortStatusUpdate();
            flags.debounce_protected_port_status_update = false;
        }

        if(CAN1_IsRXErrorPassive() || CAN1_IsTXErrorPassive()){
            IO_LED2_SetHigh(); //uncomment after testing
        }else{
            IO_LED2_SetLow(); //uncomment after testing
        }

        GoToSleep();
        ReturnFromSleep();
    }
}
// END - Main application

/**
 End of File
*/