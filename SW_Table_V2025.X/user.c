    /*
 * File:   user.c
 * Author: SZEnergy
 *
 * Created on April 21, 2020, 3:35 PM
 */

#include "user.h"
#include "mcc_generated_files/can1.h"
#include "mcc_generated_files/can_module_features.h"
#include "mcc_generated_files/can_types.h"


//#define TESTING
//#include "mcc_generated_files/pin_manager.h"
//#include "mcc_generated_files/adc1.h"

// ******************************
// Global user variables
// ******************************
volatile VCU_STATE_A VcuState_A;
volatile VCU_STATE_B VcuState_B;
volatile ST_STATE_A StState_A;
volatile ST_STATE_B StState_B;
volatile ST_STATE_C StState_C;
volatile ST_STATE_D StState_D;

volatile MC_Bytes MC_REF;
volatile CAN_Bytes battery_voltage;
volatile CAN_Bytes rpm;
volatile double mc_duty_cycle;
volatile int32_t mc_data_buffer;

volatile double vcu_throttle;
volatile int32_t vcu_data_buffer;

//CAN_MSG_OBJ testmsg;
volatile CAN_MSG_OBJ VCUmsg;
volatile CAN_MSG_OBJ MCmsg;
volatile CAN_MSG_OBJ RECmsg;

volatile struct FLAGS flags;
volatile struct VEHICLE vehicle;

//uint8_t data_test[8];
volatile uint8_t data_mc[4];
volatile uint8_t data_vcu_state[4];
volatile uint8_t data_rec_message[8];

volatile uint8_t countdown_battery_low;
volatile uint8_t counter_can_tx_100ms;
volatile uint8_t debounce_ms_counter;
volatile uint8_t debounce_timestamp;
volatile uint16_t systemTimer; //for testing


volatile bool prev_DC_EN;
volatile bool PGOOD;
volatile bool displayed_steeringw_installed;

volatile ADC_Bytes conversion;
volatile ADC_Bytes prev_conversion;
volatile ADC_Bytes prev_ref_conversion;
volatile uint16_t adc_delay_counter;


//volatile float EMA_A;
volatile uint16_t ema_s;

//Right_state = 0; Left_State = 1;
volatile uint8_t wiper_state;
volatile uint16_t wiper_step_cnt;
volatile uint16_t wiper_step_time;

//first value changed to 222 from 479 just for smoother testing
volatile uint16_t counter_buzzer_1s = 0;
volatile uint16_t counter_battery_led_500ms = 0;
volatile uint16_t counter_pgood_led_500ms = 0;

volatile uint16_t rpm_rnd;

#ifdef NOT_USED_VARIABLES

extern uint8_t REF;
volatile float DISTANCE_STEP;
volatile uint16_t battery_Voltage; 
uint8_t LUT_DISTANCE_RESOLUTION;
uint16_t LUT_SIZE;
uint16_t RATE_LIMIT; 
bool lut_buffer;
int16_t acceleration_rate;
volatile uint16_t CanCounter;
#endif

float WIPER_MAP[100] = {
14900.0000, 14906.8157, 14914.1350, 14921.9937, 14930.4305, 14939.4870, 14949.2076, 14959.6404,
14970.8366, 14982.8511, 14995.7425, 15009.5734, 15024.4103, 15040.3240, 15057.3894, 15075.6857,
15095.2967, 15116.3099, 15138.8174, 15162.9151, 15188.7025, 15216.2825, 15245.7609, 15277.2455,
15310.8456, 15346.6711, 15384.8311, 15425.4330, 15468.5806, 15514.3730, 15562.9022, 15614.2513,
15668.4926, 15725.6847, 15785.8707, 15849.0755, 15915.3034, 15984.5360, 16056.7298, 16131.8147,
16209.6921, 16290.2346, 16373.2846, 16458.6551, 16546.1305, 16635.4676, 16726.3984, 16818.6326,
16911.8614, 17005.7616, 17100.0000, 17194.2384, 17288.1386, 17381.3674, 17473.6016, 17564.5324,
17653.8695, 17741.3449, 17826.7154, 17909.7654, 17990.3079, 18068.1853, 18143.2702, 18215.4640,
18284.6966, 18350.9245, 18414.1293, 18474.3153, 18531.5074, 18585.7487, 18637.0978, 18685.6270,
18731.4194, 18774.5670, 18815.1689, 18853.3289, 18889.1544, 18922.7545, 18954.2391, 18983.7175,
19011.2975, 19037.0849, 19061.1826, 19083.6901, 19104.7033, 19124.3143, 19142.6106, 19159.6760,
19175.5897, 19190.4266, 19204.2575, 19217.1489, 19229.1634, 19240.3596, 19250.7924, 19260.5130,
19269.5695, 19278.0063, 19285.8650, 19293.1843, 19300.0000
};


