#include <stdio.h>

int obterDobro(int valor) {
    return valor * 2;
}

int main() {
    int valor, resultado;

    printf("Informe um numero: ");
    scanf("%d", &valor);

    resultado = obterDobro(valor);
    printf("Dobro do numero: %d\n", resultado);

    return 0;
}
