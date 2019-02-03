/*Programs to find Endianness of a machine */

/* Program 1: Source: GeeksForGeeks 
 ***********************************
 https://www.geeksforgeeks.org/little-and-big-endian-mystery/
 */
#include <stdio.h>

int main()
{
	unsigned int i= 1;
	char *p = (char *)&i;

	if (*p)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	return 0;
}

/* Program 2: Source: Wikipedia
 *******************************
 https://en.wikipedia.org/wiki/Endianness

#include <stdio.h>
#include <stdint.h>  // This header file is necessary for below used datatypes

int main()
{
	union u_t{
		uint8_t u8;
		uint16_t u16;
		uint32_t u32;
		uint64_t u64;
	}u = {.u64 = 0x4A};

	puts(u.u8 == u.u16 && u.u8 == u.u32 && u.u8 == u.u64 ? "true":"false");
	return 0;
}
*/
