#include <stdio.h>

int main() {
    int numeros[10];
    int positivosPares[10], negativosImpares[10];
    int qtdPP = 0, qtdNI = 0;
    int i, j, aux;

    printf("Digite 10 numeros inteiros:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);

        if (numeros[i] > 0 && numeros[i] % 2 == 0) {
            positivosPares[qtdPP] = numeros[i];
            qtdPP++;
        }

        if (numeros[i] < 0 && numeros[i] % 2 != 0) {
            negativosImpares[qtdNI] = numeros[i];
            qtdNI++;
        }
    }

    /* Ordena os positivos pares em ordem crescente. */
    for (i = 0; i < qtdPP - 1; i++) {
        for (j = i + 1; j < qtdPP; j++) {
            if (positivosPares[i] > positivosPares[j]) {
                aux = positivosPares[i];
                positivosPares[i] = positivosPares[j];
                positivosPares[j] = aux;
            }
        }
    }

    /* Ordena os negativos impares em ordem crescente. */
    for (i = 0; i < qtdNI - 1; i++) {
        for (j = i + 1; j < qtdNI; j++) {
            if (negativosImpares[i] > negativosImpares[j]) {
                aux = negativosImpares[i];
                negativosImpares[i] = negativosImpares[j];
                negativosImpares[j] = aux;
            }
        }
    }

    printf("\nPositivos e pares:\n");
    for (i = 0; i < qtdPP; i++) {
        printf("%d ", positivosPares[i]);
    }

    printf("\nNegativos e impares:\n");
    for (i = 0; i < qtdNI; i++) {
        printf("%d ", negativosImpares[i]);
    }

    printf("\n");
    return 0;
}
