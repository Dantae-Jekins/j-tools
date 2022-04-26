#ifndef J_BSTCOMMON_H
#define J_BSTCOMMON_H

// V 1.0

#include <stdlib.h>
#include <stdbool.h>

// Estrutura do node
struct bNode
{
    struct bNode *dir; // right
    struct bNode *esq; // left
    struct bNode *par; // parent
    int val;
} typedef * bnode;


// Estrutura da  BST
struct bTree
{
    struct bNode *root; // root
} typedef bsTree;



// para fazer:
// primeiramente todas as funções em recursão, e então iterativas 
// (mais rápidas e menor consumo de memória)
// free, remove, search, count, print

// próximo objetivo
// deselvonver árvores AVL 


// -------------------------------------------------------------- //
// FUNÇÕES SUJEITAS A MUDANÇA, NECESSÁRIO ADAPTAR DE PROJETO PARA PROJETO

// Gera um novo node de memória e o retorna 
// É necessário desalocar o espaço
bnode __bnode_New( int val )
{
    bnode ret = (bnode) malloc(sizeof(struct bNode));
    ret->dir = NULL;
    ret->esq = NULL;
    ret->par = NULL;
    ret->val = val;
    return ret;
}


// Função auxiliar para a bst_Insert, procura e insere um valor
// Retorna se o valor foi inserido ou se já existe, true se foi inserido
bool __bnode_Insert( bnode target, int val)
{

    // se o valor for maior
    if ( target->val < val)
    {
        // se houver espaço disp
        if (target->dir == NULL)
        {
            bnode newn = __bnode_New( val );
            target->dir = newn;
            return true;
        }

        // se não
        else
        {
            return __bnode_Insert(target->dir, val);
        }
    }

    // se o valor for menor
    else if ( target->val > val)
    {
        // se houver espaço disp
        if (target->esq == NULL)
        {
            bnode newn = __bnode_New( val );
            target->esq = newn;
            return true;
        }

        // se não
        else
        {
            return __bnode_Insert(target->esq, val);
        }
    }

    // se for =
    else
    {
        return false;
    }
}






// ------------------------------------------------------------- //
/// FUNÇÕES NÃO SUJEITAS A MUDANÇA, NÃO TOQUE, SÓ EM CASO DE BUG


// Gera uma nova árvore com valores nulos e retorna
bsTree bst_New()
{
    bsTree ret;
    ret.root = NULL;
    return ret;
}


// Insere um novo elemento na BST
// Retorna se a inserção do elemento foi um sucesso
bool bst_Insert( bsTree *target, int value)
{
    // se a bst está vazia, inicializa
    if (target->root == NULL)
    {
        bnode newn = __bnode_New(value);
        target->root = newn;
        return true;
    }

    // se a bst já contém valores
    else
    {
        return __bnode_Insert(target->root, value);
    }
}


#endif