//This LUT for set the throttle reference
float LUT_MOTOR_EF[386]  = {
    0.0, 0.229248904, 0.229701676, 0.230154449, 0.230607221, 0.231059993, 0.23150927, 0.231909184,
    0.232309097, 0.23270901, 0.233108924, 0.23353682, 0.233977995, 0.234419169, 0.234860344,
    0.235301519, 0.235742693, 0.236183868, 0.236625042, 0.237066217, 0.237507392, 0.237948566,
    0.238389741, 0.238830915, 0.23927209, 0.239713265, 0.240154439, 0.240595614, 0.241036788,
    0.241477963, 0.241148683, 0.240813542, 0.240478402, 0.240143261, 0.23980812, 0.23947298,
    0.239057655, 0.238637817, 0.238217979, 0.23779814, 0.237378302, 0.236958464, 0.236538625,
    0.236118787, 0.235698949, 0.235279111, 0.234859272, 0.234439434, 0.234019596, 0.233599757,
    0.233179919, 0.232760081, 0.232340243, 0.231920404, 0.231500566, 0.231080728, 0.230660889,
    0.230267371, 0.230166969, 0.230066568, 0.229966167, 0.229865766, 0.229765364, 0.229664963,
    0.229564562, 0.22946416, 0.229363759, 0.229263358, 0.229162957, 0.229062555, 0.22893629,
    0.228802175, 0.22866806, 0.228533945, 0.22839983, 0.228265715, 0.2281316, 0.227997484,
    0.227863369, 0.227729254, 0.227595139, 0.227461024, 0.227326909, 0.227192794, 0.227058679,
    0.226924564, 0.226792158, 0.226672115, 0.226552071, 0.226432028, 0.226311984, 0.22619194,
    0.226071897, 0.225951853, 0.22583181, 0.225711766, 0.225591723, 0.225471679, 0.225351636,
    0.225231592, 0.225111399, 0.22498537, 0.22485934, 0.22473331, 0.224607281, 0.224481251,
    0.224355221, 0.224229192, 0.224103162, 0.223977132, 0.223851103, 0.223725073, 0.223599043,
    0.223473014, 0.223369104, 0.223381608, 0.223394112, 0.223406616, 0.22341912, 0.223431624,
    0.223444128, 0.223456633, 0.223469137, 0.223481641, 0.223494145, 0.223506649, 0.223519153,
    0.223531657, 0.223536441, 0.223538136, 0.223539831, 0.223541526, 0.223543221, 0.223544916,
    0.223546611, 0.223548306, 0.223550001, 0.223551696, 0.223553391, 0.223555086, 0.223556781,
    0.223558476, 0.223560171, 0.223569888, 0.22361212, 0.223654353, 0.223696586, 0.223738818,
    0.223781051, 0.223823283, 0.223865516, 0.223907748, 0.223949981, 0.223992213, 0.224034446,
    0.224076678, 0.224118911, 0.22416859, 0.224219172, 0.224269754, 0.224320336, 0.224370918,
    0.2244215, 0.224472082, 0.224522664, 0.224573246, 0.224623828, 0.22467441, 0.224724992,
    0.224775574, 0.224826155, 0.224872511, 0.224905907, 0.224939302, 0.224972697, 0.225006092,
    0.225039488, 0.225072883, 0.225106278, 0.225139674, 0.225173069, 0.225206464, 0.22523986,
    0.225273255, 0.22530665, 0.225340045, 0.225369188, 0.225396905, 0.225424622, 0.225452339,
    0.225480057, 0.225507774, 0.225535491, 0.225563208, 0.225590925, 0.225618642, 0.22564636,
    0.225674077, 0.225701794, 0.225729511, 0.225754917, 0.225774449, 0.22579398, 0.225813512,
    0.225833044, 0.225852576, 0.225872108, 0.225891639, 0.225911171, 0.225930703, 0.225950235,
    0.225969766, 0.225989298, 0.22600883, 0.226028362, 0.226046206, 0.226061259, 0.226076313,
    0.226091367, 0.226106421, 0.226121475, 0.226136528, 0.226151582, 0.226166636, 0.22618169,
    0.226196744, 0.226211797, 0.226226851, 0.226241905, 0.226255794, 0.226267243, 0.226278692,
    0.22629014, 0.226301589, 0.226313038, 0.226324487, 0.226335935, 0.226347384, 0.226358833,
    0.226370281, 0.22638173, 0.226393179, 0.226404628, 0.226416122, 0.226427618, 0.226439115,
    0.226450611, 0.226462108, 0.226473604, 0.226485101, 0.226496597, 0.226508093, 0.22651959,
    0.226531086, 0.226542583, 0.226554079, 0.226565576, 0.22658325, 0.226611723, 0.226640196,
    0.226668668, 0.226697141, 0.226725614, 0.226754087, 0.22678256, 0.226811032, 0.226839505,
    0.226867978, 0.226896451, 0.226924924, 0.226953396, 0.226981869, 0.227010342, 0.227036148,
    0.227061657, 0.227087167, 0.227112676, 0.227138186, 0.227163695, 0.227189205, 0.227214714,
    0.227240223, 0.227265733, 0.227291242, 0.227316752, 0.227342261, 0.227363242, 0.227377425,
    0.227391609, 0.227405792, 0.227419975, 0.227434159, 0.227448342, 0.227462526, 0.227476709,
    0.227490892, 0.227505076, 0.227519259, 0.227533443, 0.227547626, 0.227561809, 0.227580978,
    0.227628976, 0.227676975, 0.227724973, 0.227772971, 0.227820969, 0.227868968, 0.227916966,
    0.227964964, 0.228012963, 0.228060961, 0.228108959, 0.228156958, 0.228179785, 0.228170364,
    0.228160942, 0.228151521, 0.2281421, 0.228132678, 0.228123257, 0.228113836, 0.228104414,
    0.228094993, 0.228085572, 0.22807615, 0.228066729, 0.228063308, 0.228064771, 0.228066234,
    0.228067697, 0.22806916, 0.228070623, 0.228072086, 0.228073549, 0.228075012, 0.228076475,
    0.228077938, 0.228079401, 0.228080864, 0.228082327, 0.22808379, 0.228085253, 0.228197083,
    0.228426133, 0.228655184, 0.228884234, 0.229113285, 0.229342335, 0.229571386, 0.229800436,
    0.230029487, 0.230258537, 0.230487588, 0.230716638, 0.230945689, 0.231174739, 0.23140379,
    0.23163284, 0.231861891, 0.232090941, 0.232218743, 0.232294482, 0.232370221, 0.23244596,
    0.232521699, 0.232597438, 0.232673177, 0.232748916, 0.232824655, 0.232900394, 0.233823982,
    0.23551196, 0.237807134, 0.240679813, 0.243552493, 0.246425173, 0.250236199, 0.255082031,
    0.259927864, 0.270423938, 0.284696227, 0.307775891, 0.353527544, 0.471522906, 0.599582688,
    0.677089741
};

