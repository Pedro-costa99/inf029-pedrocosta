
#include <stdio.h>
#include <stdlib.h>

void paresDecrescente(int n);

int main(void){

    int n;

    printf("Informe o número:");
    scanf("%d", &n);

    paresDecrescente(n);

    return 0;
}

void paresDecrescente(int n){

    if(n >= 0){

    	if(n % 2 == 0)
    		printf("%d ", n);

    	paresDecrescente(n - 1);

    }

}