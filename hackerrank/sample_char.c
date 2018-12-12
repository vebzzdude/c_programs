#include <stdio.h>
#include <string.h>

int main()
{
  char *str1 = "abc";
  char *str2 = "cde";
  int len1 = strlen(str1), len2 = strlen(str2), i = 0, j = 0;
  char str3[len1], str4[len2];
  memcpy(str3, str1, len1+1);
  memcpy(str4, str2, len2+1);
  printf("len1 = %d, len2 = %d\n", len1, len2);

  for (i=0; i<len1; i++)
     {
       for (j=0; j<len2; j++)
          {
            if(str3[i] == str4[j])
              {
                memmove(&str3[i], &str3[i + 1], len1-i);
                memmove(&str4[j], &str4[j + 1], len2-j);
                len1 = strlen(str3+1);
                len2 = strlen(str4+1);
                i = 0;
              }
          }
     }



  printf("str1: %s; str2 = %s\n", str1, str2);
  printf("str3: %s; str4 = %s\n", str3, str4);
  printf("\nResult: %d\n", len1+len2);
  return 0;
}
