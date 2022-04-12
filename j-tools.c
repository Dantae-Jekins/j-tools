// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "./j-tools/j_strings.h"
#include <stdio.h>

int main() {
  char **ret = str_split("something", ',');
  for(int i = 0; ret[i] != NULL; i++)
    printf("%s\n", ret[i]);
  return 0;
}
