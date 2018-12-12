#include <stdio.h>

int main()
{
  if(fork() && fork())
  {
    fork();
  }

  if(fork() || fork())
  {
    fork();
  }

printf("\nHello world");
return 0;
}

