/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TADItemMatriz.h
 * Created on 8 de Setembro de 2018, 08:27
 */

#include "TADListaVoo.h"

typedef struct{ 
    TLista Lista;
    int QTDVoos;
    int horas;
    int minutos;
    int segundos;
}TipoItemMatriz;

void InicializarItemMatriz(TipoItemMatriz* pItemMatriz);
int setInsereDadosLista (TipoItemMatriz* pItemMatriz, TipoVoo* pVoo);
int setRemoveDadosLista (TipoItemMatriz* pItemMatriz,TipoVoo* pVoo,int VIDRemove);
int getNumeroDeVoos (TipoItemMatriz * pItemMatriz, int Qtd_Voo);
int getHorarioAtualizacao_Horas (TipoItemMatriz* pItemMatriz);
int getHorarioAtualizacao_Minutos (TipoItemMatriz* pItemMatriz);
int getHorarioAtualizacao_Segundos(TipoItemMatriz* pItemMatriz);
void ImprimirListaItemMatrizVoo (TipoItemMatriz* pItemMatriz);
int getQtdeVoo ( TipoItemMatriz* pItemMatriz);

TipoVoo* ProcuraItem(TipoItemMatriz* pItemMatriz,TipoVoo* pVoo,int VIDProcura);