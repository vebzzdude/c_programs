/* Program to  satisfy below condition using BITWISE operators 

 if (n >=64 && n < 128)
    return "true";
  else
    return "false";
*/

#include <stdio.h>

char* divisibility (unsigned int n)
{
  return ((n >> 6) && (!(n >> 7))) ? "true" : "false";
}


int main()
{
  unsigned int num = 0;
  char *str = NULL;

  printf("Enter a number:");
  scanf("%d", &num);

  str = divisibility(num);
  printf("%s\n", str);

  return 0;
}
