#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\util\linked_list_int.c"

typedef struct ch8k_any_dtype
{
  char *key;
  void *value;
  char *index;
  struct ch8k_any_dtype *left;
  struct ch8k_any_dtype *right;
} ch8node_any_dtype_node_Tree;

typedef struct key
{
  int table_key;
  char *dRef_key;
} any_map_dRefKey;

ch8node_any_dtype_node_Tree *__create_new_ch8k_any_dtype_node(char *key, void *value, char *dref_key)
{
  ch8node_any_dtype_node_Tree *new_node = (ch8node_any_dtype_node_Tree *)malloc(sizeof(ch8node_any_dtype_node_Tree));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->index = strdup(dref_key);
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

any_map_dRefKey *__ch8_key_hash_any_map(char *key, int *size)
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
  any_map_dRefKey *drk = (any_map_dRefKey *)malloc(sizeof(any_map_dRefKey));
  drk->table_key = KEY_INDEX;
  drk->dRef_key = strdup(parent);
  return drk;
}

void set_dict_ch8k_any_dtype(ch8node_any_dtype_node_Tree **map, char *key, any_map_dRefKey *dref, void *value)
{
  // The tree is yet to grow.
  if (map[dref->table_key] == NULL)
    map[dref->table_key] = __create_new_ch8k_any_dtype_node(key, value, dref->dRef_key);
  else
  {
    int key_index = atoi(dref->dRef_key);
    // Tree's root already exists.
    ch8node_any_dtype_node_Tree *root = map[dref->table_key];
    while (root != NULL)
    {
      if (atoi(root->index) > key_index)
      {
        if (root->left == NULL)
        {
          root->left = __create_new_ch8k_any_dtype_node(key, value, dref->dRef_key);
          break;
        }
        root = root->left;
      }
      else if (atoi(root->index) < key_index)
      {
        if (root->right == NULL)
        {
          root->right = __create_new_ch8k_any_dtype_node(key, value, dref->dRef_key);
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

void main()
{
  // dict<T, ?> map6 = new map<>(10)
  // T: type string be default
  // ?: Can be any dtype

  // dict<T, ?> map6 = new map<>(10)
  int map6_size = 10;
  ch8node_any_dtype_node_Tree *map6[map6_size];
  for (int i = 0; i < map6_size; i++)
    map6[i] = NULL;

  // list<int> l1 = new list<>()
  i32node *l1 = NULL;
  int l1_size = 0;

  // l1.push(1)
  add_i32_node(&l1, 1, &l1_size);
  // l1.push(2)
  add_i32_node(&l1, 2, &l1_size);
  // l1.push(3)
  add_i32_node(&l1, 3, &l1_size);
  // l1.push(4)
  add_i32_node(&l1, 4, &l1_size);

  // map6.set("hello", l1)
  set_dict_ch8k_any_dtype(map6, "hello", __ch8_key_hash_any_map("hello", &map6_size), l1);

  // list<int> l2 = new list<>()
  i32node *l2 = NULL;
  int l2_size = 0;

  // l2.push(10)
  add_i32_node(&l2, 10, &l2_size);
  // l2.push(20)
  add_i32_node(&l2, 20, &l2_size);
  // l2.push(30)
  add_i32_node(&l2, 30, &l2_size);
  // l2.push(40)
  add_i32_node(&l2, 40, &l2_size);

  // map6.set("hi", l2)
  set_dict_ch8k_any_dtype(map6, "hi", __ch8_key_hash_any_map("hi", &map6_size), l2);
}