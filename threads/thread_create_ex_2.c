#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

pthread_t tid[2];

void *doSomething(void *arg)
{
 unsigned long i = 0;
 pthread_t thread_id;
 thread_id = pthread_self();
 
 if (pthread_equal(thread_id, tid[0]))
   {
     printf("\nFirst thread is processing\n");
   }
 else if (pthread_equal(thread_id, tid[1]))
   {
     printf("\nSecond thread is processing\n");
   }
 
 for(i = 0; i < 0xFFFFFFFF; i++);

 if (pthread_equal(thread_id, tid[0]))
   {
     printf("\nFirst thread finished\n");
   }
 else if (pthread_equal(thread_id, tid[1]))
   {
     printf("\nSecond thread finished\n");
   }

}

int main()
{
  int i = 0, ret;
  
  while( i < 2)
  {
    ret = pthread_create(&tid[i], NULL, doSomething, NULL);

    if (ret == 0)
      {
        printf("\nThread %d is created successfully\n", i+1);
      }
    else
      {
        printf("\nThread %d is not created successfully: %s\n", i+1, strerror(ret));
      }
    i++;
  }

    pthread_join(tid[0], 0);
    pthread_join(tid[1], 0);
//  sleep(5);
  return 0;
}
