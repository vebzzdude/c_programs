#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
  int n, i, j, val = 1, max;
  printf("Enter no. of rows(or columns) in magic square:");
  scanf("%d", &n);
  max = n * n;
  int a[n][n];

  /* Initialise all elements in matrix with 0 */ 
  memset(&a, 0, sizeof(a));
  i = n-1;
  j = n/2;

  while(1)
    {
          if (a[i][j] == 0)
            {
              a[i][j] = val;
              ++val;

              i = (i+1)%n;
              j = (j+1)%n;
            }
          else if (a[i][j] != 0)
            {
              i = (i-2+n)%n;
              j = (j-1+n)%n;
            }
         
          if (val > max)
            break;
    }

  printf("\nResultant Magic Square:\n");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          printf("%d\t", a[i][j]);
        }
      printf("\n");
    }
  printf("\n");
  return 0;
}

