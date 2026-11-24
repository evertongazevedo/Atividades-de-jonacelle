#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
    int id;
    char cargo[30];
    float salario;
};

int main() {
    struct Funcionario *funcionario;
    struct Funcionario *backup;
    FILE *arquivo;

    // Reserva memoria para os dois registros
    funcionario = malloc(sizeof(struct Funcionario));
    backup = malloc(sizeof(struct Funcionario));

    if (funcionario == NULL || backup == NULL) {
        printf("Erro ao reservar memoria.\n");
        free(funcionario);
        free(backup);
        return 1;
    }

    // Recebe os dados do funcionario
    printf("ID: ");
    scanf("%d", &funcionario->id);

    printf("Cargo: ");
    scanf(" %29[^\n]", funcionario->cargo);

    printf("Salario: ");
    scanf("%f", &funcionario->salario);

    // Copia os dados para o backup
    memcpy(backup, funcionario, sizeof(struct Funcionario));

    // Salva o backup em arquivo binario
    arquivo = fopen("backup_rh.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        free(funcionario);
        free(backup);
        return 1;
    }

    fwrite(backup, sizeof(struct Funcionario), 1, arquivo);
    fclose(arquivo);

    printf("\nBackup salvo em backup_rh.bin!\n");
    printf("ID: %d\n", backup->id);
    printf("Cargo: %s\n", backup->cargo);
    printf("Salario: R$ %.2f\n", backup->salario);

    free(funcionario);
    free(backup);

    return 0;
}
