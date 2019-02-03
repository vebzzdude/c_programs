/* Program to convert Endianness of a given number
 * Source: https://stackoverflow.com/questions/19275955/convert-little-endian-to-big-endian
 * Solution 1: Changing/Swapping byte values using Bitwise operators
 ***********************************************************************
 */
#include <stdio.h>
#include <inttypes.h>

int main()
{
	unsigned int n;
	printf("Enter a number:");
	scanf("%d", &n);

	printf("Value in Hex before converting Endianness: 0x%.8x\n", n);
	printf("Converting Endianness by changing byte values using Bitwise operators....\n");
	n =   (((n & 0x000000ff) << 24)
	   |   ((n & 0x0000ff00) << 8)
	   |   ((n & 0x00ff0000) >> 8)
	   |   ((n & 0xff000000) >> 24)) ;

	printf("Value in Hex after converting Endianness: 0x%" PRIx32 "\n", n);
	return 0;
}


/* Solution 2: Using built-in function __builtin_bswap32(uint32_t x)
 *********************************************************************
 
#include <stdio.h>
#include <inttypes.h>

int main()
{
        unsigned int n;
        printf("Enter a number:");
        scanf("%d", &n);

        printf("Value in Hex before converting Endianness: 0x%.8x\n", n);
        printf("Converting Endianness using __builtin_bswap32()..\n");
        n = __builtin_bswap32(n);
        printf("Value in Hex after converting Endianness: 0x%" PRIx32 "\n", n);
        return 0;
}
*/
