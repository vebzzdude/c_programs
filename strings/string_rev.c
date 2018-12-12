#include <stdio.h>
#include <ctype.h>

void string_reverse(char *a)
{
  int i, j, len = 0, vowels = 0, consonants = 0;

  // Calculate string length
  for (len = 0; a[len] != '\0'; len++)
     {
       if ((a[len] >= 'a' && a[len] <= 'z')
           || (a[len] >= 'A' && a[len] <= 'Z'))
         {
           if (a[len] == 'a' || a[len] == 'A'
               ||a[len] == 'e' || a[len] == 'E'
               ||a[len] == 'i' || a[len] == 'I'
               ||a[len] == 'o' || a[len] == 'O'
               ||a[len] == 'u' || a[len] == 'U')
             {
               vowels++;
             }
           else
             {
               consonants++;
             }
         }
     }
  a[len] = '\0';
  printf("String length = %d; Vowels = %d; Consonants = %d\n", len, vowels, consonants);

  /* String Reverse without temp variable */
  for (i = 0, j = len-1; i < j ; i++, j--)
     {
       a[i] = a[i] ^ a[j];
       a[j] = a[i] ^ a[j];
       a[i] = a[i] ^ a[j];
     }
  a[len] = '\0';


/*
  for (i = 0, j = len-1; i < j ; i++, j--)
     {
       *(a+i) = *(a+i) ^ *(a+j);
       *(a+j) = *(a+i) ^ *(a+j);
       *(a+i) = *(a+i) ^ *(a+j);
     }

 *(a + len) = '\0';
*/

  /* String Reverse with temp variable */
  /*
  for (i = 0, j = len-1; i < j ; i++, j--)
     {
       char temp;
       temp = a[i];
       a[i] = a[j];
       a[j] = temp;
     }
  
  */
}

int main()
{
  char str[100];
  printf("\nEnter a string of less than 100 characters:");
  scanf("%20[^\n]", str);
  printf("Original String: %s\n", str);
  string_reverse(str);
  printf("Reversed String: %s\n", str);

  return 0;
}
