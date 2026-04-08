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
#ifndef LINKED_LIST_INT
#define LINKED_LIST_INT
#include "./linked_list_int.c"
#endif

typedef struct int32_vec
{
  i32node **vec;
  struct int32_vec *next;
} i32vec;

i32vec *alloc_mem_i32vec()
{
  return (i32vec *)malloc(sizeof(i32vec));
}

void add_i32_vec(i32vec **node, i32node **vec, int *magnitude)
{
  i32vec *new_node = alloc_mem_i32vec();
  if ((*node) == NULL)
  {
    (new_node)->vec = vec;
    (new_node)->next = NULL;
    *node = new_node;
  }
  else
  {
    (new_node)->vec = vec;
    (new_node)->next = NULL;
    i32vec *curr = *node;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void view_i32_vec(i32vec *root, int magnitude)
{
  if (root == NULL)
  {
    printf("[]\n");
    return;
  }
  printf("[\n");
  int pos = 1;
  while (root != NULL)
  {
    printf("  [");
    i32node **payload = root->vec;
    i32node *buffer = (*payload);
    while (buffer != NULL)
    {
      printf(buffer->next != NULL ? "%d, " : "%d", buffer->data);
      buffer = buffer->next;
    }
    printf(pos < magnitude ? "],\n" : "]\n");

    root = root->next;
    pos++;
  }
  printf("]\n");
}

i32node *get_i32_vec(i32vec **root, int index)
{
  int position = 0;
  i32vec *current = (*root);

  while (current != NULL)
  {
    if (position == index)
      return *(current->vec);
    current = current->next;
    position++;
  }

  return NULL;
}

int magnitude_i32_node(i32node **node)
{
  int magnitude = 0;
  i32node *buffer = (*node);
  while (buffer != NULL)
  {
    magnitude++;
    buffer = buffer->next;
  }
  return magnitude;
}

int size_i32_vec(int magnitude)
{
  return magnitude;
}

void insert_at_i32_vec(i32vec **root, i32node **vec, int index, int *magnitude)
{
  int position = 0;
  i32vec *new_node = alloc_mem_i32vec();
  new_node->vec = vec;
  i32vec *prev_node = NULL;
  i32vec *current_node = *root;

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
      i32vec *successor = prev_node->next;
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

int is_empty_i32_vec(int *magnitude)
{
  if ((*magnitude) == 0)
    return 1;
  return 0;
}

void clear_i32_vec(i32vec **root, int *magnitude)
{
  i32vec *current = *root;
  while (current != NULL)
  {
    i32vec *next = current->next;
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void pop_i32_vec(i32vec **root, int *magnitude)
{
  if (*root == NULL || *magnitude == 0)
    return;

  i32vec *current = *root;
  i32vec *prev_node = NULL;

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

void poll_i32_vec(i32vec **node, int *magnitude)
{
  i32vec *root = *node;
  if (root == NULL)
    return;
  *node = (root)->next;
  free(root);
  (*magnitude)--;
}

void delete_at_i32_vec(i32vec **root, int index, int *magnitude)
{
  i32vec *prev_node = NULL;
  i32vec *current_node = (*root);
  int position = 0;
  if (index > (*magnitude) - 1)
  {
    printf("List out of bound error\n");
    exit(1);
  }
  if (index == 0)
  {
    poll_i32_vec(&(*root), magnitude);
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
