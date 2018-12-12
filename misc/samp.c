#include<stdio.h>

void myalloc(char **a)
{
  *a  = "iamastring";
}

void main(void)
{
  char *str = "hey";
  printf("Before myalloc - str = %s\n", str);
  myalloc(&str);
  printf("After myalloc - str = %s\n", str);
}