volatile enum StateMachine current_state;
volatile enum StateMachine prev_state;

// ******************************
// User functions
// ******************************

void VariableInit(void){
    VcuState_A.VCUBits_1    = 0b00000000;
    VcuState_B.VCUBits_2    = 0b00000000;
    StState_A.ST_bits_1     = 0b00000000;
    StState_B.ST_bits_2     = 0b00000000;
    StState_C.ST_bits_3     = 0b00000000;
    StState_D.ST_bits_4     = 0b00000000;
    PortStatusUpdate();
    MC_REF.LowByte              = 0;
    MC_REF.HighByte             = 0;
    battery_voltage.Word        = 40000;
    data_mc[4]                  = 0;
    data_vcu_state[4]           = 0;
    data_rec_message[8]         = 0;
    prev_DC_EN                  = false; 
    countdown_battery_low       = 0;
    counter_can_tx_100ms        = 0;
    debounce_ms_counter         = 0;
    debounce_timestamp          = 0;
    mc_duty_cycle               = 0.;
    mc_data_buffer              = 0;
    ema_s                       = 0;
    wiper_state                 = 0;
    wiper_step_cnt              = 0;
    wiper_step_time             = 0;
    systemTimer                 = 0;
    flags.port_status_update                        = false;
    flags.can_process_rec_msg                       = false;
    flags.can_vcu_state                             = false;
    flags.mc_command_update_and_send                = false;
    flags.mc_override_changed_to_1                  = false;
    flags.mc_override_changed_to_0                  = false;
    flags.can_synced                                = false;
    flags.wiper_on                                  = false;
    flags.wiper_move                                = false;
    flags.pgood                                     = false;
    vehicle.distance = 0;
    vehicle.speed = 0;
    vehicle.rpm = 0;
}


