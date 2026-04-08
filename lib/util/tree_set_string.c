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
#define LINKED_LIST_STRING
#include "./linked_list_string.c"
#endif

typedef struct tree_set_ch8
{
  char *data;
  long d_ref_pointer;
  struct tree_set_ch8 *left;
  struct tree_set_ch8 *right;
} ch8_t_set;

ch8_t_set *sow_seed_ch8_t_set(char *data, long id)
{
  ch8_t_set *SEED = (ch8_t_set *)malloc(sizeof(ch8_t_set));
  SEED->data = strdup(data);
  SEED->d_ref_pointer = id;
  SEED->left = NULL;
  SEED->right = NULL;
  return SEED;
}

void view_ch8_set(ch8node *root, int l1_size)
{
  int position = 1;
  printf("{");
  while (root != NULL)
  {
    printf(position < l1_size ? "%s, " : "%s", root->data);
    root = root->next;
    position++;
  }
  printf("}\n");
}
long __dref__(char *data)
{
  int len = strlen(data);
  long KEY_INDEX = 0;
  char *parent = (char *)malloc(50);
  strcpy(parent, "1");
  for (int i = 0; i < len; i++)
  {
    int k = data[i] - '0';
    char *buff = (char *)malloc(50);
    sprintf(buff, "%d", k);
    strcat(parent, buff);
    KEY_INDEX += k;
  }

  return KEY_INDEX;
}
void seed_ch8_t_set(ch8_t_set **root, char *data)
{
  long id = __dref__(data);
  if ((*root) == NULL)
    (*root) = sow_seed_ch8_t_set(data, id);
  else
  {
    ch8_t_set *head = *root;
    while (head != NULL)
    {
      if (head->d_ref_pointer > id)
      {

        if (head->left == NULL)
        {
          head->left = sow_seed_ch8_t_set(data, id);
          break;
        }
        head = head->left;
      }
      else if (head->d_ref_pointer < id)
      {
        if (head->right == NULL)
        {
          head->right = sow_seed_ch8_t_set(data, id);
          break;
        }
        head = head->right;
      }
      else
        break;
    }
  }
}

char *__min__t_s_value_ch8(ch8_t_set *root)
{
  char *min_val = strdup(root->data);

  while (root->left != NULL)
  {

    min_val = root->left->data;
    root = root->left;
  }
  return min_val;
}

ch8_t_set *__delete_ch8_t_set(ch8_t_set *root, char *data)
{
  //
  long id = __dref__(data);

  if (root == NULL)
    return NULL;

  if (id < root->d_ref_pointer)
    root->left = __delete_ch8_t_set(root->left, data);
  else if (id > root->d_ref_pointer)
    root->right = __delete_ch8_t_set(root->right, data);
  else
  {

    if (root->left == NULL)
    {
      ch8_t_set *temp = root->right;
      free(root->data);
      // free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      ch8_t_set *temp = root->left;
      free(root->data);
      // free(root);
      return temp;
    }

    char *val = __min__t_s_value_ch8(root->right);
    root->data = strdup(val);
    root->d_ref_pointer = __dref__(val);
    root->right = __delete_ch8_t_set(root->right, val);
  }
  return root;
}

ch8_t_set *delete_ch8_t_set(ch8_t_set **_root_, char *data)
{
  *_root_ = __delete_ch8_t_set(*_root_, data);
  return *_root_;
}

void __explore_tree_ch8_t_set(ch8_t_set *head, ch8node **list, int *mag)
{
  if (head == NULL)
    return;
  __explore_tree_ch8_t_set(head->left, list, mag);
  add_ch8_node(list, head->data, mag);
  __explore_tree_ch8_t_set(head->right, list, mag);
}

void elements_ch8_t_set(ch8_t_set **root, ch8node **list, int *mag)
{
  ch8_t_set *head = *root;
  if (head == NULL)
    return;

  __explore_tree_ch8_t_set(head, list, mag);
}

void __destroy_tree_ch8_t_set(ch8_t_set *head)
{
  if (head == NULL)
    return;
  __destroy_tree_ch8_t_set(head->left);

  free(head);
  __destroy_tree_ch8_t_set(head->right);
}

