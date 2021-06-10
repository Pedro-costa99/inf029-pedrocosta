#include<stdio.h>
#include <stdlib.h>


int somaN(int n);

int main(void){

	int n;

	printf("Informe o número:\n");
	scanf("%d", &n);

	int calculo = somaN(n);

	printf("\n");
	printf("%d", calculo);

	return 0;

}


int somaN(int n){

	if(n > 0){

		return n + somaN(n - 1);

	}else{

		return 0;

	}

}