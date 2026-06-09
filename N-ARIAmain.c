#include<stdio.h>
#include<stdlib.h>
#include "N-ARIA.h"

int main() {
    PONT raiz = NULL;
    int v, p, b, n, h;
    int continuar = 1;

    do {
        printf("\n\tMenu de Opção\n\n");
        printf("1. Inicializa a arvore \n");
        printf("2. Insere na árvore\n");
        printf("3. Buscar um valor na árvore\n");
        printf("4. Conta o número de nós da árvore\n");
        printf("5. Imprime a árvore\n");
        printf("6. Imprime a altura da árvore\n");
        printf("7. Remove um nó da árvore\n");
        printf("0.  Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar) {
            case 1:
                printf("Digite o nó raiz da árvore: ");
                scanf("%d", &v);
                raiz = criarRaiz(v);
                printf("Árvore criada com sucesso!");
                break;

            case 2:
                if (raiz == NULL) {
                    printf("Erro: árvore não inicializada!\n");
                    break;
                }
                printf("Digite um número para inserir na árvore: ");
                scanf("%d", &v);
                printf("Digite o nó pai: ");
                scanf("%d", &p);
                if (inserirFilho(raiz, v, p))
                    printf("Nó inserido com sucesso!");
                else
                    printf("Erro: pai não encontrado!");
                break;

            case 3:
                if (raiz == NULL) {
                    printf("Erro: árvore não inicializada!\n");
                    break;
                }
                printf("Digite um valor para pesquisar: ");
                scanf("%d", &b);
                {
                    PONT resultado = buscarChave(raiz, b);
                    if (resultado == NULL)
                        printf("O valor %d não foi localizado", b);
                    else
                        printf("O valor %d foi localizado na árvore", b);
                }
                break;

            case 4:
                if (raiz == NULL) {
                    printf("Erro: árvore não inicializada!\n");
                    break;
                }
                n = numeroDeNos2(raiz);
                printf("A árvore tem %d elementos", n);
                break;

            case 5:
                if (raiz == NULL) {
                    printf("Árvore vazia.\n");
                    break;
                }
                exibirArvore(raiz);
                printf("\n");
                break;

            case 6:
                if (raiz == NULL) {
                    printf("Erro: árvore não inicializada!\n");
                    break;
                }
                h = altura(raiz);
                printf("A altura da árvore é %d", h);
                break;

            case 7:
                if (raiz == NULL) {
                    printf("Erro: árvore não inicializada!\n");
                    break;
                }
                printf("Digite o valor do nó a ser removido: ");
                scanf("%d", &v);
                if (removerNo(raiz, v))
                    printf("Remoção concluída!\n");
                else
                    printf("Valor %d não encontrado na árvore.\n", v);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Digite uma opção válida\n");
        }
    } while (continuar);

    return 0;
}