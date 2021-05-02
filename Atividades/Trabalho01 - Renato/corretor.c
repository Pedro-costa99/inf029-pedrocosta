// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.c
#include "PedroCosta2019116037.h"

void testSomar();    //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{
    //testSomar();
    //testFatorial();
    //testQ1();
    //testQ2();
    //testQ3();
    testQ4();
    //testQ5();
   //testQ6();
}

void testSomar()
{
    printf("%d\n", somar(3, 4) == 7);
    printf("%d\n", somar(-1, -3) == 2);
    printf("%d\n", somar(-6, 6) == 0);
    printf("%d\n", somar(74, 9) == 83);
    printf("%d\n", somar(30, -9) == 21);
}

void testFatorial()
{
    printf("%d\n", fatorial(3) == 6);
    printf("%d\n", fatorial(1) == 1);
    printf("%d\n", fatorial(5) == 120);
}

void testQ1()
{
    char str[11];
    printf("Abaixo estão as datas válidas. Tudo tem que dar 1\n");
    strcpy(str, "01/02/2001");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
    strcpy(str, "1/02/2001");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
    strcpy(str, "01/2/2001");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
    strcpy(str, "1/2/2001");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
    strcpy(str, "1/2/01");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
    strcpy(str, "01/2/01");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
    strcpy(str, "1/02/01");
    printf("%d\n", q1(str) == 1);//imprime 1//Data válida
   
    printf("Abaixo estão as datas inválidas. Tudo tem que dar 1\n");
    strcpy(str, "/02/2001");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "/2/2001");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "01//2001");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "1//2001");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "//2001");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "//201");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "//21");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "//2");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "//");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "29/02/2015");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "45/03/2010");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "20/15/2010");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida
    strcpy(str, "20/03/1800");
    printf("%d\n", q1(str) == 0);//imprime 0//Data inválida

}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
  
    printf("Validando informações **Data válida com resultados - Retorno 1** Tudo tem que dar 1\n");
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);   
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 0);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);

    
    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    
    printf("Validando informações **Data 01 inválida - Retorno 2** A impressão tem que dar 1\n");
    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 2);

    printf("Validando informações **Data 02 inválida - Retorno 3** A impressão tem que dar 1\n");
    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 3);

    printf("Validando informações **Data01 > Data02 - Retorno 4** A impressão tem que dar 1\n");
    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 4);

    
    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    printf("Validando informações **Data válida com resultados - Retorno 1** Tudo tem que dar 1\n");
    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 1);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0); 
}

void testQ3()
{ 
      
    wchar_t str[250]; 
    wcscpy(str, L"Renato Lima Novais");
    printf("Validando informações. Tudo tem que dar 1: \n");
    wprintf(L"%d\n", q3(str, 'a', 0) == 3);
    wprintf(L"%d\n", q3(str, 'b', 0) == 0);
    wprintf(L"%d\n", q3(str, 'l', 1) == 0);
    wprintf(L"%d\n", q3(str, 'l', 0) == 1);
    wprintf(L"%d\n", q3(str, L'á', 0) == 3);
    wprintf(L"%d\n", q3(str, L'ó', 1) == 2);
    wprintf(L"%d\n", q3(str, L'ö', 0) == 2);
   
}

void testQ4()
{   wchar_t strTexto[250];
    wchar_t strBusca[50];
    //char strTexto[250];
    //char strBusca[50];
   
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    printf("Primeira validação\n");
    //strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    wcscpy(strTexto, L"Laboratorio de programacao: para ratos de programação");
    //strcpy(strBusca, "rato");
    wcscpy(strBusca, L"rato");
    wprintf(L"%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);
    //wprintf(L"%d\n", q3(str, 'a', 0) == 3);
    
    printf("Segunda validação\n");
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    //strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    wcscpy(strTexto, L"Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    //strcpy(strBusca, "mui");
    wcscpy(strBusca, L"mui");
    wprintf(L"%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);
}

void testQ5()
{
    printf("Resultados: \n");
    printf("%d\n", q5(345) == 543);
    printf("%d\n", q5(78) == 87);
    printf("%d\n", q5(3) == 3);
    printf("%d\n", q5(5430) == 345);
}

void testQ6()
{   
    printf("Resultados: \n");
    printf("%d\n", q6(34567368, 3) == 2);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3539343, 3) == 4);
    printf("%d\n", q6(3539343, 39) == 1);
}