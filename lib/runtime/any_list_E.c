#include <stdio.h>
#include <stdlib.h>

#define LINKED_LIST_STRING false
#include "../util/linked_list_string.c"
#include "../util/tree_set_string.c"

typedef enum
{
  VALUE_NODE,
  OBJECT_NODE
} node_type;

typedef struct any_list_dtype
{
  node_type type;
  void *value;
  struct any_list_dtype *next;
} any_list_dtype;

any_list_dtype *allocate_any_list_dtype_memory()
{
  return (any_list_dtype *)malloc(sizeof(any_list_dtype));
}

any_list_dtype *add_any_list_dtype_node(any_list_dtype **gen_ref, int *magnitude, void *value, int is_object)
{
  any_list_dtype *new_node = allocate_any_list_dtype_memory();
  new_node->value = value;
  new_node->type = is_object ? OBJECT_NODE : VALUE_NODE;
  new_node->next = NULL;
  if ((*gen_ref) == NULL)
    (*gen_ref) = new_node;
  else
  {
    any_list_dtype *curr = *gen_ref;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void view_E_node(ch8node *root)
{
  printf("[");
  while (root != NULL)
  {
    printf(root->next != NULL ? "%s, " : "%s", root->data);
    root = root->next;
  }
  printf("]");
}

void view_any_list_dtype_node(any_list_dtype *node)
{
  if (!node)
    return;
  printf("[");
  any_list_dtype *curr = node;
  while (curr)
  {
    if (curr->type == VALUE_NODE)
      view_E_node((ch8node *)curr->value);
    else
      view_any_list_dtype_node((any_list_dtype *)curr->value);
    if (curr->next)
      printf(", ");
    curr = curr->next;
  }
  printf("]\n");
}
void main()
{
  // All the values will be in 'String' by default while working with wild card types.
  // 'T' indicates a list ch8node

  // list<?> l = new list<>()
  any_list_dtype *l = NULL;
  int l_magnitude = 0;

  // list<T> e1 = new list<>()
  ch8node *e1 = NULL;
  int e1_size = 0;

  // e1.push(98)
  add_ch8_node(&e1, "98", &e1_size);

  // e1.push(232)
  add_ch8_node(&e1, "232", &e1_size);

  // l.push(e1)
  add_any_list_dtype_node(&l, &l_magnitude, e1, 0);

  // list<T> e2 = new list<>()
  ch8node *e2 = NULL;
  int e2_size = 0;

  // e2.push(3.79)
  add_ch8_node(&e2, "3.79", &e2_size);

  // e2.push(34.3)
  add_ch8_node(&e2, "34.3", &e2_size);

  // e2.push(376.09)
  add_ch8_node(&e2, "376.09", &e2_size);

  // l.push(e2)
  add_any_list_dtype_node(&l, &l_magnitude, e2, 0);

  // list<T> e3 = new list<>()
  ch8node *e3 = NULL;
  int e3_size = 0;

  // e3.push("hi")
  add_ch8_node(&e3, "hi", &e3_size);

  // e3.push("how are you")
  add_ch8_node(&e3, "how are you", &e3_size);

  // l.push(e3)
  add_any_list_dtype_node(&l, &l_magnitude, e3, 0);
  // Set 0 if type is T, else 1

  // l.print()
  view_any_list_dtype_node(l);

  // --------------------------------------------

  // list<list<list<int>>>
  // any_list_dtype *l = NULL;
  // int l_magnitude = 0;

  // // list<?> g1 = new list<>()
  // any_list_dtype *g1 = NULL;
  // int g1_magnitude = 0;

  // // list<T> E1 = new list<>()
  // ch8node *E1 = NULL;
  // int E1_size = 0;

  // // e1.push(98)
  // // e1.push(232)
  // add_ch8_node(&E1, "98", &E1_size);
  // add_ch8_node(&E1, "232", &E1_size);

  // // g1.push(E1)
  // add_any_list_dtype_node(&g1, &g1_magnitude, E1, 0);

  // // list<?> g2 = new list<>()
  // any_list_dtype *g2 = NULL;
  // int g2_magnitude = 0;

  // // list<T> E2 = new list<>()
  // ch8node *E2 = NULL;
  // int E2_size = 0;

  // // E2.push("Hi")
  // // E2.push("How are you?")
  // add_ch8_node(&E2, "Hi", &E2_size);
  // add_ch8_node(&E2, "How are you?", &E2_size);

  // // g2.push(E2)
  // add_any_list_dtype_node(&g2, &g1_magnitude, E2, 0);

  // // l.push(g1)
  // add_any_list_dtype_node(&l, &l_magnitude, g1, 1);

  // // l.push(g2)
  // add_any_list_dtype_node(&l, &l_magnitude, g2, 1);

  // l.print()
  // view_any_list_dtype_node(l);

  // -----------------------------------------------------------

  // Pre-reqs, add these at start while working with set's in list.
  ch8node *any_set_temp_view;
  int any_set_temp_view_size;

  // list<?> listOfSet = new list<>()
  any_list_dtype *listOfSet = NULL;
  int listOfSet_magnitude = 0;

  // set<T> s = new set<>()
  ch8_t_set *s = NULL;

  // s.union("ram")
  seed_ch8_t_set(&s, "ram");
  // s.union("ramesh")
  seed_ch8_t_set(&s, "ramesh");
  // s.union("ramesh")
  seed_ch8_t_set(&s, "ramesh");

  // listOfSet.push(s)
  any_set_temp_view = NULL;
  any_set_temp_view_size = 0;
  elements_ch8_t_set(&s, &any_set_temp_view, &any_set_temp_view_size);
  add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, any_set_temp_view, 0);

  // set<T> s2 = new set<>()
  ch8_t_set *s2 = NULL;

  // s2.union("ram")
  seed_ch8_t_set(&s2, "shyam");
  // s2.union("ramesh")
  seed_ch8_t_set(&s2, "shyam");
  // s2.union("ramesh")
  seed_ch8_t_set(&s2, "sunil");

  // listOfSet.push(s2)
  any_set_temp_view = NULL;
  any_set_temp_view_size = 0;
  elements_ch8_t_set(&s2, &any_set_temp_view, &any_set_temp_view_size);
  add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, any_set_temp_view, 0);

  // list<T> E5 = new list<>()
  ch8node *E5 = NULL;
  int E5_size = 0;

  // E2.push("Hi")
  // E2.push("How are you?")
  add_ch8_node(&E5, "1", &E5_size);
  add_ch8_node(&E5, "2", &E5_size);
  add_ch8_node(&E5, "2", &E5_size);
  add_ch8_node(&E5, "3", &E5_size);

  // g2.push(E2)
  add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, E5, 0);

  // listOfSet.print()
  view_any_list_dtype_node(listOfSet);
}