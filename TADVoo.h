/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TADVoo.h
 * Created on 4 de Setembro de 2018, 23:45
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TAM 6


typedef struct{
    int Identificador_voo;
    char H_decolagem[TAM];
    char H_pouso[TAM];
    char Aeroporto_Decolagem[TAM];
    char Aeroporto_Pouso[TAM];
    int IdentificadorPistas_Decolagem;
}TipoVoo;

void InicializarItemVoo(TipoVoo* pVoo);
int getIdentificador_voo(TipoVoo* pVoo,int IdentificadorVoo);
int setH_decolagem(TipoVoo* pVoo,char* horarioDecolagem);
char* getH_decolagem(TipoVoo* pVoo);
int setH_pouso(TipoVoo* pVoo,char* horarioPouso);
char* getH_pouso(TipoVoo* pVoo);
int setAeroporto_Decolagem(TipoVoo* pVoo,char* AeroportoDecolagem);
char* getAeroporto_Decolagem(TipoVoo* pVoo);
int setAeroporto_Pouso(TipoVoo* pVoo,char* AeroportoPouso);
char* getAeroporto_Pouso(TipoVoo* pVoo);
int setIdentificadorPistas_Decolagem(TipoVoo* pVoo,int IdentificadorPista);
int getIdentificadorPistas_Decolagem(TipoVoo* pVoo);


