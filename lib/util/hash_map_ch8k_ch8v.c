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

typedef struct ch8k_ch8v
{
  char *key;
  char *value;
  char *index;
  struct ch8k_ch8v *left;
  struct ch8k_ch8v *right;
} ch8node_ch8node_Tree;

#ifndef D_REF_KEY
#define D_REF_KEY
typedef struct key
{
  int table_key;
  char *dRef_key;
} dRefKey;
#endif

#ifndef __ch8_KEY_HASH
#define __ch8_KEY_HASH
dRefKey *__ch8_key_hash(char *key, int *size)
{
  int len = strlen(key);
  int KEY_INDEX = 0;
  char *parent = (char *)malloc(50);
  strcpy(parent, "1");
  for (int i = 0; i < len; i++)
  {
    int k = key[i] - '0';
    char *buff = (char *)malloc(50);
    sprintf(buff, "%d", k);
    strcat(parent, buff);
    KEY_INDEX += k;
  }
  KEY_INDEX %= (*size);
  // printf("-> %s\n", parent);
  dRefKey *drk = (dRefKey *)malloc(sizeof(dRefKey));
  drk->table_key = KEY_INDEX;
  drk->dRef_key = strdup(parent);
  return drk;
}
#endif

ch8node_ch8node_Tree *__create_new_ch8k_ch8v_node(char *key, char *value, char *dref_key)
{
  ch8node_ch8node_Tree *new_node = (ch8node_ch8node_Tree *)malloc(sizeof(ch8node_ch8node_Tree));
  new_node->key = strdup(key);
  new_node->value = strdup(value);
  new_node->index = strdup(dref_key);
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void set_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, char *key, dRefKey *dref, char *value)
{
  // The tree is yet to grow.
  if (map[dref->table_key] == NULL)
    map[dref->table_key] = __create_new_ch8k_ch8v_node(key, value, dref->dRef_key);
  else
  {
    int key_index = atoi(dref->dRef_key);
    // Tree's root already exists.
    ch8node_ch8node_Tree *root = map[dref->table_key];
    while (root != NULL)
    {
      if (atoi(root->index) > key_index)
      {
        if (root->left == NULL)
        {
          root->left = __create_new_ch8k_ch8v_node(key, value, dref->dRef_key);
          break;
        }
        root = root->left;
      }
      else if (atoi(root->index) < key_index)
      {
        if (root->right == NULL)
        {
          root->right = __create_new_ch8k_ch8v_node(key, value, dref->dRef_key);
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

void *__min_value_ch8k_ch8v(ch8node_ch8node_Tree *root)
{
  while (root && root->left != NULL)
    root = root->left;

  void **arr = malloc(3 * sizeof(void *));
  arr[0] = (void *)root->key;
  arr[1] = (void *)root->value;
  arr[2] = (void *)root->index;
  return arr;
}

ch8node_ch8node_Tree *__delete_ch8k_ch8v_binary_tree_node(ch8node_ch8node_Tree *root, char *dref_key)
{
  if (root == NULL)
    return NULL;
  int key = atoi(dref_key);
  int y = atoi(root->index);
  if (key < y)
    root->left = __delete_ch8k_ch8v_binary_tree_node(root->left, dref_key);
  else if (key > y)
    root->right = __delete_ch8k_ch8v_binary_tree_node(root->right, dref_key);
  else
  {
    if (root->left == NULL)
    {
      ch8node_ch8node_Tree *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      ch8node_ch8node_Tree *temp = root->left;
      free(root);
      return temp;
    }
    void **arr = __min_value_ch8k_ch8v(root->right);

    root->key = (char *)arr[0];
    root->value = (char *)arr[1];
    root->index = (char *)arr[2];
    root->right = __delete_ch8k_ch8v_binary_tree_node(root->right, (char *)arr[2]);

    free(arr);
  }
  return root;
}

void remove_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, char *key, dRefKey *dref)
{
  ch8node_ch8node_Tree *temp = __delete_ch8k_ch8v_binary_tree_node(map[dref->table_key], dref->dRef_key);
  map[dref->table_key] = temp;
}

char *get_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, char *key, int *size)
{
  dRefKey *idx = __ch8_key_hash(key, size);
  ch8node_ch8node_Tree *root = map[idx->table_key];
  long x = 0, y = 0;
  if (root == NULL)
    return "null";
  while (root != NULL)
  {
    x = atoi(root->index);
    y = atoi(idx->dRef_key);
    if (x == y)
      return root->value;
    root = (y < x) ? root->left : root->right;
  }
  return "null";
}

void __explore_keys_ch8k_ch8v(ch8node_ch8node_Tree *root, ch8node **keys, int *mag)
{
  if (root == NULL)
    return;
  __explore_keys_ch8k_ch8v(root->left, keys, mag);
  add_ch8_node(keys, root->key, mag);
  __explore_keys_ch8k_ch8v(root->right, keys, mag);
}

void keys_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, int *size, ch8node **keys, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_keys_ch8k_ch8v(map[loc], keys, mag);
  }
}

void __explore_values_ch8k_ch8v(ch8node_ch8node_Tree *root, ch8node **values, int *mag)
{
  if (root == NULL)
    return;
  __explore_values_ch8k_ch8v(root->left, values, mag);
  add_ch8_node(values, root->value, mag);
  __explore_values_ch8k_ch8v(root->right, values, mag);
}

void values_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, int *size, ch8node **values, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_values_ch8k_ch8v(map[loc], values, mag);
  }
}

