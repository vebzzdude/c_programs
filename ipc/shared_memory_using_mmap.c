/* Shared Memory in C using mmap 
   Source: Jacob Sorber
   YouTube Video: https://www.youtube.com/watch?v=rPV6b8BUwxM */

#include <stdio.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int value = 5;

int main()
{
  int *shared_memory = mmap(NULL, PAGE_SIZE,
                            PROT_READ|PROT_WRITE,
                            MAP_SHARED | MAP_ANONYMOUS, -1, 0 );
  *shared_memory = 34;

  if (fork() == 0)
  {
    /* Child Process */
    value = 23;
    *shared_memory = 49;
  }
  else
  {
    /* Parent Process */
    wait(NULL);    /* Wait for all Child processes to complete */ 
  }

  printf("Varaible NOT shared b/w Parent & Child processes--> value = %d\n", value);
  printf("Varaible shared b/w Parent & Child processes--> shared_memory = %d, address of shared_memory = %lu\n", *shared_memory, shared_memory);
  
  return 0;
}

