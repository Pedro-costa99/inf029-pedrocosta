#include <stdio.h>
#include <stdlib.h>

//é pra retornar o vetor no return?, por ex: "return vetor"? Não ficou claro.

void ler4Numeros(){
	
	struct numeros
	{
		int n;
		
	};
	//definição de Struct
	//criação de tipo de dados

	struct numeros valores[4];

	for (int i = 0; i < 4; i++)
	{
	printf("Informe o %dº número: \n", i+1);
	scanf("%d", &valores[i].n);
	
	}

	printf("Os números digitados foram: \n");

	for (int i = 0; i < 4; i++)
	{

	printf("%d\n",valores[i].n);
	}
	
}

int main(int argc, char const *argv[])
{

	ler4Numeros();
	
	return 0;	
}