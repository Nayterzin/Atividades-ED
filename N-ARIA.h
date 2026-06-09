//N-ARIA.h
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct auxNo {
  TIPOCHAVE chave;
  struct auxNo * ultimoFilho; 
  struct auxNo * proximoIrmao; 
} NO, * PONT;

//protótipos das funções
PONT buscarChave(PONT raiz, TIPOCHAVE ch);
int numeroDeNos(PONT raiz);
int numeroDeNos2(PONT raiz);
int altura(PONT raiz);
PONT criarNovoNo(TIPOCHAVE ch);
bool inserirFilho(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai);
void exibirArvore(PONT raiz);
PONT criarRaiz(TIPOCHAVE novaChave);
bool removerNo(PONT raiz, TIPOCHAVE ch);