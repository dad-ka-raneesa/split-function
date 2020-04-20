#include <stdio.h>
#include <stdlib.h>
#include "split.h"

int get_substrings_count(char *string, char delimiter, int length)
{
  int count = 1;
  for (int i = 0; i < length; i++)
  {
    if (string[i] == delimiter)
    {
      count++;
    }
  }
  return count;
}

char *get_substring(char *copy_to, char *copy_from, int start, int str_length)
{
  int count = 0;
  int end = start + str_length;
  copy_to = malloc(sizeof(char) * str_length);
  for (int i = start; i < end - 1; i++)
  {
    copy_to[count] = copy_from[i];
    count++;
  }
  copy_to[count] = NULL_CHARACTER;
  return copy_to;
}

Char_Array *split_string(char *string, int str_length, char delimiter)
{
  int substrings_count = get_substrings_count(string, delimiter, str_length);

  Char_Array *substrings = malloc(sizeof(Char_Array));
  substrings->size = 0;
  substrings->values = malloc(sizeof(char_ptr) * substrings_count);

  int start = 0;
  int end = 0;
  for (int i = 0; i < str_length; i++)
  {
    end++;
    if (string[i] == delimiter)
    {
      int str_length = end - start;
      substrings->values[substrings->size] = get_substring(substrings->values[substrings->size], string, start, str_length);
      start = end;
      substrings->size++;
    }
  }
  substrings->values[substrings->size] = get_substring(substrings->values[substrings->size], string, start, end - start);
  substrings->size++;
  return substrings;
}

void print_substrings(Char_Array *split_string)
{
  for (int i = 0; i < split_string->size; i++)
  {
    printf("%s", split_string->values[i]);
    printf("\n");
  }
}
