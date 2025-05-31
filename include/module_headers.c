#define LINKED_LIST_INT
#define LINKED_LIST_STRING
#define LINKED_LIST_FLOAT
#define HASH_MAP_STRING

#include <stdio.h>   // Standard input/output functions
#include <stdlib.h>  // General utilities: memory allocation, program control
#include <string.h>  // String handling
#include <math.h>    // Math functions
#include <ctype.h>   // Character handling
#include <time.h>    // Time/date utilities
#include <stdbool.h> // Boolean type and values (C99 and later)
#include <stdarg.h>  // Variable argument handling
#include <limits.h>  // Integer limits
#include <float.h>   // Floating-point limits
#include <assert.h>  // Debugging macro
#include <signal.h>  // Signal handling
#include <setjmp.h>  // Non-local jumps

#include "./lib/util/linked_list_int.c"
#include "./lib/util/linked_list_string.c"
#include "./lib/util/linked_list_float.c"
#include "./lib/util/hash_map_ch8k_ch8v.c"
#include "./lib/util/hash_map_ch8k_i32v.c"
#include "./lib/util/hash_map_ch8k_f64v.c"
#include "./lib/util/hash_map_i32k_ch8v.c"
#include "./lib/util/hash_map_i32k_i32v.c"
#include "./lib/util/hash_map_i32k_f64v.c"
#include "./lib/util/tree_set_int32.c"
#include "./lib/util/tree_set_float64.c"
#include "./lib/util/tree_set_string.c"
#include "./lib/util/string_sub_routines.c"