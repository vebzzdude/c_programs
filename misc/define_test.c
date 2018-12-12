#include <stdio.h>
#define q(Y) (Y*Y*Y)

int main()
{
   int a;
   int b=3;
   a = q(++b);
   printf("\na = %d b= %d\n",a,b);
   return 0;
}
