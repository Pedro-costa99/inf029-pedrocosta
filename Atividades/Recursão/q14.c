
#include <stdio.h>
#include <stdlib.h>

void paresCrescente(int n);

int main(void){

    int n;

    printf("Informe o número:");
    scanf("%d", &n);

    paresCrescente(n);

    return 0;
}

void paresCrescente(int n){

    if(n >= 0){
    	
    	paresCrescente(n - 1);

    	if(n % 2 == 0)
    		printf("%d ", n);

    }

}