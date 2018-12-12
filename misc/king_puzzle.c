#include <stdio.h>

int main()
{
  int i =0,  j, count = 0, num,  king, sword, surv_count;

  printf("\nEnter no. of people standing in circle:");
  scanf("%d", &num);

  printf("\nEnter how many people to be survived:");
  scanf("%d", &surv_count);

  printf("\nEnter which person holds the sword first:");
  scanf("%d", &sword);

  count = num;
  int a[num];
  printf("Initial array:\n");
  for (i = 0; i < num; i++)
     {
       a[i] = i + 1;
        printf("%5d", a[i]);
     }
  printf("\n");

  /* king is an index value. Hence -1 */
  king = sword-1;
  while (1)
    {
      j = (king + 1)%num ;

      while(a[j] == 0)
        j = (j+1)%num ;

      if (a[j] != 0)
        {
          a[j] = 0;
          --count;

          if (count == surv_count)
            break;

          king = (j+1)%num ;

          while (a[king] == 0)
              king = (king+1)%num ;
        }
    }
  
  printf("Total survivors: %d\n", surv_count); 
  printf("Safe Position (Person finally holding the sword): %d\n", king+1);
  printf("Survivors list:\n");
  for (i = 0; (i < num); i++)
     {
       if (a[i] !=  0)
         printf("%5d", a[i]);
     }

  printf("\n");

  return 0;
}
