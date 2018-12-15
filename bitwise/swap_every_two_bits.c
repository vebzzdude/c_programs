/* Swap every two bits in a Byte (8 bits) */
/* Swap nibbles in a Byte (8 bits) */

#include <stdio.h>

/* Data type is taken as 'unsigned char' as it's size is 1 Byte */
/* Function to display a given number in binary format */
void binary_print(unsigned char num)
{
  if (num)
   {
     binary_print (num >> 1);
     putc((num & 1) ? '1' : '0', stdout);
   }
}

int main()
{
  unsigned char i = 0, j = 0, k = 0;

  printf("Enter a number(0<=n<=255) whose bits has to be swapped:");
  scanf("%d", &i);
  printf("i = %d in binary form: ", i);
  binary_print(i);

  /* Swap every two bits */
  printf("\nSwapping every two bits in a Byte...");
  j = ((i & 0xaa) >> 1) | ((i & 0x55) << 1);       /*Equivalent statement:  j = ((i & 170) >> 1) | ((i & 85) << 1); */
  printf("\nj = %d in binary form: ", j);
  binary_print(j);

  /* Swap nibbles in a word */
  printf("\nSwapping nibbles in a Byte...");
  k = ((i & 0xf) << 4)  | (i >> 4);        /* Equivalent statement: k = ((i & 15) << 4)  | (i >> 4); */
  printf("\nk = %d in binary form: ",k);
  binary_print(k);
  printf("\n");
  return 0;
}
