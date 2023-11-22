/* +---------- INTEGRANTES ------------+
   | Heloisa Feitosa Rocha   | 260803  |
   | Higor Gabriel Magalhaes | 2474838 | */

/*Faça um programa para gerenciar a tabela de notas. O usuário

terá 3 opções ao iniciar o programa:

(1) Adicionar mais um aluno (RA e nota)
(2) Exibir todas as notas e
(3) Calcular a média da turma*/

#include <stdio.h>

#define MAX_ALUNOS 100

typedef struct {
    int ra;
    float nota;
} Aluno;

void exibirMenu() {
    printf("\t\t\t SISTEMA DE CADASTRO DE NOTAS\n\n");
    printf("1 - ADICIONAR MAIS UM ALUNO\n");
    printf("2 - EXIBIR TODAS AS NOTAS\n");
    printf("3 - CALCULAR A MEDIA DA TURMA\n");
    printf("4 - ALTERAR NOTA DE ALUNO\n");
    printf("5 - EXCLUIR ALUNO\n");
    printf("6 - SAIR\n");
}

int main() {
    FILE *arquivo;
    Aluno alunos[MAX_ALUNOS];
    int opcao, numAlunos = 0;
    float somaNotas = 0.0;

    arquivo = fopen("notas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo notas.txt\n");
        return 1;
    }

    while (fscanf(arquivo, "%d %f", &alunos[numAlunos].ra, &alunos[numAlunos].nota) == 2) {
        somaNotas += alunos[numAlunos].nota;
        numAlunos++;
    }

    fclose(arquivo);

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Adicionar aluno
                if (numAlunos < MAX_ALUNOS) {
                    printf("Informe o RA do aluno: ");
                    scanf("%d", &alunos[numAlunos].ra);

                    printf("Informe a nota do aluno: ");
                    scanf("%f", &alunos[numAlunos].nota);

                    somaNotas += alunos[numAlunos].nota;
                    numAlunos++;

                    arquivo = fopen("notas.txt", "a");
                    if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo notas.txt para atualizacao\n");
                        return 1;
                    }
                    fprintf(arquivo, "%d %.2f\n", alunos[numAlunos - 1].ra, alunos[numAlunos - 1].nota);
                    fclose(arquivo);
                } else {
                    printf("Limite de alunos atingido.\n");
                }
                break;

            case 2:
                // Exibir todas as notas
                printf("Notas de todos os alunos:\n");
                for (int i = 0; i < numAlunos; i++) {
                    printf("RA: %d, Nota: %.2f\n", alunos[i].ra, alunos[i].nota);
                }
                break;

            case 3:
                // Calcular a média da turma
                if (numAlunos > 0) {
                    float media = somaNotas / numAlunos;
                    printf("Média da turma: %.2f\n", media);
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;

            case 4:
                // Alterar nota de aluno por RA
                printf("Digite o RA do aluno para alterar a nota: ");
                int raBusca;
                scanf("%d", &raBusca);

                int encontrado = 0;

                for (int i = 0; i < numAlunos; i++) {
                    if (alunos[i].ra == raBusca) {
                        printf("Nota atual do aluno com RA %d: %.2f\n", raBusca, alunos[i].nota);

                        printf("Digite a nova nota: ");
                        scanf("%f", &alunos[i].nota);

                        arquivo = fopen("notas.txt", "w");
                        if (arquivo == NULL) {
                            printf("Erro ao abrir o arquivo notas.txt para atualizacao\n");
                            return 1;
                        }
                        somaNotas = 0.0;
                        for (int j = 0; j < numAlunos; j++) {
                            fprintf(arquivo, "%d %.2f\n", alunos[j].ra, alunos[j].nota);
                            somaNotas += alunos[j].nota;
                        }
                        fclose(arquivo);

                        printf("Nota do aluno com RA %d atualizada com sucesso.\n", raBusca);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Aluno com RA %d nao encontrado.\n", raBusca);
                }
                break;

            case 5:
                // Excluir aluno
                printf("Digite o RA do aluno para excluir: ");
                int raExcluir;
                scanf("%d", &raExcluir);

                int posicaoExcluir = -1;

                for (int i = 0; i < numAlunos; i++) {
                    if (alunos[i].ra == raExcluir) {
                        posicaoExcluir = i;
                        break;
                    }
                }

                if (posicaoExcluir != -1) {
                    arquivo = fopen("notas.txt", "w");
                    if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo notas.txt para atualizacao\n");
                        return 1;
                    }
                    somaNotas = 0.0;
                    for (int j = 0; j < numAlunos; j++) {
                        if (j != posicaoExcluir) {
                            fprintf(arquivo, "%d %.2f\n", alunos[j].ra, alunos[j].nota);
                            somaNotas += alunos[j].nota;
                        }
                    }
                    fclose(arquivo);

                    for (int k = posicaoExcluir; k < numAlunos - 1; k++) {
                        alunos[k] = alunos[k + 1];
                    }
                    numAlunos--;

                    printf("Aluno com RA %d excluido com sucesso.\n", raExcluir);
                } else {
                    printf("Aluno com RA %d nao encontrado.\n", raExcluir);
                }
                break;

            case 6:
                // Sair do programa
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}