void PortStatusUpdate(void){

    VcuState_A.AUT      = IO_AUT_GetValue();
    VcuState_A.BRAKE    = IO_BRAKE_GetValue();
    VcuState_A.HAZARD   = IO_HAZARD_GetValue();
    VcuState_A.LAMP     = IO_LAMP_GetValue();
    VcuState_A.FUNCTION = IO_FUNCTION_GetValue();
    VcuState_A.MC_OW    = IO_MC_OW_GetValue();
    VcuState_A.WIPER    = IO_WIPER_GetValue();
    VcuState_B.RELAY_NO = IO_SHELL_C1_GetValue();   //  Relay_NO
    
    if(VcuState_A.BRAKE == 1){
        BREAK_OUT_SetLow();
    }else{
        BREAK_OUT_SetHigh();
    }
    
    if(VcuState_B.RELAY_NO == 1){
            VcuState_A.MC_OW = 0;
            }
#ifdef SHELL_RELAY_TEST
    if(VcuState_A.AUT == 1){                  //Shell_Relay_Test
        IO_SHELL_RELAY_SetHigh();
    }else{
        IO_SHELL_RELAY_SetLow();
    }
#endif 
    }
  
void CanMessageCheck(void){
    // Receive CAN messages and store their data
    RECmsg.data = data_rec_message;
    if(CAN1_Receive(&RECmsg)){
        if(RECmsg.msgId==0x185){
            counter_can_tx_100ms = 0;
            flags.can_synced = true;
        }
        
        if(RECmsg.msgId==0x190){
            
            StState_A.ST_bits_1 = RECmsg.data[0];
            StState_B.ST_bits_2 = RECmsg.data[1];
            StState_C.ST_bits_3 = RECmsg.data[2];
            StState_D.ST_bits_4 = RECmsg.data[3];
            
            if(VcuState_B.RELAY_NO ==1){
                StState_A.ACC = 0;
                StState_A.DRIVE = 0;
                StState_A.REVERSE = 0;
            }
        }
        if(RECmsg.msgId==0x123){
            rpm.HighByte = RECmsg.data[0];
            rpm.LowByte = RECmsg.data[1];
            vehicle.rpm = rpm.Word/100;
        }
        if(RECmsg.msgId==0x10){
            if(1 & RECmsg.data[0]){
                IO_SHELL_RELAY_SetHigh();
            }else{
                IO_SHELL_RELAY_SetLow();
            }
        }
    }
}

void CalculateSpeed(void){
    vehicle.speed = vehicle.rpm * SPEED_MULT_FACTOR;
}

#ifdef CALCULATE_DISTANCE // not used yet
void CalculateDistance(void){
    vehicle.distance += ((vehicle.speed*100)/3600); //values in cms | 72 if we use it every 50 ms
                                             // 3600 if we use it every 1 ms
}
#endif

