#include <stdio.h>

void imprimirMultiplicacoes(int base) {
    int contador;

    for (contador = 1; contador <= 10; contador++) {
        printf("%d * %d = %d\n", base, contador, base * contador);
    }
}

int main() {
    int base;

    printf("Qual tabuada deseja ver? ");
    scanf("%d", &base);

    imprimirMultiplicacoes(base);
    return 0;
}
