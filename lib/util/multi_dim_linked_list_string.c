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
#ifndef LINKED_LIST_STRING
#define LINKED_LIST_STRING
#include "./linked_list_string.c"
#endif

typedef struct ch8_vec
{
  ch8node **vec;
  struct ch8_vec *next;
} ch8vec;

ch8vec *alloc_mem_ch8vec()
{
  return (ch8vec *)malloc(sizeof(ch8vec));
}

void add_ch8_vec(ch8vec **node, ch8node **vec, int *magnitude)
{
  ch8vec *new_node = alloc_mem_ch8vec();
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
    ch8vec *curr = *node;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void view_ch8_vec(ch8vec *root, int magnitude)
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
    ch8node **payload = root->vec;
    ch8node *buffer = (*payload);
    while (buffer != NULL)
    {
      printf(buffer->next != NULL ? "%s, " : "%s", buffer->data);
      buffer = buffer->next;
    }
    printf(pos < magnitude ? "],\n" : "]\n");

    root = root->next;
    pos++;
  }
  printf("]\n");
}

ch8node *get_ch8_vec(ch8vec **root, int index)
{
  int position = 0;
  ch8vec *current = (*root);

  while (current != NULL)
  {
    if (position == index)
      return *(current->vec);
    current = current->next;
    position++;
  }

  return NULL;
}

int magnitude_ch8_node(ch8node **node)
{
  int magnitude = 0;
  ch8node *buffer = (*node);
  while (buffer != NULL)
  {
    magnitude++;
    buffer = buffer->next;
  }
  return magnitude;
}

int size_ch8_vec(int magnitude)
{
  return magnitude;
}

void insert_at_ch8_vec(ch8vec **root, ch8node **vec, int index, int *magnitude)
{
  int position = 0;
  ch8vec *new_node = alloc_mem_ch8vec();
  new_node->vec = vec;
  ch8vec *prev_node = NULL;
  ch8vec *current_node = *root;

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
      ch8vec *successor = prev_node->next;
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

int is_empty_ch8_vec(int *magnitude)
{
  if ((*magnitude) == 0)
    return 1;
  return 0;
}

void clear_ch8_vec(ch8vec **root, int *magnitude)
{
  ch8vec *current = *root;
  while (current != NULL)
  {
    ch8vec *next = current->next;
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void pop_ch8_vec(ch8vec **root, int *magnitude)
{
  if (*root == NULL || *magnitude == 0)
    return;

  ch8vec *current = *root;
  ch8vec *prev_node = NULL;

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

void poll_ch8_vec(ch8vec **node, int *magnitude)
{
  ch8vec *root = *node;
  if (root == NULL)
    return;
  *node = (root)->next;
  free(root);
  (*magnitude)--;
}

void delete_at_ch8_vec(ch8vec **root, int index, int *magnitude)
{
  ch8vec *prev_node = NULL;
  ch8vec *current_node = (*root);
  int position = 0;
  if (index > (*magnitude) - 1)
  {
    printf("List out of bound error\n");
    exit(1);
  }
  if (index == 0)
  {
    poll_ch8_vec(&(*root), magnitude);
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
