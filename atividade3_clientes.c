#include <stdio.h>

struct Cliente {
    int conta_corrente;
    char nome[50];
    float saldo;
};

int main() {
    struct Cliente cliente;
    int conta;
    float valor;
    char operacao;
    FILE *arquivo;
    int encontrou = 0;

    printf("Numero da conta: ");
    scanf("%d", &conta);

    printf("Digite D para deposito ou S para saque: ");
    scanf(" %c", &operacao);

    printf("Valor: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor invalido.\n");
        return 1;
    }

    // Abre o arquivo para leitura e escrita binaria
    arquivo = fopen("clientes.bin", "rb+");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir clientes.bin.\n");
        printf("Crie o arquivo com os registros de clientes antes de executar.\n");
        return 1;
    }

    // Procura a conta registro por registro
    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        if (cliente.conta_corrente == conta) {
            encontrou = 1;

            if (operacao == 'D' || operacao == 'd') {
                cliente.saldo += valor;
            } else if (operacao == 'S' || operacao == 's') {
                if (valor > cliente.saldo) {
                    printf("Saldo insuficiente.\n");
                    fclose(arquivo);
                    return 0;
                }
                cliente.saldo -= valor;
            } else {
                printf("Operacao invalida.\n");
                fclose(arquivo);
                return 1;
            }

            // Volta ao inicio do registro encontrado e atualiza o saldo
            fseek(arquivo, -(long)sizeof(struct Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

            printf("\nCliente: %s\n", cliente.nome);
            printf("Novo saldo: R$ %.2f\n", cliente.saldo);
            break;
        }
    }

    if (!encontrou) {
        printf("Conta nao encontrada.\n");
    }

    fclose(arquivo);
    return 0;
}

/*
Exemplo para criar clientes.bin:
Use um programa separado que grave registros do tipo struct Cliente
com fwrite(), ou adapte este programa para cadastrar os clientes primeiro.
*/
