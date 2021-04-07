#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_LISTA_ALUNO 5
#define TAM_LISTA_PROFESSOR 5
#define TAM_LISTA_GERAL 5//tem que ser igual a lista_aluno ou lista_professor

struct dadosPessoa{
		//verificar tamanho da matrícula
		//gerar matrícula automática
		int matricula;
		char nome[100];
		char sexo;
		char dataNascimento[20];
		char cpf[12];		
	};

struct date{
   int matricula;
   int dia;
   int mes;
   int ano;
   char nome[100];
};

struct date input[TAM_LISTA_GERAL];
struct dadosPessoa aluno[TAM_LISTA_ALUNO];
struct dadosPessoa professor[TAM_LISTA_PROFESSOR];	

//variáveis usadas para ordenar ALUNOS por data de nascimento 
struct date input[TAM_LISTA_GERAL];
char str1[30];
char str2[30];
char str3[30];
int valor1[TAM_LISTA_GERAL], valor2[TAM_LISTA_GERAL], valor3[TAM_LISTA_GERAL];
int somaValor[TAM_LISTA_GERAL];

//variáveis usadas para ordenar PROFESSOR por data de nascimento 
struct date input2[TAM_LISTA_GERAL];
char str4[30];
char str5[30];
char str6[30];
int valor4[TAM_LISTA_GERAL], valor5[TAM_LISTA_GERAL], valor6[TAM_LISTA_GERAL];
int somaValor2[TAM_LISTA_GERAL];


struct dadosDisciplina{
		
		int vagas;
		char nome[100];
		int codigo;
		char semestre[20];
		char professor[100];
		
	};

struct dadosDisciplina disciplina[TAM_LISTA_GERAL];

void listarALunos();//declaração da função
void dadosALunos(struct dadosPessoa []);
void listarAlunosOrdemNome();
int listarAlunosOrdemNascimento();


void cadastrarAluno(void)
{
	int n = TAM_LISTA_ALUNO; //quantidade de alunos
	int len = 0;

	printf("\nPara cadastrar o aluno, preencha os dados abaixo:\n\n");

	for(int i = 0; i < n; i++){

	printf("Informe sua matrícula: ");
	scanf("%i",&aluno[i].matricula);	
	fflush(stdin);

	printf("Informe seu nome: ");
	fgets(aluno[i].nome, 100, stdin);	
	//remove \0 da string
	len = strlen(aluno[i].nome);
	if(aluno[i].nome[len-1] == '\n')
	    aluno[i].nome[len-1] = 0;	
	//remove \0 da string	

	printf("Informe seu sexo: ");
	scanf("%c", &aluno[i].sexo);
	fflush(stdin);	

	printf("Informe sua data de nascimento: ");
	fgets(aluno[i].dataNascimento, 40, stdin);

	printf("Informe seu CPF: ");
	fgets(aluno[i].cpf, 40, stdin);

	}		

	printf("\n");
	printf("\n");
	
	
}

void cadastrarProfessor(void)
{
	//o nome do professor tb é pedido em Cadastrar Disciplina
	//seria bom se essas informações fossem cruzadas
	int i;
	int n = TAM_LISTA_PROFESSOR;//quantidade de professores
	int len;
		
	printf("\nPara cadastrar o Professor, preencha os dados abaixo:\n\n");
	for (int i = 0; i < n; i++)
	{	
	printf("Informe sua matrícula: ");
	scanf("%d", &professor[i].matricula);	
	fflush(stdin);

	printf("Informe seu nome: ");
	fgets(professor[i].nome, 100, stdin);
	//remove \0 da string
	len = strlen(professor[i].nome);
	if(professor[i].nome[len-1] == '\n')
	    professor[i].nome[len-1] = 0;	
	//remove \0 da string

	printf("Informe seu sexo: ");
	scanf("%c", &professor[i].sexo);
	fflush(stdin);	

	printf("Informe sua data de nascimento: ");
	fgets(professor[i].dataNascimento, 40, stdin);

	printf("Informe seu CPF: ");
	fgets(professor[i].cpf, 40, stdin);	

	printf("\n");
	}	

	printf("\n");
	printf("\n");
	
}


