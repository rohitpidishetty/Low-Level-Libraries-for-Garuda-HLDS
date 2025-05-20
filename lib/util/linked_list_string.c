#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ch8node
{
  char *data;
  struct ch8node *next;
} ch8node;

ch8node *alloc_ch8_node()
{
  return (ch8node *)malloc(sizeof(ch8node));
}

void add_ch8_node(ch8node **node, const char *data, int *magnitude)
{
  ch8node *new_node = alloc_ch8_node();
  new_node->data = strdup(data);
  new_node->next = NULL;

  if ((*node) == NULL)
  {
    *node = new_node;
  }
  else
  {
    ch8node *curr = *node;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void poll_ch8_node(ch8node **node, int *magnitude)
{
  if (*node == NULL)
    return;

  ch8node *root = *node;
  *node = root->next;
  free(root->data);
  free(root);
  (*magnitude)--;
}

void view_ch8_node(ch8node *root, int size)
{
  int position = 1;
  printf("[");
  while (root != NULL)
  {
    printf(position < size ? "\"%s\", " : "\"%s\"", root->data);
    root = root->next;
    position++;
  }
  printf("]\n");
}

void pop_ch8_node(ch8node *root, int *magnitude)
{
  if (root == NULL || root->next == NULL)
  {
    printf("Cannot pop from empty or single-node list.\n");
    return;
  }

  ch8node *prev_node = NULL;
  while (root->next != NULL)
  {
    prev_node = root;
    root = root->next;
  }
  prev_node->next = NULL;
  free(root->data);
  free(root);
  (*magnitude)--;
}

int size_ch8_node(int magnitude)
{
  return magnitude;
}

void insert_at_ch8_node(ch8node **root, const char *value, int index, int *magnitude)
{
  int position = 0;
  ch8node *new_node = alloc_ch8_node();
  new_node->data = strdup(value);

  if (index == 0)
  {
    new_node->next = *root;
    *root = new_node;
    (*magnitude)++;
    return;
  }

  ch8node *prev_node = NULL;
  ch8node *current_node = *root;

  while (current_node != NULL)
  {
    if (index == position)
    {
      prev_node->next = new_node;
      new_node->next = current_node;
      (*magnitude)++;
      return;
    }
    prev_node = current_node;
    current_node = current_node->next;
    position++;
  }

  if (position == index)
  {
    prev_node->next = new_node;
    new_node->next = NULL;
    (*magnitude)++;
  }
}

void delete_at_ch8_node(ch8node **root, int index, int *magnitude)
{
  if (index >= *magnitude)
  {
    printf("List out of bound error\n");
    exit(1);
  }

  ch8node *prev_node = NULL;
  ch8node *current_node = *root;
  int position = 0;

  if (index == 0)
  {
    poll_ch8_node(root, magnitude);
    return;
  }

  while (current_node != NULL)
  {
    if (position == index)
    {
      prev_node->next = current_node->next;
      free(current_node->data);
      free(current_node);
      (*magnitude)--;
      return;
    }
    prev_node = current_node;
    current_node = current_node->next;
    position++;
  }
}

void remove_ch8_node(ch8node **root, const char *data, int *magnitude)
{
  ch8node *prev_node = NULL;
  ch8node *current = *root;
  int removed = 0;
  while (current != NULL)
  {
    if (strcmp(current->data, data) == 0)
    {
      removed = 1;
      if (prev_node == NULL)
      {
        *root = current->next;
        free(current->data);
        free(current);
        (*magnitude)--;
        return;
      }
      else
      {
        prev_node->next = current->next;
        free(current->data);
        free(current);
        (*magnitude)--;
        return;
      }
    }
    prev_node = current;
    current = current->next;
  }
  if (removed == 0)
  {
    printf("Element '%s' not found\n", data);
    exit(1);
  }
}

char *contains_ch8_node(ch8node **root, const char *data)
{
  ch8node *current = *root;
  while (current != NULL)
  {
    if (strcmp(current->data, data) == 0)
      return "True";
    current = current->next;
  }
  return "False";
}

char *get_ch8_node(ch8node **root, int index)
{
  int position = 0;
  ch8node *current = *root;
  while (current != NULL)
  {
    if (position == index)
      return current->data;
    current = current->next;
    position++;
  }
  return NULL;
}

int index_of_ch8_node(ch8node **root, const char *value)
{
  int position = 0;
  ch8node *current = *root;
  while (current != NULL)
  {
    if (strcmp(current->data, value) == 0)
      return position;
    current = current->next;
    position++;
  }
  return -1;
}

char *is_empty_ch8_node(int *magnitude)
{
  return (*magnitude == 0) ? "True" : "False";
}

void clear_ch8_node(ch8node **root, int *magnitude)
{
  ch8node *current = *root;
  while (current != NULL)
  {
    ch8node *next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void reverse_ch8_node(ch8node **root)
{
  ch8node *current = *root;
  ch8node *prev_node = NULL;
  ch8node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev_node;
    prev_node = current;
    current = next;
  }

  *root = prev_node;
}

char *equals_ch8_node(ch8node **root_0, ch8node **root_1, int *root_0_mag, int *root_1_mag)
{
  if (*root_0_mag != *root_1_mag)
    return "False";

  ch8node *r0 = *root_0;
  ch8node *r1 = *root_1;

  while (r0 != NULL && r1 != NULL)
  {
    if (strcmp(r0->data, r1->data) != 0)
      return "False";
    r0 = r0->next;
    r1 = r1->next;
  }

  return "True";
}
