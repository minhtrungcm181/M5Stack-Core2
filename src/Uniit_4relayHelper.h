#include <M5Core2.h>
#include <Unit_4RELAY.h>

#define SYNCHRONOUS     true
#define ASYNCHRONOUS    false

#define ON_RELAY_1      0
#define OFF_RELAY_1     1
#define ON_RELAY_2      2
#define OFF_RELAY_2     3
#define ON_RELAY_3      4
#define OFF_RELAY_3     5
#define ON_RELAY_4      6
#define OFF_RELAY_4     7
#define SWITCH_FLAG     10

#define IDLE            99

#define RELAY_1         0
#define RELAY_2         1
#define RELAY_3         2
#define RELAY_4         3

#define ON_ALL          21
#define OFF_ALL         20

#define ON_SIGNAL       1
#define OFF_SIGNAL      0

extern UNIT_4RELAY relay;
extern bool syn_asyn_flag;
extern bool all_flag;
extern uint8_t relayState;
extern uint8_t ALLrelayState;

extern bool relay_1_state;
extern bool relay_2_state;
extern bool relay_3_state;
extern bool relay_4_state;

void controlRelay();
void controlALL();
void setupRelay();