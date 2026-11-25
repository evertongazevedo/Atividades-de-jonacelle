#include <stdio.h>

int somarItens(int quantidades[], int n) {
    int j, soma = 0;
    for (j = 0; j < n; j++) soma += quantidades[j];
    return soma;
}

int produtosEmFalta(int quantidades[], int n) {
    int j, cont = 0;
    for (j = 0; j < n; j++) {
        if (quantidades[j] < 5) cont++;
    }
    return cont;
}

int localizarItem(int codigo) {
    if (codigo >= 1 && codigo <= 8) {
        return codigo - 1;
    }
    return -1;
}

int main() {
    int quantidades[8], j, codigo, indice;


    for (j = 0; j < 8; j++) {
        printf("Quantidade do item %d no estoque: ", j + 1);
        scanf("%d", &quantidades[j]);
    }

    printf("\nQuantidade total armazenada: %d\n", somarItens(quantidades, 8));
    printf("Itens com estoque menor que 5: %d\n", produtosEmFalta(quantidades, 8));

    printf("\nDigite o codigo do item para consultar (1-8): ");
    scanf("%d", &codigo);
    indice = localizarItem(codigo);

    if (indice >= 0) {
        printf("Item localizado no indice %d. Quantidade atual: %d\n", indice, quantidades[indice]);
    } else {
        printf("Codigo nao valido para consulta.\n");
    }

    return 0;
}
