
/***************************** Include Files *******************************/
#include "IO.h"
#include "xparameters.h"
#include "stdio.h"
#include "xil_io.h"
#include "sleep.h"

XStatus IO_SelfTest(void)
{
	int i;
	xil_printf("******************************\n\r");
	xil_printf("* IO Peripheral Self Test\n\r");
	xil_printf("******************************\n\n\r");

	/*
	 * Write to user IO slave module register(s) and read back
	 */
	xil_printf("User logic IO module test...\n\r");

    for(i = 0; i < 1000; i ++)
    {
    	IODriver_instance()->write(IO_CHANNEL_0, i);
    	usleep(5000 * IODriver_instance()->read(IO_CHANNEL_0) + 50000);
    }

	xil_printf("   - IO register write/read passed\n\n\r");

	return XST_SUCCESS;
}
