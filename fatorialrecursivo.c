#include <stdio.h>
int fatorialRec(int n){
    if (n){
        return n * fatorialRec (n-1);
    }else{
        return 1;
    }
}
int main(){

    int num;
    scanf("%d", &num);
    int fatorial = fatorialRec( num);
    printf("%d", fatorial);
    return 0;
}