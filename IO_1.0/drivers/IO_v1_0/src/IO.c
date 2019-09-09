

/***************************** Include Files *******************************/
#include "xparameters.h"
#include "IO.h"

static uint32_t * IO_base_address = XPAR_IO_0_S00_AXI_BASEADDR;

/************************** Function Definitions ***************************/
void IO_write(IOChannel channel, uint32_t data)
{
	if (IO_CHANNEL_FIRST <= channel && channel <= IO_CHANNEL_LAST)
		*(IO_base_address + (channel * 4)) = data;
}

uint32_t IO_read(IOChannel channel)
{
	if (IO_CHANNEL_FIRST <= channel && channel <= IO_CHANNEL_LAST)
		return *(IO_base_address + (channel * 4));
	else
		return 0;
}

static IODriver IO_driver = { IO_write, IO_read };

IODriver * IODriver_instance()
{
	return &IO_driver;
}

