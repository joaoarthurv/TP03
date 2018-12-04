/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TADMatrizVoo.h
 * Created on 8 de Setembro de 2018, 15:41
 */

#include "TADItemMatriz.h"
#define MAXMATRIZ 24
// Bloco de instrucoes para criar voos automaticamente


typedef struct {
    TipoItemMatriz Matriz[MAXMATRIZ][MAXMATRIZ];
    int dia,mes,horas,minutos;
    int qtdTotalDeVoo;
    int ChaveIdentificacao;
}TipoMatriz;


void InicializarMatriz (TipoMatriz* pMatriz);
int setInsereVooMatriz (TipoMatriz*pMatriz,TipoVoo *pVoo);
int setRemoverVooMatriz (TipoMatriz *pMatriz,TipoVoo *pVoo,int VIDRemove);
TipoVoo* getProcuraVooMatriz (TipoMatriz* pMatriz,TipoVoo* pVoo,int VIDProcura);
void imprimirVooHorario_Decolagem_Pouso (TipoMatriz* pMatriz,TipoVoo *pVoo,char* horarioDecolagem,char* horarioPouso);
void imprimirVooHorario_Decolagem_Apenas (TipoMatriz* pMatriz,TipoVoo *pVoo,char* horarioDecolagem);
void imprimirVooHorario_Pouso_Apenas (TipoMatriz* pMatriz,TipoVoo *pVoo,char* horarioPouso);
void imprimirTodaMatriz (TipoMatriz* pMatriz);


int encontrarFaixaHorarioMaiorQtdVoo (TipoMatriz* pMatriz);
int encontrarFaixaHorarioMenorQtdVoo (TipoMatriz* pMatriz);
int encontrarListaVooAlteradaMaisRecente (TipoMatriz* pMatriz);
int encontrarListaVooAlteradaMenosRecente (TipoMatriz* pMatriz);
int verificarseMatrizEhEsparca(TipoMatriz* pMatriz);



TipoMatriz* bubbleSort(TipoMatriz* VetorMatriz, int n);
//TListaPalavras selectSort(TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//TListaPalavras insertSort (TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//TListaPalavras shellSort (TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//TListaPalavras quickSort(TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//TListaPalavras heapSort(TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//
//void Constroi(TPalavra *A, int *n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//void Refaz(int Esq, int Dir, TPalavra *A, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//void Particao(int Esq, int Dir, int *i, int *j, TPalavra *A, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);
//void Ordena(int Esq, int Dir, TPalavra *A, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes);


// Bloco de métodos para criar voos automaticamente.
int intN(int n) ;
char *randomStringLetras(int len);
char *randomStringHoraP(int len) ;
char *randomStringHoraQ1(int len);
char *randomStringHoraQ2(int len) ;
char *randomStringHoraR(int len);
char *randomStringHoraS(int len);
void shuffle(int *array, size_t n);
