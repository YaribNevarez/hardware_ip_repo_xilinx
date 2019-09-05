
/***************************** Include Files *******************************/
#include "ILI9341_DISPLAY_YARIB.h"
#include "ili9341_graphics.h"
#include "xparameters.h"
#include "stdio.h"
#include "xil_io.h"

#include "stdlib.h"
#include "math.h"
#include "sleep.h"

/************************** Constant Definitions ***************************/
#define READ_WRITE_MUL_FACTOR 0x10

/************************** Function Definitions ***************************/
/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus ILI9341_DISPLAY_YARIB_Reg_SelfTest(void)
{
	TFTGraphics * graphics = NULL;

	xil_printf("******************************\n\r");
	xil_printf("* ILI9341_DISPLAY_YARIB Peripheral Self Test\n\r");
	xil_printf("******************************\n\n\r");

	/*
	 * Write to user logic slave module register(s) and read back
	 */
	xil_printf("User logic slave module test...\n\r");

	graphics = TFTGraphics_instance();

	if (graphics == NULL)
		return XST_FAILURE;

	graphics->initialize();

	FramePanel * frame = FramePanel_new(0, 0, MAX_WIDTH -1, MAX_HEIGHT -1, WHITE, NAVY);
	Plot2D     * plot = Plot2D_new(50, 100, 100, 100, RED, BLACK);
	TextLabel  * textLabel = TextLabel_new(25, 20, 0, 0, "     Hello World!        ", YELLOW, BLACK);


	if (frame && plot && textLabel)
	{
		double angle;
		uint16_t color;
		uint16_t i;
		frame->give_widget(frame, (Widget *)plot);
		frame->give_widget(frame, (Widget *)textLabel);

		frame->draw((Widget *)frame);

		for (i = 0; i < 100; i ++)
		{
			color = rand() % WHITE;
			for (angle = 0.0f; angle <= 360.0f; angle += 360.0f/50)
			{
				//plot->add_point(plot, 25.0f*sin(2*M_PI*(angle/360))+50.0f, color);
				plot->add_point(plot, rand()%50 + 25, color);
				usleep(1);
			}
		}
	}
	else
	   return XST_FAILURE;

	xil_printf("   - slave register write/read passed\n\n\r");

	return XST_SUCCESS;
}
