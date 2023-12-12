#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// Função recursiva para resolver a Torre de Hanoi
void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        // Se há apenas um disco, mova-o diretamente para o destino
        printf("\nMova o disco 1 da pilha %c para a pilha %c", origem, destino);
        return;
    }

    // Mover n-1 discos de origem para auxiliar usando destino como auxiliar
    hanoi(n-1, origem, auxiliar, destino);

    // Mover o disco restante de origem para destino
    printf("\nMova o disco %d da pilha %c para a pilha %c", n, origem, destino);

    // Mover n-1 discos de auxiliar para destino usando origem como auxiliar
    hanoi(n-1, auxiliar, destino, origem);
}

int main() {
    // Solicitar ao usuário o número de discos
    char *input = readline("Digite o numero de discos: ");
    int n = atoi(input);  // Converter a entrada de string para inteiro
    free(input);  // Liberar a memória alocada para a string de entrada

    // Chamar a função de Hanoi para resolver o problema
    hanoi(n, 'A', 'C', 'B');

    // Exibir uma nova linha no final para melhor formatação
    printf("\n");

    return 0;
}
