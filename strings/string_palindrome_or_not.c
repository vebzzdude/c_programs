#include <stdio.h>

void string_palindrome(char *a)
{
  int i, j, len = 0;

  // Calculate string length
  for (len = 0; a[len] != '\0';len++);

  printf("String length = %d\n", len);

  for (i = 0, j = len-1; i < j ; i++, j--)
     {
       if (a[i] != a[j])
         {
           printf("Entered string is not a palindrome\n");
           return;
         }
     }

/*
  for (i = 0, j = len-1; i < j ; i++, j--)
     {
       if (*(a+i) != *(a+j))
         {
           printf("Entered string is NOT a Palindrome\n");
           return;
         }
     }

*/

printf("Entered string is a Palindrome\n");
}

int main()
{
  char str[100];
  printf("\nEnter a string of less than 100 characters:");
  scanf("%s", str);
  printf("Entered String: %s\n", str);
  string_palindrome(str);

  return 0;
}
