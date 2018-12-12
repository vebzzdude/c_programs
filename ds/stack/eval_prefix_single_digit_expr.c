#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int  n)
{
  top++;
  stack[top] = n;
}

int pop()
{
  int n;
  n = stack[top];
  top--;
  return n;
}
int is_operand(char ch)
{
  if (ch >= '0' && ch <= '9')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int eval_operator(char ch)
{
  int a, b, c;
  a = pop();
  b = pop();

  if (ch == '+')
    c = b + a;
  else if (ch == '-')
    c = b - a;
  else if (ch == '*')
    c = b * a;
  else if (ch == '/')
    c = b / a;
  else if (ch == '%')
    c = b % a;
  else if (ch == '^')
    c = b ^ a;
  else
    return 0;

  push(c);
  return 1;
}

void eval_prefix_single_digit_expr(char exp[])
{
  int i, k, len;

  /* Length of expression */
  for(len = 0; exp[len] != '\0'; len++);

  for (i = len-1; i >= 0; i--)
     {
       if ( is_operand(exp[i]) ==  1 )
         {
           push(exp[i] - 48);
         }
       else
         {
           if (top-1 < 0)  // if(top < -1)
             {
               printf("\nInvalid expression\n");
               return;
             }
           k = eval_operator(exp[i]);
           if (k == 0)
             {
               printf("\nInvalid expression\n");
               return;
             }
         }
     }

   if (top > 0)
     {
       printf("Expression is not balanced\n");
     }
   else
     {
       printf("Value of entered prefix expression: %d\n", stack[top]);
     }
}

int main()
{
  char exp_arr[MAX] = "+4*56";
  printf("Entered Prefix Expression:%s\n", exp_arr);
  eval_prefix_single_digit_expr(exp_arr);
  return 0;
}
