#include <stdio.h>
#include <stdlib.h>

void ordemCrescente(int n);

int main(void){

    int n;

    printf("Informe o número:");
    scanf("%d", &n);

    ordemCrescente(n);

    return 0;
}

void ordemCrescente(int n){

    if(n >= 0){

    	ordemCrescente(n - 1);
    	printf("%d ", n);

    }

}