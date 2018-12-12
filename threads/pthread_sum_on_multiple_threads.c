#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

struct sum_runner_struct
{
   long long limit;
   long long answer;
};


/*Thread Function to calculate sum from 0 to N*/
void *sum_runner(void *arg)
{
 struct sum_runner_struct *arg_struct =  (struct sum_runner_struct *)arg;
 long long i, sum;

 for (i = 0; i <= arg_struct->limit; i++)
   {
     sum += i;
   }
 arg_struct->answer = sum;
 pthread_exit(0); 
}

int main(int argc, char **argv[])
{
  if (argc < 2)
    {
      printf("\nUsage: %s <num 1> <num 2> <num 3> ...... <num n>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

  int num_args = argc -1, i;
  //Thread IDs
  pthread_t tids[num_args];

  // Thread attributes
  pthread_attr_t attr[num_args];

  struct sum_runner_struct args[num_args];

  for (i = 0; i < num_args; i++)
    {
      //Values passed at command line 
      args[i].limit = atoll((char *)argv[i+1]);
      //Initialize thread attributes
      pthread_attr_init(&attr[i]);
      // Create Threads
      pthread_create(&tids[i], &attr[i], sum_runner, (void *)&args[i]);
    }

  //Wait until all threads finish their tasks
  for (i = 0; i < num_args; i++)
    {
      pthread_join(tids[i], NULL);
      printf("Sum  = %lld\n", args[i].answer);
    }

  return 0;
}
