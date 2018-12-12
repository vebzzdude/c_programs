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

void quick_sort(int a[], int lower, int n)
{
  int i, j, pos_ele, temp;

  if (lower < n)
    {
      /* Value of 'i' is always '0' as 'lower' is always '0'.
       * This function doesn't need lower as a parameter.
       * i = 0; can be used directly instead of i = lower;
       */
      i = lower;
      j = n;

      pos_ele = a[lower];

      while (i < j)
        {
          while (pos_ele > a[i])
               i++;

          while (pos_ele < a[j])
               j--;

          if (i < j)
            {
              temp = a[i];
              a[i] = a[j];
              a[j] = temp;
            }

	  quick_sort(a, lower, j-1);
	  quick_sort(a, j+1, n);
        }
    }
}

int main()
{
int a[20], n;

printf("\nEnter no. of elements:");
scanf("%d", &n);

printf("\nEnter %d Array elements:\n", n);
accept(a, n);

printf("\nArray elements before Quick Sort:");
display(a,n);

quick_sort(a,0,n-1);

printf("\nArray elements after Quick Sort:");
display(a,n);

return 0;
}
