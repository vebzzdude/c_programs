#include <stdio.h>

#define MAX_SIZE 100
#define ALPHABETS 26

int main()
{
  char str[MAX_SIZE], ch;
  int arr[ALPHABETS], i, var = 0;

  for (i = 0; i < ALPHABETS; i++)
    {
      arr[i] = 0;
    }

  printf("Enter a string:");
  scanf("%[^\n]%*c", str);
  printf("Entered String: %s\n", str);

  for (i = 0; str[i]!='\0'; i++)
    {
      arr[str[i]-97]++;
      if (var < arr[str[i]-97])
        {
          ch = str[i];
          var = arr[str[i]-97];
        }
    }
 
  for (i = 0; i < ALPHABETS; i++)
    {
      printf("%c = %d\n", (i+97), arr[i]);
    }
  
  printf("Highest repeating character = %c with count = %d\n", ch, var);

  return 0;
}
