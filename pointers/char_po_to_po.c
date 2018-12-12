#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Write myalloc here
void myalloc(char **a)
{
  a[0] = (char *)malloc(20 * sizeof(char));
  strcpy(a[0], "IP Infusion");
  printf("\n &a[0] =  %u", &a[0]);
  printf("\n *a[0] =  %u", *a[0]);

  a[1] = (char *)malloc(20 * sizeof(char));
  strcpy(a[1], "Google Inc.");
  printf("\n &a[1] =  %u", &a[1]);
  printf("\n *a[1] =  %u", *a[1]);
}

void main(void)
{
char *myptr;
int inc;
myalloc(&myptr);
printf("\n myptr = %s", myptr);
printf("\n &myptr = %u", &myptr);

inc = 8;

myptr = myptr + inc;
printf("\n Increment myptr by %d bytes", inc);
printf("\n myptr = %s", myptr);
printf("\n &myptr = %u\n", &myptr);

return;
}

/*
Output:
./a.out 
IP Infusion

*/
