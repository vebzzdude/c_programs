#include <stdio.h>

int main()
{
  unsigned int a, b, count = 0;

  printf("Enter total no. of persons standing in circle:");
  scanf("%d", &a);
  b = a;

  /* Find the nearest power of 2 which is less than the total no. of persons */
  while (b != 1)
    {
      b = b >> 1;
      ++count;
    }
  b = b << count;

  printf("Total no. of persons standing in circle = %d\n",a);
  printf("Nearest power of 2 which is less than total no. of persons = %d\n", b);
  printf("Survivor: %d\n", (2*(a-b)+1));
}
