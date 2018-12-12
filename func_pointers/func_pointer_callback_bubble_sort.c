#include<stdio.h>
/*
void BubbleSort(int *A, int n)
{
  int i, j, temp;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n-1; j++)
        {
          if (A[j] > A[j+1])
            {
              temp = A[j];
              A[j] = A[j+1];
              A[j+1] = temp;
            }
        }
    }
}
*/

int compare(int a, int b)
{
  if (a > b)
    return 1;
  else
    return -1; 
}

void BubbleSort(int *A, int n, int (*compare)(int,int))
{
  int i, j, temp;

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n-1; j++)
        {
          if (compare(A[j], A[j+1]) > 0)
            {
              temp = A[j];
              A[j] = A[j+1];
              A[j+1] = temp;
            }
        }
    }
}

int main()
{
  int i, A[] = {4, 7, 6, 3, 1, 9, 2}, ele = 7;
  BubbleSort(A, ele, compare);
  for (i = 0; i < ele; i++)
    {
      printf("%d\t",A[i]);
    }
  printf("\n");  
  return 0;
}