void CanVcuState(void){
    
    vcu_throttle = (double)conversion.ADC_Word / 1023;
    vcu_data_buffer = vcu_throttle * 100000;
    
    data_vcu_state[2] = vcu_data_buffer >> 24;        
    data_vcu_state[3] = vcu_data_buffer >> 16;
    data_vcu_state[4] = vcu_data_buffer >> 8;
    data_vcu_state[5] = vcu_data_buffer;
    
    data_vcu_state[0] = VcuState_A.VCUBits_1;
    data_vcu_state[1] = VcuState_B.VCUBits_2;

    
    CAN1_OperationModeSet(CAN_NORMAL_2_0_MODE);
    VCUmsg.msgId = 0x129;
    VCUmsg.field.frameType = CAN_FRAME_DATA;
    VCUmsg.field.idType = CAN_FRAME_STD;
    VCUmsg.field.dlc = CAN_DLC_6;
    VCUmsg.data = data_vcu_state;
            
    CAN1_Transmit(CAN_PRIORITY_HIGH, &VCUmsg);
    
    // END - Send CAN message about VCU state
    
}
//

void CanMcCommand(void){
    // Send CAN message about MC Command
    mc_duty_cycle = (double)conversion.ADC_Word/1023;
    if(StState_A.REVERSE){
        mc_duty_cycle = mc_duty_cycle * -1;    
    }
     
    mc_data_buffer = mc_duty_cycle * 100000;
    data_mc[0] = mc_data_buffer >> 24;
    data_mc[1] = mc_data_buffer >> 16;
    data_mc[2] = mc_data_buffer >> 8;
    data_mc[3] = mc_data_buffer; 
     
     
    if(!VcuState_A.MC_OW){
        if(StState_A.DRIVE || StState_A.REVERSE ){

            CAN1_OperationModeSet(CAN_NORMAL_2_0_MODE);

            MCmsg.msgId = 0xA51;
            MCmsg.field.frameType = CAN_FRAME_DATA;
            MCmsg.field.idType = CAN_FRAME_EXT;
            MCmsg.field.dlc = CAN_DLC_4;
            MCmsg.data = data_mc;

            CAN1_Transmit(CAN_PRIORITY_HIGH, &MCmsg);
        }
    }
    
    // END - Send CAN message about MC Command
}

void StateMachineUpdate(void){
    
    if(!StState_A.DRIVE && !StState_A.REVERSE){
        current_state = Neutral;
    }else if(!VcuState_A.MC_OW && conversion.ADC_Word > 0){
        if(StState_A.DRIVE){
            current_state = Drive_Pedal;
        }else if(StState_A.REVERSE){
            current_state = Reverse_Pedal;
        }
    }else if(!VcuState_A.MC_OW && StState_A.ACC && conversion.ADC_Word == 0){
        if(StState_A.DRIVE){
            current_state = Automatic_Acc;
        }else if(StState_A.REVERSE){
            current_state = Automatic_Dec;
        }
    }else{
        current_state = Neutral;
    }
    if(prev_state != Neutral && current_state == Neutral){
        conversion.ADC_Word = 0;
        prev_ref_conversion.ADC_Word = 0;
//        McCommandUpdate();
        CanMcCommand();
    }
    prev_state = current_state;
}


