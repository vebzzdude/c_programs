#include <stdio.h>

int z = 19;
extern int y; //It means y is declared and initialised somewhere but want to use here
extern int k = 190;

int main()
{
  auto int x = 32;
  printf("x = %d, y = %d, z = %d, k = %d\n", x, y, z, k);
  return 0;
}
