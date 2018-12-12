#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 40

int main() 
{
    char ch;
    char s[MAX_LEN];
    char sen[MAX_LEN];

    printf("\nEnter a Character:");
    scanf("%c",&ch);

    printf("\nEnter a Word:");
    scanf("%s",s);

    printf("\nEnter a Sentence:");
    scanf("\n");
    scanf("%[^\n]%*c",sen);

    printf("\nCharacter: %c, Word: %s, Sentence: %s\n", ch, s, sen);
    return 0;
}
