#include <stdio.h>

int main()
{
  unsigned int a, b, i, shift_bits, res, pos = 0;
  printf("Enter a number and no. of bits to be left shifted:");
  scanf("%d %d", &a, &shift_bits);
  res = a;
  for (i = 1; i <= shift_bits; i++)
    {
      b = res;
      pos = 0;
      while (b!=1)
        {
          b = b >> 1;
          ++pos;
        }

  //b =  1 << pos;
  //printf("%d %d\n", pos, b);
      res = ((res & ((1 << pos)-1)) << 1) + 1;
      printf("Survivor %d = %d\n", i, res);
    }
  return 0;
}
