#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

/* Sum calculated by background thread */
long long sum = 0;

/*Thread Function to calculate sum from 0 to N*/
void *sum_runner(void *arg)
{
 long long *limit_ptr =  (long long *)arg;
 long long limit_val = *limit_ptr;
 long long i;

 for (i = 0; i <= limit_val; i++)
   {
     sum += i;
   }

 /* Sum is a global variable. It can be accessed by any thread */
 
 pthread_exit(0); 
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

  long long limit = atoll((char *)argv[1]);

  // Create a Thread
  pthread_create(&tid, &attr, sum_runner, (void *)&limit);

  //Wait for the thread to finish its task
  pthread_join(tid, NULL);

  printf("Sum = %lld\n", sum);
  return 0;
}
