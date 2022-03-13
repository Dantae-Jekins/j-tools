// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.

#include "j-tools/j-structures/j_linkedList.h"
#include <stdio.h>

int main() {
    int_LinkedList list = new_int_List();
    
    char *val = int_List_String(&list);
    printf("\n%s", val);
    free(val);

    insert_int_List(&list, 10);

    val = int_List_String(&list);
    printf("\n%s", val);
    free(val);

    insert_int_List(&list, 10);

    val = int_List_String(&list);
    printf("\n%s", val);
    free(val);

    remove_int_List(&list, 10);

    val = int_List_String(&list);
    printf("\n%s", val);
    free(val);

    remove_int_List(&list, 15);
    
    val = int_List_String(&list);
    printf("\n%s", val);
    free(val);

    free_int_List(&list);
}
