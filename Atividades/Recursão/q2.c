#include<stdio.h>
#include <stdlib.h>

int fibonacci(int valor);

int main(void){

	int valor;

	printf("Informe a quantidade de termos da sequência: ");
	scanf("%d", &valor);

	int i = 0;
	printf("%d ", i);

	for(i = 0; i < valor - 1; i++){

		printf("%d ", fibonacci(i + 1));

	}        	
	

	return 0;

}


int fibonacci(int valor){

	if (valor <= 1)
		return valor;
	return fibonacci(valor - 1) + fibonacci(valor - 2);

}