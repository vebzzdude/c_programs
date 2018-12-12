/* Designated Initialisation */
#include<stdio.h>

int main()
{
//  int a[10] = {0, 0, 0, 20, 0, 0, 0, 0, 35, 0};
  int a[10] = {[3] = 20, [8] = 35};
  int i;

  for (i=0; i<10; i++)
       printf("%d\t", a[i]);

  printf("\n");
  return 0;
}
