#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main() {
    PONT r = NULL;
    int v, b, n;
    int continuar = 1;

    do {
        printf("\n\tMenu de Opção\n\n");
        printf("1. Inicializa a arvore\n");
        printf("2. Insere na árvore\n");
        printf("3. Buscar um valor na árvore\n");
        printf("4. Conta o número de nós da árvore\n");
        printf("5. Imprime a árvore\n");
        printf("6. Remove um nó da árvore\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar) {
            case 1:
                r = inicializa();
                printf("Árvore AVL criada com sucesso!\n");
                break;

            case 2:
                printf("Digite um número para inserir na árvore: ");
                scanf("%d", &v);
                r = adiciona(r, v);
                printf("Nó inserido com sucesso!\n");
                break;

            case 3:
                printf("Digite um valor para pesquisar: ");
                scanf("%d", &b);
                {
                    PONT resultado = contem(b, r);
                    if (resultado != NULL)
                        printf("O valor %d foi localizado na árvore!\n", b);
                    else
                        printf("O valor %d não consta na árvore.\n", b);
                }
                break;

            case 4:
                n = numeroNos(r);
                printf("A árvore possui: %d nós\n", n);
                break;

            case 5:
                if (r == NULL)
                    printf("Árvore vazia.\n");
                else {
                    exibirArvore(r);
                    printf("\n");
                }
                break;

            case 6:
                printf("Digite um valor para remover da árvore: ");
                scanf("%d", &v);
                if (contem(v, r) != NULL) {
                    r = removeNo(r, v);
                    printf("Valor removido com sucesso!\n");
                } else {
                    printf("Valor %d não encontrado na árvore.\n", v);
                }
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
