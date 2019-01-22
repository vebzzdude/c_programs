/* Squeeze a given string "hello  world" to "hello wrld" */

#include<stdio.h>
#include<string.h>

#define SET_FLAG(V, POS) ((V) = (V) | (1 << POS))
#define UNSET_FLAG(V, POS) ((V) = (V) & ~(1 << POS))
#define CHECK_FLAG(V, POS) ((V) & (1 << POS)  == (1 << POS))

int main()
{
  int i = 0, count = 0, len = 0;
  //char a[15] = "hello  world";
  char a[15];

  printf("Enter a string (with less than 30 characters):");
  scanf("%[^\n]%*c", a);
  len = strlen(a);

  /* If character is 'o', Set bit at 0th position in 'count' variable.
   * If character is ' ', Set bit at 1st position in 'count' variable.
   */
  for (i=0; a[i]!='\0'; i++)
  {
    if ((a[i] == 'o' && CHECK_FLAG(count, 0)) || (a[i] == ' ' && CHECK_FLAG(count, 1)))
    {
        memmove(&a[i], &a[i+1], len - i);
    }

    if (a[i] == 'o')
      SET_FLAG(count, 0);

    if (a[i] == ' ')
       SET_FLAG(count, 1);
  }

  printf ("Squeezed string = %s\n",a);
  return 0;
}
