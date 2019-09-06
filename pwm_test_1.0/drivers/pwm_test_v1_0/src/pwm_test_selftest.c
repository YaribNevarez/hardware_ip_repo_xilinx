
/***************************** Include Files *******************************/
#include "pwm_test.h"
#include "xparameters.h"
#include "stdio.h"
#include "xil_io.h"
#include "sleep.h"

/************************** Constant Definitions ***************************/
#define READ_WRITE_MUL_FACTOR 0x10

/************************** Function Definitions ***************************/
XStatus PWM_TEST_SelfTest(void)
{
    PwmDriver * pwm = PwmDriver_instance();
    PwmChannel  channel;
    PwmValue    value;
    uint8_t		counter;

	xil_printf("******************************\n\r");
	xil_printf("* PWM_TEST Self Test\n\r");
	xil_printf("******************************\n\n\r");

	/*
	 * Write to user logic slave module register(s) and read back
	 */
	xil_printf("User logic PWM_TEST module test...\n\r");

    for (counter = 0; counter < 100; counter ++)
		for (channel = CHANNEL_FIRST; channel <= CHANNEL_LAST; channel ++)
		{
			for (value = 0; value < 0xFFFF; value ++)
			{
				pwm->setValue(channel, value);
				usleep(pwm->getDigitalInput());
			}

			for (value = 0xFFFF; 0 < value; value --)
			{
				pwm->setValue(channel, value);
				usleep(pwm->getDigitalInput());
			}
		}

	xil_printf("   - PWM_TEST register write/read passed\n\n\r");

	return XST_SUCCESS;
}
