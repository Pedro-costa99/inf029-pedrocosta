#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
//é pra retornar o vetor no return?, por ex: "return vetor"? Não ficou claro.

char* ler3Letras(){
	
	char* letra = malloc(sizeof(int) * 5);	

	for (int i = 0; i < 3; i++)
	{
		printf("Informe a %iº letra: \n", i+1);
		scanf(" %c",&letra[i]);
	}

	return letra;
	
}

int main(int argc, char const *argv[])
{

	char* letra = ler3Letras();
	

	printf("\n");
	printf("Resultado: \n");

	for (int i = 0; i < 3; ++i)
	{
		printf("%dª letra: %c\n", i+1, letra[i]);
	}

	free(letra);
	return 0;
}