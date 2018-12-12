#include "single_linked_list.h"

sl *sum_of_reverse_lists(sl *list1, sl *list2)
{
  sl *nd1 = NULL, *nd2 = NULL, *list3 = NULL, *node = NULL, *last = NULL;
  int carry = 0;

  /* Reverse both the linked lists */
  list1 = reverse_linked_list(list1);
  list2 = reverse_linked_list(list2);
 
  nd1 = list1;
  nd2 = list2;

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
   
  return list3;
}


static sl * sum1(sl *root)
{
  sl *nd = root;
  
  if (nd == NULL)
    return NULL;

  sum1(nd->next);
  return nd;
}

sl *sum_of_lists(sl *root1, sl *root2, sl *root3)
{

  sl  *node = NULL, *nd1 = NULL, *nd2 = NULL;
  int a = 0, b = 0;
/*
  if (nd1 == root1 || nd2 == root2)
    return root3;
*/
  nd1 = root1;
  nd2 = root2;

  if (nd1 == NULL && nd2 == NULL)
    return NULL;

  if(nd1 && nd2)
  sum_of_lists(nd1->next, nd2->next, root3);

  if (nd1 && nd2)
  printf("%d\t%d\n", nd1->data, nd2->data);
  return root3;
}

void create_two_lists()
{
  sl *list1 = NULL, *list2 = NULL, *list3 = NULL, *last = NULL;

  printf("Create List 1:\n");
  list1 = create_list(list1);

  printf("Create List 2:\n");
  list2 = create_list(list2);

  printf("List 1:\n");
  display(list1);

  printf("List 2:\n");
  display(list2);

//  list3 = sum_of_reverse_lists(list1, list2);

  list3 = sum_of_lists(list1, list2, list3);
  printf("Sum of lists:\n");
  display(list3);
}
