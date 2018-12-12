#include <stdio.h>
#include <stdlib.h>

typedef struct single_linked_list
{
  int data;
  struct single_linked_list * next;
}sl;

//typedef struct single_linked_list sl;


sl *create_list();
void display (sl *nd);
int search(sl *first, int n);
void search_node(sl *first);
sl *delete_node(sl *first);
sl *insert_first(sl *first);
sl *get_last(sl *first);
void insert_last(sl *first);
sl *insert_before(sl *first);
void insert_after(sl *first);
void update_node(sl *first);
void print_reverse(sl *first);
sl *reverse_linked_list(sl *first);
void create_two_lists();
sl *sum_of_reverse_lists(sl *listA, sl *listB);
sl *sum_of_lists(sl *root1, sl *root2, sl *root3);
sl * pair_wise_swap(sl * first);
