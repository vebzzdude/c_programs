#include <stdio.h>
#define CHAR_BIT 8

int main()
{
  unsigned int a, b, shift_bits;
  printf("Enter a number and no. of bits to be shifted:");
  scanf("%d %d", &a, &shift_bits);

  b = (a << shift_bits) | (a >> sizeof(a)*CHAR_BIT - shift_bits);
  printf("Value of %d after left rotate of %d bits: %d\n", a, shift_bits, b);

  b = (a >> shift_bits) | (a << sizeof(a)*CHAR_BIT - shift_bits);
  printf("Value of %d after right rotate of %d bits: %d\n", a, shift_bits, b);
  return 0;
}