void cadastrarDisciplina(void)
{   //verificar por que dá erro na impressao qd digitamos acento
	int n = TAM_LISTA_GERAL;

	printf("\nPara cadastrar a Disciplina, preencha os dados abaixo:\n\n");
	for (int i = 0; i < n; i++)
	{
	printf("Informe o número de vagas da disciplina: ");
	scanf("%d", &disciplina[i].vagas);	
	fflush(stdin);
	
	printf("Informe o nome da disciplina: ");
	fgets(disciplina[i].nome, 100, stdin);

	printf("Informe o código da disciplina: ");
	scanf("%d", &disciplina[i].codigo);	
	fflush(stdin);

	printf("Informe o semestre da disciplina: ");
	fgets(disciplina[i].semestre, 40, stdin);
	
	printf("Informe o nome do professor: ");
	fgets(disciplina[i].professor, 100, stdin);
	printf("\n");
	printf("\n");

	}	
	
	printf("\n");
	printf("\n");
	
	
}

/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
//funcao que auxilia a função quebraDataNascimento
int qtd_espacos(char *str){ 
    int espacos = 0;
    while(*str){
        if (*str == '/'){
           espacos++;
        }
        str++;
    }
    return espacos;    
}

//funcao que quebra a data de nascimento em 3 partes, dia, mes e ano
//quebra e transforma essas partes em número inteiro
void quebraDataNascimento() {
    char str[30];

    int n = TAM_LISTA_GERAL;
    
    //essa quantidade do for tem que estar igual a do for do cadastro aluno
    for (int j = 0; j < n; j++)
    {
		    strcpy(str, aluno[j].dataNascimento);

		   
		    int qtd_strings = qtd_espacos(str) + 1, i = 0;
		    char strings[qtd_strings][strlen(str)];
		    char *pch = strtok (str,"/");

		    while (pch != NULL){
		        strcpy(strings[i++], pch); 
		        pch = strtok (NULL, "/");
		    }		    
		  
		    
		    //colocando as partes dentro do vetor de inteiros
		    strcpy(str1, strings[0]);
		    valor1[j] = atoi(str1);//dia

		    strcpy(str2, strings[1]);
		    valor2[j] = atoi(str2);//mes

		    strcpy(str3, strings[2]);
		    valor3[j] = atoi(str3);//ano

		    //somando a data. Ex: 01 + 02 + 1989
		    //utilizo esta soma para vincular corretamente a data ao nome e à matricula 
		    somaValor[j] = valor1[j] + valor2[j] + valor3[j];		    
	    
    }    

    
}


/******************************************************************/
/******************************************************************/
/******************************************************************/

