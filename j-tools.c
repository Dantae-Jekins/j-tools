// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "j-tools/j_structures.h"
#include <stdio.h>

int main() {
    int_LinkedList list = new_int_List();
    
    printf("\n%s", int_List_String(&list));

    insert_int_List(&list, 10);

    printf("\n%s", int_List_String(&list));

    insert_int_List(&list, 10);

    printf("\n%s", int_List_String(&list));

    remove_int_List(&list, 10);

    printf("\n%s", int_List_String(&list));

    remove_int_List(&list, 15);
    
    printf("\n%s", int_List_String(&list));

}