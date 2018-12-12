#include <stdio.h>
#include <stdlib.h>

void accept(int a[], int n)
{
 int i = 0;
 for (i = 0; i < n; i++)
    {
	scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
 int i = 0;
 for (i = 0; i < n; i++)
    {
	printf("%d\t", a[i]);
    }
 printf("\n");
}

int digit(int n, int d)
{
  int i;

  for (i = 1; i < d; i++)
     {
       n =  n/10;
     }

  /* Return Face value of the number at given place */
  return n%10;
}

void radix_sort(int a[], int n)
{
  int i, j, k, x, big = 0, index, nd = 0;
  int temp[n];

  /* Find the Biggest element in the array */
  for (i = 0; i <n; i++)
     {
      if (big < a[i])
        big = a[i];
     }

  /* Find the no. of digits in the biggest element */
  while (big > 0)
    {
      nd++;
      big = big/10;
    }

  /* Process at each place of number (starting from unit's place) */
  for (i = 1; i < nd; i++)
     {
       index = 0;
       for (j = 0; j <=9 ; j++)
         {
           for (k = 0; k < n; k++)
             {
               /*  Compare Face value of the number in array at given place  */ 
               if (j == digit(a[k], i))
                 {
                   temp[index] = a[k];
                   index++;
                 }
             }
         }
       for (x = 0; x < n; x++)
         {
           a[x] = temp[x];
         }
//       display(a, n);
     }

}

int main()
{
int a[20], n;

printf("\nEnter no. of elements:");
scanf("%d", &n);

printf("\nEnter %d Array elements:\n", n);
accept(a, n);

printf("\nArray elements before Radix Sort:");
display(a, n);

radix_sort(a, n);

printf("\nArray elements after Radix Sort:");
display(a, n);

return 0;
}
