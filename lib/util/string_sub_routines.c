#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef LINKED_LIST_INT
#include "./linked_list_int.c"
#define LINKED_LIST_INT
#endif

#ifndef LINKED_LIST_STRING
#include "./linked_list_string.c"
#define LINKED_LIST_STRING
#endif

#ifndef HASH_MAP_STRING
#include "./hash_map_ch8k_ch8v.c"
#define HASH_MAP_STRING
#endif

#define NULL_STRING "null"
#define END_OF_STRING '\0'
#define SPACE ' '
#define LOWER_CASE_START 'a'
#define LOWER_CASE_END 'z'
#define UPPER_CASE_START 'A'
#define UPPER_CASE_END 'Z'
#define DIGIT_START '0'
#define DIGIT_END '9'

int word_magnitude(char **word)
{
  if ((*word) == NULL)
    return 0;
  int magnitude = 0;
  while ((*word)[magnitude++] != END_OF_STRING)
    ;
  return --magnitude;
}

char *word_character_at_index(char **word, int index)
{
  if ((*word) == NULL)
    return NULL_STRING;
  if (index >= 0 && index < word_magnitude(word))
  {
    char *buffer = (char *)malloc(2);
    buffer[0] = (*word)[index];
    buffer[1] = END_OF_STRING;
    return buffer;
  }
  return NULL_STRING;
}

char *__to_word(char character)
{
  char *buffer = (char *)malloc(2);
  buffer[0] = character;
  buffer[1] = END_OF_STRING;
  return buffer;
}

char *word_sub_string(char **word, int first_index, int last_index)
{
  if ((*word) == NULL)
    return NULL_STRING;
  int word_mag = word_magnitude(word);
  int mag = (last_index - first_index) + 1;

  if ((first_index >= 0 && first_index <= word_mag) &&
      (last_index >= 0 && last_index <= word_mag) &&
      (first_index < last_index))
  {
    char *buffer = (char *)malloc(mag + 1);
    char *__word__ = *word;
    int idx = 0;
    while (first_index < last_index)
      buffer[idx++] = __word__[first_index++];
    buffer[idx] = END_OF_STRING;
    return buffer;
  }
  else if ((first_index >= 0 && first_index <= word_mag) &&
           (last_index == -1))
  {
    char *buffer = (char *)malloc(word_mag - first_index + 1);
    char *__word__ = *word;
    int idx = 0;
    while (first_index < word_mag)
      buffer[idx++] = __word__[first_index++];
    buffer[idx] = END_OF_STRING;
    return buffer;
  }
  return NULL_STRING;
}

int word_check_similarity(char **word_one, char **word_two)
{
  if ((*word_one) == NULL || (*word_two) == NULL)
    return 0;
  int wo_mag = word_magnitude(word_one);
  int wt_mag = word_magnitude(word_two);
  if (wo_mag != wt_mag)
    return 0;
  int idx = 0;
  while (idx < wo_mag)
  {
    if ((*word_one)[idx] != (*word_two)[idx])
      return 0;
    idx++;
  }
  return 1;
}

int word_contains(char **word, char **stream)
{
  if ((*word) == NULL || (*stream) == NULL)
    return 0;
  int col_mag = word_magnitude(word);
  int row_mag = word_magnitude(stream);
  int look_up_table[row_mag][col_mag];
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      look_up_table[i][j] = 0;
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      if ((*word)[j] == (*stream)[i])
        look_up_table[i][j] = ((i == 0) || (j == 0)) ? 1 : (look_up_table[i - 1][j - 1] + 1);
  for (int j = 0; j < col_mag; j++)
    if (look_up_table[row_mag - 1][j] == row_mag)
      return j - row_mag + 1;
  return 0;
}

int word_starts_with(char **word, char **stream)
{
  if ((*word) == NULL || (*stream) == NULL)
    return 0;
  int col_mag = word_magnitude(word);
  int row_mag = word_magnitude(stream);
  int look_up_table[row_mag][col_mag];
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      look_up_table[i][j] = 0;
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      if ((*word)[j] == (*stream)[i])
        look_up_table[i][j] = ((i == 0) || (j == 0)) ? 1 : (look_up_table[i - 1][j - 1] + 1);
  for (int j = 0; j < col_mag; j++)
    if (look_up_table[row_mag - 1][j] == row_mag && j - row_mag + 1 == 0)
      return 1;
  return 0;
}

