/** Given string: BarryAllen
    Pattern to be reversed: ryA
    Pattern reversed string: BarAyrllen **/

#include <stdio.h>
#include <string.h>

int string_length(char *str)
{
  int len;
  if (str == NULL)
    return 0;

  for(len = 0; str[len] != '\0'; len++);

  return len;
}

int string_comparison(char *str1, char *str2, int len)
{
  for ( len = len - 1; len >= 0 ; len--)
    {
      if (str1[len] != str2[len])
        return -1;
    }

  return 0;
}

int string_reverse(char *str, int pos, int len)
{
  int k = pos, l = pos+len-1;

  for (; k < l; k++, l--)
    {
        *(str+k) = *(str+k) ^ *(str+l);
        *(str+l) = *(str+k) ^ *(str+l);
        *(str+k) = *(str+k) ^ *(str+l);
    }
}

void inplace_pattern_rev(char *str, char *pattern)
{
  int len1, len2, i, j, k;

  if (str == NULL || pattern == NULL)
    return;

  len1 = string_length(str);
  len2 = string_length(pattern);

  for (i = 0; str[i] != '\0'; i++)
    {
      if (string_comparison(&str[i], pattern, len2) == 0)
        {
          string_reverse(str, i, len2);
        }
    }
}

int main()
{
  char str[100] = "BarryAllen";
  char pattern[10] = "ryA";

  printf("Given string: %s\nPattern to be reversed: %s\n", str, pattern);
  inplace_pattern_rev(str, pattern);
  printf("Pattern reversed string: %s\n", str);

  return 0;
}