int listarAlunosOrdemNascimento(){
	//ORDEM: o aluno mais velho está mais em cima	

	//trazendo a data de nascimento quebrada em 3 partes
	//e já em formato int
	quebraDataNascimento();

	printf("\nImprimindo função listarAlunosOrdemNascimento\n\n");	
    
    int n = TAM_LISTA_ALUNO;
    int soma = -1;    
    int i, k, p, y;	
	
	int lugar [n];
	int temp;
	int somaInput[n];

	for(i=0;i<n;i++){
	
	input[i].matricula = aluno[i].matricula;
	input[i].dia = valor1[i];
	input[i].mes = valor2[i];
	input[i].ano = valor3[i];
	strcpy(input[i].nome, aluno[i].nome);	
	
	}	


    /***********************************/
    //ORDENAÇÂO - ordenando dia, mes e ano
    /***********************************/
     for (int i=0; i<n-1; i++){
      for (int j=i+1; j<n; j++){
         if (input[i].ano > input[j].ano){
            struct date temp = input[i];
            input[i] = input[j];
            input[j] = temp;
         }
         else if (input[i].ano == input[j].ano && input[i].mes > input[j].mes){
            struct date temp = input[i];
            input[i] = input[j];
            input[j] = temp;
         }
         else if (input[i].ano == input[j].ano && input[i].mes == input[j].mes && input[i].dia > input[j].dia){
            struct date temp = input[i];
            input[i] = input[j];
            input[j] = temp;
         }
      }
   }

   /***********************************/
    //ORDENAÇÂO
    /***********************************/

   //somando o total da data ordenada, para comparar com a ordem digitada 
   for (int i = 0; i < n; i++)
   {
   	  somaInput [i] = input[i].dia + input[i].mes + input[i].ano;
   }


    printf("\n\n");   
 
    //preenchendo o vetor lugar com -1;
   for (i = 0; i < n; i++)
   {
   	 lugar[i] = -1;
   	 //printf("Lugar: %d\n", lugar[i]);
   }

    
	printf("Matrícula ------- Nome do aluno ------------------------------ Data de Nascimento\n\n");

	
    for(k=0;k<n;k++){
    	for(p=0;p<n;p++){
    	    	 		
    		if(somaInput[k] == somaValor[p] && valor1[p] == input[k].dia && valor2[p] == input[k].mes && valor3[p] == input[k].ano){    			

    			for (y = 0; y < n; y++)
    			{
    				if (p == lugar[y])
    				{
    					soma = 1;
    					//para nao imprimir    					
    					
    				} 
    			}

    			if (soma != 1){
    					lugar[k] = p;
    				}    				   
	    	
				if(soma == -1)
				{
				printf("%-17d %-40s %3s %02d/%02d/%d\n",aluno[p].matricula,aluno[p].nome,"  ",input[k].dia,input[k].mes,input[k].ano);
				}

				soma = -1; 
				break;
			}
	    }	    			
} 

    printf("\n");
	printf("\n");       

    return 0;
}


/******************************************************************/
/******************************************************************/
/******************************************************************/

/******************************************************************/
/******************************************************************/
/******************************************************************/
 // ABAIXO AS FUNÇÕES PRA ORDENAR NASCIMENTO PROFESSOR
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/

//funcao que quebra a data de nascimento em 3 partes, dia, mes e ano
//quebra e transforma essas partes em número inteiro
void quebraDataNascimentoProfessor() {
    char str[30];

    int n = TAM_LISTA_GERAL;
    
    //essa quantidade do for tem que estar igual a do for do cadastro aluno
    for (int j = 0; j < n; j++)
    {
		    strcpy(str, professor[j].dataNascimento);

		   
		    int qtd_strings = qtd_espacos(str) + 1, i = 0;
		    char strings[qtd_strings][strlen(str)];
		    char *pch = strtok (str,"/");

		    while (pch != NULL){
		        strcpy(strings[i++], pch); 
		        pch = strtok (NULL, "/");
		    }		    
		  
		    
		    //colocando as partes dentro do vetor de inteiros
		    strcpy(str4, strings[0]);
		    valor4[j] = atoi(str4);//dia

		    strcpy(str5, strings[1]);
		    valor5[j] = atoi(str5);//mes

		    strcpy(str6, strings[2]);
		    valor6[j] = atoi(str6);//ano

		    //somando a data. Ex: 01 + 02 + 1989
		    //utilizo esta soma para vincular corretamente a data ao nome e à matricula 
		    somaValor2[j] = valor4[j] + valor5[j] + valor6[j];		    
	    
    }    

    
}


/******************************************************************/
/******************************************************************/
/******************************************************************/

