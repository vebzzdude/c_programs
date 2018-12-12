
#include <stdio.h>

int main()
{
  char str[] = "vebzzdude";
  char *ptr;
  ptr = str;  // ptr = &str[0];

  void *ptr1;
  ptr1 = &ptr;
  
  void *ptr2;
  ptr2 = &ptr1;
  
  printf("%s\n", ptr);  //printf("%s\n", (char *)ptr);

  //printf("%s\n", ?ptr1);  Replace '?' mark with correct answer
  printf("%s\n", *(char **)ptr1);

  //printf("%s\n", ?ptr2);  Replace '?' mark with correct answer
  printf("%s\n",  **(char ***)ptr2);
}

/*
Output required:
================
vebzzdude
vebzzdude
vebzzdude
*/
