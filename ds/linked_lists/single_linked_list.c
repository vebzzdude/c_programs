#include "single_linked_list.h"

sl *create_list()
{
  sl *first = NULL, *last = NULL, *node = NULL;
  int num = 0;
  char ch;

  do
   {
     printf("\nEnter node data to be inserted:");
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

int search(sl *first, int n)
{
  sl *nd = first;

  while (nd != NULL)
    {
      if (nd->data == n)
        return 1;

      nd = nd->next;
    }

  return 0;
}

void search_node(sl *first)
{
  int num;

  if (first == NULL)
    {
      printf("List is empty\n");
      return;
    }

  printf("Enter a value to be searched:");
  scanf("%d",&num);

  if (search(first, num) == 1)
    printf("Node is present in the list\n");
  else
    printf("Node is NOT present in the list\n");
}

sl *delete_node(sl *first)
{
  int num;
  sl *nd = NULL, *before = NULL;

  if (first == NULL)
    {
      printf("List is empty\n");
      return NULL;
    }

  printf("Enter a value to be deleted:");
  scanf("%d",&num);

  if (search(first, num) == 0)
    printf("Node is NOT present in the list. Hence it cannot be deleted\n");

  if (first->data == num)
    {
          nd = first->next;
          free(first);
          first = nd;
    }
  else
    {
     nd = first->next;
     before = first;

      while (nd != NULL)
        {
          if (nd->data == num)
            {
              before->next =  nd->next;
              free(nd);
            }
          before = nd;
          nd = nd->next;
        }
      printf("Node is deleted\n");
    }

  return first;

}

sl *insert_first(sl *first)
{
  sl *node;
  int num;

  if (first == NULL)
    {
      printf("List is empty\n");
      return NULL;
    }

  printf("Enter node data to be inserted at first of list:");
  scanf("%d", &num);

  node =  (sl *)malloc(sizeof(sl));

  node->data = num;
  node->next = first;
  first = node;

  printf("Node is inserted at first\n");
  return first;
}

sl *get_last(sl *first)
{
  sl *nd;
  nd = first;

  if (first == NULL)
    return NULL;

  while (nd->next != NULL)
   nd = nd->next;

  return nd;
}
void insert_last(sl *first)
{
  sl *node, *last, *nd;
  int num;

  if (first == NULL)
    {
      printf("List is empty\n");
      return;
    }

  printf("Enter node data to be inserted at last of list:");
  scanf("%d", &num);

  node =  (sl *)malloc(sizeof(sl));
  node->data = num;

  nd = first;
  last = get_last(nd);

  while (last->next != NULL)
       last = last->next;

  last->next = node;
  last = node;
  last->next = NULL;

  printf("Node is inserted at last\n");
}

sl *insert_before(sl *first)
{
  sl * node = NULL, *before = NULL, *nd = NULL;
  int num, value;

  if (first == NULL)
    {
      printf("List is empty\n");
      return NULL;
    }


  printf("Before which node would you like to insert?:");
  scanf("%d", &num);

  nd = first;

  if (search(nd, num) == 1)
    {
      printf("Enter value of node to be inserted:");
      scanf("%d", &value);

      node =  (sl *)malloc(sizeof(sl));
      node->data = value;

      if (first->data == num)
        {
          node->next = first;
          first = node;          
        }
      else
        {
          before = first;
          nd = first->next;

          while (nd != NULL && (nd->data != num))
            {
              before = nd;
              nd = nd->next;
            }

          node->next = before->next;
          before->next = node;
        }
     }
   else
     {
       printf("Node not found\n");
       return first;
     }

  printf("Node is inserted\n");
  return first;

}

void insert_after(sl *first)
{
  sl *node = NULL, *nd = NULL;
  int num, value;

  if (first == NULL)
    {
      printf("List is empty\n");
      return;
    }

  printf("After which node would you like to insert?:");
  scanf("%d", &num);

  nd = first;

  if (search(nd, num) == 1)
    {
      printf("Enter value of node to be inserted:");
      scanf("%d", &value);

      node =  (sl *)malloc(sizeof(sl));
      node->data = value;

      nd = first;

      while (nd != NULL && (nd->data != num))
        {
          nd = nd->next;
        }

      node->next = nd->next;
      nd->next = node;
      printf("Node is inserted\n");
    }
  else
    printf("Node not found\n");
}

void update_node(sl *first)
{
  sl *nd;
  int num, value;

  printf("Enter node to be updated:");
  scanf("%d", &num);

  nd = first;
  if (search(nd, num) == 0)
    {
      printf("Node not found\n");
      return;
    }
  else
    {
      printf("Enter new value:");
      scanf("%d", &value);

      while (nd != NULL && nd->data != num)
         nd = nd->next;

      nd->data = value;
      printf("Node value is updated\n"); 
    }
}

void print_reverse(sl *first)
{
   sl *nd = first;

   if (nd == NULL)
     {
       return;
     }

   print_reverse(nd->next);
   printf("%d\t",nd->data);
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

  printf("Linked List is reversed\n");
  return prev;
}

sl * pair_wise_swap(sl * first)
{
  sl *prev = NULL, *curr = NULL, *next = NULL;

  if (first == NULL || first->next == NULL)
    return first;

  prev = first;
  curr = prev->next;

  while (next != NULL && next->next != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev->next = next->next;
      prev = next;
      curr = prev->next;

      display(first);
    }

  return first;
}

int main()
{
  int opt;
  sl *list = NULL;
  while(1)
    {
      printf("\t\t\t\tMENU\n");
      printf("\t\t\t====================\n"); 
      printf("\t\t\t\t1.  Create Single Linked List\n");
      printf("\t\t\t\t2.  Display\n");
      printf("\t\t\t\t3.  Search Node\n");
      printf("\t\t\t\t4.  Delete Node\n");
      printf("\t\t\t\t5.  Insert First\n");
      printf("\t\t\t\t6.  Insert Last\n");
      printf("\t\t\t\t7.  Insert Before\n");
      printf("\t\t\t\t8.  Insert After\n");
      printf("\t\t\t\t9.  Update\n");
      printf("\t\t\t\t10. Print Linked List in Reverse order\n");
      printf("\t\t\t\t11. Reverse a Linked List\n");
      printf("\t\t\t\t12. Sum of two Linked List\n");
      printf("\t\t\t\t13. Pairwise swap elements in Linked List\n");
      printf("\t\t\t\t14. Exit\n");
      printf("\t\t\t====================\n");

      printf("Enter your option:");
      scanf("%d", &opt);

      switch(opt)
        {
          case 1:
                printf("\nCreate a new single linked list:");
                list = create_list(list);
                break;
          case 2:
                display(list);
                break;
          case 3:
                search_node(list);
                break;
          case 4:
                list = delete_node(list);
                break;
          case 5:
                list = insert_first(list);
                break;
          case 6:
                insert_last(list);
                break;
          case 7:
                list = insert_before(list);
                break;
          case 8:
                insert_after(list);
                break;
          case 9:
                update_node(list);
                break;
          case 10:
                print_reverse(list);
                printf("\n");
                break;
          case 11:
                list = reverse_linked_list(list);
                break;
          case 12:
                create_two_lists();
                break;
          case 13:
                list = pair_wise_swap(list);
                break;
          case 14:
          default:
                exit(EXIT_SUCCESS);
        }

    }

  return 0;
}
