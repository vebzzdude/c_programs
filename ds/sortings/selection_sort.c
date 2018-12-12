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

void selection_sort(int a[], int n)
{
  int i, j, loc, temp;

  for (i = 0; i < n-1; i++)
     {
       loc = i;
       for (j = i+1; j < n; j++)
          {
	    /* Find the location of smallest element in the array */
	    if (a[loc] > a[j])
	      {
		loc = j;
	      }
	  }
	/* Swap the smallest element to ith position i.e., to the end of sorted portion of array */
	if (loc != i)
	  {
	    temp = a[loc];
            a[loc] = a[i];
            a[i] = temp;
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

printf("\nArray elements before Selection Sort:");
display(a,n);

selection_sort(a,n);

printf("\nArray elements after Selection Sort:");
display(a,n);

return 0;
}