void clear_ch8_t_set(ch8_t_set **root)
{
  __destroy_tree_ch8_t_set(*root);
  *root = NULL;
}

void __seed_ch8_difference(ch8_t_set **root, char *data)
{
  long id = __dref__(data);
  if ((*root) == NULL)
    return;
  else
  {
    ch8_t_set *head = *root;
    while (head != NULL)
    {
      if (head->d_ref_pointer > id)
        head = head->left;
      else if (head->d_ref_pointer < id)
        head = head->right;
      else
      {
        // printf("rq : %s\n", data);
        delete_ch8_t_set(root, data);
        break;
      };
    }
  }
}

void __seed_ch8_intersections(ch8_t_set **root, char *data, ch8node **buffer, int *mag)
{
  long id = __dref__(data);
  if ((*root) == NULL)
    return;
  else
  {
    ch8_t_set *head = *root;
    while (head != NULL)
    {
      if (head->d_ref_pointer > id)
        head = head->left;
      else if (head->d_ref_pointer < id)
        head = head->right;
      else
      {
        add_ch8_node(buffer, data, mag);
        break;
      };
    }
  }
}

void __explore_union_tree_ch8_t_set(ch8_t_set *head, ch8_t_set **new_head)
{
  if (head == NULL)
    return;
  __explore_union_tree_ch8_t_set(head->left, new_head);
  seed_ch8_t_set(new_head, head->data);
  __explore_union_tree_ch8_t_set(head->right, new_head);
}

void __explore_intersection_tree_ch8_t_set(ch8_t_set *head, ch8_t_set **new_head, ch8node **buffer, int *mag)
{
  if (head == NULL)
    return;
  __explore_intersection_tree_ch8_t_set(head->left, new_head, buffer, mag);
  __seed_ch8_intersections(new_head, head->data, buffer, mag);
  __explore_intersection_tree_ch8_t_set(head->right, new_head, buffer, mag);
}

void __explore_difference_tree_ch8_t_set(ch8_t_set *head, ch8_t_set **new_head)
{
  if (head == NULL)
    return;
  __explore_difference_tree_ch8_t_set(head->left, new_head);

  __seed_ch8_difference(new_head, head->data);
  __explore_difference_tree_ch8_t_set(head->right, new_head);
}

void __union_ch8_tree(ch8_t_set **root, ch8_t_set **new_head)
{
  ch8_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_union_tree_ch8_t_set(head, new_head);
}

void union_ch8_t_set(ch8_t_set **A, ch8_t_set **B)
{
  __union_ch8_tree(B, A);
}

void __intersect_ch8_tree(ch8_t_set **root, ch8_t_set **new_head, ch8node **buffer, int *mag)
{
  ch8_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_intersection_tree_ch8_t_set(head, new_head, buffer, mag);
}

void __difference_ch8_tree(ch8_t_set **root, ch8_t_set **new_head)
{
  ch8_t_set *head = *root;
  if (head == NULL || (*new_head) == NULL)
    return;
  __explore_difference_tree_ch8_t_set(head, new_head);
}

void intersection_ch8_t_set(ch8_t_set **A, ch8_t_set **B, ch8node **buffer, int *mag)
{
  __intersect_ch8_tree(B, A, buffer, mag);
}

void difference_ch8_t_set(ch8_t_set **A, ch8_t_set **B)
{
  __difference_ch8_tree(B, A);
}

// int main()
// {
//   /**
//    * set<str> s = new set<>()
//    */
//   ch8_t_set *s = NULL;

//   seed_ch8_t_set(&s, "ram");
//   seed_ch8_t_set(&s, "ram");
//   seed_ch8_t_set(&s, "ramesh");

//   ch8node *e = NULL;
//   int e_size = 0;
//   elements_ch8_t_set(&s, &e, &e_size);

//   view_ch8_set(e, e_size);

//   delete_ch8_t_set(&s, "20");

//   e = NULL;
//   e_size = 0;
//   elements_ch8_t_set(&s, &e, &e_size);

//   view_ch8_set(e, e_size);

//   clear_ch8_t_set(&s);

//   e = NULL;
//   e_size = 0;
//   elements_ch8_t_set(&s, &e, &e_size);

//   view_ch8_set(e, e_size);
// }
