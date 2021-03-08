#include <stdio.h>
#include <stdlib.h>
#include "Soma.h"

//soma de dois números inteiros

int main()
{
	int n1, n2;
	int soma;

	printf("Informe o primeiro número inteiro: \n");	
	scanf("%i",&n1);

	printf("Informe o segundo número inteiro: \n");	
	scanf("%i",&n2);

	soma = somaInteiros(n1, n2);

	printf("A soma dos dois números é: %i\n", soma);

	return 0;
}