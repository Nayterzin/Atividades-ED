#include <stdio.h>
#include <stdlib.h>
#include "N-ARIA.h"

PONT buscarChave(PONT raiz, TIPOCHAVE ch) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == ch) return raiz;
    PONT aux = buscarChave(raiz->ultimoFilho, ch);
    if (aux) return aux;
    return buscarChave(raiz->proximoIrmao, ch);
}

/* retorna o tamanho (numero de nos da arvore) */
int numeroDeNos(PONT raiz) {
    if (!raiz) return 0;
    int res = 1;
    PONT filhos = raiz->ultimoFilho;
    while (filhos != NULL) {
        res += numeroDeNos(filhos);
        filhos = filhos->proximoIrmao;
    }
    return res;
}

/* retorna o tamanho (numero de nos da arvore) */
int numeroDeNos2(PONT raiz) {
    if (!raiz) return 0;
    return 1 + numeroDeNos2(raiz->ultimoFilho) + numeroDeNos2(raiz->proximoIrmao);
}

/* retorna a altura da arvore */
int altura(PONT raiz) {
    if (!raiz) return -1;
    int max = -1;
    int temp;
    PONT filhos = raiz->ultimoFilho;
    while (filhos != NULL) {
        temp = altura(filhos);
        if (temp > max) max = temp;
        filhos = filhos->proximoIrmao;
    }
    return max + 1;
}

PONT criarNovoNo(TIPOCHAVE ch) {
    PONT novoNo = (PONT) malloc(sizeof (NO));
    novoNo->ultimoFilho = NULL;
    novoNo->proximoIrmao = NULL;
    novoNo->chave = ch;
    return novoNo;
}

bool inserirFilho(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai) {
    PONT pai = buscarChave(raiz, chavePai);
    if (!pai) return false;
    PONT novo = criarNovoNo(novaChave);
    novo->ultimoFilho = NULL;
    novo->proximoIrmao = pai->ultimoFilho;
    pai->ultimoFilho = novo;
    return true;
}

void exibirArvore(PONT raiz) {
    if (raiz == NULL) return;
    printf("%d", raiz->chave);
    printf("(");                        // sempre abre parêntese
    PONT filhos = raiz->ultimoFilho;
    while (filhos != NULL) {
        exibirArvore(filhos);
        filhos = filhos->proximoIrmao;
    }
    printf(")");                        // sempre fecha parêntese
}

PONT criarRaiz(TIPOCHAVE novaChave) {
    return criarNovoNo(novaChave);
}
                                            
bool removerNo(PONT raiz, TIPOCHAVE ch) {
    if (raiz == NULL) return false;
    
    PONT anterior = NULL;
    PONT atual = raiz->ultimoFilho;
    
    while (atual != NULL) {
        if (atual->chave == ch) {
            if (atual->ultimoFilho == NULL) {
                if (anterior == NULL)
                    raiz->ultimoFilho = atual->proximoIrmao;
                else
                    anterior->proximoIrmao = atual->proximoIrmao;
                free(atual);
            } else {
                PONT primeiroFilho = atual->ultimoFilho;
                PONT outrosFilhos = primeiroFilho->proximoIrmao;

                if (anterior == NULL)
                    raiz->ultimoFilho = primeiroFilho;
                else
                    anterior->proximoIrmao = primeiroFilho;

                primeiroFilho->proximoIrmao = atual->proximoIrmao;

                if (outrosFilhos != NULL) {
                    PONT ultimo = primeiroFilho->ultimoFilho;
                    if (ultimo == NULL) {
                        primeiroFilho->ultimoFilho = outrosFilhos;
                    } else {
                        while (ultimo->proximoIrmao != NULL)
                            ultimo = ultimo->proximoIrmao;
                        ultimo->proximoIrmao = outrosFilhos;
                    }
                }

                free(atual);
            }
            printf("Nó %d removido com sucesso!\n", ch);
            return true;
        }
        
        anterior = atual;
        atual = atual->proximoIrmao;
    }
    
    atual = raiz->ultimoFilho;
    while (atual != NULL) {
        if (removerNo(atual, ch))
            return true;
        atual = atual->proximoIrmao;
    }
    
    return false;
}