void __explore_items_ch8k_ch8v(ch8node_ch8node_Tree *root, ch8node **items, int *mag)
{
  if (root == NULL)
    return;
  __explore_items_ch8k_ch8v(root->left, items, mag);
  char *buffer = (char *)malloc(100);
  strcpy(buffer, "(");
  strcat(buffer, root->key);
  strcat(buffer, ", ");
  strcat(buffer, root->value);
  strcat(buffer, ")");
  add_ch8_node(items, buffer, mag);
  __explore_items_ch8k_ch8v(root->right, items, mag);
}

void items_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, int *size, ch8node **items, int *mag)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
      __explore_items_ch8k_ch8v(map[loc], items, mag);
  }
}

void __clear_ch8k_ch8v(ch8node_ch8node_Tree *root)
{
  if (root == NULL)
    return;
  __clear_ch8k_ch8v(root->left);
  free(root);
  __clear_ch8k_ch8v(root->right);
}

void clear_dict_ch8k_ch8v(ch8node_ch8node_Tree **map, int *size)
{
  int loc = 0;
  for (; loc < (*size); loc++)
  {
    if (map[loc] != NULL)
    {
      __clear_ch8k_ch8v(map[loc]);
      map[loc] = NULL;
    }
  }
}

// int main()
// {
//   /**
//    * dict<str, str> map5 = new dict<>(10)
//    */
//   int map5_size = 10;
//   ch8node_ch8node_Tree *map5[map5_size];
//   for (int i = 0; i < map5_size; i++)
//     map5[i] = NULL;

//   set_dict_ch8k_ch8v(map5, "hello", __ch8_key_hash("hello", &map5_size), "a");
//   set_dict_ch8k_ch8v(map5, "world", __ch8_key_hash("world", &map5_size), "b");
//   set_dict_ch8k_ch8v(map5, "how", __ch8_key_hash("how", &map5_size), "c");

//   set_dict_ch8k_ch8v(map5, "are", __ch8_key_hash("are", &map5_size), "d");

//   char *v = get_dict_ch8k_ch8v(map5, "hello", &map5_size);
//   printf("%s\n", v);

//   v = get_dict_ch8k_ch8v(map5, "how", &map5_size);
//   printf("%s\n", v);

//   remove_dict_ch8k_ch8v(map5, "how", __ch8_key_hash("how", &map5_size));

//   v = get_dict_ch8k_ch8v(map5, "how", &map5_size);
//   printf("%s\n", v);

//   ch8node *keys5 = NULL;
//   int keys5_size = 0;
//   keys_dict_ch8k_ch8v(map5, &map5_size, &keys5, &keys5_size);
//   view_ch8_node(keys5, keys5_size);

//   ch8node *values5 = NULL;
//   int values5_size = 0;
//   values_dict_ch8k_ch8v(map5, &map5_size, &values5, &values5_size);
//   view_ch8_node(values5, values5_size);

//   ch8node *items5 = NULL;
//   int items5_size = 0;
//   items_dict_ch8k_ch8v(map5, &map5_size, &items5, &items5_size);
//   view_ch8_node(items5, items5_size);

//   clear_dict_ch8k_ch8v(map5, &map5_size);

//   return 0;
// }