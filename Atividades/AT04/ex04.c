#include <stdio.h>
//é pra retornar o vetor no return?, por ex: "return vetor"? Não ficou claro.

void ler3Numeros(int *vetor){
	
	int count = 3;

	for (int i = 0; i < count; i++)
	{
		printf("Informe o %iº número: \n", i+1);
		scanf("%i",&vetor[i]);
	}
	
}

int main(int argc, char const *argv[])
{

	int vetor[3]= {};
	int count = 3;
	
	ler3Numeros(vetor);

	printf("Resultado:\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", vetor[i]);
	}
	
	return 0;
}