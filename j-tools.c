// The sole purpose of this file is to mix all headers in j-tools files
// and to test them myself.


#include "j-tools/j_math.h"
#include "j-tools/j_sorters.h"
#include "j-tools/j_statystyka.h"
#include "j-tools/j_wektory.h"
#include "j-tools/j_geometry.h"

int main(int argc, char *argv[])
{
    init_vector_space();

    printf("\n\n funções geométricas:");
    
    ponto A = create_point(0, 0);
    ponto B = create_point(3, 4);
    ponto C = create_point(-6, 8);

    vetor v1 = create_vector(A, B);
    vetor v2 = create_vector(A, C);
    vetor v3 = create_vector(B, C);

    print_point("A", A);
    print_point("B", B);
    print_point("C", C);

    print_vector("AB", v1);
    print_vector("AC", v2);
    print_vector("BC", v3);

    printf("\n\nMódulo do vetor AB %.2f", modulo(v1, canonica));
    printf("\nMódulo do vetor AC %.2f", modulo(v2, canonica));
    printf("\nMódulo do vetor BC %.2f", modulo(v3, canonica));
    
    printf("\nCosseno entre AB e AC %.2f", cosseno_interno(v1, v2));
    
    printf("\n\nVersores:");
    print_vector("versorx", _versor_x);
    print_vector("versory", _versor_y);
    printf("\nCosseno entre estes%.2f", cosseno_interno(_versor_x, _versor_y));
    
    return 0;
}