#include <stdio.h>

float mediaNotas(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

void informarResultado(float m) {
    if (m >= 7.0) {
        printf("Situacao: aprovado!\n");
    } else {
        printf("Situacao: reprovado!\n");
    }
}

int main() {
    float n1, n2, n3, media;

    printf("Digite as notas (3): ");
    scanf("%f %f %f", &n1, &n2, &n3);

    media = mediaNotas(n1, n2, n3);
    printf("Media final: %.2f\n", media);
    informarResultado(media);

    return 0;
}
