#include <stdio.h>

int testarPrimo(int n) {
    int divisor;

    if (n <= 1) return 0;

    for (divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;

    printf("Informe um numero para testar: ");
    scanf("%d", &n);

    if (testarPrimo(n)) {
        printf("E um numero primo.\n");
    } else {
        printf("Nao e primo.\n");
    }

    return 0;
}
