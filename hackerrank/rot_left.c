#include <stdio.h>
#include <stdlib.h>
/*
void rotLeft(int num_array[], int s, int rot)
{
  int temp, j, c;

for (c = 1 ; c <= rot; c++)
 { 
  for(j=0; j<s-1; j++)
     {
       temp = num_array[j];
       num_array[j] = num_array[j+1];
       num_array[j+1] = temp;
     }
  printf("\nArray after rotation %d:\n",c);
  
  for(j=0; j<s; j++)
     printf("%d\t",num_array[j]);
 }

 //   return num_array;
}
*/

void rotLeft(int num_array[], int s, int rot)
{
  int temp, i, j, c;

  for(c=1, i=0; c <= rot || i<s-1; c++, i++)
     {
       temp = num_array[i];
       num_array[i] = num_array[i+1];
       num_array[i] = temp;
     }
//  printf("\nArray after rotation %d:\n",);

  printf("\n");
  for(i=0; i<s; i++)
     printf("%d\t",num_array[i]);

//  return num_array;
}
int main()
{
int size = 0, rotations = 0, i = 0;

printf("\nEnter array size and no. of rotations seperated by space:");
scanf("%d %d", & size, &rotations);

int *b;
b = (int *)malloc(size * sizeof(int));
printf("\nEnter %d elements each seperated by space:", size);
for (i = 0; i < size; i++)
   {
     scanf("%d", (b+i));
   }

printf("\nEntered Array:\n");
for (i = 0; i < size; i++)
   {
     printf("%d\t", *(b+i));
   }


rotLeft(b, size, rotations);

printf("\nResultant Array:\n");

for (i = 0; i < size; i++)
   {
     printf("%d\t", *(b+i));
   }
printf("\n");

free(b);
return 0;
}
