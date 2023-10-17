//bibliotecas: funções prontas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int jogador,computador;
	//lógica do jogador
	printf("_____JoKenPo_____\n\n");
	printf("1. PEDRA\n");
	printf("2. PAPEL\n");
	printf("3. TESOURA\n");
	printf("Digite a opcao desejada: ");


	scanf("%d",&jogador);
	printf("\n___________\n\n");
	switch(jogador)
	{
		case 1:
			printf("Jogador escolheu PEDRA\n");
		break;
		
		case 2:
			printf("Jogador escolheu PAPEL\n");
		break;
		
		case 3:
			printf("Jogador escolheu TESOURA\n");
		break;
		
		default: //não é nenhum dos casos acima
			printf("Opcao invalida\n");
	}

	// lógica do computador
	srand(time(NULL)); //alimenta o rand com uma semente, que é o tempo atual
	computador=("%d",rand()%3 + 1); //módulo de 3, +1
	switch(computador)
	{
		case 1:
			printf("Computador escolheu PEDRA\n");
		break;
		
		case 2:
			printf("Computador escolheu PAPEL\n");
		break;
		
		case 3:
			printf("Computador escolheu TESOURA\n");
		break;		
	}
	//lógica para determinar o vencedor
	if(jogador==computador)
	{
		printf("EMPATE\n");
	}
	else if ((jogador==1 && computador==3) || (jogador==2 && computador==1) ||
	(jogador==3 && computador==2))
	{
		printf("JOGADOR VENCEU\n");
	}
	else
	{
		printf("COMPUTADOR VENCEU\n");
	}
	printf("___________\n");
	
	return 0;
}