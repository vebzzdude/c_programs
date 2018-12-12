#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int i = 0;
void doSomeStuff(char *name)
{
  const int NUM_LOOPS = 5;
  //int i;
  
  for (; i < NUM_LOOPS; i++)
    {
      sleep(rand() % 4);
      printf("Done with pass %d in %s\n",i,name);
    }
}

int main()
{
  printf("I am process with pid %d in func %s() at line %d\n",(int)getpid(), __FUNCTION__, __LINE__);

  sleep(5);

  pid_t pid = fork();
  srand((int)pid);
  printf("fork() returned a value: %d\n", (int)pid);

  if (pid < 0)
    {
      perror("Fork failed !!");
      exit(EXIT_FAILURE);
    }
  else if(pid == 0)
    {
      printf("I am Child process with pid %d in func %s() at line %d\n",(int)getpid(), __FUNCTION__, __LINE__);
      doSomeStuff("Child");
      exit(49);
    }
  else if (pid > 0)
    {
      printf("I am Parent process with pid %d in func %s() at line %d\n",(int)getpid(), __FUNCTION__, __LINE__);
    }

  // We must be the parent
  printf("I am the Parent, waiting for child to end\n");
  sleep(10);

  int status = 0;
  pid_t childpid = wait(&status);
  printf("Parent knows that child with pid %d finished with status %d\n", (int)childpid, status);

  int childReturnVal = WEXITSTATUS(status);
  printf("Return value was %d\n", childReturnVal);
  sleep(10);

  return 0;
}
