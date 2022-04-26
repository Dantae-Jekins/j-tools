// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "./j-tools/j-structures/j_binaryTree.h"
#include <stdio.h>

int main() {
  bsTree main = bst_New();
  printf("%d", bst_Insert(&main, 1));
  printf("%d", bst_Insert(&main, 1));
  printf("%d", bst_Insert(&main, 2));
  printf("%d", bst_Insert(&main, 3));
}
