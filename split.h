#ifndef __FILTER_H_
#define __FILTER_H_
#define NULL_CHARACTER '\0'

typedef char *char_ptr;
typedef struct
{
  int size;
  char_ptr *values;
} Char_Array;

int get_substrings_count(char *string, char delimiter, int length);
char *get_substring(char *copy_to, char *copy_from, int start, int str_length);
Char_Array *split_string(char *string, int str_length, char delimiter);
void print_substrings(Char_Array *split_string);

#endif