#include <stdio.h>

int main()
{
 int i = 5;
 i = i++ + ++i;
 printf("%d\n", i);
 return 0;
}
