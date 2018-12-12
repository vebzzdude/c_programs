#include <stdio.h>
#include <stdlib.h>

typedef struct single_linked_list
{
  int data;
  struct single_linked_list * next;
}sl;

sl *create_list()
{
  sl *first = NULL, *last = NULL, *node = NULL;
  int num = 0;
  char ch;

  do
   {
     printf("\nEnter node data(0<=data<=9) to be inserted:");
     scanf("%d", &num);

     node = (sl *)malloc(sizeof(sl));

     if (node == NULL)
       {
         printf("Insufficient Memory\n");
         return NULL;
       }

     node->data = num;

     if (first == NULL)
       {
         first = last = node;
       }
     else
       {
         last->next = node;
         last = node;
       }

     last->next = NULL;

     printf("Would you like to enter another node(y/n):");
     while(getchar() != '\n');
     ch = getchar();
   }while(ch != 'n' &&  ch != 'N');

  printf("List is created\n");
  return first;
}

void display (sl *nd)
{

  if (nd == NULL)
    printf("List is empty");
  else
    {
      printf("List of nodes:\n");
      while (nd != NULL)
       {
         printf("%d\t", nd->data);
         nd = nd->next;
       }
    }
  printf("\n");
}

sl *reverse_linked_list(sl *first)
{
  sl *current = first, *prev = NULL, *next = NULL;
  if (current == NULL)
    {
      printf("List is Empty\n");
      return NULL;
    }

  while(current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

  //printf("Linked List is reversed\n");
  return prev;
}


void sum_helper(sl *nd1, sl *nd2, sl *root1, sl *root2)
{

  int ele1 = 0, ele2 = 0;
  static int list1_end = 0, list2_end = 0;

  if (nd1 == NULL && nd2 == NULL)
    return;

  if (nd1 == NULL)
    nd1 = root1;
  else if (nd2 == NULL)
    nd2 = root2;

  if (list1_end == 0)
    ele1 = nd1->data;

  if (list2_end == 0)
    ele2 = nd2->data;

  sum_helper(nd1->next, nd2->next, root1, root2);
  printf("%d\t%d\t%d\n", ele1, ele2, ele1+ele2);

  if (nd1 == root1)
    list1_end = 1;
  else if (nd2 == root2)
    list2_end = 1;
}

sl *linked_lists_sum(sl *list1, sl *list2)
{
  sl *nd1 = NULL, *nd2 = NULL, *list3 = NULL, *node = NULL, *last = NULL;
  int carry = 0;

  nd1 = list1;
  nd2 = list2;

  printf("Sum of Linked Lists:\n");
  sum_helper(nd1, nd2, list1, list2);


#if 0
  /* Traverse both the lists and find the sum of corresponding nodes
   * till both lists reach end. Remember the final carry forward (if any)
   * also has to be appened in the newly created list.
   */
  while(nd1 != NULL || nd2 != NULL || carry > 0)
    {
      /* Create a new node */
      node = (sl *)malloc(sizeof(sl));
      node->data = 0;

      /* Add data values of corresponding nodes from both lists */
      if (nd1)
        node->data = node->data + nd1->data;
      if (nd2)
        node->data = node->data + nd2->data;

      /* Add carry forward */
      node->data = node->data + carry;

      /* Calcualte carry forward for current node->data */
      if (node->data > 9)
        {
          carry = (node->data)/10;
          node->data = (node->data)%10;
        }
      else
        {
          carry = 0;
        }
      /* Append the node in newly created list */
      if (list3 == NULL)
        {
          list3 = last = node;
        }
      else
        {
          last->next = node;
          last = node;
        }

      last->next = NULL;

      /* Move to next node in list 1 */
      if (nd1)
         nd1 = nd1->next;
      /* Move to next node in list 2 */
      if (nd2)
         nd2 = nd2->next;
    }

  list3 = reverse_linked_list(list3);

  /* Reverse both the linked lists again */
  list1 = reverse_linked_list(list1);
  list2 = reverse_linked_list(list2);
#endif

  return list3;

}

int main()
{
  sl *list1 = NULL, *list2 = NULL, *list3 = NULL;

  printf("Create List 1:");
  list1 = create_list(list1);

  printf("Create List 2:");
  list2 = create_list(list2);

  printf("List 1:\n");
  display(list1);

  printf("List 2:\n");
  display(list2);

  list3 = linked_lists_sum(list1, list2);

  printf("Resultant Sum List:\n");
  display(list3);

  return 0;
}
