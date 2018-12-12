#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void *a, const void *b)
{
  int A = *((int *)a);
  int B = *((int *)b);
  return abs(A) - abs(B);
}


int main()
{
  int i, A[] = {-4, 7, -22, 3, -1, 9, 2}, ele = 7;
  qsort(A, ele, sizeof(int), compare);
  for (i = 0; i < ele; i++)
    {
      printf("%d\t",A[i]);
    }
  printf("\n");  
  return 0;
}
