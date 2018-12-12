#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int i, j, arr[10] = {0};
    char *num = "1234sttingstring92lwertsg#2@";
    char ch;
    printf("string = %s\n", num);

 
    for (i = 0; num[i]!='\0'; i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            ch = num[i];
            arr[atoi(&ch)]++;
        }
    }
    for(i = 0; i < 10; i++)
        printf("%d ",arr[i]);
    printf("\n"); 
    return 0;
}

