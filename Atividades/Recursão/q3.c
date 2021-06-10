#include<stdio.h>
#include <stdlib.h>


int inverteN(int n);

int valorInverso = 0;
int algarismo;

int main(){

	int n;
	int numeroInvertido;

	printf("Informe o número para inversão: \n");
	scanf("%d", &n);

	numeroInvertido = inverteN(n);

	printf("\n");
	printf("%d", numeroInvertido);

	return 0;

}


int inverteN(int n){
	

	if(n){

		algarismo = n % 10;
		valorInverso = valorInverso * 10 + algarismo;
		inverteN(n / 10);

	}else{

		return valorInverso;

	}

	return valorInverso;

}