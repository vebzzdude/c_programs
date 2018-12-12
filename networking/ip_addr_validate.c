#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
  int i = 0, retv = 0;
  struct in_addr router_id;

  if (argc != 2)
    {
      printf("Usage: ./ip_addr_validate <IP Address>\n");
      exit(EXIT_FAILURE);
    }

  for (i = 0; i < argc; i++)
       printf("argv[%d] =  %s\n", i, argv[i]);

  retv = inet_pton(AF_INET, argv[1], &router_id);


  if (!retv)
    printf("retv = %d, router_id = %lu, Invalid IP entered\n", retv, router_id);
  else
   printf("retv = %d, router_id = %lu, Valid IP entered\n", retv, router_id);
  
  return 0;
}
