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
#include "linked_list_int.c"
#endif

#ifndef LINKED_LIST_STRING
#include "linked_list_string.c"
#endif

typedef struct i32k_i32v
{
  int key;
  int value;
  struct i32k_i32v *left;
  struct i32k_i32v *right;
} i32node_i32node_Tree;
// i32node: int(key)_i32node:int(value) tree
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

i32node_i32node_Tree *__create_new_i32k_i32v_node(int key, int value)
{
  i32node_i32node_Tree *new_node = (i32node_i32node_Tree *)malloc(sizeof(i32node_i32node_Tree));
  new_node->key = key;
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

int *__min_value(i32node_i32node_Tree *root)
{
  int min_val = root->value;
  int min_key = root->key;

  while (root->left != NULL)
  {
    min_key = root->left->key;
    min_val = root->left->value;
    root = root->left;
  }
  int *arr = (int *)malloc(2 * sizeof(int));
  arr[0] = root->key;
  arr[1] = root->value;
  return arr;
}

i32node_i32node_Tree *__delete_i32k_binary_tree_node(i32node_i32node_Tree *root, int key)
{
  if (root == NULL)
    return NULL;

  if (key < root->key)
    root->left = __delete_i32k_binary_tree_node(root->left, key);
  else if (key > root->key)
    root->right = __delete_i32k_binary_tree_node(root->right, key);
  else
  {
    if (root->left == NULL)
    {
      i32node_i32node_Tree *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      i32node_i32node_Tree *temp = root->left;
      free(root);
      return temp;
    }

    int *arr = __min_value(root->right);

    root->key = arr[0];
    root->value = arr[1];
    root->right = __delete_i32k_binary_tree_node(root->right, arr[0]);
    free(arr);
  }

  return root;
}

void remove_dict_i32k_i32v(i32node_i32node_Tree **map, int key, int key_index)
{
  i32node_i32node_Tree *temp = __delete_i32k_binary_tree_node(map[key_index], key);
  map[key_index] = temp;
}

void set_dict_i32k_i32v(i32node_i32node_Tree **map, int key, int key_index, int value)
{
  // The tree is yet to grow.
  if (map[key_index] == NULL)
    map[key_index] = __create_new_i32k_i32v_node(key, value);
  else
  {
    // Tree's root already exists.
    i32node_i32node_Tree *root = map[key_index];
    while (root != NULL)
    {
      if (root->key > key)
      {
        if (root->left == NULL)
        {
          root->left = __create_new_i32k_i32v_node(key, value);
          break;
        }
        root = root->left;
      }
      else if (root->key < key)
      {
        if (root->right == NULL)
        {
          root->right = __create_new_i32k_i32v_node(key, value);
          break;
        }
        root = root->right;
      }
      else
      {
        root->value = value;
        break;
      }
    }
  }
}

int get_dict_i32k_i32v(i32node_i32node_Tree **map, int key, int *size)
{
  int idx = __i32_key_hash(key, size);
  i32node_i32node_Tree *root = map[idx];
  while (root != NULL)
  {
    if (key == root->key)
      return root->value;
    root = (key < root->key) ? root->left : root->right;
  }
  return -1;
}

void __explore_keys_i32k_i32v(i32node_i32node_Tree *root, i32node **keys, int *mag)
{
  if (root == NULL)
    return;
  __explore_keys_i32k_i32v(root->left, keys, mag);
  add_i32_node(keys, root->key, mag);
  __explore_keys_i32k_i32v(root->right, keys, mag);
}

void __explore_items_i32k_i32v(i32node_i32node_Tree *root, ch8node **items, int *mag)
{
  if (root == NULL)
    return;
  __explore_items_i32k_i32v(root->left, items, mag);
  char *buffer = (char *)malloc(100);
  char *key = (char *)malloc(50);
  char *value = (char *)malloc(50);
  strcpy(buffer, "(");
  sprintf(key, "%d", root->key);
  sprintf(value, "%d", root->value);
  strcat(buffer, key);
  strcat(buffer, ", ");
  strcat(buffer, value);
  strcat(buffer, ")");
  add_ch8_node(items, buffer, mag);
  __explore_items_i32k_i32v(root->right, items, mag);
}

void __explore_values_i32k_i32v(i32node_i32node_Tree *root, i32node **values, int *mag)
{
  if (root == NULL)
    return;
  __explore_values_i32k_i32v(root->left, values, mag);
  add_i32_node(values, root->value, mag);
  __explore_values_i32k_i32v(root->right, values, mag);
}

void keys_dict_i32k_i32v(i32node_i32node_Tree **map, int *size, i32node **keys, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_keys_i32k_i32v(map[loc], keys, mag);
  }
}

void values_dict_i32k_i32v(i32node_i32node_Tree **map, int *size, i32node **values, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_values_i32k_i32v(map[loc], values, mag);
  }
}

void items_dict_i32k_i32v(i32node_i32node_Tree **map, int *size, ch8node **items, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_items_i32k_i32v(map[loc], items, mag);
  }
}

void __clear_i32k_i32v(i32node_i32node_Tree *root)
{
  if (root == NULL)
    return;
  __clear_i32k_i32v(root->left);
  free(root);
  __clear_i32k_i32v(root->right);
}

void clear_dict_i32k_i32v(i32node_i32node_Tree **map, int *size)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
    {
      __clear_i32k_i32v(map[loc]);
      map[loc] = NULL;
    }
  }
}

// int main()
// {
//   /**
//    * dict<int, int> map = new dict<>(10)
//    */
//   int map_size = 10;
//   i32node_i32node_Tree *map[map_size];
//   for (int i = 0; i < map_size; i++)
//     map[i] = NULL;

//   /**
//    * key = 1
//    * value = 100
//    * map.set(key, value)
//    */
//   int key = 1;
//   int value = 100;
//   set_dict_i32k_i32v(map, key, __i32_key_hash(key, &map_size), value);
//   // --------------
//   set_dict_i32k_i32v(map, 2, __i32_key_hash(2, &map_size), 5674);

//   set_dict_i32k_i32v(map, 3, __i32_key_hash(3, &map_size), 3434);

//   /**
//    * map.set(7, 234)
//    */
//   set_dict_i32k_i32v(map, 7, __i32_key_hash(7, &map_size), 234);

//   /**
//    * v = map.get(7)
//    */
//   int v = get_dict_i32k_i32v(map, 7, &map_size);
//   printf("%d\n", v);

//   /**
//    * map.remove(7)
//    */
//   remove_dict_i32k_i32v(map, 7, __i32_key_hash(7, &map_size));

//   /**
//    * keys = map.keys()
//    * keys.view()
//    */

//   i32node *keys = NULL;
//   int keys_size = 0;
//   keys_dict_i32k_i32v(map, &map_size, &keys, &keys_size);
//   view_i32_node(keys, keys_size);

//   /**
//    * values = map.values()
//    * values.view()
//    */
//   i32node *values = NULL;
//   int values_size = 0;
//   values_dict_i32k_i32v(map, &map_size, &values, &values_size);
//   view_i32_node(values, values_size);

//   /**
//    * items = map.items()
//    * items.view()
//    */
//   ch8node *items = NULL;
//   int items_size = 0;
//   items_dict_i32k_i32v(map, &map_size, &items, &items_size);
//   view_ch8_node(items, items_size);

//   /**
//    * map.clear()
//    */
//   clear_dict_i32k_i32v(map, &map_size);

//   return 0;
// }