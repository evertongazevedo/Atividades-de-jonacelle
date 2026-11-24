#include <stdio.h>

#define TAM 15
#define ANIMAIS 6

int primo(int n) {
    int i;

    if (n < 2) {
        return 0;
    }

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int vetor[TAM], distintos[TAM], qtd[TAM];
    char animais[ANIMAIS][40];
    int total = 0, i, j, achou;
    int soma;

    printf("Digite 15 numeros inteiros:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
    }

    /* Monta a lista de numeros diferentes e conta as ocorrencias. */
    for (i = 0; i < TAM; i++) {
        achou = 0;

        for (j = 0; j < total; j++) {
            if (distintos[j] == vetor[i]) {
                qtd[j]++;
                achou = 1;
                break;
            }
        }

        if (achou == 0) {
            distintos[total] = vetor[i];
            qtd[total] = 1;
            total++;
        }
    }

    printf("\nCadastre 6 nomes de animais:\n");
    for (i = 0; i < ANIMAIS; i++) {
        printf("Animal %d: ", i + 1);
        scanf(" %39[^\n]", animais[i]);
    }

    printf("\n--- NUMEROS E OCORRENCIAS ---\n");
    for (i = 0; i < total; i++) {
        printf("%d aparece %d vez(es) - ", distintos[i], qtd[i]);

        if (qtd[i] == 1) {
            printf("Nao repetido\n");
        } else if (primo(distintos[i]) && qtd[i] % 2 != 0) {
            printf("Primo - impar\n");
        } else if (qtd[i] % 2 == 0) {
            if (primo(distintos[i])) {
                printf("Primo - par\n");
            } else {
                printf("Par\n");
            }
        } else {
            printf("Impar\n");
        }
    }

    printf("\n--- ASSOCIACAO COM ANIMAIS ---\n");

    for (i = 0; i < total; i++) {
        if (qtd[i] > 1 && primo(distintos[i]) && qtd[i] % 2 != 0) {
            /* Soma das ocorrencias: numero somado uma vez por aparicao. */
            soma = 0;
            for (j = 0; j < qtd[i]; j++) {
                soma = soma + distintos[i];
            }

            printf("Numero %d: soma das ocorrencias = %d. ", distintos[i], soma);

            /* A soma e usada como posicao, quando estiver entre 1 e 6. */
            if (soma >= 1 && soma <= ANIMAIS) {
                printf("Animal: %s\n", animais[soma - 1]);
            } else {
                printf("Nao existe correspondencia.\n");
            }
        } else if (qtd[i] > 1 && qtd[i] % 2 == 0) {
            /* Usa a posicao do numero diferente na lista. */
            printf("Numero %d: ", distintos[i]);

            if (i < ANIMAIS) {
                printf("Animal: %s\n", animais[i]);
            } else {
                printf("Nao existe correspondencia.\n");
            }
        }
    }

    return 0;
}
