/** Convert a given Binary Search Tree into (Double) Linked List. **/

/* To convert a given Binary Search Tree into (Double) Linked List,
 * BST InOrder Traversal technique can be used.
 */

/* Source: GeeksforGeeks
 *  https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
 */

#include <stdio.h>
#include <stdlib.h>

/* Binary Search Tree and Linked List structure should be
 * declared in a similar format. Or else there is a chance
 * of addresses getting displayed instead of values
 */

struct bst
{
        struct bst *left;
        int data;
        struct bst *right;
};

struct ll
{
  struct ll *prev;
  int data;
  struct ll *next;
};

/* A simple recursive function to convert a given Binary Search tree
 * to Double Linked List 
 * root_bst --> Root of a Binary Search Tree 
 * root_ll  --> Pointer to root(starting) node of created double linked list
 */
void bst_to_ll(struct bst *root_bst, struct ll **root_ll)
{
  /* Base Case */
  if (root_bst == NULL)
    {
      return;
    }

  /* Initialize previously visited node in linked list
   * as NULL. It is declared as static variable so that
   * the same value is accessible in all recursive
   * function calls
   */
  static struct ll *visited = NULL;

  /* Recursively convert left subtree */
  bst_to_ll(root_bst->left, root_ll);

  /* Now convert this node */
  if (visited == NULL)
    {
      *root_ll = (struct ll *)root_bst;
    }
  else
    {
      root_bst->left = (struct bst *)visited;
      visited->next = (struct ll *)root_bst;
    }
  visited = (struct ll *)root_bst;

  /* Finally convert right subtree */
  bst_to_ll(root_bst->right, root_ll);
  
}

struct bst * insert(struct bst * rt, int n)
{
        if (rt == NULL)
        {
                rt = (struct bst *)malloc(sizeof(struct bst));
                rt->data = n;
                rt->left = NULL;
                rt->right = NULL;
        }
        else if(rt->data < n)
        {
                rt->right = insert(rt->right, n);
        }
        else if(rt->data > n)
        {
                rt->left = insert(rt->left, n);
        }
        else
        {
                printf("\nNode with data %d already exists",n);
        }

        return rt;
}

struct bst * create_bst(struct bst *root)
{
        int value;
        char ch;
        do
        {
                printf("\nEnter value of node to insert:");
                scanf("%d", &value);

                root  = insert(root, value);

                printf("\nWould you like to add another node(y/n):");
                // flushes the standard input
                // (clears the input buffer)
                 while( (getchar())!= '\n');
                 ch = getchar();

                //scanf("%c", &ch);
        }while(ch != 'n');

        return root;
}

void inorder(struct bst * rt)
{
        if (rt == NULL)
          {
            return;
          }

        if (rt != NULL)
        {
                inorder(rt->left);
                printf("%d\t", rt->data);
                inorder(rt->right);
        }
}

int main()
{
  struct bst *root_bst = NULL;
  struct ll *root_ll = NULL, *temp = NULL;

  printf("Creating BST now\n");  
  root_bst = create_bst(root_bst);

  printf("BST in InOrder:\n");
  inorder(root_bst);

  printf("\nConverting BST into Double Linked List\n");
  bst_to_ll(root_bst, &root_ll);

  printf("BST after converted into Double Linked List:\n");

  temp = root_ll;
  while (temp != NULL)
       {
         printf("%d",temp->data);
         if (temp->next)
           printf("<=>");
         temp = temp->next;
       }

  printf("\n");
  return 0;
}
