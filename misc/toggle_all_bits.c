/* Toggle all the bits in a given number
 *
 * Solution: Find the nearest power of 2 which is greater than given number
 * Subtract the given number and a '1' from it.
 */

#include<stdio.h>

void binary_display(unsigned int num)
{
  if (num == 0)
    return;

  binary_display(num >> 1);
  putc((num & 1) ? '1' : '0',stdout);
}

int main()
{

  unsigned int val, temp;
  int i, count = 0;
  printf("Enter a number:");
  scanf("%d", &val);

  temp = val;
  while(temp != 0)
  {
    temp = temp >> 1;
    ++count;	
  }

  
  //temp = val ^ ((1 << count) - 1);
  temp = (1 << count) - 1 -val;

  printf("\nBinary format of %u is:\n", val);
  binary_display(val);

  printf("\nBinary format of resultant value %u is:\n", temp);
  binary_display(temp);

 
  printf("\n");
  return 0;
}
