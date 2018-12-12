/** Binary Search Tree and different operations
    Sources: mycodeschool **/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct bsearchtree
{
	struct bsearchtree *left;
	int data;
	struct bsearchtree *right;
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

bst * create_bs_tree(bst *root)
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

int bst_height(bst * rt)
{

  if (rt == NULL)
    {
      return -1;
    }

  return max(bst_height(rt->left), bst_height(rt->right)) + 1;

}

int max(int a, int b)
{
  return (a>b?a:b);
}

bst * findMin(bst * root)
{
  if (root == NULL)
    return NULL;

  while(root->left != NULL)
    {
      root = root->left;
    }

  return root;
}

bst * delete_node(bst *root, int num)
{
  if (root == NULL)
    return NULL;
  else if (root->data > num)
    root->left  = delete_node(root->left, num);
  else if (root->data < num)
    root->right = delete_node(root->right, num);
  else
    {
      /* Node found. Delete the node now... */
      // Case 1: No children
      if (root->left == NULL && root->right == NULL)
        {
          free(root);
          root = NULL;
        //  return root;
        }
      //Case 2: If one child is present
      else if (root->left == NULL)
        {
          bst *temp =  root;
          root = root->right;
          free(temp);
          temp = NULL;
         // return root;
        }
      //Case 2: If one child is present
      else if (root->right == NULL)
        {
          bst *temp =  root;
          root = root->left;
          free(temp);
          temp = NULL;
         // return root;
        }
      //Case 3: If both left and right children are present
      else
        {
          bst *temp = findMin(root->right);
          root->data = temp->data;
          root->right = delete_node(root->right, temp->data);
         // return root;
        }
    }
  return root;
}

int bst_common_parent(bst * root, int ele1, int ele2)
{
  if (root ==  NULL)
    return 0;

  if ((root->data < ele1 && root->data > ele2)
      || (root->data > ele1 && root->data < ele2))
    return root->data;

  if (root->data < ele1 && root->data < ele2)
    return bst_common_parent(root->right, ele1, ele2);
  else if (root->data > ele1 && root->data > ele2)
    return bst_common_parent(root->left, ele1, ele2);
}

bool isBSUtil(bst * root, int minValue, int maxValue)
{
  if (root == NULL)
    return true;

  if (root->data > minValue
      && root->data < maxValue
      && isBSUtil(root->left, minValue, root->data)
      && isBSUtil(root->right, root->data, maxValue))
    return true;
  else
    return false;
}

bool isBinarySearchTree(bst * root)
{
  return isBSUtil(root, INT_MIN, INT_MAX);
}

bst * search_node(bst *root, int num)
{
   bst * temp = root;

   if (root == NULL)
     return NULL;

   if (temp->data == num)
     {
       return temp;
     }
   else if (temp->data > num)
     {
       return search_node(temp->left, num);
     }
   else if (temp->data < num)
     {
       return search_node(temp->right, num);
     }
}

bst * predecessor_inorder(bst *root, int num)
{
  bst *current = NULL;

  if (root == NULL)
    return NULL;

  current = search_node(root, num);

  if (current == NULL)
    {
      printf("Node not found\n");
      return NULL;
    }

  /* Case 1: When left sub tree is present,
   * its immediate left child is its predecessor.
   */
   if (current->left != NULL)
     return current->left;
   /* Case 2: When left sub tree is not present,
    * Go to the nearest ancestor for which the
    * given node would be in right sub tree.
    * Note: Ancestors has to be looked only when
    * there is no left sub tree.
    */ 
   else
     {
       bst *predecessor = NULL;
       bst *ancestor = root;
       while (ancestor != current)
         {
           if (current->data < ancestor->data)
            {
               ancestor = ancestor->left;
            }
           else
            {
              predecessor = ancestor;
              ancestor = ancestor->right;
            }
         }

        if (predecessor == NULL)
          printf("No predecessor exists\n");

        return predecessor;
     }
}

bst * successor_inorder(bst *root, int num)
{
   bst *current = NULL;

   if (root == NULL)
     return NULL;

   current = search_node(root, num);

   if (current == NULL)
     return NULL;

  /* Case 1: When right sub tree is present,
   * Find the minimum element in right sub tree
   * i.e., Go deep to leftmost node in the
   * right sub tree.
   */
   if (current->right != NULL)
     {
       return findMin(current->right);
     }
  /* Case 2: When no right sub tree is present,
   * Go to the nearest ancestor for which given
   * node would be in left sub tree.
   * Note: Ancestors has to be looked only when
   * there is no right sub tree.
   */
   else
     {
       bst * successor = NULL;
       bst * ancestor = root;

       while(ancestor != current)
         {
           if (current->data < ancestor->data)
             {
               successor = ancestor;
               ancestor  = ancestor->left; 
             }
           else
             {
               ancestor = ancestor->right;
             }
         }
      if (successor == NULL)
        printf("No successor exists\n");

      return successor;
     }
}

int main()
{
	bst * root = NULL, *temp = NULL;
        int height = 0, opt;
        int ele1, ele2, common_parent;
        int num;
        bool is_bst = false;
        while(1)
          {
            printf("\t\t\t\tMENU\n");
            printf("\t\t\t====================\n");
            printf("\t\t\t\t1.  Create Binary Search Tree (BST)\n");
            printf("\t\t\t\t2.  Pre Order Traversal of BST\n");
            printf("\t\t\t\t3.  InOrder Traversal of BST\n");
            printf("\t\t\t\t4.  Post Order Traversal of BST\n");
            printf("\t\t\t\t5.  Height of BST\n");
            printf("\t\t\t\t6.  Insert a node in BST\n");
            printf("\t\t\t\t7.  Delete a node in BST\n");
            printf("\t\t\t\t8.  Search a node in BST\n");
            printf("\t\t\t\t9.  Lowest Common Ancestor/Parent\n");
            printf("\t\t\t\t10. Predecessor of a node in InOrder\n");
            printf("\t\t\t\t11. Successor of a node in InOrder\n");
            printf("\t\t\t\t12. Is BST or not\n");
            printf("\t\t\t\t13. Exit\n");
            printf("\t\t\t====================\n");

            printf("Enter your option:");
            scanf("%d", &opt);

           switch(opt)
             {
                case 1:
	        printf("Create a Binary Search Tree\n");
	        root = create_bs_tree(root);
                printf("Binary Search Tree created");
                break;

	        case 2:
                if (root == NULL)
                  printf("Tree is Empty");
                else
                  {
	            printf("Pre Order traversal of BST:");
	            preorder(root);
                  }
                break;

                case 3:
                if (root == NULL)
                  printf("Tree is Empty");
                else
                  {
                    printf("InOrder traversal of BST:");
                    inorder(root);
                  }
                break;

                case 4:
                if (root == NULL)
                  printf("Tree is Empty\n");
                else
                  {
                    printf("Post Order traversal of BST:");
                    postorder(root);
                  }
                break;

                case 5:
                height = bst_height(root);
                printf("Height of Binary Search Tree: %d",height);
                break;

                case 6:
                /* Insert a node*/
                printf("Enter value of node to be inserted:");
                scanf("%d", &num);
                root = insert(root, num);
                if (root != NULL)
                  printf("Node is inserted");
                break;

                case 7:
                /* Delete a node*/
                printf("Enter value of node to be deleted:");
                scanf("%d", &num); 
                root = delete_node(root, num);
                break;

                case 8:
                /* Search a node */
                printf("Enter value of node to be searched:");
                scanf("%d", &num);
                temp = search_node(root, num);
                if (temp != NULL)
                  printf("Node exists in BST");
                else
                  printf("Node does not exists in BST");
                break;

                case 9:
                printf("Enter ele1 and ele2:");
                scanf("%d %d", &ele1, &ele2);
                common_parent = bst_common_parent(root, ele1, ele2);
                printf("Common Parent: %d", common_parent);
                break;

                case 10:
                /* Predecessor */
                printf("Enter value of node whose predecessor has to be found:");
                scanf("%d", &num);
                temp = predecessor_inorder(root, num);
                if (temp != NULL)
                  printf("Predecessor of %d in InOrder: %d", num, temp->data);
                break;

                case 11:
                /* Successor */
                printf("Enter value of node whose successor has to be found:");
                scanf("%d", &num);
                temp = successor_inorder(root, num);
                if (temp != NULL)
                  printf("Successor of %d in InOrder: %d", num, temp->data);
                break;

                case 12:
                is_bst = isBinarySearchTree(root);
                if (is_bst == true)
                  printf("It is a Binary Search Tree");
                else
                  printf("It is not a Binary Search Tree");
                break;

                case 13:
                default:
                free(root);
                printf("\n");
                exit(0);
             }
           printf("\n");
         }
        printf("\n");	
	return 0;
}
