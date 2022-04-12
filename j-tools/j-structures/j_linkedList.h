#ifndef J_LINKEDLIST_H
#define J_LINKEDLIST_H

// V 1.1

#include<stdlib.h>
#include<stdbool.h>
#include "../j_strings.h"
#include "../j_transform.h"


// ESTRUTURAS DE MEMÓRIA PARA INTEIROS
// Node de memória (int)
struct int_Node
{
    struct int_Node *next;
    struct int_Node *prev;
    int item;
} typedef * int_n; 


// Lista ligada (int | HEAD)
typedef struct 
{
    int_n ini;
    int_n end;
    int len;
} int_ll;


// FUNÇÕES DE LISTAS PARA INTEIROS

//Cria uma nova lista e retorna
int_ll intll_new()
{
  int_ll ret;
  ret.len = 0;
  ret.ini = NULL;
  ret.end = NULL;
  return ret;
}


// Adiciona um elemento ao inicio da lista
// é necessário liberar a memória
void intll_add_First(int_ll * target, int value)
{
  int_n new_n = malloc(sizeof( struct int_Node ));
  new_n->item = value;
  new_n->prev = NULL;
  new_n->next = NULL;

  if ( target->len == 0 )
  {
    target->ini = new_n;
    target->end = new_n;
    target->len = 1;
    return;
  }

  target->len += 1;
  
  int_n aux = target->ini;
  target->ini = new_n;

  new_n->next = aux;
  aux->prev = new_n;
}


// Adiciona um elemento ao final da lista
// é necessário liberar a memória
void intll_add_Last(int_ll * target, int value)
{
  int_n new_n = malloc(sizeof( struct int_Node ));
  new_n->item = value;
  new_n->prev = NULL;
  new_n->next = NULL;

  if ( target->len == 0 )
  {
    target->ini = new_n;
    target->end = new_n;
    target->len = 1;
    return;
  }

  target->len += 1;
  
  int_n aux = target->end;
  target->end = new_n;
  
  aux->next = new_n;
  new_n->prev = aux;
}


// Função apenas para ser utilizada pela biblioteca no quesito remoção
void __intll_remove_node(int_ll *target, int_n node)
{
  int_n parent = node->prev;
  int_n child = node->next;
  
  // faz o antecessor se conectar ao sucessor
  if (parent != NULL)
    parent->next = child;

  else
    target->ini = child;

  
  // faz o sucessor se conectar ao antecessor
  if (child != NULL)
    child->prev = parent;

  else
    target->end = parent;


  free(node);
}


// Remove um elemento da lista, retorna true com sucesso
bool intll_Remove( int_ll * target, int value) 
{
  // checa o tamanho da lista
  if (target->len == 0) return false; 
  
  if (target->len == 1 ) 
  {
    if (target->ini->item == value)
    {
      __intll_remove_node( target, target->ini );
      return true;
    }
    else return false;
  }

  // exitem mais de dois elementos:
  int_n parent = (int_n) target;
  while(parent->next != NULL)
  {
    if ( parent->next->item == value )
    {
      __intll_remove_node( target, parent->next);
      return true;
    }

    // movimenta
    parent = parent->next;
  } 
  
  return false;
}


// retorna a quantidade de elementos da lista
int intll_Count( int_ll target )
{
  if (target.ini == NULL)
    return 0;
  
  int_n current = target.ini;
  int count = 1;
  while ( current->next != NULL )
  {
    current = current->next;
    count += 1;
  }

  return count;
}


// transforma a lista em uma string, útil para printagem
// é necessário liberar a memória
char *intll_to_String( int_ll target)
{

  // Checa se está vazia
  if (target.ini == NULL)
  {
    return str_copy("{ null }");
  }

  else
  {
    // prepara o retorno
    char *ret = "{ ";
    char *value = NULL;

    // 2 strings para possibilitar free
    char *str1 = str_copy( ret );
    char *str2 = NULL;

    // percorre
    int_n This = target.ini;
    while (1)
    {
      // libera value
      if ( value != NULL )
        free(value);

      value = ret_str(This->item);

      // concatena e libera a string anterior
      str2 = str_concac(str1, value);
      free(str1);
      str1 = str2;

      // vê se é o fim
      if (This->next == NULL)
      {
        str2 = str_concac(str1, " }");
        free(str1);
        free(value);
        return str2;
      }

      // se não adiciona uma vírgula
      str2 = str_concac(str1, ", ");
      free(str1);
      str1 = str2;

      This = This->next;
    }
  } 
}


// limpa a lista liberando toda sua memória
void intll_Free( int_ll *target)
{
  int_n node = target->ini;
  int_n aux;
  while ( node != NULL )
  {
    aux = node->next;
    __intll_remove_node(target, node);
    node = aux;
  }
}

#endif
