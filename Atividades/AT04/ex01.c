#include <stdio.h>

int soma(int n1, int n2){

	int soma;

	soma = n1 + n2;

	return soma;

}

int main()
{
	int n1, n2, somaValores;

	printf("Informe o primeiro número: \n");
	scanf("%i", &n1);

	printf("Informe o segundo número: \n");
	scanf("%i", &n2);

	somaValores = soma(n1, n2);

	printf("A soma dos dois números é: %i\n", somaValores);


	return 0;
}