#include <stdio.h>

struct sample
{
	int a;
	float b;
	char c;
};

int main()
{
	struct sample *ptr = NULL;
	ptr++;

	struct sample st[2]  = {0};
	printf("Size of structure: %u\n", ptr);
	printf("Address st[0] = %lu, st[1] =%lu \n", &st[0], &st[1]); 
	printf("Size of structure : %lu\n", ((char *)(&st[1]) - (char *)(&st[0])));
	return 0;
}
