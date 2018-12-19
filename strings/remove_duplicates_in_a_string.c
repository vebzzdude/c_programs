/* Program to remove duplicate characters in a given string
 *
 * Input:   My name is Barry Allen and I am the fastest man alive!
 * Output:  My nameisBrAldIthfv!
 */

#include <stdio.h>
#include <string.h>

/* Total number of ASCII characters */
#define MAX_CHARS 256

/* Maximum number of characters in a string */
#define MAX_LEN  100

/* Function to remove duplicate characters in a given string */
void * remove_duplicate(char *str)
{
  /* Declare an array with 257 (256+1 as index starts from 0)
   * number of elements and initialize all elements to '0'
   */
  short int val[MAX_CHARS] = {0};
  int len = 0, i = 0;

  /* Calculate the length of string */
  for(len = 0; str[len] != '\0'; len++);

  /* Traverse string */
  for (i = 0; str[i] != '\0'; i++)
    {
      /* If a character is visited, mark the corresponding
       * index in 'val' array to '1'.
       */
      if (val[str[i]] == 0)
        {
          val[str[i]] = 1;
        }
      /* If the value of corresponding character's position(index)
       * in 'val' array is '1', it means that it is a duplicate
       * character. So, remove the character from the string.
       */
      else if (val[str[i]] == 1)
        {
          memmove(&str[i], &str[i+1], len-i);

          /* Decrement 'i' by '1' which makes the new character at
           * current index is traversed.
           */
           i--;
        }
    }
  return str;
}

int main()
{
  char a[MAX_LEN];
  char *s = NULL;
  printf("Enter a string:");
  scanf("%[^\n]%*c", a);
  s = remove_duplicate(a);
  printf("Resultant string: %s\n", s);
  return 0;
}
