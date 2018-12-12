#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


/*Thread Function to calculate sum from 0 to N*/
void *sum_runner(void *arg)
{
 long long *limit_ptr =  (long long *)arg;
 long long limit_val = *limit_ptr;
 free(arg);

 long long i;
 long long sum = 0;

 for (i = 0; i <= limit_val; i++)
   {
     sum += i;
   }

 //Pass back data in dynamically allocated memory
 long long *answer =(long long *)malloc(sizeof(*answer));
 *answer = sum; 
 pthread_exit(answer);
}

int main(int argc, char **argv[])
{
  if (argc != 2)
    {
      printf("\nUsage: %s   <num>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

  //Thread ID
  pthread_t tid;

  // Thread attributes
  pthread_attr_t attr;

  //Initialize thread attributes
  pthread_attr_init(&attr);

  long long *limit = (long long *)malloc(sizeof(*limit));
  *limit = atoll((char *)argv[1]);

  // Create a Thread
  pthread_create(&tid, &attr, sum_runner, (void *)limit);
//  pthread_create(&tid, &attr, sum_runner, limit); // Also does the same job. Need not type cast limit to (void *)

  //Wait for the thread to finish its task
  long long *result;
  pthread_join(tid, (void**)&result);
  printf("Sum = %lld\n", *result);
  free(result);
  return 0;
}
