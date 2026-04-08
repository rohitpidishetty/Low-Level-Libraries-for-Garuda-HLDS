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

#ifndef LINKED_LIST_FLOAT
#include "linked_list_float.c"
#endif

#ifndef LINKED_LIST_STRING
#include "linked_list_string.c"
#endif

typedef struct i32k_f64v
{
  int key;
  float value;
  struct i32k_f64v *left;
  struct i32k_f64v *right;
} i32node_f64node_Tree;

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

i32node_f64node_Tree *__create_new_i32k_f64v_node(int key, float value)
{
  i32node_f64node_Tree *new_node = (i32node_f64node_Tree *)malloc(sizeof(i32node_f64node_Tree));
  new_node->key = key;
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void *__min_value_f64v(i32node_f64node_Tree *root)
{
  float min_val = root->value;
  int min_key = root->key;

  while (root->left != NULL)
  {
    min_key = root->left->key;
    min_val = root->left->value;
    root = root->left;
  }
  void **arr = malloc(2 * sizeof(void *));
  arr[0] = (void *)(intptr_t)root->key;
  arr[1] = (void *)(intptr_t)root->value;
  return arr;
}

i32node_f64node_Tree *__delete_i32k_f64v_binary_tree_node(i32node_f64node_Tree *root, int key)
{
  if (root == NULL)
    return NULL;

  if (key < root->key)
    root->left = __delete_i32k_f64v_binary_tree_node(root->left, key);
  else if (key > root->key)
    root->right = __delete_i32k_f64v_binary_tree_node(root->right, key);
  else
  {
    if (root->left == NULL)
    {
      i32node_f64node_Tree *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      i32node_f64node_Tree *temp = root->left;
      free(root);
      return temp;
    }

    int *arr = __min_value_f64v(root->right);

    root->key = (int)(intptr_t)arr[0];
    root->value = (float)arr[1];
    root->right = __delete_i32k_f64v_binary_tree_node(root->right, arr[0]);
    free(arr);
  }

  return root;
}

void remove_dict_i32k_f64v(i32node_f64node_Tree **map3, int key, int key_index)
{
  i32node_f64node_Tree *temp = __delete_i32k_f64v_binary_tree_node(map3[key_index], key);
  map3[key_index] = temp;
}

void set_dict_i32k_f64v(i32node_f64node_Tree **map3, int key, int key_index, float value)
{
  // The tree is yet to grow.
  if (map3[key_index] == NULL)
    map3[key_index] = __create_new_i32k_f64v_node(key, value);
  else
  {
    // Tree's root already exists.
    i32node_f64node_Tree *root = map3[key_index];
    while (root != NULL)
    {
      if (root->key > key)
      {
        if (root->left == NULL)
        {
          root->left = __create_new_i32k_f64v_node(key, value);
          break;
        }
        root = root->left;
      }
      else if (root->key < key)
      {
        if (root->right == NULL)
        {
          root->right = __create_new_i32k_f64v_node(key, value);
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

float get_dict_i32k_f64v(i32node_f64node_Tree **map3, int key, int *size)
{
  int idx = __i32_key_hash(key, size);
  i32node_f64node_Tree *root = map3[idx];
  while (root != NULL)
  {
    if (key == root->key)
      return root->value;
    root = (key < root->key) ? root->left : root->right;
  }
  return -1;
}

void __explore_keys_i32k_f64v(i32node_f64node_Tree *root, i32node **keys, int *mag)
{
  if (root == NULL)
    return;
  __explore_keys_i32k_f64v(root->left, keys, mag);
  add_i32_node(keys, root->key, mag);
  __explore_keys_i32k_f64v(root->right, keys, mag);
}

void __explore_items_i32k_f64v(i32node_f64node_Tree *root, ch8node **items, int *mag)
{
  if (root == NULL)
    return;
  __explore_items_i32k_f64v(root->left, items, mag);
  char *buffer = (char *)malloc(100);
  char *key = (char *)malloc(50);
  char *value = (char *)malloc(50);
  strcpy(buffer, "(");
  sprintf(key, "%d", root->key);
  sprintf(value, "%f", root->value);
  strcat(buffer, key);
  strcat(buffer, ", ");
  strcat(buffer, value);
  strcat(buffer, ")");
  add_ch8_node(items, buffer, mag);
  __explore_items_i32k_f64v(root->right, items, mag);
}

void __explore_values_i32k_f64v(i32node_f64node_Tree *root, f64node **values, int *mag)
{
  if (root == NULL)
    return;
  __explore_values_i32k_f64v(root->left, values, mag);
  add_f64_node(values, root->value, mag);
  __explore_values_i32k_f64v(root->right, values, mag);
}

void keys_dict_i32k_f64v(i32node_f64node_Tree **map3, int *size, i32node **keys, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map3[loc] != NULL)
      __explore_keys_i32k_f64v(map3[loc], keys, mag);
  }
}

void values_dict_i32k_f64v(i32node_f64node_Tree **map3, int *size, f64node **values, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map3[loc] != NULL)
      __explore_values_i32k_f64v(map3[loc], values, mag);
  }
}

void items_dict_i32k_f64v(i32node_f64node_Tree **map3, int *size, ch8node **items, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map3[loc] != NULL)
      __explore_items_i32k_f64v(map3[loc], items, mag);
  }
}

