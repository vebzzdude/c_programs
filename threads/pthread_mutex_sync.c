#include<stdio.h>
#include<pthread.h>

#define NUM_LOOPS 50000000
long long sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *counting_thread(void *arg)
{
  long long i;
  int offset = *(int *)arg;

  for (i = 0; i < NUM_LOOPS; i++)
     {
       pthread_mutex_lock(&mutex);
       sum += offset;
       pthread_mutex_unlock(&mutex);
     }
  pthread_exit(NULL); 
}

int main()
{
  pthread_t tid1;
  int offset1 = 1;
  pthread_create(&tid1, NULL, counting_thread, (void *)&offset1);

  pthread_t tid2;
  int offset2 = -1;
  pthread_create(&tid2, NULL, counting_thread, (void *)&offset2);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  
  printf("\nSum = %lld\n", sum);

  return 0;
}
