// AVL.h
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    int altura;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT inicializa();
PONT criaNovoNo(TIPOCHAVE ch);
int alturaNo(PONT no);
int fatorBalanceamento(PONT no);
PONT atualizaAltura(PONT no);
PONT rotacaoDireita(PONT y);
PONT rotacaoEsquerda(PONT x);
PONT rotacaoEsquerdaDireita(PONT no);
PONT rotacaoDireitaEsquerda(PONT no);
PONT balanceia(PONT no);
PONT adiciona(PONT raiz, TIPOCHAVE ch);
PONT contem(TIPOCHAVE ch, PONT raiz);
int numeroNos(PONT raiz);
void exibirArvore(PONT raiz);
PONT menorNo(PONT raiz);
PONT removeNo(PONT raiz, TIPOCHAVE ch);
