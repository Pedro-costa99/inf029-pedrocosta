#include <stdio.h>

int fatorial(int n){
	
		int fatorial;

		if (n < 0)
		{
			printf("Este programa não calcula fatorial de número negativo,\npor favor reinicie o sistema e informe um valor positivo.\n");

			return 0;
			
		} else{

			for(fatorial = 1; n > 1; n = n - 1){
				fatorial = fatorial * n;
			}
			

			return fatorial;

		}		
}

int main()
{
	int n, fatorialCalculo;

	printf("Informe um valor para o cálculo do fatorial: \n");
	scanf("%i", &n);

	if (n >= 0){		
			
		fatorialCalculo = fatorial(n);

		printf("O fatorial de %i é: %i\n", n, fatorialCalculo);
	}else{
		fatorial(n);
	}


	return 0;
}

