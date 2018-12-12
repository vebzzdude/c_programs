/** Input: My name is Barry Allen and I am the fastest man alive
   Output: yM eman si yrraB nellA dna I ma eht tsetsaf nam evila **/

#include <stdio.h>
#include <ctype.h>
#include<math.h>

void string_reverse(char *a)
{
  int i = 0, j = 0,  k = 0, len = 0;

  // Calculate string length
  for (len = 0; a[len] != '\0'; len++);
  printf("String length: %d\n", len);

  for (; i < len; i++)
    {
      for (; (a[j] != ' ' && a[j] != '\0'); j++);
      k = j;
      j--;
      for ( ; i < j; i++, j--)
        {
          a[i] = a[i] ^ a[j];
          a[j] = a[i] ^ a[j];
          a[i] = a[i] ^ a[j];
        }
      printf("String after iteration %d: %s\n", i, a);
      i = k;
      j = k+1;
      printf("a[%d] = %c, a[%d] = %c\n", i, a[i], j, a[j]);
    }
   
  a[len] = '\0';

}

#if 0
void string_reverse2(char *a)
{
  int i = 0, j = 0,  k = 0, len = 0, sub_len = 0;

  // Calculate string length
  for (len = 0; a[len] != '\0'; len++);
  printf("String length: %d\n", len);

  for (i = 0; i < len; i++)
    {
      k = i;
      for (sub_len = 0; (a[i] != ' ' && a[i] != '\0'); i++, sub_len++);
      printf("sub_len = %d\n", sub_len);
      for (j = k + sub_len -1; k < j; k++, j--)
        {
          a[k] = a[k] ^ a[j];
          a[j] = a[k] ^ a[j];
          a[k] = a[k] ^ a[j];
        }
      printf("String after iteration %d: %s\n", i, a);
      i =  i+sub_len+1;
      j = i;
      printf("a[%d] = %c, a[%d] = %c\n", i, a[i], j, a[j]);
    }

  a[len] = '\0';

}
#endif

int main()
{
  char str[100];
  printf("\nEnter a string of less than 100 characters:");
  scanf("%100[^\n]", str);
  printf("Original String: %s\n", str);
  string_reverse(str);
  printf("Reversed String: %s\n", str);

  return 0;
}
