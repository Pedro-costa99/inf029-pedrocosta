#include <stdio.h>
#include <stdlib.h>

int fatorial(int numero);

int main(void){

	int fatorial;
    int numero;

    puts("Informe o número");
    scanf("%d", &numero);

    fatorialN = fatorial(numero);

    printf("O fatorial de %d é %d\n", numero, fatorialN);

    return 0;
}

int fatorial(int numero){

    if(numero == 1)
        return 1;

    return numero * fatorial(numero - 1);
}