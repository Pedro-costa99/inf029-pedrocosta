#include <stdio.h>
#include <string.h>
//é pra retornar o vetor no return?, por ex: "return vetor"? Não ficou claro.

void ler3Palavras(char str[3][20]){	
	

	for (int i = 0; i < 3; i++)
	{
		printf("Informe a %iº palavra: \n", i+1);
		scanf("%s", str[i]);
	}
	
}

int main(int argc, char const *argv[])
{

	char str[3][20]= {};	
	
	ler3Palavras(str);

	printf("As palavras digitadas pelo usuário foram: \n");

	for (int i = 0; i < 3; ++i)
	{
		printf("%i - %s\n", i+1, str[i]);
	}
	
	return 0;
}