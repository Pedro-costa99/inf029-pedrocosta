#include<stdio.h>

int multiplica(int k, int n);


int main(void){

	int k;
	int n;

	printf("Informe o valor de k:\n");
	scanf("%d", &k);

	printf("Informe o valor de n:\n");
	scanf("%d", &n);

	int produto = multiplica(k, n);

	printf("\n");
	printf("%d elevado a %d == %d", k, n, produto);

	return 0;

}


int multiplica(int k, int n){

	if(n > 0){

		return k * multiplica(k, n - 1);

	}else{

		return 1;

	}

}