#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("\nMova o disco 1 da pilha %c para a pilha %c", origem, destino);
        return;
    }
    
    hanoi(n-1, origem, auxiliar, destino);
    
    printf("\nMova o disco %d da pilha %c para a pilha %c", n, origem, destino);
    
    hanoi(n-1, auxiliar, destino, origem);
}

int main() {
    char *input = readline("Digite o numero de discos: ");
    int n = atoi(input);
    free(input);

    hanoi(n, 'A', 'C', 'B');
    
    printf("\n");
    
    return 0;
}
