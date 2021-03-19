#include <stdio.h>
//essa função não considera valores negativos
int subtrai(int n1, int n2, int n3){

	int subtrai;

	subtrai = n1 - n2;

	if (subtrai < 0)
	{
		subtrai = subtrai * (-1);
	}
	subtrai = subtrai - n3;

	if (subtrai < 0)
	{
		subtrai = subtrai * (-1);
	}

	return subtrai;

}

int main()
{
	int n1, n2, n3, subtraiValores;

	printf("Informe o primeiro número: \n");
	scanf("%i", &n1);

	printf("Informe o segundo número: \n");
	scanf("%i", &n2);

	printf("Informe o terceiro número: \n");
	scanf("%i", &n3);

	subtraiValores = subtrai(n1, n2, n3);

	printf("A subtração dos valores é: %i\n", subtraiValores);


	return 0;
}
