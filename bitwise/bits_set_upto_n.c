#include <stdio.h>

int main()
{
  int num, i, j, sum = 0;

  printf("Enter number upto which total bits set has to be calculated:");
  scanf("%d", &num);

  for (i=1; i <= num; i++)
    {
      for (j = i; j != 0; j = j >> 1)
        {
          sum = sum + (j & 1);
        }
      printf("Total Bits set upto %d: %d\n", i, sum);
    }

  return 0;
}
