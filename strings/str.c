#include <stdio.h>

void find_length(char *input){

    printf("%s", input);
    int length = 0;
    while(input[length]!='\0')
    {
        length++;
        printf("%i", length);
    }
}

int main() {

        char *input = "This is a string";
        find_length(input);
        return 0;

}

