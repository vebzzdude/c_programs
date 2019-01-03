#include <stdio.h>

/* Function to display a given number in binary format */
void binary_print(unsigned int num)
{
  if (num)
   {
     binary_print (num >> 1);
     putc((num & 1) ? '1' : '0', stdout);
   }
}

int length_of_longest_consecutive_ones(unsigned int x)
{
  int count = 0;
  while (x != 0)
    {
      x = (x & (x << 1));
      count++;
    }

  return count;
}

int length_of_longest_consecutive_zeros(unsigned int x)
{
  int count = 0;
   while (((x+1) & x) != 0)
    {
      x = (x | (x >> 1));
      count++;
    }
  return count;
}

int main()
{
  unsigned int i = 0;
  printf("Enter a number:");
  scanf("%u", &i);

  printf("Binary format of %u is ", i);
  binary_print(i);
  printf("\n");

  printf("Longest no. of consecutive 1s in %u: %d\n", i, length_of_longest_consecutive_ones(i));
  printf("Longest no. of consecutive 0s in %u: %d\n", i, length_of_longest_consecutive_zeros(i));

  return 0;
}

