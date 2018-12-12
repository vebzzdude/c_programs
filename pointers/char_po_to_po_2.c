#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Write myalloc here
void myalloc1(char **a)
{
    *a = "IP Infusion";
}

/*
void myalloc2(char **a)
{
    a[0] = (char *)malloc(strlen("IP Infusion")+1);
    strcpy(a[0], "IP Infusion"); 
}

void myalloc3(char **a)
{
    a[0] = (char *)malloc(12 * sizeof(char));
    strcpy(a[0], "IP Infusion");
}
*/

void main(void)
{
char *myptr;
myalloc1(&myptr);
printf("%s", myptr);

/*
myalloc2(&myptr);
printf("%s", myptr);

myalloc3(&myptr);
printf("%s", myptr);
*/
}
