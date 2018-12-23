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
  char msgs[3][30] = {"Hello!", "My name is Barray Allen and ", "I am the fastest man alive."};

  char input_buffer[100];

  if (pipe(fd) < 0)
    {
       perror("Pipe failure!");
       exit(EXIT_FAILURE);
    }

  /* Write the messages into a virtual file using write file descriptor */
  for (i = 0; i < 3; i++)
    {
      write(fd[1], msgs[i], string_length(msgs[i]));
    }

  /* Read the messages from the virtual file,
   * Copy it into input_buffer and
   * Print it.
   */
  for (i = 0; i < 3; i++)
    {
      read(fd[0], input_buffer, string_length(msgs[i]));
      printf("%s\n", input_buffer);
    }

  return 0;
}
