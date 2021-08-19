#include "BCM2837.h"

typedef unsigned int uint;

void write32(void *dst, uint val)
{
	uint* dst_u = (uint*)dst;
	*dst_u = val;

	return;
}

uint read32(void *src)
{
	uint* src_u = (uint*)src;
	return *src_u;
}


void main(void)
{
	uint gpfsel2 = read32(BCM2837_GPFSEL2);
	gpfsel2 |= (1<<3); //turn pin 21 into an output.
	write32(BCM2837_GPFSEL2, gpfsel2);

	int i = 0;

	while(1)
	{
		//turn on pin 21
		write32(BCM2837_GPSET0, 1<<21);

		//delay
		i = 0;
		while (i < 0x800000)
		{
			i++;
		}

		//turn off pin 21
		write32(BCM2837_GPCLR0, 1<<21);

		//delay
		i = 0;
		while (i < 0x800000)
		{
			i++;
		}

	}
}