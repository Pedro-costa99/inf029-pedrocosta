#include <stdio.h>
#include <stdlib.h>

void ordemDecrescente(int n);

int main(void){

    int n;

    printf("Informe um número:");
    scanf("%d", &n);

    ordemDecrescente(n);

    return 0;
}

void decrescente(int n){

    if(n >= 0){

    	printf("%d ", n);
    	ordemDecrescente(n - 1);

    }

}