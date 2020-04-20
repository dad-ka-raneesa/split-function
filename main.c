#include <stdio.h>
#include <stdlib.h>
#include "split.h"

int main(void)
{
  char string[] = "Hello World";
  int str_length = sizeof(string) / sizeof(char);
  char delimiter = 'o';
  Char_Array *substrings = split_string(string, str_length, delimiter);
  print_substrings(substrings);
  free(substrings);
  return 0;
}