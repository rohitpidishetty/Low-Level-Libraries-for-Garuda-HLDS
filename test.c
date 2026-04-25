#define LINKED_LIST_INT
#define LINKED_LIST_STRING
#define LINKED_LIST_FLOAT
#define HASH_MAP_STRING
#define TREE_SET_STRING

#include <stdio.h>
#include <stdlib.h>

#include "./lib/util/linked_list_int.c"
#include "./lib/util/linked_list_string.c"
#include "./lib/util/linked_list_float.c"
#include "./lib/util/hash_map_i32k_i32v.c"
#include "./lib/util/hash_map_i32k_f64v.c"
#include "./lib/util/hash_map_i32k_ch8v.c"
#include "./lib/util/hash_map_ch8k_i32v.c"
#include "./lib/util/hash_map_ch8k_ch8v.c"
#include "./lib/util/hash_map_ch8k_f64v.c"
#include "./lib/util/tree_set_int32.c"
#include "./lib/util/tree_set_float64.c"
#include "./lib/util/tree_set_string.c"
#include "./lib/util/string_sub_routines.c"
#include "./lib/util/multi_dim_linked_list_int.c"
#include "./lib/util/multi_dim_linked_list_float.c"
#include "./lib/util/multi_dim_linked_list_string.c"
#include "./lib/util/priority_queue_i32.c"
#include "./lib/util/priority_queue_f64.c"
#include "./lib/runtime/any_list_E.c"

