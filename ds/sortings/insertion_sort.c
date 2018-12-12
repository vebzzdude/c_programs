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

void insertion_sort(int a[], int n)
{
  int i, j, temp;

  for (i = 1; i < n; i++)
     {
       for (j = i; ((j > 0) && (a[j] < a[j-1])); j--)
          {
	    temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
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

printf("\nArray elements before Insertion Sort:");
display(a,n);

insertion_sort(a,n);

printf("\nArray elements after Insertion Sort:");
display(a,n);

return 0;
}
