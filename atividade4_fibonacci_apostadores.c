#include <stdio.h>
#include <string.h>

#define TAM 5

long long fibonacci(int termos) {
    long long a = 0, b = 1, c, soma = 0;
    int i;

    for (i = 0; i < termos; i++) {
        soma = soma + a;
        c = a + b;
        a = b;
        b = c;
    }

    return soma;
}

int primo(long long n) {
    long long i;

    if (n < 2) {
        return 0;
    }

    for (i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char nomes[TAM][50];
    long long resultados[TAM];
    int termos[TAM];
    int premiado[TAM] = {0, 0, 0, 0, 0};
    int i, primeiro = -1, segundo = -1, terceiro = -1;
    float media;
    long long somaTotal = 0;

    for (i = 0; i < TAM; i++) {
        printf("\nNome do apostador %d: ", i + 1);
        scanf(" %49[^\n]", nomes[i]);

        do {
            printf("Quantidade de termos (numero positivo): ");
            scanf("%d", &termos[i]);
        } while (termos[i] <= 0);

        resultados[i] = fibonacci(termos[i]);
        somaTotal = somaTotal + resultados[i];
    }

    media = (float)somaTotal / TAM;

    /* Primeiro lugar: maior resultado que seja primo. */
    for (i = 0; i < TAM; i++) {
        if (primo(resultados[i])) {
            if (primeiro == -1 || resultados[i] > resultados[primeiro]) {
                primeiro = i;
            }
        }
    }

    if (primeiro != -1) {
        premiado[primeiro] = 1;
    }

    /* Segundo lugar: maior resultado par entre os que sobraram. */
    for (i = 0; i < TAM; i++) {
        if (premiado[i] == 0 && resultados[i] % 2 == 0) {
            if (segundo == -1 || resultados[i] > resultados[segundo]) {
                segundo = i;
            }
        }
    }

    if (segundo != -1) {
        premiado[segundo] = 1;
    }

    /* Terceiro lugar: maior resultado acima da media entre os restantes. */
    for (i = 0; i < TAM; i++) {
        if (premiado[i] == 0 && resultados[i] > media) {
            if (terceiro == -1 || resultados[i] > resultados[terceiro]) {
                terceiro = i;
            }
        }
    }

    printf("\n--- RESULTADOS ---\n");
    for (i = 0; i < TAM; i++) {
        printf("%s: soma Fibonacci = %lld\n", nomes[i], resultados[i]);
    }

    printf("\nMedia dos resultados: %.2f\n", media);
    printf("\n--- VENCEDORES ---\n");

    if (primeiro != -1)
        printf("1 lugar: %s - %lld\n", nomes[primeiro], resultados[primeiro]);
    else
        printf("1 lugar: nao houve resultado primo.\n");

    if (segundo != -1)
        printf("2 lugar: %s - %lld\n", nomes[segundo], resultados[segundo]);
    else
        printf("2 lugar: nao houve outro resultado par.\n");

    if (terceiro != -1)
        printf("3 lugar: %s - %lld\n", nomes[terceiro], resultados[terceiro]);
    else
        printf("3 lugar: nao houve resultado acima da media.\n");

    return 0;
}
