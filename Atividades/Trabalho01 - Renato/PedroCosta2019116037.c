// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Fernando C. Costa
//  email: pedro-ccosta@live.com
//  Matrícula: 2019116037
//  Semestre: 2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
//void quebraDataNascimentoAlunoValida(char *data);
//int qtd_espacos(char *str);
//int validaDataNascimento(int valor7, int valor8, int valor9, char *data);

int q1(char *data)
{
    char palavra[12];
    strcpy(palavra, data);
           

   

    char str1[10], str2[10], str3[10]; 
        
    //quebra a string data em strings sDia, sMes, sAno
    int qtd_strings = 2 + 1, i = 0;
    char strings[qtd_strings][strlen(data)];
    char *pch = strtok (data,"/");

    while (pch != NULL){
        strcpy(strings[i++], pch); 
        pch = strtok (NULL, "/");
    }           
                   
            
    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    //colocando as partes dentro do vetor de inteiros
    strcpy(str1, strings[0]);
    int valor7 = atoi(str1);//dia

    strcpy(str2, strings[1]);
    int valor8 = atoi(str2);//mes

    strcpy(str3, strings[2]);
    int tam = strlen(str3); //contando o tamanho da string         
    int valor9 = atoi(str3);//ano       

    
    int dd = valor7;
    int mm = valor8;
    int yy = valor9;  


     if(tam == 2){
        yy = yy + 2000;      

     }
    
     //pelo input também dá pra resolver o problema das barras com "%d/%d/%d".
    //primeiro verifica se as barras foram colocadas corretemante nos seus lugares
    if((palavra[2] == '/' && palavra[5] == '/') || (palavra[1] == '/' && palavra[4] == '/') || (palavra[1] == '/' && palavra[3] == '/') 
        || (palavra[2] == '/' && palavra[4] == '/') ){

            //check year
            if (yy >= 1900 && yy <= 9999){
                            //check month
                            if (mm >= 1 && mm <= 12) {
                                    //check days
                                    if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                                        return 1;
                                    else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                                        return 1;
                                    else if ((dd >= 1 && dd <= 28) && (mm == 2))
                                        return 1;
                                    else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                                        return 1;
                                    else
                                        return 0;
                            } else {
                                
                                return 0;  
                            }
            } else {
                
                return 0;
            }

    } else {
        return 0;
    }   
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    int day1, mon1, year1,
        day2, mon2, year2;

    int day_diff, mon_diff, year_diff;  

    char data01[11];
    strcpy(data01, datainicial);
    if(q1(data01) == 0)//verifica se primeira data é válida
    {       
        return 2;        
    }

    char data02[11];
    strcpy(data02, datafinal);
    if(q1(data02) == 0)//verifica se segunda data é válida
    {        
        return 3; 
    }     
   

    //função abaixo para quebrar a datainicial
    char str1[10], str2[10], str3[10];                 

    int qtd_strings = 2 + 1, i = 0;
    char strings[qtd_strings][strlen(datainicial)];
    char *pch = strtok (datainicial,"/");

    while (pch != NULL){
        strcpy(strings[i++], pch); 
        pch = strtok (NULL, "/");
    }                   
            
    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    //colocando as partes dentro do vetor de inteiros
    strcpy(str1, strings[0]);
    int valor7 = atoi(str1);//dia

    strcpy(str2, strings[1]);
    int valor8 = atoi(str2);//mes

    strcpy(str3, strings[2]);
    int tam = strlen(str3); //contando o tamanho da string         
    int valor9 = atoi(str3);//ano                
      

     if(tam == 2){
        valor9 = valor9 + 2000;      

     }  

    
    day1 = valor7;
    mon1 = valor8;
    year1 = valor9;  
  
    //função abaixo para quebrar a datafinal
    char str4[10], str5[10], str6[10];                 

    int qtd_strings2 = 2 + 1, p = 0;
    char strings2[qtd_strings2][strlen(datafinal)];
    char *pch2 = strtok (datafinal,"/");

    while (pch2 != NULL){
        strcpy(strings2[p++], pch2); 
        pch2 = strtok (NULL, "/");
    }                   
    
    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    //colocando as partes dentro do vetor de inteiros
    strcpy(str4, strings2[0]);
    int valor10 = atoi(str4);//dia

    strcpy(str5, strings2[1]);
    int valor11 = atoi(str5);//mes

    strcpy(str6, strings2[2]); 
    int tam2 = strlen(str6); //contando o tamanho da string                  
    int valor12 = atoi(str6);//ano    

    if(tam2 == 2){
        valor12 = valor12 + 2000;      

    }     

    day2 = valor10;
    mon2 = valor11;
    year2 = valor12;  
  

    /********************************************/
    //FUNÇÃO ABAIXO QUE VERIFICA SE dataInicial < dataFinal
    /********************************************/
    if(year1 > year2){        
        return 4;

    } else if (year1 < year2){        
        
    } else{// year1 ==  year2
    
            if (mon1 ==  mon2)
            {
                    if (day1 ==  day2){
                        
                        
                    } else if(day1 > day2) {
                        
                        return 4;
                    } else {
                        
                    }
            } else if (mon1 > mon2){
               
                return 4;
            } else {
                
            }        
    }
    /********************************************/
    //FUNÇÃO ACIMA QUE VERIFICA SE dataInicial < dataFinal
    /********************************************/

    /********************************************/
    //FUNÇÃO ABAIXO QUE RETORNA OS VALORES data, mes e ano
    /********************************************/

    if(day2 < day1)
    {      
        
        if (mon2 == 3)
        {
            
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            {
                day2 += 29;
            }

            else
            {
                day2 += 28;
            }                        
        }

        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) 
        {
           day2 += 30; 
        }
        
        else
        {
           day2 += 31;
        }

        mon2 = mon2 - 1;
    }

    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }       

    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;

    *qtdDias = day_diff;
    *qtdMeses = mon_diff;
    *qtdAnos = year_diff;

    return 1;

}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(wchar_t *str, wchar_t c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;    
     
    wchar_t str1[100];//guarda a string em minúsculo
    wchar_t str2[100];//guarda a string em maiúsculo    
    int p = isCaseSensitive;    
    int soma = 0;    


    if (c == L'á' || c == L'ã' || c == L'â' || c == L'à' ||c == L'ä'||c == L'Á' ||c == L'Ã' ||c == L'Â' ||c == L'À' ||c == L'Ä')
    {
        c = L'a';
   
    }else if (c == L'é' || c == L'ê' || c == L'ë' || c == L'è' ||c == L'É'||c == L'Ê' ||c == L'Ë' ||c == L'È')
    {
        c = L'e';
        
    }else if (c == L'í' || c == L'î' || c == L'ï' || c == L'ì' ||c == L'Í'||c == L'Î' ||c == L'Ï' ||c == L'Ì')
    {
        c = L'i';        

    }else if (c == L'ó' || c == L'õ' || c == L'ô' || c == L'ò' ||c == L'ö'||c == L'Ó' ||c == L'Õ' ||c == L'Ô' ||c == L'Ò' ||c == L'Ö')
    {   c = L'o';
        

    }else if (c == L'ú' || c == L'û' || c == L'ù' || c == L'ü' ||c == L'Ú'||c == L'Û' ||c == L'Ù' ||c == L'Ü')
    {   
        c = L'u';       

    }    

    //convertendo a string toda em minúsculo
    int y = 0;
    while(str[y] != '\0'){
        str1[y] = tolower(str[y]);
        y++;
    }
    str1[y] = '\0';     

    //convertendo a string toda em maiúsculo
    int k = 0;
    while(str[k] != '\0'){
        str2[k] = toupper(str[k]);
        k++;
    }
    str2[k] = '\0'; 


    for (int i = 0; i < wcslen(str); i++){
         
         if(p == 1) {
            if (str[i] == c)
            {
                soma = soma + 1;
            }

         } else{//p != 1
            if (islower(c))
            {
                if (str1[i] == c)//minúsculo
                {
                    soma = soma + 1;
                }
                
            }else{

                if (str2[i] == c)//maiúsculo
                {
                    soma = soma + 1;
                }

            }
         }  
    }   
    
    qtdOcorrencias = soma;

    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(wchar_t *strTexto, wchar_t *strBusca, int posicoes[30])
{
  int qtdOcorrencias = -1;    
  int total = 0;

  wchar_t *p1, *p2, *p3;
  int i=0,j=0,sinal=0;
  int k = 0;

  p1 = strTexto;
  p2 = strBusca;

  for(i = 0; i<wcslen(strTexto); i++)
  {
    if(*p1 == *p2)
      {
          p3 = p1;
          for(j = 0;j<wcslen(strBusca);j++)
          {
            if(*p3 == *p2)
            {
              p3++;p2++;
            } 
            else
              break;
          }
          p2 = strBusca;
          if(j == wcslen(strBusca))
          {         
             
             sinal = 1;
             posicoes[k] = i + 1;
             posicoes[k + 1] = i + (j - 1) + 1;      
             k = k + 2;
             total = total + 1;
            
          }
      }
    p1++; 
  }
  if(sinal==0)
  {
       return qtdOcorrencias = -1;
  }

  qtdOcorrencias = total;
  return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int r = 0; //resto

  while (num != 0)
  {
    r = r * 10;
    r = r + (num % 10);
    num = num/10;
  }  

    return r;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0;  

  int num = numerobase;//sequência 
  int num2 = numerobusca;//n a ser buscado

  char source [50];
  char string2find [50];
  
  //convertendo int em string
  itoa(num, source, 10);
  itoa(num2, string2find, 10);
 
 //buscando o valor dentro da string
  char *position;
  for(position=source; *position; position++) {
      int comparepos, equal=1;
      for(comparepos=0; string2find[comparepos]; comparepos++) {
         if(position[comparepos] != string2find[comparepos]) {
             equal = 0;
             break;
         }
      }
      qtdOcorrencias+=equal;
  }

  return qtdOcorrencias;
 
}