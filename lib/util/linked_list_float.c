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
#include <float.h>

typedef struct float64_node
{
  float data;
  struct float64_node *next;
} f64node;

f64node *alloc_mem_f64node()
{
  return (f64node *)malloc(sizeof(f64node));
}

void add_f64_node(f64node **node, float data, int *magnitude)
{
  f64node *new_node = alloc_mem_f64node();
  if ((*node) == NULL)
  {
    new_node->data = data;
    new_node->next = NULL;
    *node = new_node;
  }
  else
  {
    new_node->data = data;
    new_node->next = NULL;
    f64node *curr = *node;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void poll_f64_node(f64node **node, int *magnitude)
{
  f64node *root = *node;
  if (root == NULL)
    return;
  *node = root->next;
  free(root);
  (*magnitude)--;
}

void view_f64_node(f64node *root, int l1_size)
{
  int position = 1;
  printf("[");
  while (root != NULL)
  {
    printf(position < l1_size ? "%.2f, " : "%.2f", root->data);
    root = root->next;
    position++;
  }
  printf("]\n");
}

// void pop_f64_node(f64node *root, int *magnitude)
// {
//   if (root == NULL)
//     return;
//   f64node *prev_node = NULL;
//   while (root->next != NULL)
//   {
//     prev_node = root;
//     root = root->next;
//   }
//   prev_node->next = NULL;
//   free(root);
//   (*magnitude)--;
// }

void pop_f64_node(f64node **root, int *magnitude)
{
  if (*root == NULL || *magnitude == 0)
    return;

  f64node *current = *root;
  f64node *prev_node = NULL;

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

  (*magnitude)--;
}

int size_f64_node(int magnitude)
{
  return magnitude;
}

void insert_at_f64_node(f64node **root, float value, int index, int *magnitude)
{
  int position = 0;
  f64node *new_node = alloc_mem_f64node();
  new_node->data = value;
  f64node *prev_node = NULL;
  f64node *current_node = *root;

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
      f64node *successor = prev_node->next;
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

void delete_at_f64_node(f64node **root, int index, int *magnitude)
{
  f64node *prev_node = NULL;
  f64node *current_node = (*root);
  int position = 0;
  if (index > (*magnitude) - 1)
  {
    printf("List out of bound error\n");
    exit(1);
  }
  if (index == 0)
  {
    poll_f64_node(&(*root), magnitude);
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

void remove_f64_node(f64node **root, float data, int *magnitude)
{
  f64node *prev_node = NULL;
  f64node *current = *root;
  int removed = 0;
  while (current != NULL)
  {
    if (current->data == data)
    {
      removed = 1;
      if (prev_node == NULL)
      {
        f64node *head = *root;
        *root = head->next;
        free(head);
        (*magnitude)--;
        return;
      }
      else
        prev_node->next = current->next;
    }
    prev_node = current;
    current = current->next;
  }
  if (removed == 1)
    (*magnitude)--;
  else
  {
    printf("Element %f not found\n", data);
    exit(1);
  }
}

int contains_f64_node(f64node **root, float data)
{
  f64node *current = *root;
  while (current != NULL)
  {
    if (current->data == data)
    {
      return 1;
      break;
    }
    current = current->next;
  }
  return 0;
}

float peek_f64_node(f64node **root)
{
  if ((*root) == NULL)
    return -1.0;
  f64node *buffer = (*root);
  while (buffer->next != NULL)
    buffer = buffer->next;
  return buffer->data;
}

float get_f64_node(f64node **root, int index)
{
  int position = 0;
  f64node *current = *root;
  while (current != NULL)
  {
    if (position == index)
      return current->data;
    current = current->next;
    position++;
  }
  return -1.0;
}

int index_of_f64_node(f64node **root, float value)
{
  int position = 0;
  f64node *current = *root;
  while (current != NULL)
  {
    if (current->data == value)
      return position;
    current = current->next;
    position++;
  }
  return -1;
}

int is_empty_f64_node(int *magnitude)
{
  if ((*magnitude) == 0)
    return 1;
  return 0;
}

void clear_f64_node(f64node **root, int *magnitude)
{
  f64node *current = *root;
  while (current != NULL)
  {
    f64node *next = current->next;
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void reverse_f64_node(f64node **root)
{
  f64node *current = *root;
  f64node *prev_node = NULL;
  f64node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev_node;
    prev_node = current;
    current = next;
  }

  *root = prev_node;
}

int equals_f64_node(f64node **root_0, f64node **root_1, int *root_0_mag, int *root_1_mag)
{
  f64node *r0 = *root_0;
  f64node *r1 = *root_1;

  if ((*root_0_mag) != (*root_1_mag))
    return 0;
  while (r0 != NULL && r1 != NULL)
  {
    if (r0->data != r1->data)
      return 0;
    r0 = r0->next;
    r1 = r1->next;
  }

  return 1;
}

float max_f64_node(f64node **root)
{
  f64node *current = *root;
  float maximum = -FLT_MAX;
  while (current != NULL)
  {
    if (current->data >= maximum)
      maximum = current->data;
    current = current->next;
  }
  return maximum;
}

float min_f64_node(f64node **root)
{
  f64node *current = *root;
  float minimum = FLT_MAX;
  while (current != NULL)
  {
    if (current->data < minimum)
      minimum = current->data;
    current = current->next;
  }
  return minimum;
}

float sum_f64_node(f64node **root)
{
  f64node *current = *root;
  float summation = 0.0f;
  while (current != NULL)
  {
    summation += current->data;
    current = current->next;
  }
  return summation;
}

float average_f64_node(f64node **root, int *magnitude)
{
  float sum = sum_f64_node(root);
  return ((*magnitude) == 0) ? 0.0f : (sum / (float)(*magnitude));
}

f64node *merge_f64_lists(f64node *a, f64node *b)
{
  if (!a)
    return b;
  if (!b)
    return a;

  f64node *result = NULL;
  if (a->data <= b->data)
  {
    result = a;
    result->next = merge_f64_lists(a->next, b);
  }
  else
  {
    result = b;
    result->next = merge_f64_lists(a, b->next);
  }
  return result;
}

void split_f64_list(f64node *source, f64node **front_ref, f64node **back_ref)
{
  f64node *slow = source;
  f64node *fast = source->next;
  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *front_ref = source;
  *back_ref = slow->next;
  slow->next = NULL;
}

f64node *insertion_sort_f64_list(f64node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  f64node *sorted = NULL;
  while (head != NULL)
  {
    f64node *current = head;
    head = head->next;
    if (sorted == NULL || current->data < sorted->data)
    {
      current->next = sorted;
      sorted = current;
    }
    else
    {
      f64node *temp = sorted;
      while (temp->next != NULL && temp->next->data < current->data)
        temp = temp->next;
      current->next = temp->next;
      temp->next = current;
    }
  }
  return sorted;
}

f64node *merge_sort_f64_list(f64node *head)
{
  if (!head || !head->next)
    return head;

  f64node *a = NULL;
  f64node *b = NULL;
  split_f64_list(head, &a, &b);
  a = merge_sort_f64_list(a);
  b = merge_sort_f64_list(b);
  return merge_f64_lists(a, b);
}

void hybrid_sort_f64_node(f64node **root, int magnitude)
{
  *root = (magnitude <= 75) ? insertion_sort_f64_list(*root) : merge_sort_f64_list(*root);
}

void extend_f64_node(f64node **root_0, f64node **root_1, int *root_0_mag, int *root_1_mag)
{
  if (*root_0 == NULL)
  {
    *root_0 = *root_1;
  }
  else
  {
    f64node *curr = *root_0;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = *root_1;
  }
  *root_0_mag += *root_1_mag;
}

void deep_copy_f64_node(f64node **destination_buffer, int *destination_buffer_magnitude, f64node **source_buffer, int *source_buffer_magnitude)
{
  f64node *src_buff = *source_buffer;
  while (src_buff != NULL)
  {
    add_f64_node(destination_buffer, src_buff->data, destination_buffer_magnitude);
    src_buff = src_buff->next;
  }
}