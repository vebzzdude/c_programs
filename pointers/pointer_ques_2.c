#include<stdio.h>

void main()
{
int arr[5] = {10, 20, 30, 40 ,50};
int *ptr;
ptr = arr;

printf("%u\n", *++ptr + 3);
printf("%u\n", *(ptr-- + 2)+5);
printf("%u\n", *(ptr+3)-10);
}
