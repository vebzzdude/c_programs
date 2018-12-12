#include<stdio.h>

int main(int argc, char **argv[])
{
  printf("%s\n", **argv);
  //printf("%c\n", **++argv);
  return 0;
}
