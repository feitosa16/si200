#include <stdio.h>

int main(){
int n, fatorial;

scanf("%d",&n);
    for (int i = 0 ; i < n; i--){
      fatorial = fatorial *n;
    }
printf("%d",fatorial);
8
    return 0;
}