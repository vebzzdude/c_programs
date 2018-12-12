#include <stdio.h>

#define ALPHABET_SIZE  26
#define CASE  'a'

typedef struct node
{
  struct node* parent;
  struct node* childern[ALPHABET_SIZE];
  int occurrences;
}Node;


void insertNode(Node* root, char *word)
{

}

int main()
{

  return 0;
}
