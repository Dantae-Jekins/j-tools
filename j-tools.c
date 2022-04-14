// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "./j-tools/j-structures/j_linkedList.h"
#include <stdio.h>

int main() {

  
  list teste = list_new();
  
  struct Item item1 = item_new( 15 );
  struct Item item2 = item_new( 25 );
  
  list_addFirst( &teste, item1);
  list_addFirst( &teste, item2);
  list_addLast( &teste, item1);
  list_addLast( &teste, item2);

  char *ret = list_toString(teste);
  printf("%s", ret);
  free(ret);

  list_Free(&teste);

}
