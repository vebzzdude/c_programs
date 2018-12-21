#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>

int main(void)
{
  /* Declare a shared memory variable using mmap
   * which is available to all parent and child
   * processes
   */
  int *shared = mmap(NULL, 32, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);
  int i = 0;
  pid_t pid;

  *shared = 0;

  for (i=0; i < 3; i++)
    {
      pid = fork();

      /* Increment variable 'shared' only if it is a child process */
      if (pid == 0)
        *shared = *shared + 1;

        wait(NULL);
    }
 
  /* Greatest value of variable 'shared' is the total number of
   * Child Processes that are created
   */
  if (pid == 0)
    printf("I am Child Process: %d with process id: %lu\n", *shared, getpid());

  return 0;
}
