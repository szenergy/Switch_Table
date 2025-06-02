#ifndef USER_H
#define	USER_H

#define WIPER_CODE


#include <xc.h> // include processor files - each processor file is guarded.
#include <stdbool.h>
#include "user_defines.h"
#include "mcc_generated_files/can1.h"
#include "mcc_generated_files/can_types.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/adc1.h"
//#include "mcc_generated_files/tmr2.h"

// ******************************
// User structures
// ******************************

typedef union  __attribute__(())
{
    uint8_t VCUBits_1;
    struct
    {
        uint8_t FUNCTION        :1;
        uint8_t HAZARD          :1;
        uint8_t AUT             :1;
        uint8_t BRAKE           :1;
        uint8_t LAMP            :1;
        uint8_t MC_OW           :1;
        uint8_t WIPER           :1;
    };
}VCU_STATE_A;

typedef union __attribute__(()) 
{
    uint8_t VCUBits_2;
    struct
    {
        uint8_t RELAY_NO        :1;
        uint8_t RELAY_NC        :1;
        uint8_t RESERVED1       :1;
        uint8_t RESERVED2       :1;
        uint8_t RESERVED3       :1;
        uint8_t RESERVED4       :1;
        uint8_t RESERVED5       :1;
        uint8_t RESERVED6       :1;
    };
}VCU_STATE_B;

typedef union  __attribute__(())
{
    uint8_t ST_bits_1;
    struct
    {
        uint8_t ACC                 :1;
        uint8_t DRIVE               :1;
        uint8_t REVERSE             :1; // RIVERS
        uint8_t LAP                 :1;
        uint8_t TS_L                :1;
        uint8_t TS_R                :1;
        uint8_t FUNCTION1           :1;
        uint8_t FUNCTION2                 :1;
    };
}ST_STATE_A;


typedef union __attribute__(()) 
{
    uint8_t ST_bits_2;
    struct
    {
        uint8_t ROT1_1       :1;
        uint8_t ROT1_2       :1;
        uint8_t ROT1_3       :1;
        uint8_t ROT1_4       :1;
        uint8_t ROT1_5       :1;
        uint8_t ROT1_6       :1;
        uint8_t ROT1_7       :1;
    };
}ST_STATE_B;

typedef union __attribute__(()) 
{
    uint8_t ST_bits_3;
    struct
    {
        uint8_t ROT2_1       :1;
        uint8_t ROT2_2       :1;
        uint8_t ROT2_3       :1;
        uint8_t ROT2_4       :1;
        uint8_t ROT2_5       :1;
        uint8_t ROT2_6       :1;
        uint8_t ROT2_7       :1;
    };
}ST_STATE_C;

typedef union __attribute__(()) 
{
    uint8_t ST_bits_4;
    struct
    {
        uint8_t ROT3_1       :1;
        uint8_t ROT3_2       :1;
        uint8_t ROT3_3       :1;
        uint8_t ROT3_4       :1;
        uint8_t ROT3_5       :1;
        uint8_t ROT3_6       :1;
        uint8_t ROT3_7       :1;
    };
}ST_STATE_D;

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
    uint16_t Word;
    struct
    {
        uint8_t LowByte     :8;
        uint8_t HighByte    :8;
    };
}CAN_Bytes;

typedef union __attribute__(()) 
{
    uint16_t ADC_Word;
    struct
    {
        uint8_t LowByte     :8;
        uint8_t HighByte    :8;
    };
}ADC_Bytes;

struct VEHICLE{
    double rpm;
    double speed;
    double distance;
//    double prev_distance;
};

struct FLAGS{
    bool port_status_update;
    bool can_process_rec_msg;
    bool can_vcu_state;
    bool mc_command_update_and_send;
    bool can_synced;
    bool mc_override_changed_to_1;
    bool mc_override_changed_to_0;
    bool wiper_on;
    bool wiper_move;
    bool pgood;
};

enum StateMachine {Neutral, Drive_Pedal, Reverse_Pedal, Automatic_Acc, Automatic_Dec};

// ******************************
// User exported global variables
// ******************************

extern float WIPER_LEFT_X[100];

extern volatile VCU_STATE_A VcuState_A;
extern volatile VCU_STATE_B VcuState_B;
extern volatile ST_STATE_A StState_A;
extern volatile ST_STATE_B StState_B;
extern volatile ST_STATE_C StState_C;
extern volatile ST_STATE_D StState_D;

extern volatile struct FLAGS flags;
extern volatile struct VEHICLE vehicle;

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
extern volatile uint16_t systemTimer; //for testing
extern volatile uint8_t debounce_timestamp;

extern volatile ADC_Bytes conversion;
extern volatile ADC_Bytes prev_conversion;
extern volatile ADC_Bytes prev_ref_conversion;
extern volatile uint16_t adc_delay_counter;
extern volatile CAN_Bytes battery_voltage;

extern volatile CAN_Bytes battery_voltage;
extern volatile CAN_Bytes rpm;
//extern volatile uint16_t CanCounter;

extern volatile bool prev_DC_EN;
extern volatile bool PGOOD;
extern volatile bool displayed_steeringw_installed;

//Variables for Low-pass filtering -> Exp. Moving average techinque
//extern volatile float EMA_A;
extern volatile uint16_t ema_s;

//Right_state = 0; Left_State = 1;
extern volatile uint8_t wiper_state;
extern volatile uint16_t wiper_step_cnt;
extern volatile uint16_t wiper_step_time;;
// ******************************
// User exported function prototypes
// ******************************
void VariableInit(void);
void CanMessageCheck(void);
void CanTest(void);
void CanMcCommand(void);
void CanVcuState(void);
void PortStatusUpdate(void);
void PotConversion(void);
void GoToSleep(void);
void ReturnFromSleep(void);
void CalculateMCRef(void);
void TimerProcesses(void);
void WiperActions(void);
void StateMachineUpdate(void);
void RateLimiter(void);
void CalculateSpeed(void);

#endif	/* USER_H */

