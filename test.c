#define LINKED_LIST_INT
#define LINKED_LIST_STRING
#define LINKED_LIST_FLOAT

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

void main()
{
  i32node *l1 = NULL;
  int l1_size = 0;

  add_i32_node(&l1, 1, &l1_size);
  add_i32_node(&l1, 2, &l1_size);
  add_i32_node(&l1, 3, &l1_size);
  add_i32_node(&l1, 4, &l1_size);
  view_i32_node(l1, l1_size);
  pop_i32_node(l1, &l1_size);
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
  char *s = contains_i32_node(&l1, 400);
  printf("%s\n", s);
  int n = get_i32_node(&l1, 4);
  printf("%d\n", n);
  n = index_of_i32_node(&l1, -4);
  printf("%d\n", n);
  s = is_empty_i32_node(&l1_size);
  printf("%s\n", s);
  view_i32_node(l1, l1_size);
  s = is_empty_i32_node(&l1_size);
  printf("%s\n", s);
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
  printf("%s\n", s);
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
  printf("Contains 'cherry': %s\n", contains_ch8_node(&c1, "cherry"));
  printf("Get index 2: %s\n", get_ch8_node(&c1, 2));
  printf("Index of 'date': %d\n", index_of_ch8_node(&c1, "date"));
  printf("Is empty: %s\n", is_empty_ch8_node(&c1_size));
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

  printf("Contains 3.3: %s\n", contains_f64_node(&f1, 3.3));
  printf("Get index 2: %.2f\n", get_f64_node(&f1, 2));
  printf("Index of 4.4: %d\n", index_of_f64_node(&f1, 4.4));
  printf("Is empty: %s\n", is_empty_f64_node(&f1_size));

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
}
