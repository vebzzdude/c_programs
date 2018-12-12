#include<stdio.h>

void PrintHello()
{
  printf("Hello!\n");
}

void PrintHi(char *name)
{
   printf("Hi %s!\n", name);
}

int Add(int a, int b)
{
   return (a+b);
}

int main()
{
  int c;
  int (*p)(int, int);

  p = &Add;   /*  p = Add; */
  c = (*p)(2, 7); /* c = p(2,7); */

  printf("res = %d\n",c);
 
  void (*func1)();
  func1 = PrintHello;
  func1();

  void (*func2)(char *);
  func2 = PrintHi;
  func2("Vebzzdude");
 
  return 0;
}