int listarProfessoresOrdemNascimento(){
	//ORDEM: o aluno mais velho está mais em cima	

	//trazendo a data de nascimento quebrada em 3 partes
	//e já em formato int
	quebraDataNascimentoProfessor();

	printf("\nImprimindo função listarProfessoresOrdemNascimento\n\n");	
    
    int n = TAM_LISTA_ALUNO;
    int soma = -1;    
    int i, k, p, y;	
	
	int lugar [n];
	int temp;
	int somaInput[n];

	for(i=0;i<n;i++){
	
	input2[i].matricula = professor[i].matricula;
	input2[i].dia = valor4[i];
	input2[i].mes = valor5[i];
	input2[i].ano = valor6[i];
	strcpy(input2[i].nome, aluno[i].nome);	
	
	}	


    /***********************************/
    //ORDENAÇÂO - ordenando dia, mes e ano
    /***********************************/
     for (int i=0; i<n-1; i++){
      for (int j=i+1; j<n; j++){
         if (input2[i].ano > input2[j].ano){
            struct date temp = input2[i];
            input2[i] = input2[j];
            input2[j] = temp;
         }
         else if (input2[i].ano == input2[j].ano && input2[i].mes > input2[j].mes){
            struct date temp = input2[i];
            input2[i] = input2[j];
            input2[j] = temp;
         }
         else if (input2[i].ano == input2[j].ano && input2[i].mes == input2[j].mes && input2[i].dia > input2[j].dia){
            struct date temp = input2[i];
            input2[i] = input2[j];
            input2[j] = temp;
         }
      }
   }

   /***********************************/
    //ORDENAÇÂO
    /***********************************/

   //somando o total da data ordenada, para comparar com a ordem digitada 
   for (int i = 0; i < n; i++)
   {
   	  somaInput [i] = input2[i].dia + input2[i].mes + input2[i].ano;
   }


    printf("\n\n");   
 
    //preenchendo o vetor lugar com -1;
   for (i = 0; i < n; i++)
   {
   	 lugar[i] = -1;
   	 //printf("Lugar: %d\n", lugar[i]);
   }

    
	printf("Matrícula ------- Nome do profº ------------------------------ Data de Nascimento\n\n");

	
    for(k=0;k<n;k++){
    	for(p=0;p<n;p++){
    	    	 		
    		if(somaInput[k] == somaValor2[p] && valor4[p] == input2[k].dia && valor5[p] == input2[k].mes && valor6[p] == input2[k].ano){    			

    			for (y = 0; y < n; y++)
    			{
    				if (p == lugar[y])
    				{
    					soma = 1;
    					//para nao imprimir    					
    					
    				} 
    			}

    			if (soma != 1){
    					lugar[k] = p;
    				}    				   
	    	
				if(soma == -1)
				{
				printf("%-17d %-40s %3s %02d/%02d/%d\n",professor[p].matricula,professor[p].nome,"  ",input2[k].dia,input2[k].mes,input2[k].ano);
				}

				soma = -1; 
				break;
			}
	    }	    			
} 

    printf("\n");
	printf("\n");       

    return 0;
}

/******************************************************************/
/******************************************************************/
/******************************************************************/

void listaDisciplinaQuarentaVagasMais()
{
	int n = TAM_LISTA_PROFESSOR;

	printf("\nChamando listaDisciplinaQuarentaVagasMais\n\n");
	for (int i = 0; i < n; i++)
	{
		if(disciplina[i].vagas > 40){

			printf("Disciplina: %s",disciplina[i].nome);
			printf("Professor: %s",disciplina[i].professor);
			printf("\n");

		}
	
	}

	printf("\n");	
	printf("\n");
	
}


void listarALunos(){
	int i;	
	int n = TAM_LISTA_ALUNO;

	printf("\nImprimindo função listarALunos/ Lista de Alunos: \n");

	for (int i = 0; i < n; i++)
	{	
	   printf("Aluno %i: %s\n", i+1, aluno[i].nome);
	}

	printf("\n");
	printf("\n");
}

void listarProfessores(){
	int i;	
	int n = TAM_LISTA_PROFESSOR;

	printf("\nImprimindo função listarProfessores/ Lista de Professores: \n\n");

	for (int i = 0; i < n; i++)
	{	
	   printf("Professor %i: %s\n", i+1, professor[i].nome);
	}
	printf("\n");
	printf("\n");
}

