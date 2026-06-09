#include<stdio.h>
#include<stdlib.h>
#include "ABP.h"

int main(int argc, char** argv) {


    PONT r;
    int v, b, n;
    int continuar = 1;

    do {

        printf("\n\tMenu de Opção\n\n");
        printf("1. Inicializa a arvore \n");
        printf("2. Insere na árvore\n");
        printf("3. Buscar um valor na árvore\n");
        printf("4. Conta o número de nós da árvore\n");
        printf("5. Imprime a árvore\n");
        printf("6.Remove um nó da árvore\n");
        printf("0.  Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar) {
            case 1:
                r = inicializa();
                printf("Árvore criada com sucesso!");
                break;

            case 2:
                printf("Digite um número para inserir na arvore:");
                scanf("%d", &v);
                PONT no = criaNovoNo(v);
                r = adiciona(r, no);
                printf("Nó inserido com sucesso!");
                break;
                
            case 3:
                printf("Digite um valor para pesquisar na árvores!!");
                scanf("%d", &b);
                r = contem(b, r);
                if (r == NULL)
                    printf("O valor %d, não foi localizado", b);
                else
                    printf("O valor %d foi localizado na árvore", b);
                break;
                
            case 4:
                n = numeroNos(r);
                printf("A árvore possui: %d nós", n);
                break;
                
            case 5:
                exibirArvore(r);
                break;
            
            case 6:
                printf("Digite um valor para remover da árvore:");
                scanf("%d",&v);
                r=removeNo(r,v);
                printf("Valor removido com sucesso!");
                break;

            case 0:
                break;
            default:
                printf("Digite uma opção valida\n");
        }
    } while (continuar);


}