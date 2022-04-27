// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "./j-tools/j-structures/j_binaryTree.h"
#include <stdio.h>

int main() {
  bsTree main = bst_New();

  bst_Insert(&main, 4);
  bst_Insert(&main, 2);
  bst_Insert(&main, 3);
  bst_Insert(&main, 7);
  bst_Insert(&main, 8);
  bst_Insert(&main, 5);

  bst_inOrder( main );
  bst_Graphical( main );

  printf("\n %d", bst_Remove(&main, 10));
  printf("\n %d\n", bst_Remove(&main, 2));
  
  bst_Graphical( main );
  bst_Free( &main );
}
