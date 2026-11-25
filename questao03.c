#include <stdio.h>

int compararNumeros(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int main() {
    int a, b;

    printf("Informe dois valores inteiros: ");
    scanf("%d %d", &a, &b);

    printf("Maior valor: %d\n", compararNumeros(a, b));
    return 0;
}
