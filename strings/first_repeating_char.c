#include <stdio.h>

int first_repeating_char(char *str)
{
  int alphabets_holder = 0, i = 0, value = 0;

  for (i = 0; str[i] != '\0'; i++)
    {
      value = (str[i] - 'a');

      if ((alphabets_holder & (1 << value)) > 0)
        return i;

      alphabets_holder =  alphabets_holder | (1 << value);
    }

  return -1;
}

int main()
{
  char a[200];
  int index = 0;

  printf("Enter a string:");
  scanf("%[^\n]%*c", a);

  index = first_repeating_char(a);
  
  if (index != -1)
    printf("Repeating Character: %c , Index: %d\n", a[index], index);
  else
    printf("No repeating characters in given string\n");

  return 0;
}
