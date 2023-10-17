#include <stdio.h>

int main(){
int n;
int fat = 1;
printf("Digite o valor para descobrir o fatorial: ");
scanf("%d",&n);
    for (fat = fat; n >1; n = n -1){
      fat = fat * n; 
    }
    printf("O valor do fatorial é igual a %d\n", fat);
    return 0;
}