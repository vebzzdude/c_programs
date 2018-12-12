//Function pointers and callbacks

#include<stdio.h>

void A()
{
  printf("Hello\n");
}

void B(void (*ptr)())  // function pointer as argument
{
    ptr();  //call-back function that "ptr" points to
}

int main()
{
/*
  void (*p)() = A;
  B(p);
*/
  B(A);  // A is callback function
  return 0;
}
