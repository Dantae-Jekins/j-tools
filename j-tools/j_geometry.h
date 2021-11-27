#include <math.h>
#include "j_math.h"

#ifndef J_GEOMETRY_H
// conceitos baseados em um plano 2D
#define J_GEOMETRY_H
typedef struct COORDENADA
{
    int x;
    int y;
} ponto; // coordenada

typedef struct PAR_ORDENADO
{
    int x;
    int y;

} vetor; // vetor

typedef struct BASE_VETORIAL
{
    vetor v1;
    vetor v2;
    double cos;

} base; // base

vetor _versor_x;
vetor _versor_y;
base _base_canonica;
#define canonica _base_canonica

void init_vector_space()
{
    _versor_x.x = 1;
    _versor_x.y = 0;
    _versor_y.x = 0;
    _versor_y.y = 1;
    _base_canonica.v1 = _versor_x;
    _base_canonica.v2 = _versor_y;
    _base_canonica.cos = 0.0; // 0 graus;
}

void print_point(char *sigla, ponto x)
{
    printf("\n%s: { %d, %d }", sigla, x.x, x.y);
}

void print_vector(char *sigla, vetor x)
{
    printf("\n%s: { %d, %d }", sigla, x.x, x.y);
}

ponto create_point(int x, int y)
{
    ponto AUX;
    AUX.x = x;
    AUX.y = y;
    return AUX;
}

vetor create_vector(ponto x, ponto y)
{
    vetor vec1;
    vec1.x = y.x - x.x;
    vec1.y = y.y - x.y;
    return vec1; 
}

// Retorna um valor escalar
int produto_escalar(vetor vec1, vetor vec2, base base)
{
    int x, y;
    x = vec1.x*vec2.x;
    y = vec1.y*vec2.y;
    return x + y;
}

// Retorna o tamanho do vetor
double modulo(vetor vec1, base base)
{   
    double aux1 = 0.0, aux2 = 0.0;
    
    // extrai pitágoras
    aux1 = (double)int_sqrpodniesc(vec1.x);
    aux1 += (double)int_sqrpodniesc(vec1.y);
    
    // se a base não possuir ângulo de 90 (cos=0)
    if (aux2 != base.cos)
    {
        aux2 = 2 * vec1.x * vec1.y * base.cos;
        aux1 -= aux2;
    }
    return sqrt(aux1);
}

double cosseno_interno(vetor vec1, vetor vec2)
{
    double cos = 
    produto_escalar(vec1, vec2, canonica)/
    (modulo(vec1,canonica)*modulo(vec2,canonica));

    return cos;
}

// Retorna uma base
base create_base(vetor vec1, vetor vec2)
{
    base BASE;
    BASE.v1 = vec1;
    BASE.v2 = vec2;
    BASE.cos = cosseno_interno(vec1, vec2);
    return BASE;
}


#endif