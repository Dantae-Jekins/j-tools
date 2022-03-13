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
    int val;
    struct int_Node *nxt;
} typedef int_Node; 


// Lista ligada (int | HEAD)
typedef struct 
{
    int_Node *first;
} int_LinkedList;


// Inicializa uma lista ligada
int_LinkedList new_int_List() 
{
    int_LinkedList ret;
    ret.first = NULL;
    return ret;
}


// Insere um componente na lista ligada
void insert_int_List( int_LinkedList *HEAD, int value) 
{    
    // Cria uma nova node
    int_Node *newNode = (int_Node*) malloc(sizeof(int_Node));
    newNode->nxt = NULL;
    newNode->val = value;

    // Sem node primária, insere uma
    if (HEAD->first == NULL)
    {
        HEAD->first = newNode;
        return;
    }

    // Com uma node primária, insere entre
    else 
    {
        newNode->nxt = HEAD->first;
        HEAD->first = newNode;
        return;
    }
}


// Remove o primeiro valor correspondente da lista ligada, retorna true com sucesso e false caso não exista
bool remove_int_List( int_LinkedList *HEAD, int value)
{
    // Checa se existe algum elemento na lista
    if (HEAD->first == NULL)
        return false;

    // Checa se o primeiro elemento corresponde ao valor
    if (HEAD->first->val == value) 
    {
      // remove o elemento
      int_Node *placeholder = HEAD->first->nxt;
      free(HEAD->first);
      HEAD->first = placeholder;
      return true;
    } 

    // Se não checa os elementos após o primeiro
    int_Node *previous_Node = HEAD->first;
    while(previous_Node->nxt != NULL) 
    {
        // o valor do próximo node é equivalente
        if (previous_Node->nxt->val == value)
        {
            int_Node *placeholder = previous_Node->nxt->nxt;
            free(previous_Node->nxt);
            previous_Node->nxt = placeholder;
            return true;
        }

        // movimenta
        previous_Node = previous_Node->nxt;
    }

    return false;
}


// Libera a memória de uma lista, serve como um clear.
void free_int_List( int_LinkedList *HEAD ) 
{
    while ( HEAD->first != NULL )
    {
        remove_int_List( HEAD, HEAD->first->val );
    }
}


// Retorna uma string dos valores da lista. Necessário liberar memória alocada
char *int_List_String( int_LinkedList *HEAD )
{
    // Checa se está vazia
    if (HEAD->first == NULL)
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
        int_Node *This = HEAD->first;
        while (1) 
        {
            // libera value
            if ( value != NULL )
                free(value);

            value = ret_str(This->val);

            // concatena e libera a string anterior
            str2 = str_concac(str1, value);
            free(str1);
            str1 = str2;

            // vê se é o fim
            if (This->nxt == NULL)
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
            
            This = This->nxt;
        }
    }
}

#endif