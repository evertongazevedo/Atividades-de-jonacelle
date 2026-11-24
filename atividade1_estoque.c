#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

int main() {
    struct Produto produtos[3];
    FILE *arquivo;
    int i;

    // Cadastro dos 3 produtos
    for (i = 0; i < 3; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);

        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }

    // Salva os produtos no arquivo de texto
    arquivo = fopen("estoque.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        fprintf(arquivo, "%d;%s;%.2f\n",
                produtos[i].codigo,
                produtos[i].nome,
                produtos[i].preco);
    }

    fclose(arquivo);

    // Abre novamente para leitura
    arquivo = fopen("estoque.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("\n===== ESTOQUE CADASTRADO =====\n");

    for (i = 0; i < 3; i++) {
        if (fscanf(arquivo, "%d;%49[^;];%f\n",
                   &produtos[i].codigo,
                   produtos[i].nome,
                   &produtos[i].preco) == 3) {
            printf("Codigo: %d | Nome: %s | Preco: R$ %.2f\n",
                   produtos[i].codigo,
                   produtos[i].nome,
                   produtos[i].preco);
        }
    }

    fclose(arquivo);

    return 0;
}
