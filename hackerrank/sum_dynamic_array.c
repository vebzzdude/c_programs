#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int nums = 0, i = 0, sum = 0;
    int * num_array;
    
    scanf("%d", &nums);
    num_array = (int *)malloc(nums * sizeof(int));
    for (i = 0; i < nums ; i++)
    {
        scanf("%d", (num_array+i));
        sum += *(num_array+i);
    }
    
    printf("%d", sum);
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
