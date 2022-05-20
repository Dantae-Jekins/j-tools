// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "./j-tools/j-structures/j_avlTree.h"
#include <stdio.h>

int main() {

  avlTree arvore = avl_New();

  avl_Insert(&arvore, 2);
  avl_Insert(&arvore, 3);
  avl_Insert(&arvore, 1);
  avl_Graphical(arvore);
  
  avl_Insert(&arvore, 5);
  avl_Insert(&arvore, 4);
  avl_Insert(&arvore, 6);
  avl_Graphical(arvore);

  avl_Insert(&arvore, 10);
  avl_Insert(&arvore, 9);
  avl_Insert(&arvore, -1);
  avl_Insert(&arvore, 0);
  avl_Graphical(arvore);

  avl_Free(&arvore);
  return 0;

}
