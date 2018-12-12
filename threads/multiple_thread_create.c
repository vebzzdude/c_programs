#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *myMultipleThreadCreate(void *vargp)
{
   int *my_argp = (int *)vargp;
   sleep(1);
   printf("Thread %d created\n", *my_argp);
   return 0;
}

int main()
{
  pthread_t thread_id[3];
  int i;
  for (i = 0; i < 3; i++)
    {
      pthread_create(&thread_id, NULL, myMultipleThreadCreate, (void *)&i);
      pthread_join(thread_id, NULL);
    }
  return 0; 
}
