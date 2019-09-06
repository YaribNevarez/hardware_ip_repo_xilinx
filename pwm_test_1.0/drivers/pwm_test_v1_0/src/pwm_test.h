
#ifndef PWM_TEST_H
#define PWM_TEST_H


/****************** Include Files ********************/
#include "xil_types.h"
#include "xstatus.h"

typedef enum
{
	CHANNEL_FIRST = 0,
	CHANNEL_0 = CHANNEL_FIRST,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	/* Add channel here */
	CHANNEL_LAST = CHANNEL_3
} PwmChannel;

typedef enum
{
	SUCCESS = 0,
	INVALID_CHANNEL,
	INVALID_PARAMETER,
	FAIL
} PwmResult;

typedef uint16_t PwmValue;
typedef uint16_t PwmFrequencyDiv;

typedef struct
{
	PwmResult (* setValue)(PwmChannel, PwmValue);
	PwmResult (* getValue)(PwmChannel, PwmValue *);
	PwmResult (* setFrequencyDiv)(PwmChannel, PwmFrequencyDiv);
	PwmResult (* getFrequencyDiv)(PwmChannel, PwmFrequencyDiv * );
	uint8_t   (* getDigitalInput)(void);
} PwmDriver;

/************************** Function Prototypes ****************************/

PwmDriver * PwmDriver_instance(void);

XStatus PWM_TEST_SelfTest(void);

#endif // PWM_TEST_H
