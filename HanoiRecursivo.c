#include <stdio.h>

void hanoi(int n,char origem,char destino,char auxiliar){
	/*Se sobrar apenas o disco 1, mova fazer o movimento e retornar*/
	if(n==1){ 
		printf("\nMova o disco 1 da pilha %c para a pilha %c",origem ,destino);
		return;
	}
	/*Mover o n-1 disco de A para B, usando C de auxiliar*/
	hanoi(n-1,origem,auxiliar,destino);
	/* Mover os discos restantes de A para C*/
	printf("\nMova o disco %d da pilha %c para a pilha %c",n,origem,destino);
	/*Mover os n-1 discos de B para C usando A como auxiliar*/
	hanoi(n-1,auxiliar,destino,origem);
}

int main(){
	int n;
	//pede a entrada da quantidade de discos para o usuário 
	printf("Digite o numero de discos : ");
	scanf("%d",&n);
	//chama a função de hanoi para detalhar o passo a passo das operações
	hanoi(n,'A','C','B');
	printf("\n");
	return 0;
}