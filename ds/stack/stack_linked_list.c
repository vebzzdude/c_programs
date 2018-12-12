#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int data;
  struct stack *next;
};

struct stack *top = NULL;

void push(int x)
{
  struct stack *node = NULL;
  node =  (struct stack *)malloc(sizeof(node));
  node->data = x;

  if (top == NULL)
    {
      top = node;
      top->next = NULL;
    }
  else
    {
      node->next = top;
      top = node;
    }

/*
Above if else can be replaced with
      node->next = top;
      top = node;
as 'top' is initialised to NULL. No need to check for top explicitly
*/

  printf("Element %d inserted in stack\n", x);
}

int pop()
{
  struct stack *nd = NULL;
  int x;

  if (top == NULL)
    {
      printf("Stack underflow\n");
      return -1;
    }

  nd = top;
  x = nd->data;

  top = top->next;
  free(nd);
  return x;
}

void display()
{
  struct stack *nd = NULL;
  nd = top;

  while (nd != NULL)
    {
      printf("%d\t",nd->data);
      nd = nd->next;
    }
  printf("\n");
}

int main()
{

  int opt, n, x;
  while(1)
    {
      printf("\t\t\t\tMENU\n");
      printf("\t\t\t====================\n");
      printf("\t\t\t\t1. PUSH\n");
      printf("\t\t\t\t2. POP\n");
      printf("\t\t\t\t3. DISPLAY\n");
      printf("\t\t\t\t4. EXIT\n");
      printf("\t\t\t====================\n");

      printf("Enter your option:");
      scanf("%d", &opt);

      switch(opt)
        {
          case 1:
                printf("Enter value to be inserted:");
                scanf("%d",&n);
                push(n);
                break;
          case 2:
                x = pop();
                if (x != -1)
                  {
                    printf("Element %d is deleted from stack\n", x);
                  }
                break;
          case 3:
                display();
                break;
          case 4:
                exit(EXIT_SUCCESS);
          default:
                exit(EXIT_SUCCESS);
        }
      
    }
}
