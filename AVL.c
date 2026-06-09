#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

PONT inicializa() {
    return (NULL);
}

PONT criaNovoNo(TIPOCHAVE ch) {
    PONT novoNo = (PONT) malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->altura = 0;
    return (novoNo);
}

int alturaNo(PONT no) {
    if (no == NULL) return -1;
    return no->altura;
}

int fatorBalanceamento(PONT no) {
    if (no == NULL) return 0;
    return alturaNo(no->esq) - alturaNo(no->dir);
}

PONT atualizaAltura(PONT no) {
    if (no == NULL) return no;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    no->altura = (altEsq > altDir ? altEsq : altDir) + 1;
    return no;
}

PONT rotacaoDireita(PONT y) {
    PONT x = y->esq;
    PONT B = x->dir;

    x->dir = y;
    y->esq = B;

    atualizaAltura(y);
    atualizaAltura(x);

    return x;
}

PONT rotacaoEsquerda(PONT x) {
    PONT y = x->dir;
    PONT B = y->esq;

    y->esq = x;
    x->dir = B;

    atualizaAltura(x);
    atualizaAltura(y);

    return y;
}

PONT rotacaoEsquerdaDireita(PONT z) {
    z->esq = rotacaoEsquerda(z->esq);
    return rotacaoDireita(z);
}

PONT rotacaoDireitaEsquerda(PONT z) {
    z->dir = rotacaoDireita(z->dir);
    return rotacaoEsquerda(z);
}

PONT balanceia(PONT no) {
    atualizaAltura(no);
    int fb = fatorBalanceamento(no);

    // Caso Esquerda-Esquerda
    if (fb > 1 && fatorBalanceamento(no->esq) >= 0)
        return rotacaoDireita(no);

    // Caso Esquerda-Direita
    if (fb > 1 && fatorBalanceamento(no->esq) < 0)
        return rotacaoEsquerdaDireita(no);

    // Caso Direita-Direita
    if (fb < -1 && fatorBalanceamento(no->dir) <= 0)
        return rotacaoEsquerda(no);

    // Caso Direita-Esquerda
    if (fb < -1 && fatorBalanceamento(no->dir) > 0)
        return rotacaoDireitaEsquerda(no);

    return no;
}

PONT adiciona(PONT raiz, TIPOCHAVE ch) {
    if (raiz == NULL)
        return criaNovoNo(ch);

    if (ch < raiz->chave)
        raiz->esq = adiciona(raiz->esq, ch);
    else
        raiz->dir = adiciona(raiz->dir, ch);

    return balanceia(raiz);
}

PONT contem(TIPOCHAVE ch, PONT raiz) {
    if (raiz == NULL)
        return (NULL);

    if (raiz->chave == ch)
        return (raiz);

    if (ch < raiz->chave)
        return contem(ch, raiz->esq);
    else
        return contem(ch, raiz->dir);
}

int numeroNos(PONT raiz) {
    if (!raiz) return 0;
    return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

void exibirArvore(PONT raiz) {
    if (raiz != NULL) {
        printf("%d", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}

PONT menorNo(PONT raiz) {
    PONT atual = raiz;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

PONT removeNo(PONT raiz, TIPOCHAVE ch) {
    if (raiz == NULL) return NULL;

    if (ch < raiz->chave)
        raiz->esq = removeNo(raiz->esq, ch);
    else if (ch > raiz->chave)
        raiz->dir = removeNo(raiz->dir, ch);
    else {
        // Caso 1 e 2: nó com zero ou um filho
        if (!raiz->esq || !raiz->dir) {
            PONT temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        }

        // Caso 3: nó com dois filhos
        // Substitui pela chave do sucessor em ordem (menor da subárvore direita)
        PONT sucessor = menorNo(raiz->dir);
        raiz->chave = sucessor->chave;
        raiz->dir = removeNo(raiz->dir, sucessor->chave);
    }

    return balanceia(raiz);
}
