#include <stdio.h>

int main()
{
int a;

printf("\nEnter a number:");
scanf("%d", &a);

printf("Entered value: %d", a);
a =  a ^ a;
printf("\na ^ a = %d\n", a);

return 0;
}
