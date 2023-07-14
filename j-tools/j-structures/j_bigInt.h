#ifndef J_BIGINT_H
#define J_BIGINT_H

// V 0

#include <stdlib.h>

// TODO?
// Implement the linked list to avoid having to use realloc (unsure)
// use base 256 (come up with new really hard methods) or base 10 (plenty documentation)

struct j_bigInt
{
    /* data */
    int  length;
    char *digit;
};

j_bigInt bigint_New() {
    j_bigInt ret;
    ret.length = 1;
    ret.digit = (char*)malloc(sizeof(char));
    return ret;
}

void bigint_Free(j_bigInt i) {
    i.length = 0;
    free(i.digit);
}

j_bigInt bigint_Sum(j_bigInt i1, j_bigInt i2) {
    j_bigInt ret;
    return ret;
}

j_bigInt bigint_Subtract(j_bigInt i1, j_bigInt i2) {
    j_bigInt ret;
    return ret;
}

j_bigInt bigint_Multiply(j_bigInt i1, j_bigInt i2) {
    j_bigInt ret;
    return ret;
}

j_bigInt bigint_Division(j_bigInt i1, j_bigInt i2) {
    j_bigInt ret;
    return ret;
}

#endif

