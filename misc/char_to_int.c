#include <stdio.h>
#include <stdlib.h>

int main()
{
  char ch = '9';
  int i = (int)ch;
  int j = atoi(&ch);
  int arr[10] = {0};
  printf("ch = %c, i = %d, j = %d\n", ch, i, j);
    for(i = 0; i < 10; i++)
        printf("%d ",arr[i]);
  return 0;
}
