
/* +---------- INTEGRANTES ------------+
   | Heloisa Feitosa Rocha   | 260803  |
   | Higor Gabriel Magalhaes | 2474838 | */

/*Faça um programa para ler, do usuário, os RAs e as notas de
10 alunos. Salve os dados em um arquivo notas.txt, em que
cada linha contenha os dados de um aluno diferente (caso o
arquivo não exista, o seu programa deve criar antes)*/

#include <stdio.h>

struct aluno{ 
    int ra; 
    float nota; 
};  

int main(){
FILE *arquivo; 
struct aluno alunos[10]; 

 for (int i = 0; i < 10; i++){
    printf("Digite o RA do aluno %d: ", i+1); 
    scanf ("%d\n", &alunos[i].ra);
     printf("Digite a nota do aluno %d: ",i+1);
      scanf ("%f\n", &alunos[i].nota);
 }
//Verificação para existencia do arquivo txt e sua criação caos preciso 
    arquivo = fopen("notas.txt", "w"); 
        if(arquivo == NULL){
             printf("Erro ao criar o arquivo notas.txt\n"); 
        return 1;
        }

//Leitura de arquivo 
for(int i = 0; i <10; i++){
    fprintf(arquivo, "%d %f\n", alunos[i].ra, alunos[i].nota);
}

//Fechamento de arquivo 

 fclose(arquivo);
    printf("Informações dos alunos salvos no arquivo notas.txt\n");

    return 0;
}
