#ifndef J_STRINGS_H
#define J_STRINGS_H

// V 1.2

#include<stdlib.h>


// Retorna o tamano da string
int str_len(char *string)
{
    int i = 0;
    while(string[i]!='\0') 
      i++;

    return i;
}


// Retorna uma cópia de uma string. Necessário liberar memoria alocada.
char *str_copy(char *string)
{
    int tam = str_len(string);
    char *aux = (char*)malloc(sizeof(int)*(1+tam));
    for (int i = 0; i <= tam; i++)
        aux[i] = string[i];
    
    aux[tam] = '\0'; //coloca ponto de parada
    return aux;
}


// Retorna duas strings somadas. Necessário liberar memória alocada.
char *str_concac(char *str1, char *str2)
{
  // adquire os tamanhos
  int len1 = str_len(str1);
  int len2 = str_len(str2);
  int end = len1 + len2;

  // aloca
  char *ret = (char*)malloc(sizeof(char) * (end + 1));
  ret[end] = '\0';

  int i;
  // percorre str1 0 -> len1
  for (i = 0; i < len1; i++)
    ret[i] = str1[i]; 
  
  // percorre str2 i -> end
  for (int j = 0; i < end; i++, j++)
    ret[i] = str2[j];

  return ret;
}


// Retorna str cortado entre start e end. Necessário liberar memória alocada
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


// Move i elementos de str2 para str1
void str_mov(unsigned int i, char *str1, char *str2)
{
  int j = 0;
  while( j <= i )
  {
    str1[j] = str2[j];
    j++;
  }  
}


// Verifica se str1 == str2
int str_match(char *str1, char *str2)
{
    int i = 0;
    do
    {
        if(str1[i] != str2[i])
            return 0; // retorna falso
        
    } while( (str1[i] != '\0') && (str2[i++] != '\0') );

    return 1;
}

#endif