int word_ends_with(char **word, char **stream)
{
  if ((*word) == NULL || (*stream) == NULL)
    return 0;
  int col_mag = word_magnitude(word);
  int row_mag = word_magnitude(stream);
  int look_up_table[row_mag][col_mag];
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      look_up_table[i][j] = 0;
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      if ((*word)[j] == (*stream)[i])
        look_up_table[i][j] = ((i == 0) || (j == 0)) ? 1 : (look_up_table[i - 1][j - 1] + 1);
  for (int j = 0; j < col_mag; j++)
    if (look_up_table[row_mag - 1][j] == row_mag && j == col_mag - 1)
      return 1;
  return 0;
}

int word_last_index(char **word, char **stream)
{
  if ((*word) == NULL || (*stream) == NULL)
    return 0;
  int col_mag = word_magnitude(word);
  int row_mag = word_magnitude(stream);
  int look_up_table[row_mag][col_mag];
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      look_up_table[i][j] = 0;
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      if ((*word)[j] == (*stream)[i])
        look_up_table[i][j] = ((i == 0) || (j == 0)) ? 1 : (look_up_table[i - 1][j - 1] + 1);
  for (int j = col_mag - 1; j > -1; j--)
    if (look_up_table[row_mag - 1][j] == row_mag)
      return j - row_mag + 1;
  return 0;
}

char *word_upper_case(char **word)
{
  int mag = word_magnitude(word);
  char *__word__ = (*word);
  if (__word__ == NULL)
    return NULL_STRING;
  char *buffer = (char *)malloc(mag + 1);
  int ASCII;
  int i = 0;
  for (; i < mag; i++)
  {
    char ch = __word__[i];
    if (ch >= LOWER_CASE_START && ch <= LOWER_CASE_END)
      buffer[i] = ch - 32;
    else
      buffer[i] = ch;
  }
  buffer[i] = END_OF_STRING;
  return buffer;
}

char *word_lower_case(char **word)
{
  int mag = word_magnitude(word);
  char *__word__ = (*word);
  if (__word__ == NULL)
    return NULL_STRING;
  char *buffer = (char *)malloc(mag + 1);
  int ASCII;
  int i = 0;
  for (; i < mag; i++)
  {
    char ch = __word__[i];
    if (ch >= UPPER_CASE_START && ch <= UPPER_CASE_END)
      buffer[i] = ch + 32;
    else
      buffer[i] = ch;
  }
  buffer[i] = END_OF_STRING;
  return buffer;
}

char *word_trim(char **word)
{
  int mag = word_magnitude(word);
  int startIndex = 0;
  int endIndex = mag - 1;
  while ((*word)[startIndex] == SPACE)
    startIndex++;
  while ((*word)[endIndex] == SPACE)
    endIndex--;
  ++endIndex;
  return word_sub_string(word, startIndex, endIndex);
}

char *word_replace(char **word, char **target, char **replacer)
{
  if ((*word) == NULL || (*target) == NULL || (*replacer) == NULL)
    return (*word);
  int col_mag = word_magnitude(word);
  int row_mag = word_magnitude(target);
  int replacer_mag = word_magnitude(replacer);
  int look_up_table[row_mag][col_mag];
  i32node *__0x32_queue = NULL;
  int __0x32_queue_size = 0;
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      look_up_table[i][j] = 0;
  for (int i = 0; i < row_mag; i++)
    for (int j = 0; j < col_mag; j++)
      if ((*word)[j] == (*target)[i])
        look_up_table[i][j] = ((i == 0) || (j == 0)) ? 1 : (look_up_table[i - 1][j - 1] + 1);
  for (int j = 0; j < col_mag; j++)
    if (look_up_table[row_mag - 1][j] == row_mag)
      add_i32_node(&__0x32_queue, (j - row_mag + 1), &__0x32_queue_size);
  char *buffer = (char *)malloc(col_mag * 2);
  int i = 0;
  int idx = 0;
  while (i < col_mag)
  {
    if (contains_i32_node(&__0x32_queue, i))
    {
      poll_i32_node(&__0x32_queue, &__0x32_queue_size);
      for (int j = 0; j < replacer_mag; j++)
        buffer[idx++] = (*replacer)[j];
      i += row_mag;
    }
    else
      buffer[idx++] = (*word)[i++];
  }
  free(__0x32_queue);
  buffer[idx] = END_OF_STRING;
  return buffer;
}

