#ifndef USER_H
#define	USER_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdbool.h>
#include "user_defines.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/can1.h"
#include "mcc_generated_files/can_types.h"
#include "mcc_generated_files/pin_manager.h"
//#include "mcc_generated_files/tmr2.h"

// ******************************
// User structures
// ******************************

typedef union  __attribute__(())
{
    uint8_t VCUBits_1;
    struct
    {
        uint8_t ACC             :1;
        uint8_t DRIVE           :1;
        uint8_t REVERSE         :1;
        uint8_t LAP             :1;
        uint8_t DC_ENABLE       :1;
        uint8_t MC_OW           :1;
        uint8_t FN1             :1;
        uint8_t FN2             :1;   
    };
}VCU_STATE_A;

typedef union __attribute__(()) 
{
    uint8_t VCUBits_2;
    struct
    {
        uint8_t TS_L            :1;
        uint8_t TS_R            :1;
        uint8_t LIGHTS          :1;
        uint8_t HAZARD          :1;
        uint8_t AUT             :1;
        uint8_t BRAKE           :1;
        uint8_t RELAY_NO        :1;
        uint8_t RELAY_NC        :1;
    };
}VCU_STATE_B;

typedef union __attribute__(()) 
{
    uint8_t MCBits_1;
    struct
    {
        uint8_t NONE_0          :1;
        uint8_t RPM_FACTOR      :1;
        uint8_t MODE            :1;
        uint8_t NONE_2          :1;
        uint8_t NONE_3          :1;
        uint8_t BOOST           :1;
        uint8_t DIRECTION       :1;
        uint8_t DRIVE           :1;
    };
}MC_STATE_1;



typedef union __attribute__(()) 
{
    uint8_t MCBits_2;
    struct
    {
        uint8_t ZERO   :8;
    };
}MC_STATE_2;

typedef union __attribute__(()) 
{
    uint16_t MC_Ref_Word;
    struct
    {
        uint8_t LowByte     :8;
        uint8_t HighByte    :8;
    };
}MC_Bytes;

typedef union __attribute__(()) 
{
    uint16_t ADC_Word;
    struct
    {
        uint8_t LowByte     :8;
        uint8_t HighByte    :8;
    };
}ADC_Bytes;

typedef union __attribute__(()) 
{
    uint16_t Word;
    struct
    {
        uint8_t LowByte     :8;
        uint8_t HighByte    :8;
    };
}CAN_Bytes;


struct FLAGS{
    bool port_status_update;
    bool debounce_protected_port_status_update;
    bool can_process_rec_msg;
    bool can_vcu_state;
    bool mc_command_update_and_send;
    bool pgood;
    bool can_synced;
    bool mc_override_changed_to_1;
    bool mc_override_changed_to_0;
};

enum StateMachine {Neutral, Drive_Pedal, Reverse_Pedal, Automatic_Acc, Automatic_Dec};

// ******************************
// User exported global variables
// ******************************

extern volatile VCU_STATE_A VcuState_A;
extern volatile VCU_STATE_B VcuState_B;

extern volatile struct FLAGS flags;
//extern volatile struct VEHICLE vehicle;

extern volatile enum StateMachine current_state;
extern volatile enum StateMachine prev_state;

extern volatile CAN_MSG_OBJ testmsg;
extern volatile CAN_MSG_OBJ testMCmsg;
extern volatile CAN_MSG_OBJ VCUmsg;
extern volatile CAN_MSG_OBJ MCmsg;

extern volatile uint8_t data_test[8];
extern volatile uint8_t data_mc[4];
extern volatile uint8_t data_vcu_state[4];

//extern volatile float DISTANCE_STEP;
extern volatile uint8_t countdown_battery_low;
extern volatile uint8_t counter_can_tx_100ms;
extern volatile uint8_t debounce_ms_counter;
extern volatile uint16_t systemTimer; //for testing
extern volatile uint8_t debounce_timestamp;

extern volatile ADC_Bytes conversion;
extern volatile ADC_Bytes prev_conversion;
extern volatile ADC_Bytes prev_ref_conversion;
extern volatile uint16_t adc_delay_counter;
extern volatile CAN_Bytes battery_voltage;
//extern volatile CAN_Bytes rpm;
//extern volatile uint16_t CanCounter;

extern volatile bool prev_DC_EN;
extern volatile bool PGOOD;
extern volatile bool displayed_steeringw_installed;

//Variables for Low-pass filtering -> Exp. Moving average techinque
//extern volatile float EMA_A;
extern volatile uint16_t ema_s;

//extern volatile uint16_t STEP;
//extern volatile uint16_t ZERO_REF;
//extern volatile uint16_t MAX_REF;
//extern uint8_t REF;

// ******************************
// User exported function prototypes
// ******************************
void VariableInit(void);
void PotConversion(void);
void CanMessageCheck(void);
void CanTest(void);
void CanMcCommand(void);
void CanVcuState(void);
void PortStatusUpdate(void);
void DebounceProtectedPortStatusUpdate(void);
//void McCommandUpdate(void);
void GoToSleep(void);
void ReturnFromSleep(void);
//void CalculateSpeed(void);
//void CalculateDistance(void);
void CalculateMCRef(void);
//void GetLUTMCRef(void);
void TimerProcesses(void);
void StateMachineUpdate(void);
void RateLimiter(void);



#endif	/* USER_H */

