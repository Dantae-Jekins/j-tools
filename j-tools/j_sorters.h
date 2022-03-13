#ifndef J_SORTERS_H
#define J_SORTERS_H

// V 1.1

#include <stdio.h>
#include <stdlib.h>


// Troca os valores de duas posições em um array
void swap(int *str, int i, int j)
{
  int aux = str[i];
  str[i] = str[j];
  str[j] = aux;
}


// Ordena um vetor a partir de ini. ordenando um lado de cada vez
void merge(int *v, int *aux, int siz, int ini)
{
  // seta as coordenadas no vetor
  int mei = (siz+1)/2 + ini;
  int fim = siz       + ini;
  int dir = mei;
  int esq = ini;
  
  int i = ini;
  // enquanto não ter percorrido pelo menos a direita ou a esquerda
  while ((esq < mei) && (dir < fim))
  {
    if (v[esq] < v[dir])
      aux[i++] = v[esq++];
    else
      aux[i++] = v[dir++];
  }

  // terminar de percorrer a direita
  while (dir < fim)
    aux[i++] = v[dir++];
  
  // ou terminar de percorrer a esquerda
  while (esq < mei)
    aux[i++] = v[esq++];

  // move de aux para o vetor principal (não seria necessário)
  for(i = ini; i < (siz+ini); i++)
    v[i] = aux[i];
}


// Recursão para o merge_sort
void merge_recursion(int *array, int *aux, int siz, int ini)
{
  if (siz == 1)
    return;

  merge_recursion(array, aux, (siz+1)/2, ini);
  merge_recursion(array, aux, siz/2, ini+(siz+1)/2);
  merge(array, aux, siz, ini);
}


/// Algoritmos de ordenação

// Merge
void merge_sort(int *array, int size)
{
  int *aux = (int*) malloc(sizeof(int)*size);
  merge_recursion(array, aux, size, 0);
  free(aux);  
}


// Selection
void selection_sort(int *array, int size)
{
	int ordenado = 0;
  for (int i = 0; i < size-1; i++)
  { 
		for (int j = i + 1; j < size; j++ )    
			if (array[i] > array[j])
			{
				ordenado = 0;
				swap(array, i, j);
			}
	}
}


// Bubble 
void bubble_sort(int *array, int size)
{
	int ordenado = 0;
  for (int i = 0; i < size-1; i++)
	{
    for(int j = 0; j < size-1-i; j++)
			if(array[j] > array[j+1])
    	{
				ordenado = 0;
        swap(array, j, j+1);
  	  }
	}
}
#endif