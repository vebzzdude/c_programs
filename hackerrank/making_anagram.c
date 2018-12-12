#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the makeAnagram function below.
int makeAnagram(char* a, char* b) {

  int len1 = strlen(a), len2 = strlen(b), i = 0, j = 0;
  char str1[len1], str2[len2];
  memcpy(str1, a, len1+1);
  memcpy(str2, b, len2+1);

  for (i=0; i<len1; i++)
     {
       for (j=0; j<len2; j++)
          {
            if(str1[i] == str2[j])
              {
                memmove(&str1[i], &str1[i + 1], len1-i+1);
                memmove(&str2[j], &str2[j + 1], len2-j+1);
                len1 = strlen(str1);
                len2 = strlen(str2);
                i = 0;
              }
          }
     }

    return len1+len2;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* a = readline();

    char* b = readline();

    int res = makeAnagram(a, b);

    fprintf(fptr, "%d\n", res);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

