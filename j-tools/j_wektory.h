// cópia de elementos
#include <stdlib.h>
#include "j_math.h"

#ifndef J_WEKTORY_H
#define J_WEKTORY_H

int *copy_array(int *array, int tam)
{
    int *aux = (int*)malloc(sizeof(int)*tam);
    for(int i = 0; i < tam; i++)
        aux[i] = array[i];
    return aux;
}

int str_len(char *string)
{
    int i = 0;
    while(string[i++]!='\0');
    return i;
}

char *str_copy(char *array)
{
    int tam = str_len(array);
    char *aux = (char*)malloc(sizeof(int)*(1+tam));
    for (int i = 0; i < tam; i++)
        aux[i] = array[i];
    
    aux[tam] = '\0'; //coloca ponto de parada
    return aux;
}

// move de uma str para outra, começando do ponto min.
char *str_crop(unsigned int start, unsigned int end, char *str1)
{ 

  int size = end-start+1;
  char *str2 = (char*)malloc(sizeof(char)*(size));
  
  int i = 0;
  while((str1[start] != '\0') && (end > start))
  {
    str2[i++] = str1[start++];
  } 

  str2[size-1] = '\0'; // coloca ponto de parada
  return str2;
}

// move uma quantidade pré-determinada de elementos para o vetor 1 do vetor 2.
void str_mov(unsigned int i, char *str1, char *str2)
{
  int j = 0;
  while( j <= i )
  {
    str1[j] = str2[j];
    j++;
  }  
}

int str_match(char *palavra1, char *palavra2)
{
    int i = 0;
    do
    {
        if(palavra1[i] != palavra2[i])
            return 0; // retorna falso
        
    } while( (palavra1[i] != '\0') && (palavra2[i++] != '\0') );

    return 1;
}

unsigned return_unsigned(char *palavra1)
{
    int count = 0, size = 0;
    for(int i = 0; palavra1[i] != 0; i++)
        size += 1;

    for(int j = 1; size >= j; j++)
        count += (palavra1[size-j] - 48) * int_podniesc(10, j-1);

    return count;
}

int return_integer(char *palavra1)
{
    // retorna o valor em inteiros da palavra
    int count = 0, size = 0;

    int negativo = 0;
    if(palavra1[0] == '-')
        negativo = 1;
 
    for(int i = 0; palavra1[i] != 0; i++)
        size += 1;

    for(int j = 1; size >= j+negativo; j++)
        count += (palavra1[size-j] - 48) * int_podniesc(10, j-1);

    if(negativo)
        return -count;
    
    return count;
}

#endif