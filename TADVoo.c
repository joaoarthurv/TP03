#include "TADVoo.h"
/* InicializarItemVoo - Essa função é responsável por inicializar os itens
 * que serão inseridos pelo usuário.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
void InicializarItemVoo(TipoVoo* pVoo){
    pVoo->Aeroporto_Decolagem[0]= '0';
    pVoo ->Aeroporto_Pouso[0] = '0';
    pVoo ->H_decolagem[0] = '0';
    pVoo ->H_pouso[0] = '0';
    pVoo ->Identificador_voo = 0 ;
    pVoo ->IdentificadorPistas_Decolagem  = 0 ;
}
/* getIdentificador_voo - Essa função é responsável por gerar o valor aleatório
 * do identificador do Voo.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @param Recebe um inteiro o qual ira armazenar o valor aleatorio gerado.
 */
int getIdentificador_voo(TipoVoo* pVoo,int IdentificadorVoo){
    
    IdentificadorVoo = rand() % 500;
    pVoo->Identificador_voo = IdentificadorVoo;
    return pVoo->Identificador_voo;
}
/* setH_decolagem - Essa função é responsável por receber o valor inserido pelo
 * usuário do horario de decolagem.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @param Recebe um endereço para char o qual ira armazenar uma string contendo
 * o horário de decolagem.
 */
int setH_decolagem(TipoVoo* pVoo,char* horarioDecolagem){
    // printf("Insira o horario de decolagem HH:MM\n");
    strcpy(pVoo->H_decolagem,horarioDecolagem);
    return 0;
}

/* getH_Decolagem - Essa função é responsável por retornar o valor contido em
 * H_decolagem.
 * @param Recebe endereço para a estrutra TipoVoo
 */
char* getH_decolagem(TipoVoo* pVoo){
    return pVoo->H_decolagem;
}

/* setH_Pouso - Essa função é responsável por receber o valor inserido pelo
 * usuário do horario de pouso.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @param Recebe um endereço para char o qual ira armazenar uma string contendo
 * o horário de Pouso.
 */
int setH_pouso(TipoVoo* pVoo,char* horarioPouso){
    strcpy(pVoo->H_pouso,horarioPouso);
    return 0;
}

/* getH_Decolagem - Essa função é responsável por retornar o valor contido em
 * H_Pouso.
 * @param Recebe endereço para a estrutra TipoVoo
 */
char* getH_pouso(TipoVoo*pVoo){
    return pVoo->H_pouso;
}

/* setAeroporto_Decolagem - Essa função é responsável por receber o valor
 * inserido pelo usuário do Aeroporto de Decolagem.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
int setAeroporto_Decolagem(TipoVoo* pVoo,char* AeroportoDecolagem){
    strcpy(pVoo->Aeroporto_Decolagem,AeroportoDecolagem);
    return 0;
}

/* getAeroporto_Decolagem - Essa função é responsável por retornar o valor
 * contido em Aeroporto_Decolagem.
 * @param Recebe endereço para a estrutra TipoVoo
 */
char* getAeroporto_Decolagem(TipoVoo* pVoo){
    return pVoo->Aeroporto_Decolagem;
}

/* setAeroporto_Pouso - Essa função é responsável por receber o valor inserido
 *  pelo usuário do Aeroporto de Pouso.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
int setAeroporto_Pouso(TipoVoo* pVoo,char* AeroportoPouso){
    strcpy(pVoo->Aeroporto_Pouso,AeroportoPouso);
    return 0;
}
/* getAeroporto_Pouso - Essa função é responsável por retornar o valor
 * contido em Aeroporto_Pouso.
 * @param Recebe endereço para a estrutra TipoVoo
 */
char* getAeroporto_Pouso(TipoVoo* pVoo){
    return pVoo->Aeroporto_Pouso;
}

/* setIdentificadorPistas_Decolagem - Essa função é responsável por receber o
 *  valor inserido pelo usuário do IdentificadorPistas_Decolagem
 * @param Recebe endereço para a estrutura TipoVoo.
 */
int setIdentificadorPistas_Decolagem(TipoVoo* pVoo, int IdentificadorPista){
    
    pVoo->IdentificadorPistas_Decolagem = IdentificadorPista;
    return 0;
}
/* getIdentificadorPistas_Decolagem - Essa função é responsável por retornar o
 * valor contido em IdentificadorPistas_Decolagem.
 * @param Recebe endereço para a estrutra TipoVoo
 */
int getIdentificadorPistas_Decolagem(TipoVoo* pVoo){
    return pVoo->IdentificadorPistas_Decolagem;
}
