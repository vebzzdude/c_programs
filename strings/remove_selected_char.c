/* Remove character 'o' from a given string "hello  world" to "hell wrld" */

#include<stdio.h>
#include<string.h>

int main()
{
  int i = 0, count = 0, len = 0;
  //char a[15] = "hello  world";
  char a[15];

  printf("Enter a string (with less than 15 characters):");
  scanf("%[^\n]%*c", a);
  len = strlen(a);

  for (i=0; a[i]!='\0'; i++)
  {
    if (a[i] == 'o')
      memmove(&a[i], &a[i+1], len - i);
  }

  printf ("Squeezed string = %s\n",a);
  return 0;
}
