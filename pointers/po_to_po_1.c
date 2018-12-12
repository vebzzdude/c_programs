#include<stdio.h>

int main()
{

int a = 49;
int *p1, **p2;

p1 = &a;
p2 = &p1;

printf("\nValue of a: %d", a);
printf("\nAddress of a: %u\n", &a);

printf("\nValue of p1: %u", p1);
printf("\nAddress of p1: %u\n", &p1);

printf("\nValue of p2: %u", p2);
printf("\nAddress of p2: %u\n", &p2);

printf("\nValue at Address stored in p1: %u", *p1);
printf("\nValue at Address stored in p2: %u\n", *p2);

printf("\na = %d", a);
printf("\n*p1 = %d", *p1);
printf("\n**p2 = %d\n", **p2);

return 0;

} 