void PotConversion(void){
    ADC1_Enable();
    
    ADC1_ChannelSelect(POT_FOOT);
    ADC1_SoftwareTriggerEnable();
    
    //Provide Delay
    for(adc_delay_counter=0;adc_delay_counter <1000;adc_delay_counter++) {}
    
    ADC1_SoftwareTriggerDisable();
    while(!ADC1_IsConversionComplete(POT_FOOT));
    conversion.ADC_Word = (ADC1_ConversionResultGet(POT_FOOT));
    // 12bit ADC resolution:

    if(conversion.ADC_Word>ZERO_REF){
        ema_s = (EMA_A * conversion.ADC_Word) + ((1-EMA_A) * ema_s);
        conversion.ADC_Word = ema_s;
    }

    if((conversion.ADC_Word - prev_conversion.ADC_Word) <= 50)

        conversion.ADC_Word = prev_conversion.ADC_Word;
    else
        prev_conversion.ADC_Word = conversion.ADC_Word;  
//
    if(conversion.ADC_Word <= ZERO_REF  )
        conversion.ADC_Word = 0;

    else if(conversion.ADC_Word - ZERO_REF <= STEP) 
//        conversion.ADC_Word = 51;
        conversion.ADC_Word = 0;

    else if(conversion.ADC_Word - ZERO_REF <= STEP*2)
        conversion.ADC_Word = 102;

    else if(conversion.ADC_Word - ZERO_REF <= STEP*3)
        conversion.ADC_Word = 153;

    else if(conversion.ADC_Word - ZERO_REF <= STEP*4)
        conversion.ADC_Word = 204;

    else if(conversion.ADC_Word - ZERO_REF <= STEP*5)
        conversion.ADC_Word = 255;

    else if(conversion.ADC_Word - ZERO_REF <= STEP*6)
        conversion.ADC_Word = 306;      

    else if(conversion.ADC_Word - ZERO_REF <= STEP*7)
        conversion.ADC_Word = 357;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*8)
        conversion.ADC_Word = 408;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*9)
        conversion.ADC_Word = 459;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*10)
        conversion.ADC_Word = 510;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*11)
        conversion.ADC_Word = 561;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*12)
        conversion.ADC_Word = 612;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*13)
        conversion.ADC_Word = 663;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*14)
        conversion.ADC_Word = 714;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*15)
        conversion.ADC_Word = 765;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*16)
        conversion.ADC_Word = 816;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*17)
        conversion.ADC_Word = 867;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*18)
        conversion.ADC_Word = 918;   

    else if(conversion.ADC_Word - ZERO_REF <= STEP*19)
        conversion.ADC_Word = 969;   

    else if(conversion.ADC_Word - ZERO_REF >  STEP*19)
        conversion.ADC_Word = 1023;   

    ADC1_Disable();
}

void RateLimiter(void){
//    acceleration_rate = conversion.ADC_Word;
//    acceleration_rate -= prev_ref_conversion.ADC_Word;
    if(2000+conversion.ADC_Word-prev_ref_conversion.ADC_Word > 2000+RATE_LIMIT_UP){
        conversion.ADC_Word = prev_ref_conversion.ADC_Word + RATE_LIMIT_UP;
    }else if(2000+conversion.ADC_Word-prev_ref_conversion.ADC_Word < 2000-RATE_LIMIT_DOWN){
        conversion.ADC_Word = prev_ref_conversion.ADC_Word - RATE_LIMIT_DOWN;
    }
        
//    if(conversion.ADC_Word>1023){
//        conversion.ADC_Word = 1023;
//    }
    prev_ref_conversion.ADC_Word = conversion.ADC_Word;
}

void CalculateMCRef(void){
    rpm_rnd = vehicle.rpm;

    
    switch(StState_D.ST_bits_4){
        case 0:
                conversion.ADC_Word = 1023;
            break;
            
        case 1:
            
                conversion.ADC_Word = 1023;
            
            break;
            
        case 2:
            
                if(rpm_rnd >= 221){
                    conversion.ADC_Word = 1023*LUT_MOTOR_EF[rpm_rnd];
                }else{
                    conversion.ADC_Word = 1023; //full thrutle based on motor bench masurment
                }
                
                break;

        case 4:

                conversion.ADC_Word = 1023;

                break;
        case 8:
            
                conversion.ADC_Word = 1023;
                

                break;
        case 16:
            if(vehicle.speed >= 5 ){
                conversion.ADC_Word = 409;
            }else{
                conversion.ADC_Word = 1023;
            }
                break;
        case 32:

                conversion.ADC_Word = 818;
                
                break;
        case 64:
            
                conversion.ADC_Word = 920;
                   
            break;

            default:
                conversion.ADC_Word = 0;
            break;
        }
    
//    conversion.ADC_Word = 100;

}

void GoToSleep(void){
    //add lines if necessary
    //RCONbits.SLEEP = 0;
    RCONbits.IDLE = 0;
    RCONbits.WDTO = 0;
    //Disable DMA interrupts
    IPC1bits.DMA0IP = 0;
    IPC6bits.DMA2IP = 0;
    //ADC disabled in idle ADSIDL = 1
    Idle();
}

