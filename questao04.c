#include <stdio.h>

float converterTemperatura(float c) {
    return c * 9 / 5 + 32;
}

int main() {
    float c, f;

    printf("Temperatura em Celsius: ");
    scanf("%f", &c);

    f = converterTemperatura(c);
    printf("Equivalente em Fahrenheit: %.2f\n", f);

    return 0;
}