ch8node **word_split(char **word, ch8node **bucket, int *magnitude)
{
  char *word_bucket = word_trim(word);

  int left_pointer = 0, right_pointer = 0;
  int word_mag = word_magnitude(&word_bucket);
  while (right_pointer < word_mag)
  {
    if (word_bucket[right_pointer] == SPACE || right_pointer == word_mag - 1)
    {
      if (right_pointer == word_mag - 1)
        add_ch8_node(bucket, word_sub_string(word, left_pointer, right_pointer + 1), magnitude);
      else
      {
        add_ch8_node(bucket, word_sub_string(word, left_pointer, right_pointer), magnitude);
        right_pointer++;
        while (word_bucket[right_pointer] == SPACE)
          right_pointer++;
        left_pointer = right_pointer;
      }
    }
    right_pointer++;
  }
  return bucket;
}

ch8node **word_char_split(char **word, ch8node **bucket, int *magnitude)
{
  int word_mag = word_magnitude(word);
  for (int i = 0; i < word_mag; i++)
    add_ch8_node(bucket, __to_word((*word)[i]), magnitude);
  return bucket;
}

char *word_binder_with_delimiter(int number_of_tokens, ...)
{
  va_list args;
  char *buffer = (char *)malloc(number_of_tokens * 512 + 1);
  buffer[0] = END_OF_STRING;
  int i = 0;
  va_start(args, number_of_tokens);
  char *binder = va_arg(args, char *);
  strcat(buffer, va_arg(args, char *));
  for (; i < number_of_tokens - 2; i++)
  {
    strcat(buffer, binder);
    strcat(buffer, va_arg(args, char *));
  }
  va_end(args);
  return buffer;
}

char *__least_common_factor_(int ascii)
{
  char *buffer = (char *)malloc(32 * sizeof(char) + 1);
  buffer[0] = END_OF_STRING;
  int i = 0;
  while (ascii != 0)
  {
    int rem = ascii % 2;
    ascii /= 2;
    buffer[i++] = rem + DIGIT_START;
  }
  while (i < 8)
    buffer[i++] = DIGIT_START;
  buffer[i] = END_OF_STRING;
  buffer = strrev(buffer);
  return buffer;
}

char *word_binary_representation(char **word)
{
  int word_mag = word_magnitude(word);
  char *buffer = (char *)malloc(word_mag * 8 + 1);
  buffer[0] = END_OF_STRING;
  for (int i = 0; i < word_mag; i++)
    strcat(buffer, __least_common_factor_((*word)[i]));
  return buffer;
}

char *word_hexa_representation(char **word)
{
  int hex_map = 10;
  ch8node_ch8node_Tree *hexMap[hex_map];
  for (int i = 0; i < hex_map; i++)
    hexMap[i] = NULL;
  set_dict_ch8k_ch8v(hexMap, "0000", __ch8_key_hash("0000", &hex_map), "0");
  set_dict_ch8k_ch8v(hexMap, "0001", __ch8_key_hash("0001", &hex_map), "1");
  set_dict_ch8k_ch8v(hexMap, "0010", __ch8_key_hash("0010", &hex_map), "2");
  set_dict_ch8k_ch8v(hexMap, "0011", __ch8_key_hash("0011", &hex_map), "3");
  set_dict_ch8k_ch8v(hexMap, "0100", __ch8_key_hash("0100", &hex_map), "4");
  set_dict_ch8k_ch8v(hexMap, "0101", __ch8_key_hash("0101", &hex_map), "5");
  set_dict_ch8k_ch8v(hexMap, "0110", __ch8_key_hash("0110", &hex_map), "6");
  set_dict_ch8k_ch8v(hexMap, "0111", __ch8_key_hash("0111", &hex_map), "7");
  set_dict_ch8k_ch8v(hexMap, "1000", __ch8_key_hash("1000", &hex_map), "8");
  set_dict_ch8k_ch8v(hexMap, "1001", __ch8_key_hash("1001", &hex_map), "9");
  set_dict_ch8k_ch8v(hexMap, "1010", __ch8_key_hash("1010", &hex_map), "a");
  set_dict_ch8k_ch8v(hexMap, "1011", __ch8_key_hash("1011", &hex_map), "b");
  set_dict_ch8k_ch8v(hexMap, "1100", __ch8_key_hash("1100", &hex_map), "c");
  set_dict_ch8k_ch8v(hexMap, "1101", __ch8_key_hash("1101", &hex_map), "d");
  set_dict_ch8k_ch8v(hexMap, "1110", __ch8_key_hash("1110", &hex_map), "e");
  set_dict_ch8k_ch8v(hexMap, "1111", __ch8_key_hash("1111", &hex_map), "f");

  char *binary = word_binary_representation(word);
  int word_mag = word_magnitude(&binary);
  char *__to_hex = (char *)malloc(word_mag);
  __to_hex[0] = END_OF_STRING;
  int right_pointer = 0, left_pointer = 0;
  while (right_pointer <= word_mag)
  {
    if (right_pointer % 4 == 0 || right_pointer == word_mag)
    {
      char *__to_quad = (char *)malloc(5 * sizeof(char));
      __to_quad[0] = END_OF_STRING;
      while (left_pointer != right_pointer)
        strcat(__to_quad, __to_word(binary[left_pointer++]));

      if (word_magnitude(&__to_quad) != 0)
        strcat(__to_hex, get_dict_ch8k_ch8v(hexMap, __to_quad, &hex_map));
    }
    right_pointer++;
  }
  return __to_hex;
}

