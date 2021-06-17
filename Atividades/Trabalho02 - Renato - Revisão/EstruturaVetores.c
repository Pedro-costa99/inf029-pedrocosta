#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

Principal vetorPrincipal[TAM];

int ehPosicaoValida(int posicao);

void dobrar(int *x)
{

    *x = *x * 2;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

      if (ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;

      if (vetorPrincipal[posicao-1].auxiliar != NULL){
            return JA_TEM_ESTRUTURA_AUXILIAR;
      }else{

        vetorPrincipal[posicao-1].auxiliar = (int*)malloc(tamanho*sizeof(int));
      }      

	  if (tamanho < 1)
	    return TAMANHO_INVALIDO;	  

	  if (vetorPrincipal[posicao-1].auxiliar == NULL){

	      return SEM_ESPACO_DE_MEMORIA;
      }else{
        vetorPrincipal[posicao-1].tamanho = tamanho;
      }  

	  return SUCESSO;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int qtd;

    if (ehPosicaoValida(posicao)){
        return POSICAO_INVALIDA;
    }    

    if (vetorPrincipal[posicao-1].auxiliar == NULL){

        return SEM_ESTRUTURA_AUXILIAR;
    } else{

        qtd = vetorPrincipal[posicao-1].qtd;
    }    

    if (qtd >= vetorPrincipal[posicao-1].tamanho){

      return SEM_ESPACO;

    } else{

        vetorPrincipal[posicao-1].auxiliar[qtd] = valor;
        vetorPrincipal[posicao-1].qtd++;

    }    

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
     if (ehPosicaoValida(posicao) == 1){
            return POSICAO_INVALIDA;
     }	    

    if (vetorPrincipal[posicao-1].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao-1].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    } else{

        vetorPrincipal[posicao-1].qtd--;
    }   

	  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
	    //espaço vazio para implementação
    int retorno = SUCESSO;
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
	  if (posicao - 1 < 0 || posicao - 1 > 9)
	        return 1;
	    else
	        return 0;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void getDadosAuxiliar(int posicao, int vetorAux[], int n){
   int p;

   for (p = 0; p < n; p++){
        vetorAux[p] = vetorPrincipal[posicao-1].auxiliar[p];
   }
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int qtd;

    if (ehPosicaoValida(posicao)){
        return POSICAO_INVALIDA;
    }   

    if (vetorPrincipal[posicao-1].auxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    } else{

        qtd = vetorPrincipal[posicao-1].qtd;

        getDadosAuxiliar(posicao-1,vetorAux, qtd);

    }
    

    return SUCESSO;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/



int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
        //espaço vazio para implementação
    int retorno = 0;

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
      //espaço vazio para implementação
    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/


int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
     //espaço vazio para implementação
    int retorno = 0;
    return retorno;
}


/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{       
        int qtd;

	    if (ehPosicaoValida(posicao)){
	        return POSICAO_INVALIDA;
        }
	    

	    if (vetorPrincipal[posicao-1].auxiliar == NULL){
	        return SEM_ESTRUTURA_AUXILIAR;
        } else{

            novoTamanho = novoTamanho + vetorPrincipal[posicao-1].tamanho;

        }	    

	    if (novoTamanho < 1){
	        return NOVO_TAMANHO_INVALIDO;
        }else{
            vetorPrincipal[posicao-1].auxiliar = (int*)realloc(vetorPrincipal[posicao-1].auxiliar, novoTamanho * sizeof(int));

        }
	    

	    if (vetorPrincipal[posicao-1].auxiliar == NULL){
	        return SEM_ESPACO_DE_MEMORIA;
        }else{
            vetorPrincipal[posicao-1].tamanho = novoTamanho;
            qtd = vetorPrincipal[posicao-1].qtd;

        }	    

	    if (qtd > novoTamanho){
	        vetorPrincipal[posicao-1].qtd = novoTamanho;
        }else{
	        vetorPrincipal[posicao-1].qtd = qtd;
        }

	    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int qtd;

    	if (ehPosicaoValida(posicao)){
    	        return POSICAO_INVALIDA;
        }	    

	    if (vetorPrincipal[posicao-1].auxiliar == NULL){
	        return SEM_ESTRUTURA_AUXILIAR;
        }

	    if (vetorPrincipal[posicao-1].qtd == 0){
	        return ESTRUTURA_AUXILIAR_VAZIA;

        } else{
            qtd = vetorPrincipal[posicao-1].qtd;

        }	    

	    return qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
RetorPrincipal (Principal*)
    NULL, caso não tenha nenhum número nas listas
    Principal*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){

    //espaço vazio para implementação
    return NULL;
}


/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
RetorPrincipal void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){

   //espaço vazio para implementação

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir do início.
*/
void destruirListaEncadeadaComCabecote(No** inicio){

    //espaço vazio para implementação
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/
void inicializar(){
  int p;

  for (p = 0; p < 10; p++){
    vetorPrincipal[p].auxiliar = NULL;
    vetorPrincipal[p].qtd = 0;
    vetorPrincipal[p].tamanho = 0;
  }
}
/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{   
    int p;

	for(p = 0; p < 10; p++)
	     free(vetorPrincipal[p].auxiliar);

}