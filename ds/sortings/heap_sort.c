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
}

void create_heap (int a[], int n)
{
	int x, y, temp, i;
	
	for (i = 1; i < n; i++)
	{
		x = i;
		y = (i-1)/2;
		
		while (x > 0)
		{
			if (a[x] > a[y])
			{
				temp = a[x];
				a[x] = a[y];
				a[y] = temp;
               

			}
		}
	}
}

void heap_sort(int a[], int n)
{
  int b[20], i;

  for (i = 0; i < n; i++)
     {
       b[i] = a[i];
       create_heap(b, i);
     }
}


int main()
{
int a[20], n;

printf("\nEnter no. of elements:");
scanf("%d", &n);

printf("\nEnter %d Array elements:\n", n);
accept(a, n);

printf("\nArray elements before heap sort:");
display(a,n);

heap_sort(a,n);

printf("\nArray elements after heap sort:");
display(a,n);

return 0;
}
