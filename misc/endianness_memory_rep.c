/* Program to display memory representation of a given number - Source: GeeksForGeeks
**************************************************************************************
https://www.geeksforgeeks.org/little-and-big-endian-mystery/
*/
#include <stdio.h>

void show_mem_rep(char *s, int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("%.2x ", s[i]);

}

int main()
{
	unsigned int a = 0x01234567;
        printf("Given number: %x\n", a);
	printf("Given number's representation in memory: ");
	show_mem_rep ((char *)&a, sizeof(a));
	printf("\n");

	return 0;
}
