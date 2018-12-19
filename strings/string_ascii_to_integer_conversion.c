/* Program of own atoi() conversion */
/* The atoi() only convert a numeric string to their integer value */

#include <stdio.h>

int ascii_to_integer (char *str)
{
  int value = 0, i = 0;

  if (str[0] == '-')
    i++;

  for ( ; str[i] != '\0'; i++)
    { 
      if (str[i] < '0' ||  str[i] > '9')
        {
          return 0;
        }

      value = (value)*10 + (str[i] - '0');
    }
  
  return (str[0] == '-') ? (-1 * value): value;
}

int string_length(char *str)
{
  int len = 0;

  if (str == NULL)
    return 0;

  for (len = 0; str[len] != '\0'; len++);

  return len;
}

int main()
{
  char a[15];
  int b = 0, length = 0;

  printf("Enter a string (Max. of 16 characters):");
  scanf("%[^\n]%*c", a);

  /* String length is required for '0' and '-0' cases only */
  length = string_length(a);

  printf("Entered string is: %s\n", a);
  b = ascii_to_integer(a);


  /* ASCII to Integer converted */
  if (b != 0)
    printf("ASCII to Integer converted Value = %d\n", b);
  /* To check whether the entered string is '0' or '-0' */
  else if ((length == 1 && a[0] == '0') || (length == 2 && a[0] == '-' && a[1] == '0'))
    printf("ASCII to Integer converted Value = %d\n", 0);
  /* ASCII to Integer conversion is not possible */
  else
   printf("ASCII to Integer conversion is NOT possible\n");

  return 0;
}