void ReturnFromSleep(void){
    if(RCONbits.IDLE == 1){
        RCONbits.IDLE = 0;
        if(RCONbits.WDTO == 1){
            RCONbits.WDTO = 0;
        }
        ClrWdt();
        IPC1bits.DMA0IP = 1;
        IPC6bits.DMA2IP = 1;
    }
    //add lines if necessary
}

void WiperActions(void){
#ifdef WIPER_CODE_NEW
    
    switch(wiper_state){
        case 0: //STBY
            if(VcuState_A.WIPER == 1){
                wiper_state = 1;
            }
            break;
        case 1: //READY
//            Enable Converter
            IO_WIPER_CONV_EN_SetHigh();
//            Start PWM module
            PTCON = 0x8000;
            
//            Start Timer
            flags.wiper_on = true;
            if(flags.wiper_move == true)
            {
                wiper_state = 2;
                flags.wiper_move = false;
            }
            break;
        case 2: // Right
            PDC2 = WIPER_LIMIT_RIGHT;
            if(VcuState_A.WIPER == 0)
            {
                wiper_state = 4;
            }
            if(flags.wiper_move == true)
            {
                wiper_state = 3;
                flags.wiper_move = false;
            }
            break;
        case 3: // Left
            PDC2 = WIPER_LIMIT_LEFT;
            if(VcuState_A.WIPER == 0)
            {
                wiper_state = 4;
            }
            if(flags.wiper_move == true)
            {
                wiper_state = 2;
                flags.wiper_move = false;
            }
            break; 
        case 4: // Center and ready to SW OFF
            if(flags.wiper_move == true)
            {
                PDC2 = WIPER_WINDSCREEN_CENTER;
                flags.wiper_move = false;
                wiper_state = 5;
            }
        case 5: // ALL OFF
            if(flags.wiper_move == true){
                //Turn OFF PWM Module
                PTCON = 0x0000;
                //Disable Wiper Timer Counter
                flags.wiper_on = false;
                flags.wiper_move = false;
                //Disable 5V Converter
                IO_WIPER_CONV_EN_SetLow();
                wiper_state = 0;
            }
            break;
        default:
            break;
        }
#endif
#ifdef WIPER_CODE_OLD
            switch(wiper_state){
             case 0: //STBY
                if(VcuState_A.WIPER == 1){
                    wiper_state = 1;
                }
                break;
            case 1: //READY
//                Enable Converter
                IO_WIPER_CONV_EN_SetHigh();
//                Start PWM module
                PTCON = 0x8000;
//                Start Timer
                flags.wiper_on = true;
                if(flags.wiper_move == true)
                {
                    wiper_state = 2;
                    flags.wiper_move = false;
                }
                break;
            case 2: // Left
                PDC2 = WIPER_LEFT_X[wiper_step_cnt];
                if(VcuState_A.WIPER == 0)
                {
                wiper_state = 4;
                }
                if(wiper_step_cnt >= 99){
                    wiper_state = 3;
                    flags.wiper_move = false;
                }
                break; 
            case 3: // Right
                
            PDC2 = WIPER_LEFT_X[wiper_step_cnt];
                if(VcuState_A.WIPER == 0)
                {
                wiper_state = 4;
                }
                if(wiper_step_cnt <= 0){
                    wiper_state = 2;
                    flags.wiper_move = false;
                }
                break;
            case 4: // Center and ready to SW OFF
            if(flags.wiper_move == true)
                {
                PDC2 = WIPER_WINDSCREEN_CENTER;
                wiper_step_cnt = 0;
                flags.wiper_move = false;
                wiper_state = 5;
                }
                break;
            case 5: // ALL OFF
            if(flags.wiper_move == true){
//                Turn OFF PWM Module
                PTCON = 0x0000;
//                Disable Wiper Timer Counter
                flags.wiper_on = false;
                flags.wiper_move = false;
//                Disable 5V Converter
                IO_WIPER_CONV_EN_SetLow();
                wiper_state = 0;
                }
                break;
            default:
                break;
            }

     
#endif
    
}

