#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int superDigit(char* n, int k) {
  
    unsigned int sum = 0;
    char ch;
    int len = strlen(n), i = 0;
    
    if (k == 0)
        return 0;
    
    for (i = 0; i < len; i++)
    {
        ch = n[i];
        sum = sum + atoi(&ch);
    }    
   
    printf("%d\n", sum); 
    return sum+superDigit(n, k-1);
}

int main()
{
  char *str = "12345";
  int k = 3;
  int result = superDigit(str, k);
  printf("result = %d\n", result);
  return 0;
}