char *word_octa_representation(char **word)
{
  int oct_map_size = 5;
  ch8node_ch8node_Tree *octMap[oct_map_size];
  for (int i = 0; i < oct_map_size; i++)
    octMap[i] = NULL;
  set_dict_ch8k_ch8v(octMap, "000", __ch8_key_hash("000", &oct_map_size), "0");
  set_dict_ch8k_ch8v(octMap, "001", __ch8_key_hash("001", &oct_map_size), "1");
  set_dict_ch8k_ch8v(octMap, "010", __ch8_key_hash("010", &oct_map_size), "2");
  set_dict_ch8k_ch8v(octMap, "011", __ch8_key_hash("011", &oct_map_size), "3");
  set_dict_ch8k_ch8v(octMap, "100", __ch8_key_hash("100", &oct_map_size), "4");
  set_dict_ch8k_ch8v(octMap, "101", __ch8_key_hash("101", &oct_map_size), "5");
  set_dict_ch8k_ch8v(octMap, "110", __ch8_key_hash("110", &oct_map_size), "6");
  set_dict_ch8k_ch8v(octMap, "111", __ch8_key_hash("111", &oct_map_size), "7");
  char *binary = word_binary_representation(word);
  int word_mag = word_magnitude(&binary);
  int pad_len = (3 - (word_mag % 3)) % 3;
  char *padded_binary = (char *)malloc(word_mag + pad_len + 1);
  padded_binary[0] = END_OF_STRING;
  for (int i = 0; i < pad_len; i++)
    strcat(padded_binary, "0");
  strcat(padded_binary, binary);
  int padded_len = word_mag + pad_len;
  char *__to_oct = (char *)malloc(padded_len / 3 + 1);
  __to_oct[0] = END_OF_STRING;
  char triad[4];
  triad[3] = END_OF_STRING;
  for (int i = 0; i < padded_len; i += 3)
  {
    triad[0] = padded_binary[i];
    triad[1] = padded_binary[i + 1];
    triad[2] = padded_binary[i + 2];
    strcat(__to_oct, get_dict_ch8k_ch8v(octMap, triad, &oct_map_size));
  }
  free(padded_binary);
  return __to_oct;
}

char *word_reverse(char **word)
{
  int len = word_magnitude(word);
  for (int i = 0; i < len / 2; i++)
  {
    char temp = (*word)[i];
    (*word)[i] = (*word)[len - 1 - i];
    (*word)[len - 1 - i] = temp;
  }
  return *word;
}

int word_check_if_all_numerical(char **word)
{
  int word_mag = word_magnitude(word);
  for (int i = 0; i < word_mag; i++)
    if ((*word)[i] < DIGIT_START || (*word)[i] > DIGIT_END)
      return 0;
  return 1;
}

int word_check_if_all_alpha(char **word)
{
  int word_mag = word_magnitude(word);
  for (int i = 0; i < word_mag; i++)
    if (((*word)[i] < LOWER_CASE_START || (*word)[i] > LOWER_CASE_END) &&
        ((*word)[i] < UPPER_CASE_START || (*word)[i] > UPPER_CASE_END))
      return 0;
  return 1;
}

int word_check_if_all_alpha_numerical(char **word)
{
  int word_mag = word_magnitude(word);
  for (int i = 0; i < word_mag; i++)
    if (!(((*word)[i] >= LOWER_CASE_START && (*word)[i] <= LOWER_CASE_END) ||
          ((*word)[i] >= UPPER_CASE_START && (*word)[i] <= UPPER_CASE_END) ||
          ((*word)[i] >= DIGIT_START && (*word)[i] <= DIGIT_END)))
      return 0;
  return 1;
}

