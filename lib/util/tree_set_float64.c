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

#ifndef LINKED_LIST_FLOAT
#define LINKED_LIST_FLOAT
#include "./linked_list_float.c"
#endif

typedef struct tree_set_f64
{
  float data;
  struct tree_set_f64 *left;
  struct tree_set_f64 *right;
} f64_t_set;

f64_t_set *sow_seed_f64_t_set(float data)
{
  f64_t_set *SEED = (f64_t_set *)malloc(sizeof(f64_t_set));
  SEED->data = data;
  SEED->left = NULL;
  SEED->right = NULL;
  return SEED;
}

void view_f64_set(f64node *root, int l1_size)
{
  int position = 1;
  printf("{");
  while (root != NULL)
  {
    printf(position < l1_size ? "%f, " : "%f", root->data);
    root = root->next;
    position++;
  }
  printf("}\n");
}

void seed_f64_t_set(f64_t_set **root, float data)
{
  if ((*root) == NULL)
    (*root) = sow_seed_f64_t_set(data);
  else
  {
    f64_t_set *head = *root;
    while (head != NULL)
    {
      if (head->data > data)
      {

        if (head->left == NULL)
        {
          head->left = sow_seed_f64_t_set(data);
          break;
        }
        head = head->left;
      }
      else if (head->data < data)
      {
        if (head->right == NULL)
        {
          head->right = sow_seed_f64_t_set(data);
          break;
        }
        head = head->right;
      }
      else
        break;
    }
  }
}

float __min__t_s_value_f64(f64_t_set *root)
{
  float min_val = root->data;

  while (root->left != NULL)
  {

    min_val = root->left->data;
    root = root->left;
  }
  return min_val;
}

f64_t_set *__delete_f64_t_set(f64_t_set *root, float data)
{
  //

  if (root == NULL)
    return NULL;

  if (data < root->data)
    root->left = __delete_f64_t_set(root->left, data);
  else if (data > root->data)
    root->right = __delete_f64_t_set(root->right, data);
  else
  {
    if (root->left == NULL)
    {
      f64_t_set *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      f64_t_set *temp = root->left;
      free(root);
      return temp;
    }

    float val = __min__t_s_value_f64(root->right);
    root->data = val;
    root->right = __delete_f64_t_set(root->right, val);
  }
  return root;
}

f64_t_set *delete_f64_t_set(f64_t_set **_root_, float data)
{
  *_root_ = __delete_f64_t_set(*_root_, data);
  return *_root_;
}

void __explore_tree_f64_t_set(f64_t_set *head, f64node **list, int *mag)
{
  if (head == NULL)
    return;
  __explore_tree_f64_t_set(head->left, list, mag);
  add_f64_node(list, head->data, mag);
  __explore_tree_f64_t_set(head->right, list, mag);
}

void elements_f64_t_set(f64_t_set **root, f64node **list, int *mag)
{
  f64_t_set *head = *root;
  if (head == NULL)
    return;
  __explore_tree_f64_t_set(head, list, mag);
}

void __destroy_tree_f64_t_set(f64_t_set *head)
{
  if (head == NULL)
    return;
  __destroy_tree_f64_t_set(head->left);
  free(head);
  __destroy_tree_f64_t_set(head->right);
}

void clear_f64_t_set(f64_t_set **root)
{
  __destroy_tree_f64_t_set(*root);
  *root = NULL;
}

void __seed_f64_difference(f64_t_set **root, float data)
{
  if ((*root) == NULL)
    return;
  else
  {
    f64_t_set *head = *root;
    while (head != NULL)
    {
      if (head->data > data)
        head = head->left;
      else if (head->data < data)
        head = head->right;
      else
      {
        delete_f64_t_set(root, data);
        break;
      };
    }
  }
}

void __seed_f64_intersections(f64_t_set **root, float data, f64node **buffer, int *mag)
{
  if ((*root) == NULL)
    return;
  else
  {
    f64_t_set *head = *root;
    while (head != NULL)
    {
      if (head->data > data)
        head = head->left;
      else if (head->data < data)
        head = head->right;
      else
      {
        add_f64_node(buffer, data, mag);
        break;
      };
    }
  }
}

void __explore_union_tree_f64_t_set(f64_t_set *head, f64_t_set **new_head)
{
  if (head == NULL)
    return;
  __explore_union_tree_f64_t_set(head->left, new_head);
  seed_f64_t_set(new_head, head->data);
  __explore_union_tree_f64_t_set(head->right, new_head);
}

void __explore_intersection_tree_f64_t_set(f64_t_set *head, f64_t_set **new_head, f64node **buffer, int *mag)
{
  if (head == NULL)
    return;
  __explore_intersection_tree_f64_t_set(head->left, new_head, buffer, mag);
  __seed_f64_intersections(new_head, head->data, buffer, mag);
  __explore_intersection_tree_f64_t_set(head->right, new_head, buffer, mag);
}

void __explore_difference_tree_f64_t_set(f64_t_set *head, f64_t_set **new_head)
{
  if (head == NULL)
    return;
  __explore_difference_tree_f64_t_set(head->left, new_head);
  __seed_f64_difference(new_head, head->data);
  __explore_difference_tree_f64_t_set(head->right, new_head);
}

void __union_f64_tree(f64_t_set **root, f64_t_set **new_head)
{
  f64_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_union_tree_f64_t_set(head, new_head);
}

void union_f64_t_set(f64_t_set **A, f64_t_set **B)
{
  __union_f64_tree(B, A);
}

void __intersect_f64_tree(f64_t_set **root, f64_t_set **new_head, f64node **buffer, int *mag)
{
  f64_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_intersection_tree_f64_t_set(head, new_head, buffer, mag);
}

void __difference_f64_tree(f64_t_set **root, f64_t_set **new_head)
{
  f64_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_difference_tree_f64_t_set(head, new_head);
}

void intersection_f64_t_set(f64_t_set **A, f64_t_set **B, f64node **buffer, int *mag)
{
  __intersect_f64_tree(B, A, buffer, mag);
}

void difference_f64_t_set(f64_t_set **A, f64_t_set **B)
{
  __difference_f64_tree(B, A);
}

// int main()
// {
//   /**
//    * set<float> s = new set<>()
//    */
//   f64_t_set *s1 = NULL;

//   /**
//    * s.add(10)
//    * s.add(20)
//    * s.add(5)
//    */
//   seed_f64_t_set(&s1, 1.0);
//   seed_f64_t_set(&s1, 2.0);
//   seed_f64_t_set(&s1, 5.3);

//   /**
//    * e = s.elements()
//    */

//   f64node *e1 = NULL;
//   int e1_size = 0;
//   elements_f64_t_set(&s1, &e1, &e1_size);

//   /**
//    * e.print()
//    */

//   view_f64_set(e1, e1_size);

//   /**
//    * s.discard(20)
//    */

//   delete_f64_t_set(&s1, 2.0);

//   /**
//    * e = s.elements()
//    */

//   e1 = NULL;
//   e1_size = 0;
//   elements_f64_t_set(&s1, &e1, &e1_size);

//   /**
//    * e.print()
//    */
//   view_f64_set(e1, e1_size);

//   /**
//    * s.clear()
//    */
//   clear_f64_t_set(&s1);

//   /**
//    * e = s.elements()
//    */

//   e1 = NULL;
//   e1_size = 0;
//   elements_f64_t_set(&s1, &e1, &e1_size);

//   /**
//    * e.print()
//    */
//   view_f64_set(e1, e1_size);
// }