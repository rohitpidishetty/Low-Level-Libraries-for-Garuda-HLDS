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
#include <string.h>

#ifndef LINKED_LIST_INT
#include "linked_list_int.c"
#endif

#ifndef LINKED_LIST_STRING
#include "linked_list_string.c"
#endif

typedef struct i32k_ch8v
{
  int key;
  char *value;
  struct i32k_ch8v *left;
  struct i32k_ch8v *right;
} i32node_ch8node_Tree;

#ifndef __i32_KEY_HASH
#define __i32_KEY_HASH
int __i32_key_hash(int key, int *size)
{
  key = ((key >> 16) ^ key) * 0x45d9f3b;
  key = ((key >> 16) ^ key) * 0x45d9f3b;
  key = (key >> 16) ^ key;
  return key % (*size);
}
#endif

i32node_ch8node_Tree *__create_new_i32k_ch8v_node(int key, char *value)
{
  i32node_ch8node_Tree *new_node = (i32node_ch8node_Tree *)malloc(sizeof(i32node_ch8node_Tree));
  new_node->key = key;
  new_node->value = strdup(value);
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void set_dict_i32k_ch8v(i32node_ch8node_Tree **map, int key, int key_index, char *value)
{
  // The tree is yet to grow.
  if (map[key_index] == NULL)
    map[key_index] = __create_new_i32k_ch8v_node(key, value);
  else
  {
    // Tree's root already exists.
    i32node_ch8node_Tree *root = map[key_index];
    while (root != NULL)
    {
      if (root->key > key)
      {
        if (root->left == NULL)
        {
          root->left = __create_new_i32k_ch8v_node(key, value);
          break;
        }
        root = root->left;
      }
      else if (root->key < key)
      {
        if (root->right == NULL)
        {
          root->right = __create_new_i32k_ch8v_node(key, value);
          break;
        }
        root = root->right;
      }
      else
      {
        root->value = strdup(value);
        break;
      }
    }
  }
}

char *get_dict_i32k_ch8v(i32node_ch8node_Tree **map, int key, int *size)
{

  int idx = __i32_key_hash(key, size);
  i32node_ch8node_Tree *root = map[idx];

  if (root == NULL)
    return "null";

  while (root != NULL)
  {
    if (key == root->key)
      return root->value;
    root = (key < root->key) ? root->left : root->right;
  }
  return "null";
}

void *__min_value_i32k_ch8v(i32node_ch8node_Tree *root)
{
  while (root && root->left != NULL)
    root = root->left;

  void **arr = malloc(2 * sizeof(void *));
  arr[0] = (void *)(intptr_t)root->key;
  arr[1] = (void *)root->value;
  return arr;
}

i32node_ch8node_Tree *__delete_i32k_ch8v_binary_tree_node(i32node_ch8node_Tree *root, int key)
{
  if (root == NULL)
    return NULL;

  if (key < root->key)
    root->left = __delete_i32k_ch8v_binary_tree_node(root->left, key);
  else if (key > root->key)
    root->right = __delete_i32k_ch8v_binary_tree_node(root->right, key);
  else
  {
    if (root->left == NULL)
    {
      i32node_ch8node_Tree *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      i32node_ch8node_Tree *temp = root->left;
      free(root);
      return temp;
    }

    void **arr = __min_value_i32k_ch8v(root->right);

    root->key = (int)(intptr_t)arr[0];
    root->value = (char *)arr[1];
    root->right = __delete_i32k_ch8v_binary_tree_node(root->right, (int)(intptr_t)arr[0]);
    free(arr);
  }

  return root;
}

void remove_dict_i32k_ch8v(i32node_ch8node_Tree **map, int key, int key_index)
{
  i32node_ch8node_Tree *temp = __delete_i32k_ch8v_binary_tree_node(map[key_index], key);
  map[key_index] = temp;
}

void __explore_keys_i32k_ch8v(i32node_ch8node_Tree *root, i32node **keys, int *mag)
{
  if (root == NULL)
    return;
  __explore_keys_i32k_ch8v(root->left, keys, mag);
  add_i32_node(keys, root->key, mag);
  __explore_keys_i32k_ch8v(root->right, keys, mag);
}

void keys_dict_i32k_ch8v(i32node_ch8node_Tree **map, int *size, i32node **keys, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_keys_i32k_ch8v(map[loc], keys, mag);
  }
}

