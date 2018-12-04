/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TADListaVoo.h
 * Created on 5 de Setembro de 2018, 17:09
 */
#include "TADVoo.h"

typedef struct Celula{
    TipoVoo Voo;
    struct Celula* pProx;
}TCelula;

typedef struct{
    struct Celula* pPrimeiro;
    struct Celula* pUltimo;
}TLista;

void FLVazia(TLista *pLista);
int LEhVazia(TLista *pLista);
int setVooEmOrdemDecolagem(TLista *pLista,TipoVoo *pVoo);
TipoVoo* RemoverVooIdentificador(TLista* pLista,TipoVoo *pVoo,int VIDRemocao);
TipoVoo* ProcuraVooPeloIdentificador(TLista *pLista,TipoVoo *pVoo, int VIDProcura);
void ImprimeListaVoo(TLista *pLista);