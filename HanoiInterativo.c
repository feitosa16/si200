#include <stdio.h>

// Definindo a estrutura da pilha
typedef struct {
    int n;        // Número do disco
    char origem;   // Pino de origem
    char destino;  // Pino de destino
    char auxiliar; // Pino auxiliar
} Movimento;

// Função para realizar a torre de Hanoi de maneira iterativa
void hanoi_iterativo(int num_discos, char origem, char destino, char auxiliar) {
    // Inicializando a pilha
    Movimento pilha[1000];
    int topo = -1;

    // Adicionando o primeiro movimento à pilha
    pilha[++topo] = (Movimento){num_discos, origem, destino, auxiliar};

    // Loop principal
    while (topo >= 0) {
        // Pop do topo da pilha
        Movimento mov = pilha[topo--];

        // Se tivermos apenas um disco, movemos diretamente
        if (mov.n == 1) {
            printf("\nMova o disco %d da pilha %c para a pilha %c", mov.n, mov.origem, mov.destino);
        } else {
            // Adicionamos os movimentos à pilha (inverte-se a ordem para manter a ordem correta ao desempilhar)
            pilha[++topo] = (Movimento){mov.n - 1, mov.auxiliar, mov.destino, mov.origem};
            pilha[++topo] = (Movimento){1, mov.origem, mov.destino, mov.auxiliar};
            pilha[++topo] = (Movimento){mov.n - 1, mov.origem, mov.auxiliar, mov.destino};
        }
    }
}

int main() {
    int n;

    // Pede a entrada da quantidade de discos para o usuário
    printf("Digite o número de discos: ");
    scanf("%d", &n);

    // Chama a função de Hanoi iterativa para detalhar o passo a passo das operações
    hanoi_iterativo(n, 'A', 'C', 'B');

    printf("\n");
    return 0;
}
