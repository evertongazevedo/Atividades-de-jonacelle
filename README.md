# Atividades - Algoritmos e Pensamento Computacional (Aula 9)

Este repositório contém cinco atividades em linguagem C.

## Arquivos

1. `atividade1_estoque.c` - Cadastro de 3 produtos, gravação e leitura de `estoque.txt`.
2. `atividade2_rh.c` - Alocação dinâmica de funcionário, cópia com `memcpy` e gravação em `backup_rh.bin`.
3. `atividade3_clientes.c` - Atualização de saldo em arquivo binário `clientes.bin`.
4. `atividade4_professores.c` - Cadastro dinâmico de professores, cópia com `memcpy`, gravação e leitura de `folha.dat`.
5. `atividade5_eleitoral.c` - Cadastro dinâmico de votos com `realloc`, gravação e recuperação de `urnas.bin`.

## Como compilar

Com GCC instalado, abra o terminal na pasta e compile cada atividade:

```bash
gcc atividade1_estoque.c -o atividade1
gcc atividade2_rh.c -o atividade2
gcc atividade3_clientes.c -o atividade3
gcc atividade4_professores.c -o atividade4
gcc atividade5_eleitoral.c -o atividade5
```

No Windows, execute os arquivos `.exe` gerados. No Linux/macOS, execute com `./atividade1`, por exemplo.

## Observação sobre a Atividade 3

O enunciado considera que `clientes.bin` já contém registros de clientes. O programa procura a conta e atualiza o saldo, mas não cria o arquivo nem cadastra os clientes.
