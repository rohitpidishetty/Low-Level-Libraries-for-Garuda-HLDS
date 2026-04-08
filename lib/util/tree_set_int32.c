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

#ifndef LINKED_LIST_INT
#define LINKED_LIST_INT
#include "./linked_list_int.c"
#endif

typedef struct tree_set_i32
{
  int data;
  struct tree_set_i32 *left;
  struct tree_set_i32 *right;
} i32_t_set;

i32_t_set *sow_seed_i32_t_set(int data)
{
  i32_t_set *SEED = (i32_t_set *)malloc(sizeof(i32_t_set));
  SEED->data = data;
  SEED->left = NULL;
  SEED->right = NULL;
  return SEED;
}
int __min__t_s_value(i32_t_set *root)
{
  int min_val = root->data;

  while (root->left != NULL)
  {

    min_val = root->left->data;
    root = root->left;
  }
  return min_val;
}

i32_t_set *__delete_i32_t_set(i32_t_set *root, int data)
{
  //

  if (root == NULL)
    return NULL;

  if (data < root->data)
    root->left = __delete_i32_t_set(root->left, data);
  else if (data > root->data)
    root->right = __delete_i32_t_set(root->right, data);
  else
  {
    if (root->left == NULL)
    {
      i32_t_set *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      i32_t_set *temp = root->left;
      free(root);
      return temp;
    }

    int val = __min__t_s_value(root->right);
    root->data = val;
    root->right = __delete_i32_t_set(root->right, val);
  }
  return root;
}

i32_t_set *delete_i32_t_set(i32_t_set **_root_, int data)
{
  *_root_ = __delete_i32_t_set(*_root_, data);
  return *_root_;
}

void view_i32_set(i32node *root, int l1_size)
{
  int position = 1;
  printf("{");
  while (root != NULL)
  {
    printf(position < l1_size ? "%d, " : "%d", root->data);
    root = root->next;
    position++;
  }
  printf("}\n");
}

void seed_i32_t_set(i32_t_set **root, int data)
{
  if ((*root) == NULL)
    (*root) = sow_seed_i32_t_set(data);
  else
  {
    i32_t_set *head = *root;
    while (head != NULL)
    {
      if (head->data > data)
      {

        if (head->left == NULL)
        {
          head->left = sow_seed_i32_t_set(data);
          break;
        }
        head = head->left;
      }
      else if (head->data < data)
      {
        if (head->right == NULL)
        {
          head->right = sow_seed_i32_t_set(data);
          break;
        }
        head = head->right;
      }
      else
        break;
    }
  }
}

void __seed_i32_difference(i32_t_set **root, int data)
{
  if ((*root) == NULL)
    return;
  else
  {
    i32_t_set *head = *root;
    while (head != NULL)
    {
      if (head->data > data)
        head = head->left;
      else if (head->data < data)
        head = head->right;
      else
      {
        delete_i32_t_set(root, data);
        break;
      };
    }
  }
}

void __seed_i32_intersections(i32_t_set **root, int data, i32node **buffer, int *mag)
{
  if ((*root) == NULL)
    return;
  else
  {
    i32_t_set *head = *root;
    while (head != NULL)
    {
      if (head->data > data)
        head = head->left;
      else if (head->data < data)
        head = head->right;
      else
      {
        add_i32_node(buffer, data, mag);
        break;
      };
    }
  }
}

void __explore_union_tree_i32_t_set(i32_t_set *head, i32_t_set **new_head)
{
  if (head == NULL)
    return;
  __explore_union_tree_i32_t_set(head->left, new_head);
  seed_i32_t_set(new_head, head->data);
  __explore_union_tree_i32_t_set(head->right, new_head);
}

void __explore_intersection_tree_i32_t_set(i32_t_set *head, i32_t_set **new_head, i32node **buffer, int *mag)
{
  if (head == NULL)
    return;
  __explore_intersection_tree_i32_t_set(head->left, new_head, buffer, mag);
  __seed_i32_intersections(new_head, head->data, buffer, mag);
  __explore_intersection_tree_i32_t_set(head->right, new_head, buffer, mag);
}

void __explore_difference_tree_i32_t_set(i32_t_set *head, i32_t_set **new_head)
{
  if (head == NULL)
    return;
  __explore_difference_tree_i32_t_set(head->left, new_head);
  __seed_i32_difference(new_head, head->data);
  __explore_difference_tree_i32_t_set(head->right, new_head);
}

void __union_i32_tree(i32_t_set **root, i32_t_set **new_head)
{
  i32_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_union_tree_i32_t_set(head, new_head);
}

void union_i32_t_set(i32_t_set **A, i32_t_set **B)
{
  __union_i32_tree(B, A);
}

void __intersect_i32_tree(i32_t_set **root, i32_t_set **new_head, i32node **buffer, int *mag)
{
  i32_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_intersection_tree_i32_t_set(head, new_head, buffer, mag);
}

void __difference_i32_tree(i32_t_set **root, i32_t_set **new_head)
{
  i32_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_difference_tree_i32_t_set(head, new_head);
}

void intersection_i32_t_set(i32_t_set **A, i32_t_set **B, i32node **buffer, int *mag)
{
  __intersect_i32_tree(B, A, buffer, mag);
}

void difference_i32_t_set(i32_t_set **A, i32_t_set **B)
{
  __difference_i32_tree(B, A);
}

void __explore_tree_i32_t_set(i32_t_set *head, i32node **list, int *mag)
{
  if (head == NULL)
    return;
  __explore_tree_i32_t_set(head->left, list, mag);
  add_i32_node(list, head->data, mag);
  __explore_tree_i32_t_set(head->right, list, mag);
}

void elements_i32_t_set(i32_t_set **root, i32node **list, int *mag)
{
  i32_t_set *head = *root;
  if (head == NULL)
    return;
  __explore_tree_i32_t_set(head, list, mag);
}

void __destroy_tree_i32_t_set(i32_t_set *head)
{
  if (head == NULL)
    return;
  __destroy_tree_i32_t_set(head->left);
  free(head);
  __destroy_tree_i32_t_set(head->right);
}

void clear_i32_t_set(i32_t_set **root)
{
  __destroy_tree_i32_t_set(*root);
  *root = NULL;
}

// int main()
// {
//   /**
//    * set<int> s = new set<>()
//    */
//   i32_t_set *s = NULL;

//   /**
//    * s.add(10)
//    * s.add(20)
//    * s.add(5)
//    */
// seed_i32_t_set
//   seed_i32_t_set(&s, 10);
//   seed_i32_t_set(&s, 20);
//   seed_i32_t_set(&s, 5);

//   /**
//    * e = s.elements()
//    */

//   i32node *e = NULL;
//   int e_size = 0;
//   elements_i32_t_set(&s, &e, &e_size);

//   /**
//    * e.print()
//    */

//   view_i32_set(e, e_size);

//   /**
//    * s.discard(20)
//    */

//   delete_i32_t_set(&s, 20);

//   /**
//    * e = s.elements()
//    */

//   e = NULL;
//   e_size = 0;
//   elements_i32_t_set(&s, &e, &e_size);

//   /**
//    * e.print()
//    */
//   view_i32_set(e, e_size);

//   /**
//    * s.clear()
//    */
//   clear_i32_t_set(&s);

//   /**
//    * e = s.elements()
//    */

//   e = NULL;
//   e_size = 0;
//   elements_i32_t_set(&s, &e, &e_size);

//   /**
//    * e.print()
//    */
//   view_i32_set(e, e_size);
// }