void listarDisciplinas(){
	int i;	
	int n = TAM_LISTA_PROFESSOR;

	printf("\nImprimindo função listarDisciplinas: \n");

	printf("Dados da Disciplina: \n\n");

	for (int i = 0; i < n; i++)
	{
	printf("Nome da disciplina: %s", disciplina[i].nome);
	printf("Código: %d\n", disciplina[i].codigo);	
	printf("Semestre: %s", disciplina[i].semestre);
	printf("Professor: %s\n", disciplina[i].professor);	
	
	}
	printf("\n");
	printf("\n");
}

void listarUmaDisciplina(){
	//funcao incompleta
	//aqui vai uma struct aninhada - Disciplina - aluno
	//aluno tem uma disciplina
	//colocar a struct dadosPessoa dentro da struct dadosDisciplina
	int i;	
	int n = TAM_LISTA_PROFESSOR;

	printf("\nImprimindo função listarDisciplinas: \n\n");

	printf("Dados da Disciplina: \n\n");

	for (int i = 0; i < n; i++)
	{
	printf("Nome da disciplina: %s", disciplina[i].nome);
	printf("Código: %d\n", disciplina[i].codigo);	
	printf("Semestre: %s", disciplina[i].semestre);
	printf("Professor: %s\n", disciplina[i].professor);	
	
	}
	printf("\n");
	printf("\n");
}

void listarAlunosOrdemNome(){

	
	int i, j;	
	int n = TAM_LISTA_ALUNO;
	struct dadosPessoa aux;

	printf("\nImprimindo função listarAlunosOrdemNome: \n");

	printf("Lista dos alunos em ordem alfabética: \n\n");

	for (i = 1; i < n; i++)
	{
		aux = aluno[i];
		for (j=i; (j>0) && (strcmp(aux.nome, aluno[j-1].nome)<0); j--)
		{
			aluno[j] = aluno[j-1];
			
		}

		aluno[j] = aux;
	
	}

	for (int i = 0; i < n; i++)
	{
		printf("Nome: %s\n", aluno[i].nome);
	}
	printf("\n");
	printf("\n");
}


void listarProfessoresOrdemNome(){
	//se digitar nome do professor minúsculo e maísculo junto, não ordena
	//ajeitar isso
	int i, j;	
	int n = TAM_LISTA_PROFESSOR;
	struct dadosPessoa aux;

	printf("\nImprimindo função listarProfessoresOrdemNome: \n\n");

	printf("Lista dos Professores em ordem alfabética: \n\n");

	for (i = 1; i < n; i++)
	{
		aux = professor[i];
		for (j=i; (j>0) && (strcmp(aux.nome, professor[j-1].nome)<0); j--)
		{
			professor[j] = professor[j-1];
			
		}

		professor[j] = aux;
	
	}

	for (int i = 0; i < n; i++)
	{
		printf("Nome: %s\n", professor[i].nome);
	}
	printf("\n");
	printf("\n");
}

void listarAlunosSexo(){
	int i;	
	int n = TAM_LISTA_ALUNO;

	printf("\nImprimindo função listarAlunosSexo: \n");
	printf("\n");
	printf("Alunos do sexo masculino: \n\n");	

	for (int i = 0; i < n; i++)
	{

	if (aluno[i].sexo == 'm' || aluno[i].sexo == 'M')
	{
		printf("Nome: %s\n", aluno[i].nome);
	} 
	
	
	}

	printf("Alunos do sexo feminino: \n\n");	

	for (int i = 0; i < n; i++)
	{

	if (aluno[i].sexo == 'f' || aluno[i].sexo == 'F')
	{
		printf("Nome: %s\n", aluno[i].nome);
	} 
	
	
	}
	printf("\n");
	printf("\n");
}

