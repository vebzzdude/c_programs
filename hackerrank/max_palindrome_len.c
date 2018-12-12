#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxPalindrome(char *str)
{
  int len = strlen(str), maxlen = 1;
  char str2[len];
  int i, j, k, len2 = 0;

  for (i = 1; i <=len; i++)
    {
      for (j = 0; j < i; j++)
        {
          strncpy(str2, &str[j], i);
          str2[i] = '\0';
          len2 = strlen(str2);
          if (isPalindrome(str2) && maxlen < len2)
            {
              maxlen = strlen(str2);
            }
          printf("str2[%d] = %s, len2 = %d, maxlen = %d\n",i, str2, len2, maxlen);
        }
    }

  return maxlen;
}

int isPalindrome(char *a)
{
  int i, j, len = 0;
  len = strlen(a);

  for (i = 0, j = len -1; i < j ;i++, j--)
    {
      if (a[i] != a[j])
        return 0;
    }

  return 1;

}


int main()
{
  char *s = "bandana";
  maxPalindrome(s);
  
  return 0;
}
