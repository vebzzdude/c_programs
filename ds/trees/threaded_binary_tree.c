/* https://www.geeksforgeeks.org/convert-binary-tree-threaded-binary-tree-2/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct bsearchtree
{
	struct bsearchtree *left;
	int data;
	struct bsearchtree *right;

        bool lthread, rthread;
};

typedef struct bsearchtree bst;

bst * insert(bst * rt, int n)
{
	if (rt == NULL)
	{
		rt = (bst *)malloc(sizeof(int));
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

bst * create_bs_tree()
{
	bst * root = NULL;
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

void preorder(bst * rt)
{
	if (rt == NULL)
          {
            return;
          }

	if (rt != NULL)
	{
		printf("%7d", rt->data);
		preorder(rt->left);
		preorder(rt->right);
	}
}


void inorder(bst * rt)
{
        if (rt == NULL)
          {
            return;
          }

        if (rt != NULL)
        {
		inorder(rt->left);
		printf("%5d", rt->data);
		inorder(rt->right);
	}
}

void postorder(bst * rt)
{
        if (rt == NULL)
          {
            return;
          }

        if (rt != NULL)
        {
		postorder(rt->left);
		postorder(rt->right);
		printf("%5d", rt->data);
	}
}

/* Converts tree with given root to Right In-Threaded Binary Tree
 * This function returns right most child of root
 */
bst * createRthreadedBinaryTree(bst * rt)
{
   /* Base case 1: If Tree is empty  */
   if (rt == NULL)
     {
       return NULL;
     }

  /* Base case 2: If (sub)tree is a single node or 
   * if it is a leaf node (with no children) return root
   */
   if ((rt->left == NULL) && (rt->right == NULL))
     {
       return rt;
     }

  /* Find predecessor of root if it exists */
   if (rt->left != NULL)
     {
       /*  Find predecessor of root (Right most child in left sub tree) */
       bst *l = createRthreadedBinaryTree(rt->left);

       /* Link a thread from predecessor to root */
       l->right = rt;
       l->rthread = true;
     }

  /* If current node is right most child return it */
  if (rt->right == NULL)
    {
      return rt;
    }

  /* Perform recursion for right sub tree */
  return createRthreadedBinaryTree(rt->right);  
}

/* Converts tree with given root to Right In-Threaded Binary Tree
 * This function returns left most child of root
 */
bst * createLthreadedBinaryTree(bst * rt)
{
  if (rt == NULL)
    {
      return NULL;
    }

  if ((rt->left == NULL) && (rt->right == NULL))
    {
      return rt;
    }

  if (rt->right != NULL)
    {
      bst * r = createLthreadedBinaryTree(rt->right);

      r->left = rt;
      r->lthread = true;  
    }

  /* If current node is left most child return it */
  if (rt->left == NULL)
    {
      return rt;
    }

  /* Perform recursion for left sub tree */
  return createLthreadedBinaryTree(rt->left);

}

int main()
{
	bst * root = NULL;
	
	printf("\nCreate a Binary Search Tree\n");
	root = create_bs_tree();

	printf("\nPre-order traversal:");
	preorder(root);
	
	printf("\nInorder traversal:");
	inorder(root);

	printf("\nPost-order traversal:");
	postorder(root);

	free(root);
	printf("\n");
	
	return 0;
}
