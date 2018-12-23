#include <stdio.h>
#include <stdlib.h>

int string_length(char *str)
{
  int len = 0;

  for (len = 0; str[len] != '\0'; len++);

  return len;
}

int main()
{
  int fd[2], i = 0;
  /* It is observed that if first string's length is <=3, unknown characters are displayed
   * at the end of it. Need to debug it further
   */
  char msgs[3][30] = {"Hello!", "My name is Barray Allen and ", "I am the fastest man alive."};
  /* char msgs[3][10] = {"H", "oye", "a"}; */ /* This input too gives unexpected output */
  pid_t pid;

  char input_buffer[100];

  if (pipe(fd) < 0)
    {
      perror("Pipe failure");
      exit(EXIT_FAILURE);
    }


  if ((pid = fork()) > 0)
    {
      /* Close read fd before writing */
      close(fd[0]);
      /* Write the messages into a virtual file using write file descriptor */
      for (i = 0; i < 3; i++)
        {
          write(fd[1], msgs[i], string_length(msgs[i]));
        }
      /* Close write fd after writing is finished */
      close(fd[1]);
      /* Wait until the child process exits */
      wait(NULL);
    }
  else
    {
      /* Close write fd before reading */
      close(fd[1]);
      /* Read the messages from the virtual file,
       * Copy it into input_buffer and
       * Print it.
       */
      for (i = 0; i < 3; i++)
        {
          if (read(fd[0], input_buffer, string_length(msgs[i])) > 0)
            printf("%s\n", input_buffer);
        }
      /* Close read fd after reading is finished */ 
      close(fd[0]);
    }

  return 0;
}
