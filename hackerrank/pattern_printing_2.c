#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
// Complete the code to print the pattern.
  int n;
  scanf("%d", &n);

  if (n < 1 || n > 1000)
    {
      exit(EXIT_FAILURE);
    }

  int row = 0, col = 0, temp = n;
  int max_rows_cols = (2 * n)- 1;
  int start_index = 0;
  int end_index = max_rows_cols;

  int a[max_rows_cols][max_rows_cols];

  for (row = start_index; row <  end_index ;)
     {
       for (col = start_index; col < end_index; col++)
          {
            if (row == start_index
                || col == start_index
                || row ==  (end_index-1)
                || col == (end_index-1))
              {
                a[row][col] = temp;
              }
            else
              {
                a[row][col] = 0;
              }
          }

        row++;
        if (row ==  end_index && col == end_index)
          {
            temp--;
            start_index++;
            end_index--;

            row = start_index;
            col = start_index;
          }
     }

  for (row = 0; row <  max_rows_cols; row++)
     {
       for (col = 0 ; col < max_rows_cols; col++)
          {
            printf("%3d", a[row][col]);
          }
       printf("\n");
     }

    return 0;
}
