/** Input: My name is Barry Allen and I am the fastest man alive
   Output: yM eman si yrraB nellA dna I ma eht tsetsaf nam evila **/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

void words_reversed_in_string(char *a)
{
  int i = 0, j = 0,  k = 0, len = 0;

  // Calculate string length
  for (len = 0; a[len] != '\0'; len++);
  printf("String length: %d\n", len);

  for (; i < len; i++)
    {
      /* Find end of the current word. If it's the last word
       * in the sentence, it contains End-Of-Line character.
       */
      for (; (a[j] != ' ' && a[j] != '\0'); j++);
      k = j; /* Preserve the index value of space found after end of the word */
      j--;
      printf("Length of word to be reversed: %d\n", (j-i+1));
     
      /* Reverse the word */
      for ( ; i < j; i++, j--)
        {
          a[i] = a[i] ^ a[j];
          a[j] = a[i] ^ a[j];
          a[i] = a[i] ^ a[j];
        }
     
      printf("String after iteration %d: %s\n", i, a);
      /* Adjust i and j to process next word in the string */
      i = k;
      j = k+1;
    }
  
  a[len] = '\0';
}

int main()
{
  char str[100];
  printf("\nEnter a string of less than 100 characters:");
  scanf("%100[^\n]", str);
  printf("Original String: %s\n", str);
  words_reversed_in_string(str);
  printf("String after each word is reversed: %s\n", str);

  return 0;
}
