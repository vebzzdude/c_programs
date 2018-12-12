#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *myThreadCreate(void *argvp)
{
  sleep(1);
  printf("Thread is created.\n");
  return NULL;
}

int main()
{
  pthread_t thread_id;
  printf("Before Thread is created...\n");
  pthread_create(&thread_id, NULL, myThreadCreate, NULL);
  pthread_join(thread_id, NULL);
  printf("After Thread..\n");
  return 0;
}
