#ifndef LINKED_LIST_FLOAT
#define LINKED_LIST_FLOAT
#include "./linked_list_float.c"
#endif

typedef struct f64_vec
{
  f64node **vec;
  struct f64_vec *next;
} f64vec;

f64vec *alloc_mem_f64vec()
{
  return (f64vec *)malloc(sizeof(f64vec));
}

void add_f64_vec(f64vec **node, f64node **vec, int *magnitude)
{
  f64vec *new_node = alloc_mem_f64vec();
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
    f64vec *curr = *node;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void view_f64_vec(f64vec *root, int magnitude)
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
    f64node **payload = root->vec;
    f64node *buffer = (*payload);
    while (buffer != NULL)
    {
      printf(buffer->next != NULL ? "%f, " : "%f", buffer->data);
      buffer = buffer->next;
    }
    printf(pos < magnitude ? "],\n" : "]\n");

    root = root->next;
    pos++;
  }
  printf("]\n");
}

f64node *get_f64_vec(f64vec **root, int index)
{
  int position = 0;
  f64vec *current = (*root);

  while (current != NULL)
  {
    if (position == index)
      return *(current->vec);
    current = current->next;
    position++;
  }

  return NULL;
}

int magnitude_f64_node(f64node **node)
{
  int magnitude = 0;
  f64node *buffer = (*node);
  while (buffer != NULL)
  {
    magnitude++;
    buffer = buffer->next;
  }
  return magnitude;
}

int size_f64_vec(int magnitude)
{
  return magnitude;
}

void insert_at_f64_vec(f64vec **root, f64node **vec, int index, int *magnitude)
{
  int position = 0;
  f64vec *new_node = alloc_mem_f64vec();
  new_node->vec = vec;
  f64vec *prev_node = NULL;
  f64vec *current_node = *root;

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
      f64vec *successor = prev_node->next;
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

int is_empty_f64_vec(int *magnitude)
{
  if ((*magnitude) == 0)
    return 1;
  return 0;
}

void clear_f64_vec(f64vec **root, int *magnitude)
{
  f64vec *current = *root;
  while (current != NULL)
  {
    f64vec *next = current->next;
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void pop_f64_vec(f64vec **root, int *magnitude)
{
  if (*root == NULL || *magnitude == 0)
    return;

  f64vec *current = *root;
  f64vec *prev_node = NULL;

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

void poll_f64_vec(f64vec **node, int *magnitude)
{
  f64vec *root = *node;
  if (root == NULL)
    return;
  *node = (root)->next;
  free(root);
  (*magnitude)--;
}

void delete_at_f64_vec(f64vec **root, int index, int *magnitude)
{
  f64vec *prev_node = NULL;
  f64vec *current_node = (*root);
  int position = 0;
  if (index > (*magnitude) - 1)
  {
    printf("List out of bound error\n");
    exit(1);
  }
  if (index == 0)
  {
    poll_f64_vec(&(*root), magnitude);
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
