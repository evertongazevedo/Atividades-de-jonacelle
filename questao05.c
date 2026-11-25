#include <stdio.h>

int verificarPar(int valor) {
    return valor % 2 == 0;
}

int main() {
    int valor;

    printf("Digite um inteiro: ");
    scanf("%d", &valor);

    if (verificarPar(valor)) {
        printf("Esse valor e par.\n");
    } else {
        printf("Esse valor e impar.\n");
    }

    return 0;
}
