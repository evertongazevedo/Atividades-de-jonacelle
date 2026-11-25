#include <stdio.h>

float adicao(float x, float y) { return x + y; }
float diferenca(float x, float y) { return x - y; }
float produto(float x, float y) { return x * y; }
float quociente(float x, float y) { return x / y; }

int main() {
    float x, y, resposta;
    int escolha;

    printf("Digite dois valores: ");
    scanf("%f %f", &x, &y);

    printf("\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n");
    printf("Selecione: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            resposta = adicao(x, y);
            printf("Resposta: %.2f\n", resposta);
            break;
        case 2:
            resposta = diferenca(x, y);
            printf("Resposta: %.2f\n", resposta);
            break;
        case 3:
            resposta = produto(x, y);
            printf("Resposta: %.2f\n", resposta);
            break;
        case 4:
            if (y == 0) {
                printf("Divisao por zero nao e permitida.\n");
            } else {
                resposta = quociente(x, y);
                printf("Resposta: %.2f\n", resposta);
            }
            break;
        default:
            printf("Selecao invalida.\n");
    }

    return 0;
}
