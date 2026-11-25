#include <stdio.h>

float mediaGeral(float notas[], int n) {
    int j;
    float soma = 0;
    for (j = 0; j < n; j++) soma += notas[j];
    return soma / n;
}

float notaMaisAlta(float notas[], int n) {
    int j;
    float maior = notas[0];
    for (j = 1; j < n; j++) {
        if (notas[j] > maior) maior = notas[j];
    }
    return maior;
}

int quantidadeAprovados(float notas[], int n) {
    int j, total = 0;
    for (j = 0; j < n; j++) {
        if (notas[j] >= 7.0) total++;
    }
    return total;
}

void mostrarResumo(float media, float maior, int aprovados) {
    printf("\nMedia dos alunos: %.2f\n", media);
    printf("Nota mais alta: %.2f\n", maior);
    printf("Aprovados: %d\n", aprovados);
}

int main() {
    float notas[10], media, maior;
    int j, aprovados;

    for (j = 0; j < 10; j++) {
        printf("Nota do estudante %d: ", j + 1);
        scanf("%f", &notas[j]);
    }

    media = mediaGeral(notas, 10);
    maior = notaMaisAlta(notas, 10);
    aprovados = quantidadeAprovados(notas, 10);

    mostrarResumo(media, maior, aprovados);
    return 0;
}