void listarProfessorSexo(){
	int i;	
	int n = TAM_LISTA_PROFESSOR;

	printf("\nImprimindo função listarProfessorSexo: \n\n");
	
	printf("Professores do sexo masculino: \n\n");	

	for (int i = 0; i < n; i++)
	{

		if (professor[i].sexo == 'm' || professor[i].sexo == 'M')
		{
			printf("Nome: %s\n", professor[i].nome);
		} 
	
	
	}
	printf("\n");

	printf("Professores do sexo feminino: \n\n");	

	for (int i = 0; i < n; i++)
	{

		if (professor[i].sexo == 'f' || professor[i].sexo == 'F')
		{
			printf("Nome: %s\n", professor[i].nome);
		} 
	
	
	}
	printf("\n");
	printf("\n");
}

void aniversariantesMes(){
	int i;
	int n = TAM_LISTA_GERAL;

	//o mês precisa ser informado pelo usuário na main
	int mes = 6;		

	char palavra[20];	
	char palavra2[20];

	printf("\nImprimindo função aniversariantesMes: \n\n");
	printf("Alunos aniversariantes: \n\n");

	for (int i = 0; i < n; i++)
	{
		strcpy(palavra, aluno[i].dataNascimento);

		if (palavra[3] == '0' && palavra[4] == '1' && mes == 1)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		} else if (palavra[3] == '0' && palavra[4] == '2' && mes == 2)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		} else if (palavra[3] == '0' && palavra[4] == '3' && mes == 3)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		} else if (palavra[3] == '0' && palavra[4] == '4' && mes == 4)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '0' && palavra[4] == '5' && mes == 5)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '0' && palavra[4] == '6' && mes == 6)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '0' && palavra[4] == '7' && mes == 7)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '0' && palavra[4] == '8' && mes == 8)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '0' && palavra[4] == '9' && mes == 9)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '1' && palavra[4] == '0' && mes == 10)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '1' && palavra[4] == '1' && mes == 11)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else if (palavra[3] == '1' && palavra[4] == '2' && mes == 12)
		{
			printf("Aniversariante: %s\n", aluno[i].nome);
		}else
		{
			if (i = n - 1)
			{
				printf("Sem alunos aniversariantes\n");
				break;
			}
		}	
	
	}

	printf("\n");

	printf("Professores aniversariantes: \n\n");

	for (int i = 0; i < n; i++)
	{
		strcpy(palavra2, professor[i].dataNascimento);

		if (palavra2[3] == '0' && palavra2[4] == '1' && mes == 1)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		} else if (palavra2[3] == '0' && palavra2[4] == '2' && mes == 2)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		} else if (palavra2[3] == '0' && palavra2[4] == '3' && mes == 3)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		} else if (palavra2[3] == '0' && palavra2[4] == '4' && mes == 4)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '0' && palavra2[4] == '5' && mes == 5)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '0' && palavra2[4] == '6' && mes == 6)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '0' && palavra2[4] == '7' && mes == 7)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '0' && palavra2[4] == '8' && mes == 8)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '0' && palavra2[4] == '9' && mes == 9)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '1' && palavra2[4] == '0' && mes == 10)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '1' && palavra2[4] == '1' && mes == 11)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else if (palavra2[3] == '1' && palavra2[4] == '2' && mes == 12)
		{
			printf("Aniversariante: %s\n", professor[i].nome);
		}else
		{
			if (i = n - 1)
			{
				printf("Sem professores aniversariantes\n");
				break;
			}	
		}
			
	
	}

	printf("\n");
	printf("\n");
}
int main()
{	
	//cadastrarAluno();
	cadastrarProfessor();
	cadastrarDisciplina();
	//listarAlunosOrdemNascimento();
	listaDisciplinaQuarentaVagasMais();
	//listarALunos();
	listarProfessores();
	listarDisciplinas();
	//listarAlunosOrdemNome();
	listarProfessoresOrdemNome();
	//listarAlunosSexo();
	listarProfessorSexo();
	aniversariantesMes();
	
	return 0;
}
