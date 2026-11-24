# Atividades - Algoritmos e Pensamento Computacional

Os arquivos estao separados por atividade e escritos em linguagem C.

## Arquivos

- `atividade1_sorteio.c` - 12 numeros, contagem de ocorrencias, cadastro de produtos e ordenacao.
- `atividade2_classificacao.c` - classificacao de 10 numeros em positivos pares e negativos impares.
- `atividade3_numeros_animais.c` - contagem de 15 numeros e associacao com nomes de animais.
- `atividade4_fibonacci_apostadores.c` - soma da sequencia de Fibonacci para cinco apostadores e selecao dos vencedores.

## Como compilar

Com GCC, abra o terminal na pasta e use:

```bash
gcc atividade1_sorteio.c -o atividade1
./atividade1
```

Troque o nome do arquivo e do executavel para testar as outras atividades.

No Windows, depois de compilar, execute por exemplo:

```bash
atividade1.exe
```

## Observacao importante

A atividade de numeros e animais foi implementada seguindo uma interpretacao direta do texto visivel nas imagens: a soma das ocorrencias e usada como posicao do animal, e a quantidade par usa a posicao do numero na lista de distintos. A pagina de exemplo sugere que pode existir uma regra adicional; confira com a pagina completa/instrucao do professor antes de entregar.

A atividade de matriz, media ponderada e classificacao nao foi incluida porque a imagem da pagina 26 esta cortada e nao mostra todos os requisitos.
