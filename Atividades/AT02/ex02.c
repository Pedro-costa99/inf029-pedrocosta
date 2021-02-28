#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)

{
  setlocale(LC_ALL, "Portuguese");

  int num1 = 0;
  int num2 = 0;
  int codigo = -1;

  printf("Cálculo de dois números inteiros\n");
 
  printf("Informe o primeiro número: \n");
  scanf("%i",&num1);

  printf("Informe o segundo número: \n");
  scanf("%i",&num2);

  printf("Agora selecione a opção do MENU:\n");
  printf("0 - Sair, 1 - Somar, 2 - Subtrair, 3 - Multiplicar, 4 - Dividir. \n");
  scanf("%i",&codigo);
  

  if (codigo == 0){  

  	printf("Programa finalizado.\n");

  } else if (codigo == 1){

  	printf("Soma dos dois números: %i\n", num1 + num2);

  } else if (codigo == 2){

  	 if (num1 > num2)
  	 {
  	 	printf("Subtração dos dois números: %i\n", num1 - num2);

  	 } else {

  	 	printf("Subtração dos dois números: %i\n", num2 - num1);
  	 }
  	
  } else if (codigo == 3){  

  	printf("Multiplicação dos dois números: %i\n", num1 * num2);

  } else if (codigo == 4){  

  	printf("Divisão dos dois números: %.2f\n", (float)num1 / num2);

  } else {

  	 printf("Opção inválida. Reinicie o programa, por favor.\n");
  }

  return 0;
}