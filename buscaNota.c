/* +---------- INTEGRANTES ------------+
   | Heloisa Feitosa Rocha   | 260803  |
   | Higor Gabriel Magalhaes | 2474838 | */

/*Faça um programa para buscar, no arquivo de notas, a nota de
um determinado aluno (pelo seu RA). Caso o RA informado não
esteja no arquivo, informar que o aluno não está cadastrado.*/

#include <stdio.h>

struct aluno{
    int ra; 
    float nota; 
}; 

 int main(){
FILE *arquivo; 
struct aluno Aluno[10];
int buscaRA; 
int raEncontrado = 0;

arquivo = fopen("notas.txt", "r"); 
if (arquivo == NULL){
    printf("Erro ao abrir o arquivo notas.txt\n");
    return 1;  
}
for (int i = 0; i <10; i++){
    if (fscanf(arquivo, "%d %f", &Aluno[i].ra, &Aluno[i].nota)!=2){
        printf("Erro ao ler as informações do arquivo\n");
        fclose(arquivo);
        return 1;
    }
}
fclose (arquivo);
printf("Digite o RA do aluno a ser buscado: "); 
scanf("%d", &buscaRA); 
for(int i = 0; i<10; i++){
    if (Aluno[i].ra == buscaRA){
            printf("Nota do aluno com RA %d: %.2f\n", buscaRA, Aluno[i].nota);
            raEncontrado = 1; 
            break;
        }
    }
 if(!raEncontrado){
    printf("Aluno com RA %d nao cadastrado. \n", buscaRA); 
    }
    return 0;
 }