void main()
{
  i32node *l1 = NULL;
  int l1_size = 0;

  add_i32_node(&l1, 1, &l1_size);
  add_i32_node(&l1, 2, &l1_size);
  add_i32_node(&l1, 3, &l1_size);
  add_i32_node(&l1, 4, &l1_size);
  view_i32_node(l1, l1_size);
  pop_i32_node(&l1, &l1_size);
  view_i32_node(l1, l1_size);
  int d = size_i32_node(l1_size);
  printf("%d\n", d);
  insert_at_i32_node(&l1, 12, 1, &l1_size);
  insert_at_i32_node(&l1, 24, 2, &l1_size);
  insert_at_i32_node(&l1, -24, 0, &l1_size);
  insert_at_i32_node(&l1, -4, 5, &l1_size);
  add_i32_node(&l1, 40, &l1_size);
  view_i32_node(l1, l1_size);
  poll_i32_node(&l1, &l1_size);
  view_i32_node(l1, l1_size);
  delete_at_i32_node(&l1, 0, &l1_size);
  view_i32_node(l1, l1_size);
  add_i32_node(&l1, 400, &l1_size);
  view_i32_node(l1, l1_size);
  remove_i32_node(&l1, 40, &l1_size);
  view_i32_node(l1, l1_size);
  remove_i32_node(&l1, 12, &l1_size);
  view_i32_node(l1, l1_size);
  int s = contains_i32_node(&l1, 400);
  printf("%d\n", s);
  int n = get_i32_node(&l1, 4);
  printf("%d\n", n);
  n = peek_i32_node(&l1);
  printf("%d\n", n);
  n = index_of_i32_node(&l1, -4);
  printf("%d\n", n);
  s = is_empty_i32_node(&l1_size);
  printf("%d\n", s);
  view_i32_node(l1, l1_size);
  s = is_empty_i32_node(&l1_size);
  printf("%d\n", s);
  reverse_i32_node(&l1);
  add_i32_node(&l1, 123, &l1_size);
  view_i32_node(l1, l1_size);
  d = size_i32_node(l1_size);
  printf("%d\n", d);
  d = max_i32_node(&l1);
  printf("%d\n", d);
  d = min_i32_node(&l1);
  printf("%d\n", d);
  d = sum_i32_node(&l1);
  printf("%d\n", d);
  float d2 = average_i32_node(&l1, &l1_size);
  printf("%f\n", d2);
  hybrid_sort_i32_node(&l1, l1_size);
  view_i32_node(l1, l1_size);
  add_i32_node(&l1, 234, &l1_size);
  view_i32_node(l1, l1_size);
  d = size_i32_node(l1_size);
  printf("%d\n", d);

  i32node *l2 = NULL;
  int l2_size = 0;
  add_i32_node(&l2, 1, &l2_size);
  add_i32_node(&l2, 2, &l2_size);
  add_i32_node(&l2, 3, &l2_size);
  add_i32_node(&l2, 4, &l2_size);
  s = equals_i32_node(&l1, &l2, &l1_size, &l2_size);
  printf("%d\n", s);
  extend_i32_node(&l1, &l2, &l1_size, &l2_size);
  view_i32_node(l1, l1_size);
  d = size_i32_node(l1_size);
  printf("%d\n", d);

  // char
  ch8node *c1 = NULL;
  int c1_size = 0;

  add_ch8_node(&c1, "apple", &c1_size);
  add_ch8_node(&c1, "banana", &c1_size);
  add_ch8_node(&c1, "cherry", &c1_size);
  add_ch8_node(&c1, "date", &c1_size);
  view_ch8_node(c1, c1_size);
  poll_ch8_node(&c1, &c1_size);
  view_ch8_node(c1, c1_size);
  printf("Size: %d\n", size_ch8_node(c1_size));
  insert_at_ch8_node(&c1, "elderberry", 1, &c1_size);
  view_ch8_node(c1, c1_size);
  remove_ch8_node(&c1, "banana", &c1_size);
  view_ch8_node(c1, c1_size);
  printf("Contains 'cherry': %d\n", contains_ch8_node(&c1, "cherry"));
  printf("Get index 2: %s\n", get_ch8_node(&c1, 2));
  printf("Index of 'date': %d\n", index_of_ch8_node(&c1, "date"));
  printf("Is empty: %d\n", is_empty_ch8_node(&c1_size));
  reverse_ch8_node(&c1);
  view_ch8_node(c1, c1_size);

  // float
  f64node *f1 = NULL;
  int f1_size = 0;

  add_f64_node(&f1, 1.1, &f1_size);
  add_f64_node(&f1, 2.2, &f1_size);
  add_f64_node(&f1, 3.3, &f1_size);
  add_f64_node(&f1, 4.4, &f1_size);
  view_f64_node(f1, f1_size);

  poll_f64_node(&f1, &f1_size);
  view_f64_node(f1, f1_size);

  insert_at_f64_node(&f1, 5.5, 1, &f1_size);
  view_f64_node(f1, f1_size);

  remove_f64_node(&f1, 2.2, &f1_size);
  view_f64_node(f1, f1_size);

  printf("Contains 3.3: %d\n", contains_f64_node(&f1, 3.3));
  printf("Get index 2: %.2f\n", get_f64_node(&f1, 2));
  printf("Index of 4.4: %d\n", index_of_f64_node(&f1, 4.4));
  printf("Is empty: %d\n", is_empty_f64_node(&f1_size));

  reverse_f64_node(&f1);
  view_f64_node(f1, f1_size);

  /**
   * dict<int, int> map = new dict<>(10)
   */
  int map_size = 10;
  i32node_i32node_Tree *map[map_size];
  for (int i = 0; i < map_size; i++)
    map[i] = NULL;

  /**
   * key = 1
   * value = 100
   * map.set(key, value)
   */
  int key = 1;
  int value = 100;
  set_dict_i32k_i32v(map, key, __i32_key_hash(key, &map_size), value);
  // --------------
  set_dict_i32k_i32v(map, 2, __i32_key_hash(2, &map_size), 5674);

  set_dict_i32k_i32v(map, 3, __i32_key_hash(3, &map_size), 3434);

  /**
   * map.set(7, 234)
   */
  set_dict_i32k_i32v(map, 7, __i32_key_hash(7, &map_size), 234);

  /**
   * v = map.get(7)
   */
  int v = get_dict_i32k_i32v(map, 7, &map_size);
  printf("%d\n", v);

  /**
   * map.remove(7)
   */
  remove_dict_i32k_i32v(map, 7, __i32_key_hash(7, &map_size));

  /**
   * keys = map.keys()
   * keys.view()
   */

  i32node *keys = NULL;
  int keys_size = 0;
  keys_dict_i32k_i32v(map, &map_size, &keys, &keys_size);
  view_i32_node(keys, keys_size);

  /**
   * values = map.values()
   * values.view()
   */
  i32node *values = NULL;
  int values_size = 0;
  values_dict_i32k_i32v(map, &map_size, &values, &values_size);
  view_i32_node(values, values_size);

  /**
   * items = map.items()
   * items.view()
   */
  ch8node *items = NULL;
  int items_size = 0;
  items_dict_i32k_i32v(map, &map_size, &items, &items_size);
  view_ch8_node(items, items_size);

  /**
   * map.clear()
   */
  clear_dict_i32k_i32v(map, &map_size);

  // ------------

  /**
   * dict<int, str> table = new dict<>(10)
   */
  int table_size = 10;
  i32node_ch8node_Tree *table[table_size];
  for (int i = 0; i < table_size; i++)
    table[i] = NULL;

  set_dict_i32k_ch8v(table, 1, __i32_key_hash(1, &table_size), "hello");
  set_dict_i32k_ch8v(table, 2, __i32_key_hash(2, &table_size), "world");

  printf("%s\n", table[__i32_key_hash(1, &table_size)]->value);
  printf("%s\n", table[__i32_key_hash(2, &table_size)]->value);

  char *data = get_dict_i32k_ch8v(table, 2, &table_size);
  printf("%s\n", data);

  remove_dict_i32k_ch8v(table, 2, __i32_key_hash(2, &table_size));

  data = get_dict_i32k_ch8v(table, 2, &table_size);
  printf("%s\n", data);

  i32node *keys2 = NULL;
  int keys2_size = 0;
  keys_dict_i32k_ch8v(table, &table_size, &keys2, &keys2_size);
  view_i32_node(keys2, keys2_size);

  ch8node *values2 = NULL;
  int values2_size = 0;
  values_dict_i32k_ch8v(table, &table_size, &values2, &values2_size);
  view_ch8_node(values2, values2_size);

  ch8node *items2 = NULL;
  int items2_size = 0;
  items_dict_i32k_ch8v(table, &table_size, &items2, &items2_size);
  view_ch8_node(items2, items2_size);

  clear_dict_i32k_ch8v(table, &table_size);

  data = get_dict_i32k_ch8v(table, 2, &table_size);
  printf("%s\n", data);

  // ----------------------------------

  //  dict<int, float> map3 = new dict<>(10)
  int map3_size = 10;
  i32node_f64node_Tree *map3[map3_size];
  for (int i = 0; i < map3_size; i++)
    map3[i] = NULL;

  // map3.set(1, 100.23)
  set_dict_i32k_f64v(map3, 1, __i32_key_hash(1, &map3_size), 100.23);
  set_dict_i32k_f64v(map3, 2, __i32_key_hash(2, &map3_size), 56.74);
  set_dict_i32k_f64v(map3, 3, __i32_key_hash(3, &map3_size), 343.4);
  set_dict_i32k_f64v(map3, 7, __i32_key_hash(7, &map3_size), 2.34);

  // v = map3.get(7)
  float v3 = get_dict_i32k_f64v(map3, 7, &map3_size);
  printf("%f\n", v3);

  // map3.remove(7)
  remove_dict_i32k_f64v(map3, 7, __i32_key_hash(7, &map3_size));

  /**
   * keys = map3.keys()
   * keys.view()
   */
  i32node *keys3 = NULL;
  int keys3_size = 0;
  keys_dict_i32k_f64v(map3, &map3_size, &keys3, &keys3_size);
  view_i32_node(keys3, keys3_size);

  /**
   * values = map3.values()
   * values.view()
   */
  f64node *values3 = NULL;
  int values3_size = 0;
  values_dict_i32k_f64v(map3, &map3_size, &values3, &values3_size);
  view_f64_node(values3, values3_size);

  /**
   * items = map3.items()
   * items.view()
   */
  ch8node *items3 = NULL;
  int items3_size = 0;
  items_dict_i32k_f64v(map3, &map3_size, &items3, &items3_size);
  view_ch8_node(items3, items3_size);

  // map3.clear()
  clear_dict_i32k_f64v(map3, &map3_size);

  // ----------------------------------------

  /**
   * dict<str, int> map9 = new dict<>(10)
   */
  int map9_size = 10;
  ch8node_i32node_Tree *map9[map9_size];
  for (int i = 0; i < map9_size; i++)
    map9[i] = NULL;

  /**
   * map9.set("hello", 10)
   */

  set_dict_ch8k_i32v(map9, "hello", __ch8_key_hash("hello", &map9_size), 10);
  // // --------------
  set_dict_ch8k_i32v(map9, "world", __ch8_key_hash("world", &map9_size), 5674);
  set_dict_ch8k_i32v(map9, "how", __ch8_key_hash("how", &map9_size), 3434);
  /**
   * map9.set("are", 234)
   */
  set_dict_ch8k_i32v(map9, "are", __ch8_key_hash("are", &map9_size), 234);

  /**
   * v0 = map9.get(7)
   */
  int v0 = get_dict_ch8k_i32v(map9, "hello", &map9_size);
  printf("%d\n", v0);

  v0 = get_dict_ch8k_i32v(map9, "how", &map9_size);
  printf("%d\n", v0);

  /**
   * map9.remove(7)
   */
  remove_dict_ch8k_i32v(map9, "how", __ch8_key_hash("how", &map9_size));

  v0 = get_dict_ch8k_i32v(map9, "how", &map9_size);
  printf("%d\n", v0);

  /**
   * keys = map9.keys()
   * keys.view()
   */

  ch8node *keys9 = NULL;
  int keys9_size = 0;
  keys_dict_ch8k_i32v(map9, &map9_size, &keys9, &keys9_size);
  view_ch8_node(keys9, keys9_size);

  /**
   * values = map9.values()
   * values.view()
   */
  i32node *values9 = NULL;
  int values9_size = 0;
  values_dict_ch8k_i32v(map9, &map9_size, &values9, &values9_size);
  view_i32_node(values9, values9_size);

  /**
   * items = map9.items()
   * items.view()
   */
  ch8node *items9 = NULL;
  int items9_size = 0;
  items_dict_ch8k_i32v(map9, &map9_size, &items9, &items9_size);
  view_ch8_node(items9, items9_size);

  /**
   * map9.clear()
   */
  clear_dict_ch8k_i32v(map9, &map9_size);

  // ------------------------------

  /**
   * dict<str, str> 5 = new dict<>(10)
   */
  int map5_size = 10;
  ch8node_ch8node_Tree *map5[map5_size];
  for (int i = 0; i < map5_size; i++)
    map5[i] = NULL;

  set_dict_ch8k_ch8v(map5, "hello", __ch8_key_hash("hello", &map5_size), "a");
  set_dict_ch8k_ch8v(map5, "world", __ch8_key_hash("world", &map5_size), "b");
  set_dict_ch8k_ch8v(map5, "how", __ch8_key_hash("how", &map5_size), "c");

  set_dict_ch8k_ch8v(map5, "are", __ch8_key_hash("are", &map5_size), "d");

  char *vx = get_dict_ch8k_ch8v(map5, "hello", &map5_size);
  printf("%s\n", vx);

  vx = get_dict_ch8k_ch8v(map5, "how", &map5_size);
  printf("%s\n", vx);

  remove_dict_ch8k_ch8v(map5, "how", __ch8_key_hash("how", &map5_size));

  vx = get_dict_ch8k_ch8v(map5, "how", &map5_size);
  printf("%s\n", vx);

  ch8node *keys5 = NULL;
  int keys5_size = 0;
  keys_dict_ch8k_ch8v(map5, &map5_size, &keys5, &keys5_size);
  view_ch8_node(keys5, keys5_size);

  ch8node *values5 = NULL;
  int values5_size = 0;
  values_dict_ch8k_ch8v(map5, &map5_size, &values5, &values5_size);
  view_ch8_node(values5, values5_size);

  ch8node *items5 = NULL;
  int items5_size = 0;
  items_dict_ch8k_ch8v(map5, &map5_size, &items5, &items5_size);
  view_ch8_node(items5, items5_size);

  clear_dict_ch8k_ch8v(map5, &map5_size);

  // -----------------------------------------------

  /**
   * dict<str, float> map8 = new dict<>(10)
   */
  int map8_size = 10;
  ch8node_f64node_Tree *map8[map8_size];
  for (int i = 0; i < map8_size; i++)
    map8[i] = NULL;

  set_dict_ch8k_f64v(map8, "hello", __ch8_key_hash("hello", &map8_size), 1.0);
  set_dict_ch8k_f64v(map8, "world", __ch8_key_hash("world", &map8_size), 5.674);
  set_dict_ch8k_f64v(map8, "how", __ch8_key_hash("how", &map8_size), 3.434);
  set_dict_ch8k_f64v(map8, "are", __ch8_key_hash("are", &map8_size), 2.34);

  float vy = get_dict_ch8k_f64v(map8, "hello", &map8_size);
  printf("%f\n", vy);

  vy = get_dict_ch8k_f64v(map8, "how", &map8_size);
  printf("%f\n", vy);

  remove_dict_ch8k_f64v(map8, "how", __ch8_key_hash("how", &map8_size));

  vy = get_dict_ch8k_f64v(map8, "how", &map8_size);
  printf("%f\n", vy);

  ch8node *keys8 = NULL;
  int keys8_size = 0;
  keys_dict_ch8k_f64v(map8, &map8_size, &keys8, &keys8_size);
  view_ch8_node(keys8, keys8_size);

  f64node *values8 = NULL;
  int values8_size = 0;
  values_dict_ch8k_f64v(map8, &map8_size, &values8, &values8_size);
  view_f64_node(values8, values8_size);

  ch8node *items8 = NULL;
  int items8_size = 0;
  items_dict_ch8k_f64v(map8, &map8_size, &items8, &items8_size);
  view_ch8_node(items8, items8_size);

  clear_dict_ch8k_f64v(map8, &map8_size);

  // -------------------------------------------------------

  /**
   * set<int> s = new set<>()
   */
  i32_t_set *s0 = NULL;

  /**
   * s.union(10)
   * s.union(20)
   * s.union(5)
   */
  seed_i32_t_set(&s0, 10);
  seed_i32_t_set(&s0, 20);
  seed_i32_t_set(&s0, 5);

  /**
   * e = s.elements()
   */

  i32node *e = NULL;
  int e_size = 0;
  elements_i32_t_set(&s0, &e, &e_size);

  /**
   * e.print()
   */

  view_i32_set(e, e_size);

  /**
   * s.discard(20)
   */

  delete_i32_t_set(&s0, 20);

  /**
   * e = s.elements()
   */

  e = NULL;
  e_size = 0;
  elements_i32_t_set(&s0, &e, &e_size);

  /**
   * e.print()
   */
  view_i32_set(e, e_size);

  /**
   * s.clear()
   */
  clear_i32_t_set(&s0);

  /**
   * e = s.elements()
   */

  e = NULL;
  e_size = 0;
  elements_i32_t_set(&s0, &e, &e_size);

  /**
   * e.print()
   */
  view_i32_set(e, e_size);

  // --------------------------------------------------------------------

  /**
   * set<float> s = new set<>()
   */
  f64_t_set *s1 = NULL;

  /**
   * s.union(10)
   * s.union(20)
   * s.union(5)
   */
  seed_f64_t_set(&s1, 1.0);
  seed_f64_t_set(&s1, 2.0);
  seed_f64_t_set(&s1, 5.3);

  /**
   * e = s.elements()
   */

  f64node *e1 = NULL;
  int e1_size = 0;
  elements_f64_t_set(&s1, &e1, &e1_size);

  /**
   * e.print()
   */

  view_f64_set(e1, e1_size);

  /**
   * s.discard(20)
   */

  delete_f64_t_set(&s1, 2.0);

  /**
   * e = s.elements()
   */

  e1 = NULL;
  e1_size = 0;
  elements_f64_t_set(&s1, &e1, &e1_size);

  /**
   * e.print()
   */
  view_f64_set(e1, e1_size);

  /**
   * s.clear()
   */
  clear_f64_t_set(&s1);

  /**
   * e = s.elements()
   */

  e1 = NULL;
  e1_size = 0;
  elements_f64_t_set(&s1, &e1, &e1_size);

  /**
   * e.print()
   */
  view_f64_set(e1, e1_size);
  // --------------------------------------------------------------------
  /**
   * set<str> s = new set<>()
   */
  ch8_t_set *s3 = NULL;

  seed_ch8_t_set(&s3, "ram");
  seed_ch8_t_set(&s3, "ram");
  seed_ch8_t_set(&s3, "ramesh");

  ch8node *e3 = NULL;
  int e3_size = 0;
  elements_ch8_t_set(&s3, &e3, &e3_size);

  view_ch8_set(e3, e3_size);

  delete_ch8_t_set(&s3, "ramesh");

  e3 = NULL;
  e3_size = 0;
  elements_ch8_t_set(&s3, &e3, &e3_size);

  view_ch8_set(e3, e3_size);

  clear_ch8_t_set(&s3);

  e3 = NULL;
  e3_size = 0;
  elements_ch8_t_set(&s3, &e3, &e3_size);

  view_ch8_set(e3, e3_size);
  // -------------------------------------
  // Two sets
  i32_t_set *set1 = NULL;
  seed_i32_t_set(&set1, 1);
  seed_i32_t_set(&set1, 5);
  seed_i32_t_set(&set1, 10);
  i32_t_set *set2 = NULL;
  seed_i32_t_set(&set2, 5);
  seed_i32_t_set(&set2, 10);
  seed_i32_t_set(&set2, 11);

  // {1,5,10} U {5,10,11} : {1,5,10,11}

  /**
   * set1.union(set2)
   */
  union_i32_t_set(&set1, &set2);

  /**
   * ex = set1.elements()
   */
  i32node *ex = NULL;
  int ex_size = 0;
  elements_i32_t_set(&set1, &ex, &ex_size);
  /**
   * ex.print()
   */
  view_i32_set(ex, ex_size);
  /**
   * intsec = set1.intersection(set2)
   */
  i32node *intsec = NULL;
  int intsec_size = 0;
  intersection_i32_t_set(&set1, &set2, &intsec, &intsec_size);

  view_i32_set(intsec, intsec_size);
  /**
   * set1.difference(set2)
   */

  difference_i32_t_set(&set1, &set2);

  ex = NULL;
  ex_size = 0;
  elements_i32_t_set(&set1, &ex, &ex_size);
  view_i32_set(ex, ex_size);
  // --------------------------------------------

  // String functions
  char *name = "alice";

  // l = name.length()
  int l = word_magnitude(&name);
  printf("%d\n", l);

  // ch = name.charAt(2)
  char *ch = word_character_at_index(&name, 0);
  printf("%s\n", ch);

  // ss = name.subString(0,3)
  char *ss = word_sub_string(&name, 0, 3);
  printf("%s\n", ss);

  // ss = name.subString(3,-1)
  ss = word_sub_string(&name, 3, -1);
  printf("%s\n", ss);

  char *name2 = "namaste hyderabad, how are you der ?";

  // eq = name.equals(name2)
  int eq = word_check_similarity(&name, &name2);
  printf("%d\n", eq);

  char *stream = "der";
  // co = name2.contains(stream)
  int co = word_contains(&name2, &stream);
  printf("%d\n", co);

  stream = "d";
  // co = name2.firstIndex(stream)
  co = word_contains(&name2, &stream);
  printf("%d\n", co);

  stream = "d";
  // co = name2.lastIndex(stream)
  co = word_last_index(&name2, &stream);
  printf("%d\n", co);

  stream = "nama";
  // co = name2.startsWith(stream)
  co = word_starts_with(&name2, &stream);
  printf("%d\n", co);

  stream = "er ?";
  // co = name2.endsWith(stream)
  co = word_ends_with(&name2, &stream);
  printf("%d\n", co);

  // name = name.upperCase()
  name = word_upper_case(&name);
  printf("%s\n", name);

  // name = name.lowerCase()
  name = word_lower_case(&name);
  printf("%s\n", name);

  char *word = "      rohit       ";
  // word = word.trim()
  word = word_trim(&word);
  printf("%s\n", word);

  char *message = "hello     alice how are you alice";
  char *_name = "alice";
  char *__name = "bob";
  // message = message.replace(_name, __name)
  message = word_replace(&message, &_name, &__name);
  printf("%s\n", message);

  // tokens = message.split()
  ch8node *tokens = NULL;
  int tokens_size = 0;
  word_split(&message, &tokens, &tokens_size);
  view_ch8_node(tokens, tokens_size);

  // charArr = toCharArray()
  ch8node *charArr = NULL;
  int charArr_size = 0;
  word_char_split(&message, &charArr, &charArr_size);
  view_ch8_node(charArr, charArr_size);

  char *delimeter = " ";
  // stream2 = delimeter.join(name, name2, message)
  char *stream2 = word_binder_with_delimiter(4, "-", "hey", "hello", "how");
  printf("%s\n", stream2);

  // bin = name.toBinary()
  char *bin = word_binary_representation(&name);
  printf("%s\n", bin);

  // hex = name.toHexa()
  char *x = "hello how are you ? brooww";
  char *hex = word_hexa_representation(&x);
  printf("%s\n", hex);

  // oct = name.toOcta()
  char *oct = word_octa_representation(&name);
  printf("%s\n", oct);

  // name = name.reverse()
  name = word_reverse(&name);
  printf("%s\n", name);

  char *number = "12345566789";

  // status = number.isNum()
  int status = word_check_if_all_numerical(&number);
  printf("%d\n", status);

  number = "sujahdbvshd";
  // status = number.isAlpha()
  status = word_check_if_all_alpha(&number);
  printf("%d\n", status);

  number = "sujahdbvshd";
  // status = number.isAlphaNum()
  status = word_check_if_all_alpha_numerical(&number);
  printf("%d\n", status);

  number = "shgd";
  // status = number.isEmpty()
  status = word_check_if_empty(&number);
  printf("%d\n", status);

  // These shall be built using my java packages.
  // encrypt
  // decrypt
  // codeCrackerAlgo

  i32node *vec1 = NULL;
  int vec1_size = 0;
  add_i32_node(&vec1, 1, &vec1_size);
  add_i32_node(&vec1, 2, &vec1_size);
  add_i32_node(&vec1, 3, &vec1_size);

  i32node *vec2 = NULL;
  int vec2_size = 0;
  add_i32_node(&vec2, 4, &vec2_size);
  add_i32_node(&vec2, 5, &vec2_size);
  add_i32_node(&vec2, 6, &vec2_size);

  i32node *vec3 = NULL;
  int vec3_size = 0;
  add_i32_node(&vec3, 7, &vec3_size);
  add_i32_node(&vec3, 8, &vec3_size);
  add_i32_node(&vec3, 9, &vec3_size);
  add_i32_node(&vec3, 10, &vec3_size);

  i32node *vec4 = NULL;
  int vec4_size = 0;

  i32vec *mat = NULL;
  int mat_size = 0;
  add_i32_vec(&mat, &vec1, &mat_size);
  add_i32_vec(&mat, &vec2, &mat_size);
  add_i32_vec(&mat, &vec3, &mat_size);
  add_i32_vec(&mat, &vec4, &mat_size);

  // mat.print()
  view_i32_vec(mat, mat_size);

  // list = mat.get(2)
  i32node *list = get_i32_vec(&mat, 2);
  // The compiler should know that list is a mul-dim variable, as few functions differ in list using multi-dims.

  // list.print()
  view_i32_node(list, magnitude_i32_node(&list));

  // list.add(20)
  int __garbage__ = 0;
  add_i32_node(&list, 20, &__garbage__);

  // list.get(1)
  printf("%d\n", get_i32_node(&list, 1));

  // mat.size()
  printf("%d\n", size_i32_vec(mat_size));

  // mat.insertAt(1, vec4)
  insert_at_i32_vec(&mat, &vec4, 1, &mat_size);

  // mat.print()
  view_i32_vec(mat, mat_size);

  // mat.clear()
  // clear_i32_vec(&mat, &mat_size);

  // mat.print()
  view_i32_vec(mat, mat_size);

  // mat.pop()
  pop_i32_vec(&mat, &mat_size);

  // mat.print()
  view_i32_vec(mat, mat_size);

  // mat.delete(1)
  delete_at_i32_vec(&mat, 1, &mat_size);

  // mat.print()
  view_i32_vec(mat, mat_size);

  // M-dim float

  f64node *vec12 = NULL;
  int vec12_size = 0;
  add_f64_node(&vec12, 1, &vec12_size);
  add_f64_node(&vec12, 2, &vec12_size);
  add_f64_node(&vec12, 3, &vec12_size);

  f64node *vec22 = NULL;
  int vec22_size = 0;
  add_f64_node(&vec22, 4, &vec22_size);
  add_f64_node(&vec22, 5, &vec22_size);
  add_f64_node(&vec22, 6, &vec22_size);

  f64node *vec32 = NULL;
  int vec32_size = 0;
  add_f64_node(&vec32, 7, &vec32_size);
  add_f64_node(&vec32, 8, &vec32_size);
  add_f64_node(&vec32, 9, &vec32_size);
  add_f64_node(&vec32, 10, &vec32_size);

  f64node *vec42 = NULL;
  int vec42_size = 0;

  f64vec *mat1 = NULL;
  int mat1_size = 0;
  add_f64_vec(&mat1, &vec12, &mat1_size);
  add_f64_vec(&mat1, &vec22, &mat1_size);
  add_f64_vec(&mat1, &vec32, &mat1_size);
  add_f64_vec(&mat1, &vec42, &mat1_size);

  // mat1.print()
  view_f64_vec(mat1, mat1_size);

  // list2 = mat1.get(2)
  f64node *list2 = get_f64_vec(&mat1, 2);
  // The compiler should know that list is a mul-dim variable, as few functions differ in list using multi-dims.

  // list2.print()
  view_f64_node(list2, magnitude_f64_node(&list2));

  // list2.add(20.14)
  __garbage__ = 0;
  add_f64_node(&list2, 20.14, &__garbage__);

  // list2.get(1)
  printf("%f\n", get_f64_node(&list2, 1));

  // mat.size()
  printf("%d\n", size_f64_vec(mat1_size));

  // mat1.insertAt(1, vec42)
  insert_at_f64_vec(&mat1, &vec42, 1, &mat1_size);

  // mat.print()
  view_f64_vec(mat1, mat1_size);

  // mat1.clear()
  // clear_f64_vec(&mat1, &mat1_size);

  // mat1.print()
  view_f64_vec(mat1, mat1_size);

  // mat1.pop()
  pop_f64_vec(&mat1, &mat1_size);

  // mat1.print()
  view_f64_vec(mat1, mat1_size);

  // mat.delete(1)
  delete_at_f64_vec(&mat1, 1, &mat1_size);

  // mat.print()
  view_f64_vec(mat1, mat1_size);

  // M-dim string

  // M-dim float

  ch8node *vec123 = NULL;
  int vec123_size = 0;
  add_ch8_node(&vec123, "abc", &vec123_size);
  add_ch8_node(&vec123, "bcd", &vec123_size);
  add_ch8_node(&vec123, "cde", &vec123_size);

  ch8node *vec124 = NULL;
  int vec124_size = 0;
  add_ch8_node(&vec124, "def", &vec124_size);
  add_ch8_node(&vec124, "efg", &vec124_size);
  add_ch8_node(&vec124, "fgh", &vec124_size);

  ch8node *vec125 = NULL;
  int vec125_size = 0;
  add_ch8_node(&vec125, "ghi", &vec125_size);
  add_ch8_node(&vec125, "hij", &vec125_size);
  add_ch8_node(&vec125, "ijk", &vec125_size);
  add_ch8_node(&vec125, "jkl", &vec125_size);

  ch8node *vec126 = NULL;
  int vec126_size = 0;

  ch8vec *mat2 = NULL;
  int mat2_size = 0;
  add_ch8_vec(&mat2, &vec123, &mat2_size);
  add_ch8_vec(&mat2, &vec124, &mat2_size);
  add_ch8_vec(&mat2, &vec125, &mat2_size);
  add_ch8_vec(&mat2, &vec126, &mat2_size);

  // mat2.print()
  view_ch8_vec(mat2, mat2_size);

  // list21 = mat2.get(2)
  ch8node *list21 = get_ch8_vec(&mat2, 2);
  // The compiler should know that list is a mul-dim variable, as few functions differ in list using multi-dims.

  // list21.print()
  view_ch8_node(list21, magnitude_ch8_node(&list21));

  // list21.add(20.14)
  __garbage__ = 0;
  add_ch8_node(&list21, "20.14", &__garbage__);

  // list2.get(1)
  printf("%s\n", get_ch8_node(&list21, 1));

  // mat.size()
  printf("%d\n", size_ch8_vec(mat2_size));

  // mat2.insertAt(1, vec126)
  insert_at_ch8_vec(&mat2, &vec126, 1, &mat2_size);

  // mat.print()
  view_ch8_vec(mat2, mat2_size);

  // mat2.clear()
  // clear_ch8_vec(&mat2, &mat2_size);

  // mat2.print()
  view_ch8_vec(mat2, mat2_size);

  // mat2.pop()
  pop_ch8_vec(&mat2, &mat2_size);

  // mat2.print()
  view_ch8_vec(mat2, mat2_size);

  // mat.delete(1)
  delete_at_ch8_vec(&mat2, 1, &mat2_size);

  // mat.print()
  view_ch8_vec(mat2, mat2_size);

  // Deep copy

  i32node *x_list = NULL;
  int x_list_size = 0;
  add_i32_node(&x_list, 111, &x_list_size);
  add_i32_node(&x_list, 222, &x_list_size);
  add_i32_node(&x_list, 333, &x_list_size);

  // list<int> temp = new list<>()
  i32node *x_list_temp = NULL;
  int x_list_temp_size = 0;

  // temp.deepCopy(x_list)
  deep_copy_i32_node(&x_list_temp, &x_list_temp_size, &x_list, &x_list_size);

  // PriorityQueue-API
  // heap_pq<int> m = new heap_pq<MAX>()
  pq_i32 *m = (pq_i32 *)malloc(sizeof(pq_i32));
  int m_heap_order = 1;
  m->size = 0;
  // HEAP-Order: 0 is MIN,
  // HEAP-Order: 1 is MAX

  // m.offer(1)
  offer_i32_heap(1, &m, m_heap_order);
  // m.offer(3)
  offer_i32_heap(3, &m, m_heap_order);
  // m.offer(2)
  offer_i32_heap(2, &m, m_heap_order);
  // m.offer(7)
  offer_i32_heap(7, &m, m_heap_order);
  // m.offer(6)
  offer_i32_heap(6, &m, m_heap_order);
  // e = m.poll()
  int E = poll_i32_heap(&m, m_heap_order);
  printf("%d\n--\n", E);

  // m.offer(16)
  offer_i32_heap(16, &m, m_heap_order);
  while ((E = poll_i32_heap(&m, m_heap_order)) != -1)
  {
    printf("%d\n", E);
  }

  pq_f64 *m2 = (pq_f64 *)malloc(sizeof(pq_f64));
  int m2_heap_order = 1;
  m2->size = 0;
  // HEAP-Order: 0 is MIN,
  // HEAP-Order: 1 is MAX

  // m.offer(1)
  offer_f64_heap(1.23, &m2, m2_heap_order);
  // m.offer(3)
  offer_f64_heap(3.423, &m2, m2_heap_order);
  // m.offer(2)
  offer_f64_heap(3.23, &m2, m2_heap_order);
  // m.offer(7)
  offer_f64_heap(8.23, &m2, m2_heap_order);
  // m.offer(6)
  offer_f64_heap(6.23, &m2, m2_heap_order);
  // e = m.poll()
  double F = poll_f64_heap(&m2, m2_heap_order);
  printf("%.10f\n--\n", F);

  // m.offer(16)
  offer_f64_heap(16.97, &m2, m2_heap_order);
  while ((F = poll_f64_heap(&m2, m2_heap_order)) != -1)
  {
    printf("%.10f\n", F);
  }

  // ---------------------- Any List ------------------------

  // All the values will be in 'String' by default while working with wild card types.
  // 'T' indicates a list ch8node

  // list<?> l = new list<>()
  // For logging output use 'trace()'

  any_list_dtype *l12 = NULL;
  int l12_magnitude = 0;

  // // list<T> e1 = new list<>()
  ch8node *e12 = NULL;
  int e12_size = 0;

  // // e1.push(98)
  add_ch8_node(&e12, "98", &e12_size);

  // // e1.push(232)
  add_ch8_node(&e12, "232", &e12_size);

  // // l.push(e1)
  add_any_list_dtype_node(&l12, &l12_magnitude, e12, 0);

  // // list<T> e2 = new list<>()
  ch8node *e22 = NULL;
  int e22_size = 0;

  // // e2.push(3.79)
  add_ch8_node(&e22, "3.79", &e22_size);

  // // e2.push(34.3)
  add_ch8_node(&e22, "34.3", &e22_size);

  // // e2.push(376.09)
  add_ch8_node(&e22, "376.09", &e22_size);

  // // l.push(e2)
  add_any_list_dtype_node(&l12, &l12_magnitude, e22, 0);

  // // list<T> e3 = new list<>()
  ch8node *e32 = NULL;
  int e32_size = 0;

  // // e3.push("hi")
  add_ch8_node(&e32, "hi", &e32_size);

  // // e3.push("how are you")
  add_ch8_node(&e32, "how are you", &e32_size);

  // // l.push(e3)
  add_any_list_dtype_node(&l12, &l12_magnitude, e32, 0);
  // // Set 0 if type is T, else 1

  // // list<T> as = new list<>()
  ch8node *as = NULL;
  int as_size = 0;

  // // as.push("12")
  add_ch8_node(&as, "12", &as_size);
  // // as.push("3")
  add_ch8_node(&as, "3", &as_size);

  // // l.insertAt(1, as)
  insert_any_list_dtype_node(&l12, as, 1, &l12_magnitude, 0);

  // // l.trace()
  view_any_list_dtype_node(l12);

  // --------------------------------------------

  // // list<list<list<int>>>
  any_list_dtype *l13 = NULL;
  int l13_magnitude = 0;

  // // list<?> g1 = new list<>()
  any_list_dtype *g1 = NULL;
  int g1_magnitude = 0;

  // // list<T> E1 = new list<>()
  ch8node *E1 = NULL;
  int E1_size = 0;

  // // e1.push(98)
  add_ch8_node(&E1, "98", &E1_size);
  // // e1.push(232)
  add_ch8_node(&E1, "232", &E1_size);

  // // g1.push(E1)
  add_any_list_dtype_node(&g1, &g1_magnitude, E1, 0);

  // // list<?> g2 = new list<>()
  any_list_dtype *g2 = NULL;
  int g2_magnitude = 0;

  // // list<T> E2 = new list<>()
  ch8node *E2 = NULL;
  int E2_size = 0;

  // // E2.push("Hi")
  add_ch8_node(&E2, "Hi", &E2_size);
  // // E2.push("How are you?")
  add_ch8_node(&E2, "How are you?", &E2_size);

  // // g2.push(E2)
  add_any_list_dtype_node(&g2, &g1_magnitude, E2, 0);

  // // l.push(g1)
  add_any_list_dtype_node(&l13, &l13_magnitude, g1, 1);

  // // l.push(g2)
  add_any_list_dtype_node(&l13, &l13_magnitude, g2, 1);

  // // l.trace()
  view_any_list_dtype_node(l13);

  // // If you are getting an entry with wild-card anylist use '?'
  // // ele = (?) l.get(0)
  any_list_dtype *buff2 = (any_list_dtype *)get_any_list_dtype_node(&l13, 0);

  // // buff2.trace()
  view_any_list_dtype_node(buff2);

  // printf("+---------------------+\n");

  // // -----------------------------------------------------------

  // Pre-reqs, add these at start while working with set's in list.
  ch8node *any_set_temp_view;
  int any_set_temp_view_size;

  // list<?> listOfSet = new list<>()
  any_list_dtype *listOfSet = NULL;
  int listOfSet_magnitude = 0;

  // set<T> s = new set<>()
  ch8_t_set *s2 = NULL;

  // // s.union("ram")
  seed_ch8_t_set(&s2, "ram");
  // // s.union("ramesh")
  seed_ch8_t_set(&s2, "ramesh");
  // // s.union("ramesh")
  seed_ch8_t_set(&s2, "ramesh");

  // listOfSet.push(s)
  any_set_temp_view = NULL;
  any_set_temp_view_size = 0;
  elements_ch8_t_set(&s2, &any_set_temp_view, &any_set_temp_view_size);
  add_any_list_dtype_node(&listOfSet, &listOfSet_magnitude, any_set_temp_view, 0);

  // set<T> s2 = new set<>()
  ch8_t_set *s22 = NULL;

  // // s2.union("ram")
  seed_ch8_t_set(&s22, "shyam");
  // // s2.union("ramesh")
  seed_ch8_t_set(&s22, "shyam");
  // // s2.union("ramesh")
  seed_ch8_t_set(&s22, "sunil");

  // listOfSet.push(s2)
  any_set_temp_view = NULL;
  any_set_temp_view_size = 0;
  elements_ch8_t_set(&s22, &any_set_temp_view, &any_set_temp_view_size);
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

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  // listOfSet.poll()
  poll_any_list_dtype_node(&listOfSet, &listOfSet_magnitude);

  // listOfSet.pop()
  pop_any_list_dtype_node(&listOfSet, &listOfSet_magnitude);

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  // listOfSet.insertAt(1, l)
  insert_any_list_dtype_node(&listOfSet, l13, 0, &listOfSet_magnitude, 1);

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  // listOfSet.deleteAt(1)
  delete_any_list_dtype_node(&listOfSet, 1, &listOfSet_magnitude);

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  // listOfSet.pop()
  pop_any_list_dtype_node(&listOfSet, &listOfSet_magnitude);

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  // size = listOfSet.isEmpty()
  int size = is_empty_any_list_dtype_node(&listOfSet_magnitude);
  printf("%d\n", size);
  printf("+-----------------------+\n");
  // l.trace()
  view_any_list_dtype_node(l13);

  // l.clear()
  clear_any_list_dtype_node(&l13, &l13_magnitude);

  // l.trace()
  view_any_list_dtype_node(l13);

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  printf("+-----------------------+\n");

  // listOfSet.reverse()
  reverse_any_list_dtype_node(&listOfSet);

  // listOfSet.trace()
  view_any_list_dtype_node(listOfSet);

  printf("+-----------------------+\n");

  // If you are getting an entry with defined type, use T. 'T' will correspond to list<str>
  // buff = (T) listOfSet.get(0)
  ch8node *buff = (ch8node *)get_any_list_dtype_node(&listOfSet, 0);

  // buff.print()
  view_T_node(buff);

  // Added support for priority queue & anylist.
}