void __clear_i32k_f64v(i32node_f64node_Tree *root)
{
  if (root == NULL)
    return;
  __clear_i32k_f64v(root->left);
  free(root);
  __clear_i32k_f64v(root->right);
}

void clear_dict_i32k_f64v(i32node_f64node_Tree **map3, int *size)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map3[loc] != NULL)
    {
      __clear_i32k_f64v(map3[loc]);
      map3[loc] = NULL;
    }
  }
}

// int main()
// {
//   /**
//    * dict<int, int> map3 = new dict<>(10)
//    */
//   int map3_size = 10;
//   i32node_f64node_Tree *map3[map3_size];
//   for (int i = 0; i < map3_size; i++)
//     map3[i] = NULL;

//   /**
//    * map3.set(1, 100.23)
//    */
//   set_dict_i32k_f64v(map3, 1, __i32_key_hash(1, &map3_size), 100.23);
//   set_dict_i32k_f64v(map3, 2, __i32_key_hash(2, &map3_size), 56.74);
//   set_dict_i32k_f64v(map3, 3, __i32_key_hash(3, &map3_size), 343.4);
//   set_dict_i32k_f64v(map3, 7, __i32_key_hash(7, &map3_size), 2.34);

//   /**
//    * v = map3.get(7)
//    */
//   float v = get_dict_i32k_f64v(map3, 7, &map3_size);
//   printf("%f\n", v);

//   /**
//    * map3.remove(7)
//    */
//   remove_dict_i32k_f64v(map3, 7, __i32_key_hash(7, &map3_size));

//   /**
//    * keys = map3.keys()
//    * keys.view()
//    */

//   i32node *keys = NULL;
//   int keys_size = 0;
//   keys_dict_i32k_f64v(map3, &map3_size, &keys, &keys_size);
//   view_i32_node(keys, keys_size);

//   /**
//    * values = map3.values()
//    * values.view()
//    */
//   f64node *values = NULL;
//   int values_size = 0;
//   values_dict_i32k_f64v(map3, &map3_size, &values, &values_size);
//   view_f64_node(values, values_size);

//   /**
//    * items = map3.items()
//    * items.view()
//    */
//   ch8node *items = NULL;
//   int items_size = 0;
//   items_dict_i32k_f64v(map3, &map3_size, &items, &items_size);
//   view_ch8_node(items, items_size);

//   /**
//    * map3.clear()
//    */
//   clear_dict_i32k_f64v(map3, &map3_size);

//   return 0;
// }