int word_check_if_empty(char **word)
{
  return (*word)[0] == END_OF_STRING ? 1 : 0;
}

char *stringify_ch8_nodes_ch8_node(ch8node **root)
{
  char *buffer = (char *)malloc(2048 * sizeof(char));
  ch8node *pointer = (*root);
  buffer[0] = END_OF_STRING;
  while (pointer != NULL)
  {
    strcat(buffer, pointer->data);
    pointer = pointer->next;
  }
  return buffer;
}

// void main()
// {
//   char *name = "rohit s v";

//   // l = name.length()
//   int l = word_magnitude(&name);
//   printf("%d\n", l);

//   // ch = name.charAt(2)
//   char *ch = word_character_at_index(&name, 0);
//   printf("%s\n", ch);

//   // ss = name.subString(0,3)
//   char *ss = word_sub_string(&name, 0, 3);
//   printf("%s\n", ss);

//   // ss = name.subString(3,-1)
//   ss = word_sub_string(&name, 3, -1);
//   printf("%s\n", ss);

//   char *name2 = "namaste hyderabad, how are you der ?";

//   // eq = name.equals(name2)
//   int eq = word_check_similarity(&name, &name2);
//   printf("%d\n", eq);

//   char *stream = "der";
//   // co = name2.contains(stream)
//   int co = word_contains(&name2, &stream);
//   printf("%d\n", co);

//   stream = "d";
//   // co = name2.firstIndex(stream)
//   co = word_contains(&name2, &stream);
//   printf("%d\n", co);

//   stream = "d";
//   // co = name2.lastIndex(stream)
//   co = word_last_index(&name2, &stream);
//   printf("%d\n", co);

//   stream = "nama";
//   // co = name2.startsWith(stream)
//   co = word_starts_with(&name2, &stream);
//   printf("%d\n", co);

//   stream = "er ?";
//   // co = name2.endsWith(stream)
//   co = word_ends_with(&name2, &stream);
//   printf("%d\n", co);

//   // name = name.upperCase()
//   name = word_upper_case(&name);
//   printf("%s\n", name);

//   // name = name.lowerCase()
//   name = word_lower_case(&name);
//   printf("%s\n", name);

//   char *word = "      rohit       ";
//   // word = word.trim()
//   word = word_trim(&word);
//   printf("%s\n", word);

//   char *message = "hello     alice how are you alice";
//   char *_name = "alice";
//   char *__name = "bob";
//   // message = message.replace(_name, __name)
//   message = word_replace(&message, &_name, &__name);
//   printf("%s\n", message);

//   char *delimeter = " ";
//   // stream2 = delimeter.join(name, name2, message)
//   char *stream2 = word_binder_with_delimiter(4, "-", "hey", "hello", "how");
//   printf("%s\n", stream2);

//   // bin = name.toBinary()
//   char *bin = word_binary_representation(&name);
//   printf("%s\n", bin);

//   // hex = name.toHexa()
//   char *x = "hello how are you ? brooww";
//   char *hex = word_hexa_representation(&x);
//   printf("%s\n", hex);

//   // oct = name.toOcta()
//   char *oct = word_octa_representation(&name);
//   printf("%s\n", oct);

//   // name = name.reverse()
//   name = word_reverse(&name);
//   printf("%s\n", name);

//   char *number = "12345566789";

//   // status = number.isNum()
//   int status = word_check_if_all_numerical(&number);
//   printf("%d\n", status);

//   number = "sujahdbvshd";
//   // status = number.isAlpha()
//   status = word_check_if_all_alpha(&number);
//   printf("%d\n", status);

//   number = "sujahdbvshd";
//   // status = number.isAlphaNum()
//   status = word_check_if_all_alpha_numerical(&number);
//   printf("%d\n", status);

//   number = "shgd";
//   // status = number.isEmpty()
//   status = word_check_if_empty(&number);
//   printf("%d\n", status);

//   // tokens = message.split()
//   ch8node *tokens = NULL;
//   int tokens_size = 0;
//   word_split(&message, &tokens, &tokens_size);
//   view_ch8_node(tokens, tokens_size);

//   // charArr = toCharArray()
//   ch8node *charArr = NULL;
//   int charArr_size = 0;
//   word_char_split(&message, &charArr, &charArr_size);
//   view_ch8_node(charArr, charArr_size);

//   // encrypt
//   // decrypt
//   // codeCrackerAlgo
// }