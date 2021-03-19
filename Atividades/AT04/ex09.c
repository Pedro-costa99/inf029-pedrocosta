#include <stdio.h>
#include <string.h>

struct dadosCliente{
		char nome[20];
		char dataNascimento[20];
		char cpf[12];
		char sexo;
	};

void validarNome(char nome []){

	int tamanho = strlen(nome);
	if(tamanho <= 20){
		printf("Ok. O nome é válido\n");
	} else{
		printf("Erro! Nome muuto extenso.\n");
	}
}

void validarSexo(char sexo){

	
	if(sexo == 'm' || sexo == 'M' || sexo == 'f' || sexo == 'F' || sexo == 'o' || sexo == 'O'){
		printf("Ok. O sexo é válido\n");
	} else{
		printf("Erro! opção inválida.\n");
	}
}

//verificar apenas se o cpf tem 11 dígitos
void validarCpf(char cpf []){

	int tamanho = strlen(cpf);
	if(tamanho == 12){
		printf("Ok. O cpf é válido\n");
	} else{
		printf("Erro! CPf inválido.\n");
	}
}
//29/06/1989
void validarNascimento(char data []){

	int tamanho = strlen(data) -1;
	if(data[2] == '/' && data[5] == '/' && tamanho == 10){
		printf("Ok. A data de nascimento é válida\n");
	} else{
		printf("Erro! Data de nasc. inválida!\n");
	}
}

void cadastrarCliente(void)
{

	struct dadosCliente cliente;	

	printf("Informe seu nome: \n");
	fgets(cliente.nome, 40, stdin);
	validarNome(cliente.nome);

	printf("Informe sua data de nascimento: \n");
	fgets(cliente.dataNascimento, 40, stdin);
	validarNascimento(cliente.dataNascimento);

	printf("Informe seu CPF: \n");
	fgets(cliente.cpf, 40, stdin);
	validarCpf(cliente.cpf);

	printf("Informe seu sexo: \n");
	scanf(" %c", &cliente.sexo);
	validarSexo(cliente.sexo);
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