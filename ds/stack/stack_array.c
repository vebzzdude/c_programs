#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack[MAX], top = -1;

void push(int x)
{

  if (top >= MAX)
    {
      printf("Stack overflow\n");
      return;
    }
  else
    {
      top++;
      stack[top]=x;
    }

  printf("Element %d inserted in stack\n", x);
}

int pop()
{
  int x;

  if (top == -1)
    {
      printf("Stack underflow\n");
      return -1;
    }
  else
    {
      x = stack[top];
      top--;
    }

  return x;
}

void display()
{
  int i;

  if (top == -1)
    {
      printf("Stack underflow\n");
      return;
    }

  for (i = top; i >=0 & i < MAX; i--)
     {
       printf("%d\t", stack[i]);
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
