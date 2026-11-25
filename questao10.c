#include <stdio.h>

float somarVendas(float valores[], int n) {
    int j;
    float soma = 0;

    for (j = 0; j < n; j++) {
        soma += valores[j];
    }
    return soma;
}

float mediaVendas(float soma, int n) {
    return soma / n;
}

int diasAcima(float valores[], int n, float media) {
    int j, qtd = 0;

    for (j = 0; j < n; j++) {
        if (valores[j] > media) {
            qtd++;
        }
    }
    return qtd;
}

int main() {
    float valores[5], soma, media;
    int j, quantidade;

    for (j = 0; j < 5; j++) {
        printf("Venda registrada no dia %d: R$ ", j + 1);
        scanf("%f", &valores[j]);
    }

    soma = somarVendas(valores, 5);
    media = mediaVendas(soma, 5);
    quantidade = diasAcima(valores, 5, media);

    printf("\nSoma das vendas: R$ %.2f\n", soma);
    printf("Media por dia: R$ %.2f\n", media);
    printf("Dias acima da media: %d\n", quantidade);

    return 0;
}
