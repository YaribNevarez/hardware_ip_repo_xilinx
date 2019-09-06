

/***************************** Include Files *******************************/
#include "pwm_test.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/


static volatile void * pwm_baseAddress_ = XPAR_PWM_TEST_0_S00_AXI_BASEADDR;
static uint32_t pwm_channelState[CHANNEL_LAST + 1] = {0};

static PwmResult pwm_setValue(PwmChannel channel, PwmValue value)
{
	if (CHANNEL_FIRST <= channel && channel <= CHANNEL_LAST)
	{
		pwm_channelState[channel] = (pwm_channelState[channel] & 0xFFFF0000) | ((uint32_t)value & 0x0000FFFF);
		*(uint32_t *)(pwm_baseAddress_ + channel * sizeof(uint32_t *)) = pwm_channelState[channel];
		return SUCCESS;
	}
	else
		return INVALID_CHANNEL;
}

static PwmResult pwm_getValue(PwmChannel channel, PwmValue * value)
{
	if (value == NULL)
		return INVALID_PARAMETER;

	if (CHANNEL_FIRST <= channel && channel <= CHANNEL_LAST)
	{
		* value = pwm_channelState[channel] && 0x0000FFFF;
		return SUCCESS;
	}
	else
		return INVALID_CHANNEL;
}

static PwmResult pwm_setFrequencyDiv(PwmChannel channel, PwmFrequencyDiv frequencyDiv)
{
	if (CHANNEL_FIRST <= channel && channel <= CHANNEL_LAST)
	{
		pwm_channelState[channel] = (((((uint32_t)frequencyDiv) & 0x0000FFFF) << 16) & 0xFFFF0000) | (pwm_channelState[channel] & 0x0000FFFF);
		*(uint32_t *)(pwm_baseAddress_ + channel * sizeof(uint32_t *)) = pwm_channelState[channel];
		return SUCCESS;
	}
	return INVALID_CHANNEL;
}

static PwmResult pwm_getFrequencyDiv(PwmChannel channel, PwmFrequencyDiv * frequencyDiv)
{
	if (frequencyDiv == NULL)
		return INVALID_PARAMETER;

	if (CHANNEL_FIRST <= channel && channel <= CHANNEL_LAST)
	{
		* frequencyDiv = (pwm_channelState[channel] & 0xFFFF0000) >> 16;
		return SUCCESS;
	}
	else
		return INVALID_CHANNEL;
}

static uint8_t pwm_getDigitalInput(void)
{
	return * (uint32_t *) pwm_baseAddress_;
}

static PwmDriver pwm_driver = {pwm_setValue, pwm_getValue, pwm_setFrequencyDiv, pwm_getFrequencyDiv, pwm_getDigitalInput};

PwmDriver * PwmDriver_instance(void)
{
	return & pwm_driver;
}
