#include <stdio.h>
#include <stdlib.h>

struct Eleitor {
    char titulo[12];
    int zona;
};

struct Cedula {
    struct Eleitor eleitor;
    int numero_voto;
};

// Adiciona um voto e aumenta o vetor usando realloc
struct Cedula *adicionarVoto(struct Cedula *votos, int *total) {
    struct Cedula *novo;

    novo = realloc(votos, (*total + 1) * sizeof(struct Cedula));

    if (novo == NULL) {
        printf("Erro ao aumentar a memoria.\n");
        free(votos);
        return NULL;
    }

    votos = novo;

    printf("\nVoto %d\n", *total + 1);

    printf("Titulo do eleitor: ");
    scanf(" %11s", votos[*total].eleitor.titulo);

    printf("Zona: ");
    scanf("%d", &votos[*total].eleitor.zona);

    printf("Numero do voto: ");
    scanf("%d", &votos[*total].numero_voto);

    (*total)++;

    return votos;
}

// Recupera todos os votos do arquivo de uma so vez
void recuperarVotos() {
    FILE *arquivo;
    struct Cedula *votos;
    long tamanho;
    int quantidade, i;

    arquivo = fopen("urnas.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir urnas.bin.\n");
        return;
    }

    // Descobre o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);

    // Calcula quantos registros existem
    quantidade = tamanho / sizeof(struct Cedula);

    rewind(arquivo);

    votos = malloc(tamanho);

    if (votos == NULL) {
        printf("Erro ao reservar memoria para recuperar os votos.\n");
        fclose(arquivo);
        return;
    }

    fread(votos, sizeof(struct Cedula), quantidade, arquivo);

    printf("\n===== VOTOS RECUPERADOS =====\n");

    for (i = 0; i < quantidade; i++) {
        printf("Titulo: %s | Zona: %d | Voto: %d\n",
               votos[i].eleitor.titulo,
               votos[i].eleitor.zona,
               votos[i].numero_voto);
    }

    free(votos);
    fclose(arquivo);
}

int main() {
    struct Cedula *votos = NULL;
    FILE *arquivo;
    int quantidade, i, total = 0;

    printf("Quantos votos deseja cadastrar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        votos = adicionarVoto(votos, &total);

        if (votos == NULL) {
            return 1;
        }
    }

    // Salva todos os votos em arquivo binario
    arquivo = fopen("urnas.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar urnas.bin.\n");
        free(votos);
        return 1;
    }

    fwrite(votos, sizeof(struct Cedula), total, arquivo);
    fclose(arquivo);

    printf("\nVotos salvos com sucesso!\n");

    free(votos);

    // Abre o arquivo e recupera os registros
    recuperarVotos();

    return 0;
}
