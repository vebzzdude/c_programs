#include <stdio.h>
#define INT_BITS 32

int multiply(int a, int b)
{
  int pos1, pos2, res, temp;

  for (pos1 = 0; pos1 < INT_BITS; pos1++)
    {
      for (pos2 = 0; pos2 < INT_BITS; pos2++)
        {
          if ((a & (1 << pos1)) && (b & (1 << pos2)))
            {
              //res = res + (1 << (pos1 + pos2));
              // res = res + ((1 << pos1) << pos2);
              /* Both the above statements calculating res does the same */
              temp = (1 << pos1) << pos2;
              res = add(res, temp);
            }
        }
    }

  return res;
}

int add(int x, int y)
{
 int carry;

 while (y != 0)
   {
     carry = x & y;

     x = x ^ y;

     y = carry << 1;
   }

  return x;
}

/*
int add(int x, int y)
{
   if (y == 0)
     return x;
 
   return add(x ^ y, (x & y) << 1);
}
*/
int main()
{
  int num1, num2, product;
  printf("Enter two numbers to be multiplied:");
  scanf("%d %d", &num1, &num2);
  product = multiply(num1, num2);
  printf("Product of %d and %d: %d\n", num1, num2, product);
  return 0;
}
