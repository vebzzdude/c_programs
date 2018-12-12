#include <stdio.h>

int abc()
{
  return -1;
}


int main()
{

  int a = 5;
  a = abc();
  printf("a = %d\n",a);
  return 0;
}



