#include <stdio.h>

int main()
{

  signed int32_t a = 0x00000fff, b = 0x80000010;

  if (a > b)
    printf("%lu is greater than %lu\n", a, b);
  else if (a < b)
    printf("%lu is less than %lu\n", a, b);
  else
    printf("Equal\n");

  return 0;
}
