/*
 * Copyright (c) 2026, National Federation for Research in Advanced Computation (NFRAC)
 *
 * This file is part of the Garuda Programming Language.
 *
 * Garuda is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * Garuda is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Author: Er. P. Rohit V. Acharya
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_STRING
#include "../util/linked_list_string.c"
#endif

#ifndef TREE_SET_STRING
#include "../util/tree_set_string.c"
#endif

typedef enum
{
  VALUE_NODE,
  OBJECT_NODE
} node_type;

typedef struct any_list_dtype
{
  node_type type;
  void *value;
  struct any_list_dtype *next;
} any_list_dtype;

any_list_dtype *allocate_any_list_dtype_memory()
{
  return (any_list_dtype *)malloc(sizeof(any_list_dtype));
}

any_list_dtype *add_any_list_dtype_node(any_list_dtype **gen_ref, int *magnitude, void *value, int is_object)
{
  any_list_dtype *new_node = allocate_any_list_dtype_memory();
  new_node->value = value;
  new_node->type = is_object ? OBJECT_NODE : VALUE_NODE;
  new_node->next = NULL;
  if ((*gen_ref) == NULL)
    (*gen_ref) = new_node;
  else
  {
    any_list_dtype *curr = *gen_ref;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void view_E_node(ch8node *root)
{
  printf("[");
  while (root != NULL)
  {
    printf(root->next != NULL ? "%s, " : "%s", root->data);
    root = root->next;
  }
  printf("]");
}

void view_any_list_dtype_node(any_list_dtype *node)
{
  if (!node)
  {
    printf("[]\n");
    return;
  }
  any_list_dtype *curr = node;
  if (curr->type == VALUE_NODE || curr->type == OBJECT_NODE)
    printf("[");
  while (curr)
  {
    if (curr->type == VALUE_NODE)
      view_E_node((ch8node *)curr->value);
    else if (curr->type == OBJECT_NODE)
      view_any_list_dtype_node((any_list_dtype *)curr->value);
    else
      return;
    if (curr && curr->next)
      printf(", ");
    curr = curr->next;
  }
  printf("]\n");
}

void poll_any_list_dtype_node(any_list_dtype **node, int *magnitude)
{
  any_list_dtype *root = *node;
  if (root == NULL)
    return;
  *node = (root)->next;
  free(root);
  (*magnitude)--;
}

void pop_any_list_dtype_node(any_list_dtype **root, int *magnitude)
{
  if (*root == NULL || *magnitude == 0)
    return;

  any_list_dtype *current = *root;
  any_list_dtype *prev_node = NULL;

  while (current->next != NULL)
  {
    prev_node = current;
    current = current->next;
  }

  if (prev_node == NULL)
  {
    // Only one node in the list
    free(*root);
    *root = NULL;
  }
  else
  {
    prev_node->next = NULL;
    free(current);
  }

  (*magnitude) -= 1;
}

int size_any_list_dtype_node(int magnitude)
{
  return magnitude;
}

void insert_any_list_dtype_node(any_list_dtype **root, void *value, int index, int *magnitude, int is_object)
{
  int position = 0;
  any_list_dtype *new_node = allocate_any_list_dtype_memory();
  new_node->value = value;
  new_node->type = is_object ? OBJECT_NODE : VALUE_NODE;
  any_list_dtype *prev_node = NULL;
  any_list_dtype *current_node = *root;

  if (index == 0)
  {
    new_node->next = (*root);
    *root = new_node;
    (*magnitude)++;
    return;
  }

  while (current_node != NULL)
  {
    if (index == position)
    {
      any_list_dtype *successor = prev_node->next;
      prev_node->next = new_node;
      new_node->next = successor;
      (*magnitude)++;
      break;
    }
    prev_node = current_node;
    current_node = current_node->next;
    position++;
  }
}

void delete_any_list_dtype_node(any_list_dtype **root, int index, int *magnitude)
{
  any_list_dtype *prev_node = NULL;
  any_list_dtype *current_node = (*root);
  int position = 0;
  if (index > (*magnitude) - 1)
  {
    printf("List out of bound error\n");
    exit(1);
  }
  if (index == 0)
  {
    poll_any_list_dtype_node(&(*root), magnitude);
    return;
  }
  while (current_node != NULL)
  {
    if (position == index)
    {
      prev_node->next = current_node->next;
      break;
    }
    prev_node = current_node;
    current_node = current_node->next;
    position++;
  }
  (*magnitude)--;
}

int is_empty_any_list_dtype_node(int *magnitude)
{
  if ((*magnitude) == 0)
    return 1;
  return 0;
}

void clear_any_list_dtype_node(any_list_dtype **root, int *magnitude)
{
  any_list_dtype *current = *root;
  while (current != NULL)
  {
    any_list_dtype *next = current->next;
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void reverse_any_list_dtype_node(any_list_dtype **root)
{
  any_list_dtype *current = *root;
  any_list_dtype *prev_node = NULL;
  any_list_dtype *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev_node;
    prev_node = current;
    current = next;
  }

  *root = prev_node;
}

any_list_dtype *get_any_list_dtype_node(any_list_dtype **root, int index)
{
  int position = 0;
  any_list_dtype *current = *root;
  while (current != NULL)
  {
    if (position == index)
      return current->value;
    current = current->next;
    position++;
  }
  return NULL;
}

// void main()
// {
// // All the values will be in 'String' by default while working with wild card types.
// // 'T' indicates a list ch8node

// // list<?> l = new list<>()
// // For logging output use 'trace()'

// // any_list_dtype *l = NULL;
// // int l_magnitude = 0;

// // // list<T> e1 = new list<>()
// // ch8node *e1 = NULL;
// // int e1_size = 0;

// // // e1.push(98)
// // add_ch8_node(&e1, "98", &e1_size);

// // // e1.push(232)
// // add_ch8_node(&e1, "232", &e1_size);

// // // l.push(e1)
// // add_any_list_dtype_node(&l, &l_magnitude, e1, 0);

// // // list<T> e2 = new list<>()
// // ch8node *e2 = NULL;
// // int e2_size = 0;

// // // e2.push(3.79)
// // add_ch8_node(&e2, "3.79", &e2_size);

// // // e2.push(34.3)
// // add_ch8_node(&e2, "34.3", &e2_size);

// // // e2.push(376.09)
// // add_ch8_node(&e2, "376.09", &e2_size);

// // // l.push(e2)
// // add_any_list_dtype_node(&l, &l_magnitude, e2, 0);

// // // list<T> e3 = new list<>()
// // ch8node *e3 = NULL;
// // int e3_size = 0;

// // // e3.push("hi")
// // add_ch8_node(&e3, "hi", &e3_size);

// // // e3.push("how are you")
// // add_ch8_node(&e3, "how are you", &e3_size);

// // // l.push(e3)
// // add_any_list_dtype_node(&l, &l_magnitude, e3, 0);
// // // Set 0 if type is T, else 1

// // // list<T> as = new list<>()
// // ch8node *as = NULL;
// // int as_size = 0;

// // // as.push("12")
// // add_ch8_node(&as, "12", &as_size);
// // // as.push("3")
// // add_ch8_node(&as, "3", &as_size);

// // // l.insertAt(1, as)
// // insert_any_list_dtype_node(&l, as, 1, &l_magnitude, 0);

// // // l.trace()
// // view_any_list_dtype_node(l);

// // --------------------------------------------

// // list<list<list<int>>>
// any_list_dtype *l = NULL;
// int l_magnitude = 0;

// // list<?> g1 = new list<>()
// any_list_dtype *g1 = NULL;
// int g1_magnitude = 0;

// // list<T> E1 = new list<>()
// ch8node *E1 = NULL;
// int E1_size = 0;

// // e1.push(98)
// // e1.push(232)
// add_ch8_node(&E1, "98", &E1_size);
// add_ch8_node(&E1, "232", &E1_size);

// // g1.push(E1)
// add_any_list_dtype_node(&g1, &g1_magnitude, E1, 0);

// // list<?> g2 = new list<>()
// any_list_dtype *g2 = NULL;
// int g2_magnitude = 0;

// // list<T> E2 = new list<>()
// ch8node *E2 = NULL;
// int E2_size = 0;

// // E2.push("Hi")
// // E2.push("How are you?")
// add_ch8_node(&E2, "Hi", &E2_size);
// add_ch8_node(&E2, "How are you?", &E2_size);

// // g2.push(E2)
// add_any_list_dtype_node(&g2, &g1_magnitude, E2, 0);

// // l.push(g1)
// add_any_list_dtype_node(&l, &l_magnitude, g1, 1);

// // l.push(g2)
// add_any_list_dtype_node(&l, &l_magnitude, g2, 1);

// // l.trace()
// view_any_list_dtype_node(l);

// // If you are getting an entry with wild-card anylist use '?'
// // ele = (?) l.get(0)
// any_list_dtype *buff2 = (any_list_dtype *)get_any_list_dtype_node(&l, 0);

// // buff2.trace()
// view_any_list_dtype_node(buff2);

// printf("+---------------------+\n");

// // -----------------------------------------------------------

// // Pre-reqs, add these at start while working with set's in list.
// ch8node *any_set_temp_view;
// int any_set_temp_view_size;

// // list<?> listOfSet = new list<>()
// any_list_dtype *listOfSet = NULL;
// int listOfSet_magnitude = 0;

// // set<T> s = new set<>()
// ch8_t_set *s = NULL;

// // s.union("ram")
// seed_ch8_t_set(&s, "ram");
// // s.union("ramesh")
// seed_ch8_t_set(&s, "ramesh");
// // s.union("ramesh")
// seed_ch8_t_set(&s, "ramesh");

// // listOfSet.push(s)
// any_set_temp_view = NULL;
// any_set_temp_view_size = 0;
// elements_ch8_t_set(&s, &any_set_temp_view, &any_set_temp_view_size);
// add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, any_set_temp_view, 0);

// // set<T> s2 = new set<>()
// ch8_t_set *s2 = NULL;

// // s2.union("ram")
// seed_ch8_t_set(&s2, "shyam");
// // s2.union("ramesh")
// seed_ch8_t_set(&s2, "shyam");
// // s2.union("ramesh")
// seed_ch8_t_set(&s2, "sunil");

// // listOfSet.push(s2)
// any_set_temp_view = NULL;
// any_set_temp_view_size = 0;
// elements_ch8_t_set(&s2, &any_set_temp_view, &any_set_temp_view_size);
// add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, any_set_temp_view, 0);

// // list<T> E5 = new list<>()
// ch8node *E5 = NULL;
// int E5_size = 0;

// // E2.push("Hi")
// // E2.push("How are you?")
// add_ch8_node(&E5, "1", &E5_size);
// add_ch8_node(&E5, "2", &E5_size);
// add_ch8_node(&E5, "2", &E5_size);
// add_ch8_node(&E5, "3", &E5_size);

// // g2.push(E2)
// add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, E5, 0);

// // listOfSet.trace()
// view_any_list_dtype_node(listOfSet);

// // listOfSet.poll()
// poll_any_list_dtype_node(&listOfSet, &listOfSet_magnitude);

// // listOfSet.pop()
// pop_any_list_dtype_node(&listOfSet, &listOfSet_magnitude);

// // listOfSet.trace()
// view_any_list_dtype_node(listOfSet);

// // listOfSet.insertAt(1, l)
// insert_any_list_dtype_node(&listOfSet, l, 0, &listOfSet_magnitude, 1);

// // listOfSet.trace()
// view_any_list_dtype_node(listOfSet);

// // // listOfSet.deleteAt(1)
// // delete_any_list_dtype_node(&listOfSet, 1, &listOfSet_magnitude);

// // // listOfSet.trace()
// // view_any_list_dtype_node(listOfSet);

// // // listOfSet.pop()
// // pop_any_list_dtype_node(&listOfSet, &listOfSet_magnitude);

// // // listOfSet.trace()
// // view_any_list_dtype_node(listOfSet);

// // size = listOfSet.isEmpty()
// int size = is_empty_any_list_dtype_node(&listOfSet_magnitude);
// printf("%d\n", size);
// printf("+-----------------------+\n");
// // l.trace()
// view_any_list_dtype_node(l);

// // l.clear()
// clear_any_list_dtype_node(&l, &l_magnitude);

// // l.trace()
// view_any_list_dtype_node(l);

// // listOfSet.trace()
// view_any_list_dtype_node(listOfSet);

// printf("+-----------------------+\n");

// // listOfSet.reverse()
// reverse_any_list_dtype_node(&listOfSet);

// // listOfSet.trace()
// view_any_list_dtype_node(listOfSet);

// printf("+-----------------------+\n");

// // If you are getting an entry with defined type, use T. 'T' will correspond to list<str>
// // buff = (T) listOfSet.get(0)
// ch8node *buff = (ch8node *)get_any_list_dtype_node(&listOfSet, 0);

// // buff.print()
// view_T_node(buff);
// }

/*
  Garuda Code

  list<?> l = new list<>()
  list<T> e1 = new list<>()
  e1.push(98)
  e1.push(232)
  l.push(e1)
  list<T> e2 = new list<>()
  e2.push(3.79)
  e2.push(34.3)
  e2.push(376.09)
  l.push(e2)
  list<T> e3 = new list<>()
  e3.push("hi")
  e3.push("how are you")
  l.push(e3)
  list<T> as = new list<>()
  as.push("12")
  as.push("3")
  l.insertAt(1, as)
  l.trace()


  list<?> l = new list<>()
  !list<list<list<int>>>
  list<?> g1 = new list<>()
  list<T> E1 = new list<>()
  e1.push(98)
  e1.push(232)
  g1.push(E1)
  list<?> g2 = new list<>()
  list<T> E2 = new list<>()
  E2.push("Hi")
  E2.push("How are you?")
  g2.push(E2)
  l.push(g1)
  l.push(g2)
  l.trace()
  ele = (?) l.get(0)
  buff2.trace()
  list<?> listOfSet = new list<>()
  set<T> s = new set<>()
  s.union("ram")
  s.union("ramesh")
  s.union("ramesh")
  listOfSet.push(s)
  set<T> s2 = new set<>()
  s2.union("ram")
  s2.union("ramesh")
  s2.union("ramesh")
  listOfSet.push(s2)
  list<T> E5 = new list<>()
  E2.push("Hi")
  E2.push("How are you?")
  g2.push(E2)
  listOfSet.trace()
  listOfSet.poll()
  listOfSet.pop()
  listOfSet.trace()
  listOfSet.insertAt(1, l)
  listOfSet.trace()
  listOfSet.deleteAt(1)
  listOfSet.trace()
  listOfSet.pop()
  listOfSet.trace()
  size = listOfSet.isEmpty()
  l.trace()
  l.clear()
  l.trace()
  listOfSet.trace()
  listOfSet.reverse()
  listOfSet.trace()
  buff = (T) listOfSet.get(0)
  buff.print()
*/