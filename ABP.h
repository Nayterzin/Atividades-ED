//ABP.h
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
TIPOCHAVE chave;
/* Dados armazenados vão aqui */
struct aux *esq, *dir;
} NO;

typedef NO*  PONT;


//protoipos das funções
PONT inicializa();
PONT criaNovoNo(TIPOCHAVE ch);
PONT adiciona (PONT raiz, PONT no);
PONT contem(TIPOCHAVE ch, PONT raiz);
int numeroNos(PONT raiz);
void exibirArvore(PONT raiz);
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);
PONT removeNo(PONT raiz, TIPOCHAVE ch);


