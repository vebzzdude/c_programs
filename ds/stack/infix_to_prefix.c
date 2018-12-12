#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
  top++;
  stack[top] = ch;
}

char pop()
{
  char ch;
  ch = stack[top];
  top--;
  return ch;
}
int is_operand(char ch)
{
  if ((ch >= 'A' && ch <= 'Z')
      || (ch >= 'a' && ch <= 'z'))
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int operator_precedence(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/' || ch =='%')
    return 2;
  else if (ch == '^')
    return 3;
  else
    return 0;
}

void infix_to_prefix(char exp[])
{
  char res[MAX], ch;
  int i, j, index = 0, len;

  /* Length of expression */
  for(len = 0; exp[len] != '\0'; len++);

  /* Append an open brace '(' at the start of given expression */
  memmove(&exp[1], &exp[0] ,len);
  exp[0] = '(';
  len = len+1;

  /* Push a closed brace ')' to stack at first before starting of conversion.
   * This is to balance the above added open brace '(' to given
   * expression.
   */

  push(')');

  /* Process the expression in reverse */
  for (i = len-1; i>=0; i--)
     {
       if (is_operand(exp[i]) ==  1)
         {
           res[index] = exp[i];
           index++;
         }
       else if (exp[i] == ')')
         {
           push(exp[i]);
         }
       else if (exp[i] == '(')
         {
           while ((ch=pop()) != ')')
             {
               res[index] = ch;
               index++;
             }
         }
       else /* Need to push operator into stack */
         {
           if (operator_precedence(exp[i]) == 0)
             {
               printf("\nInvalid Expression\n");
               return;
             }
           /* If it is not just start of the (sub-section of) expression
            * i.e., if it is in the middle of (sub-section of) expression...
            */ 
           if (stack[top] != ')')
             {
               /* If stack[top] contains an operator with higher or equal precedence,
                * then immediately pop the operator from stack and copy it into
                * resultant array
                */
               if (operator_precedence(stack[top]) > operator_precedence(exp[i]))
                 {
                   ch = pop();
                   res[index] = ch;
                   index++;
                 }
             }
           /* Push operator into stack */
           push(exp[i]); 
         }
     }
  
  res[index] = '\0';

  /* Reverse the resultant expression for proper result*/
  for (i = 0, j = index-1; i <j; i++, j--)
     {
       printf("res[%d] = %c, res[%d] = %c\n", i, res[i], j, res[j]);
       res[i] = res[i] ^ res[j];
       res[j] = res[i] ^ res[j];
       res[i] = res[i] ^ res[j];
     }

  printf("\nResultant Infix to Prefix Expression: %s\n",res);
}

int main()
{
  char exp_arr[MAX] = "a+b*(c/(d-e^f)%g)-h", i;
/*
  printf("Enter an Infix Expression:");
  while(getchar() != '\n');
  for(i = 0; exp_arr[i] != '\0'; i++)
    {
      exp_arr[i] = getchar();
    }
*/
  printf("Entered Infix Expression:%s\n", exp_arr);

  infix_to_prefix(exp_arr);
  return 0;
}
