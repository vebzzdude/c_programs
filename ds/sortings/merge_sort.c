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

/* Below logic currently works only for even number of elements in the given array */
void merge_sort(int a[], int n)
{
  int i, j, l1, l2, u1, u2, k = 0;
  int temp[n];

  /* size is the max. no. of elements in each sub array before merge */
  int size = 1;

  while (size < n)
  {
    k = 0;
    l1 = 0;
   while (l1 + size < n)
      {
    /* u1 is the last element in the subarray based on l1 and size */
    u1 = l1 + size - 1;
    /* l2 is the next element of u2 */
    l2 = u1 + 1;
    /* u2 is the last element in the subarray based on l2 and size. It can be extracted just like u1 */
    u2 = l2 + size - 1;

    /* Set upper2 to maximum index if it exceeds or equals the value of total number of elements */
    if (u2 >= n)
      {
        u2 = n - 1;
      }

    i = l1;
    j = l2;

    while (i <= u1 && j <= u2)
      {
        if (a[i] <= a[j])
          {
            temp[k] = a[i];
            i++;
          }
        else
          {
            temp[k] = a[j];
            j++;
          }
        k++;
      }

     while (i <= u1)
       {
         temp[k] = a[i];
         i++;
         k++;
       }

     while (j <= u2)
       {
         temp[k] = a[j];
         j++;
         k++;
       }

    /* Move l1 to appropriate location */
    l1 = u2 + 1;
  }

  for (i = 0; i < n; i++)
     {
       a[i] = temp[i];
     }

  /* Double the sub array size */
  size = size * 2;
  }
}

int main()
{
int a[20], n;

printf("\nEnter no. of elements:");
scanf("%d", &n);

printf("\nEnter %d Array elements:\n", n);
accept(a, n);

printf("\nArray elements before Merge Sort:\n");
display(a, n);

merge_sort(a, n);

printf("\nArray elements after Merge Sort:\n");
display(a, n);

return 0;
}
