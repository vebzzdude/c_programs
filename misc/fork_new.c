#include <stdio.h>

int main()
{
  static int i = 0;
  ++i;
  if(fork() && fork())
  {
    fork();
  }

  if(fork() || fork())
  {
    fork();
  }

printf("(%d) Hello world",i);
printf("\n");
return 0;
}

