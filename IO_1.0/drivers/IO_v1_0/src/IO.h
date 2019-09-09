
#ifndef IO_H
#define IO_H

#include "xil_types.h"
#include "xstatus.h"

typedef enum
{
	IO_CHANNEL_FIRST = 0,
	IO_CHANNEL_0 = IO_CHANNEL_FIRST,
	IO_CHANNEL_1,
	IO_CHANNEL_2,
	IO_CHANNEL_3,
	/* Add new channels here*/
	IO_CHANNEL_LAST = IO_CHANNEL_3 /* Update new channels here*/
} IOChannel;

void IO_write(IOChannel channel, uint32_t data);

uint32_t IO_read(IOChannel channel);

typedef struct
{
	void     (*write)(IOChannel, uint32_t);
	uint32_t (*read) (IOChannel);
} IODriver;

IODriver * IODriver_instance();

XStatus IO_SelfTest(void);

#endif // IO_H
