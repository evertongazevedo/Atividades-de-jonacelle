#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Professor {
    int registro;
    int horas_aula;
};

struct Professor *lerArquivo(int quantidade) {
    struct Professor *lista;
    FILE *arquivo;

    lista = malloc(quantidade * sizeof(struct Professor));

    if (lista == NULL) {
        printf("Erro ao reservar memoria para leitura.\n");
        return NULL;
    }

    arquivo = fopen("folha.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir folha.dat.\n");
        free(lista);
        return NULL;
    }

    if (fread(lista, sizeof(struct Professor), quantidade, arquivo) != quantidade) {
        printf("Erro ao ler os professores.\n");
        fclose(arquivo);
        free(lista);
        return NULL;
    }

    fclose(arquivo);
    return lista;
}

int main() {
    struct Professor *professores;
    struct Professor *buffer;
    struct Professor *lidos;
    FILE *arquivo;
    int quantidade, i;

    printf("Quantos professores deseja cadastrar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // Reserva memoria para N professores
    professores = malloc(quantidade * sizeof(struct Professor));

    if (professores == NULL) {
        printf("Erro ao reservar memoria.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        printf("\nProfessor %d\n", i + 1);

        printf("Registro: ");
        scanf("%d", &professores[i].registro);

        printf("Horas aula: ");
        scanf("%d", &professores[i].horas_aula);
    }

    // Cria um buffer e copia todos os registros de uma vez
    buffer = malloc(quantidade * sizeof(struct Professor));

    if (buffer == NULL) {
        printf("Erro ao reservar buffer.\n");
        free(professores);
        return 1;
    }

    memcpy(buffer, professores, quantidade * sizeof(struct Professor));

    // Grava todo o buffer em uma unica chamada de fwrite
    arquivo = fopen("folha.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar folha.dat.\n");
        free(professores);
        free(buffer);
        return 1;
    }

    fwrite(buffer, sizeof(struct Professor), quantidade, arquivo);
    fclose(arquivo);

    // Le novamente o arquivo usando a funcao
    lidos = lerArquivo(quantidade);

    if (lidos != NULL) {
        printf("\n===== PROFESSORES SALVOS =====\n");

        for (i = 0; i < quantidade; i++) {
            printf("Registro: %d | Horas aula: %d\n",
                   lidos[i].registro,
                   lidos[i].horas_aula);
        }

        free(lidos);
    }

    free(professores);
    free(buffer);

    return 0;
}