void __explore_values_i32k_ch8v(i32node_ch8node_Tree *root, ch8node **values, int *mag)
{
  if (root == NULL)
    return;
  __explore_values_i32k_ch8v(root->left, values, mag);
  add_ch8_node(values, root->value, mag);
  __explore_values_i32k_ch8v(root->right, values, mag);
}

void values_dict_i32k_ch8v(i32node_ch8node_Tree **map, int *size, ch8node **values, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_values_i32k_ch8v(map[loc], values, mag);
  }
}

void __explore_items_i32k_ch8v(i32node_ch8node_Tree *root, ch8node **items, int *mag)
{
  if (root == NULL)
    return;
  __explore_items_i32k_ch8v(root->left, items, mag);
  char *buffer = (char *)malloc(100);
  char *key = (char *)malloc(50);
  char *value = root->value;

  strcpy(buffer, "(");
  sprintf(key, "%d", root->key);
  strcat(buffer, key);
  strcat(buffer, ", ");
  strcat(buffer, value);
  strcat(buffer, ")");
  add_ch8_node(items, buffer, mag);

  __explore_items_i32k_ch8v(root->right, items, mag);
}

void items_dict_i32k_ch8v(i32node_ch8node_Tree **map, int *size, ch8node **items, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_items_i32k_ch8v(map[loc], items, mag);
  }
}

void __clear_i32k_ch8v(i32node_ch8node_Tree *root)
{
  if (root == NULL)
    return;
  __clear_i32k_ch8v(root->left);
  free(root);
  __clear_i32k_ch8v(root->right);
}

void clear_dict_i32k_ch8v(i32node_ch8node_Tree **map, int *size)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
    {
      __clear_i32k_ch8v(map[loc]);
      map[loc] = NULL;
    }
  }
}

// int main()
// {
//   /**
//    * dict<int, str> table5 = new dict<>(10)
//    */
//   int table5_size = 10;
//   i32node_ch8node_Tree *table5[table5_size];
//   for (int i = 0; i < table5_size; i++)
//     table5[i] = NULL;

//   int key = 1;
//   char *value = "hello";
//   set_dict_i32k_ch8v(table5, key, __i32_key_hash(key, &table5_size), value);

//   set_dict_i32k_ch8v(table5, 2, __i32_key_hash(2, &table5_size), "world");
//   printf("%s\n", table5[__i32_key_hash(key, &table5_size)]->value);
//   printf("%s\n", table5[__i32_key_hash(2, &table5_size)]->value);

//   char *data = get_dict_i32k_ch8v(table5, 2, &table5_size);
//   printf("-%s\n", data);

//   remove_dict_i32k_ch8v(table5, 2, __i32_key_hash(2, &table5_size));
//   data = get_dict_i32k_ch8v(table5, 2, &table5_size);
//   printf("%s\n", data);

//   i32node *keys = NULL;
//   int keys_size = 0;
//   keys_dict_i32k_ch8v(table5, &table5_size, &keys, &keys_size);
//   view_i32_node(keys, keys_size);

//   ch8node *values = NULL;
//   int values_size = 0;
//   values_dict_i32k_ch8v(table5, &table5_size, &values, &values_size);
//   view_ch8_node(values, values_size);

//   ch8node *items = NULL;
//   int items_size = 0;
//   items_dict_i32k_ch8v(table5, &table5_size, &items, &items_size);
//   view_ch8_node(items, items_size);

//   clear_dict_i32k_ch8v(table5, &table5_size);

//   data = get_dict_i32k_ch8v(table5, 2, &table5_size);
//   printf("%s\n", data);

//   return 0;
// }