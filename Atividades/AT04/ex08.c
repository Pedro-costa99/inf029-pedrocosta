#include <stdio.h>

void cadastrarCliente(void)
{
	struct dadosCliente{
		char nome[20];
		char dataNascimento[20];
		char cpf[20];
		char sexo;
	};

	struct dadosCliente cliente;	

	printf("Informe seu nome: \n");
	fgets(cliente.nome, 40, stdin);

	printf("Informe sua data de nascimento: \n");
	fgets(cliente.dataNascimento, 40, stdin);

	printf("Informe seu CPF: \n");
	fgets(cliente.cpf, 40, stdin);

	printf("Informe seu sexo: \n");
	scanf(" %c", &cliente.sexo);
	printf("\n");

	printf("Dados do cliente: \n\n");
	printf("Nome: %s", cliente.nome);
	printf("Data de nascimento: %s", cliente.dataNascimento);
	printf("CPF: %s", cliente.cpf);
	printf("Sexo: %c", cliente.sexo);
	
}


int main(int argc, char const *argv[])
{
	cadastrarCliente();
	
	return 0;
}