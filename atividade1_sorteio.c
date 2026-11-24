#include <stdio.h>
#include <string.h>

#define TAM 12

int main() {
    int numeros[TAM], distintos[TAM], qtd[TAM];
    int total = 0, i, j, achou;
    int pares[TAM], qtdPares = 0;
    char nomes[TAM][50], auxNome[50];
    float precos[TAM], auxPreco;

    printf("Digite 12 numeros inteiros:\n");

    for (i = 0; i < TAM; i++) {
        scanf("%d", &numeros[i]);
    }

    /* Conta quantas vezes cada numero aparece. */
    for (i = 0; i < TAM; i++) {
        achou = 0;

        for (j = 0; j < total; j++) {
            if (distintos[j] == numeros[i]) {
                qtd[j]++;
                achou = 1;
                break;
            }
        }

        if (achou == 0) {
            distintos[total] = numeros[i];
            qtd[total] = 1;
            total++;
        }
    }

    /* Se a quantidade for impar, cadastra um produto.
       Se for par, guarda o numero no segundo vetor. */
    int qtdProdutos = 0;

    for (i = 0; i < total; i++) {
        if (qtd[i] % 2 != 0) {
            printf("\nProduto para o numero %d:\n", distintos[i]);
            printf("Nome: ");
            scanf(" %49[^\n]", nomes[qtdProdutos]);
            printf("Preco: ");
            scanf("%f", &precos[qtdProdutos]);
            qtdProdutos++;
        } else {
            pares[qtdPares] = distintos[i];
            qtdPares++;
        }
    }

    /* Ordena os produtos pelo nome. */
    for (i = 0; i < qtdProdutos - 1; i++) {
        for (j = i + 1; j < qtdProdutos; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) {
                strcpy(auxNome, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], auxNome);

                auxPreco = precos[i];
                precos[i] = precos[j];
                precos[j] = auxPreco;
            }
        }
    }

    /* Ordena os numeros com quantidade par em ordem decrescente. */
    for (i = 0; i < qtdPares - 1; i++) {
        for (j = i + 1; j < qtdPares; j++) {
            if (pares[i] < pares[j]) {
                int aux = pares[i];
                pares[i] = pares[j];
                pares[j] = aux;
            }
        }
    }

    printf("\n--- NUMEROS INFORMADOS ---\n");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n\n--- OCORRENCIAS ---\n");
    for (i = 0; i < total; i++) {
        printf("%d aparece %d vez(es)\n", distintos[i], qtd[i]);
    }

    printf("\n--- PRODUTOS EM ORDEM ALFABETICA ---\n");
    for (i = 0; i < qtdProdutos; i++) {
        printf("%s - R$ %.2f\n", nomes[i], precos[i]);
    }

    printf("\n--- NUMEROS COM OCORRENCIA PAR (DECRESCENTE) ---\n");
    for (i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }

    printf("\n");
    return 0;
}
