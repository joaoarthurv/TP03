#include "TADListaVoo.h"

/* FLVazia - Essa função é responsável por inicializar a lista encadeada com
 * célula cabeça.
 * @param Recebe endereço para a estrutura TLista.
 */
void FLVazia(TLista *pLista){
    pLista->pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
    InicializarItemVoo(&(pLista->pPrimeiro->Voo));
}
/* LEhVazia - Essa função é responsável por verificar se a lista esta vazia.
 * @param Recebe endereço para a estrutura TLista.
 */
int LEhVazia(TLista *pLista){
    return (pLista->pPrimeiro == pLista->pUltimo);
}
/* setVooEmOrdem - Essa função é responsável por inserir elementos na lista
 * encadeada, em ordem de Decolagem.
 * @param Recebe endereço para a estrutura TLista.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
int setVooEmOrdemDecolagem   (TLista *pLista,TipoVoo *pVoo){
    TCelula* pBackup = NULL;
    TCelula* pAux = NULL ;
    int comparador;


    pAux = pLista ->pPrimeiro;

    while(pAux->pProx!=NULL){
        comparador = strcmp(pAux->pProx->Voo.H_decolagem, pVoo->H_decolagem); //Comparar se o item Inserido é menor ou igual ao item contido na lista.
        if(comparador>=0){
            TCelula* pNovo = NULL;
            pNovo = (TCelula*) malloc(sizeof(TCelula));

            pBackup = pAux->pProx;
            pAux->pProx = pNovo;
            pNovo->pProx = pBackup;
            strcpy(pNovo->Voo.H_decolagem, pVoo->H_decolagem);
            strcpy(pNovo->Voo.H_pouso, pVoo->H_pouso);
            strcpy(pNovo->Voo.Aeroporto_Decolagem, pVoo->Aeroporto_Decolagem);
            strcpy(pNovo->Voo.Aeroporto_Pouso, pVoo->Aeroporto_Pouso);
            pNovo->Voo.Identificador_voo = pVoo->Identificador_voo;
            pNovo->Voo.IdentificadorPistas_Decolagem = pVoo->IdentificadorPistas_Decolagem;
            //printf("\n\n\n O valor inserido eh menor ou igual ao valor contido na lista\n\n\n\n");
            pBackup = NULL;
            break;
        }
        else{
            pAux = pAux->pProx;
        }
    }

    if(LEhVazia(pLista)!=0){
        TCelula* pNovo = NULL;

        pNovo = (TCelula*) malloc(sizeof(TCelula));
        pAux->pProx = pNovo;
        pLista ->pUltimo = pNovo;
        pLista ->pUltimo ->pProx = NULL;
        strcpy(pNovo->Voo.H_decolagem, pVoo->H_decolagem);
        strcpy(pNovo->Voo.H_pouso, pVoo->H_pouso);
        strcpy(pNovo->Voo.Aeroporto_Decolagem, pVoo->Aeroporto_Decolagem);
        strcpy(pNovo->Voo.Aeroporto_Pouso, pVoo->Aeroporto_Pouso);
        pNovo->Voo.Identificador_voo = pVoo->Identificador_voo;
        pNovo->Voo.IdentificadorPistas_Decolagem = pVoo->IdentificadorPistas_Decolagem;
        //printf("lista eh vazia \n\n\n");
    }

    if(pAux->pProx == NULL && LEhVazia(pLista) == 0){
        //printf("\n\n\n\nO valor Inserido eh maior ao valor contido na lista \n\n\n\n\n\n\n");
        TCelula* pNovo = NULL;

        pNovo = (TCelula*) malloc(sizeof(TCelula));
        pAux->pProx = pNovo;
        pNovo ->pProx = NULL;
        pLista ->pUltimo = pNovo;
        strcpy(pNovo->Voo.H_decolagem , pVoo->H_decolagem);
        strcpy(pNovo->Voo.H_pouso, pVoo->H_pouso);
        strcpy(pNovo->Voo.Aeroporto_Decolagem, pVoo->Aeroporto_Decolagem);
        strcpy(pNovo->Voo.Aeroporto_Pouso, pVoo->Aeroporto_Pouso);
        pNovo->Voo.Identificador_voo = pVoo->Identificador_voo;
        pNovo->Voo.IdentificadorPistas_Decolagem = pVoo->IdentificadorPistas_Decolagem;
    }
   return 0;
}

/* RemoverVooIdentificador - Essa função é responsável por remover elementos da
 * lista encadeada, através do identificador.
 * @param Recebe endereço para a estrutura TLista.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
TipoVoo* RemoverVooIdentificador (TLista* pLista,TipoVoo *pVoo, int VIDRemocao){
    TCelula* pAux = NULL;
    TCelula* pBackup = NULL;
    TipoVoo* pRetorno = NULL;
    int IdentificadorCopia = -1;

    if(LEhVazia(pLista)!=0){
        return NULL;
    }

    pAux = pLista->pPrimeiro;

    while(pAux->pProx!=NULL){
        if(pAux->pProx->Voo.Identificador_voo == VIDRemocao){
            pBackup = pAux ->pProx;
            pRetorno = (TipoVoo*)malloc(sizeof(TipoVoo));
            *pRetorno = pAux->pProx->Voo;
            pAux ->pProx = pBackup ->pProx;
            *pVoo = pBackup->Voo;
            free (pBackup);
            break;
        }
        else{
            pAux=pAux->pProx;
        }
    }

    if (pAux->pProx == NULL){
        pLista->pUltimo = pAux;
        pLista->pUltimo->pProx= NULL;
    }
    return pRetorno;
}
/* ProcuraVooPeloIdentificador - Essa função é responsável por procurar
 *elementos da lista encadeada, através do identificador.
 * @param Recebe endereço para a estrutura TLista.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @return retorna NULL caso a lista seja vazia.
 * @return retorna ponteiro para estrutura TCelula contendo o voo, desejado.
 */
TipoVoo* ProcuraVooPeloIdentificador (TLista *pLista,TipoVoo *pVoo, int VIDProcura){
    TCelula* pAux = NULL;
    TipoVoo* pSalva = NULL;

    if(LEhVazia(pLista)!=0){
        return NULL;
    }

    pAux = pLista->pPrimeiro;

    while(pAux->pProx!=NULL){
        if(pAux->pProx->Voo.Identificador_voo == VIDProcura){
            pSalva = (TipoVoo*) malloc(sizeof(TipoVoo));
            *pSalva = pAux->pProx->Voo;
            return pSalva;
            break;
        }
        else{
            pAux=pAux->pProx;
        }
    }
    if (pAux->pProx == NULL){
        pLista->pUltimo = pAux;
        pLista->pUltimo->pProx= NULL;
    }
    return NULL;
}
/* ImprimeListaVoo - Essa função é responsável por imprimir os elementos da
 * lista encadeada, através do identificador.
 * @param Recebe endereço para a estrutura TLista.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
void ImprimeListaVoo (TLista *pLista){
    TCelula* pAux = NULL;

    pAux = pLista->pPrimeiro->pProx;

    while (pAux != NULL){
        printf("\n\n");
        printf("Identificador de Voo: %d\n",pAux->Voo.Identificador_voo);
        printf("A pista de decolagem eh: %d\n",pAux->Voo.IdentificadorPistas_Decolagem);
        printf("O Aeroporto de Decolagem: %s\n",pAux->Voo.Aeroporto_Decolagem);
        printf("O Aeroporto De Pouso: %s\n",pAux->Voo.Aeroporto_Pouso);
        printf("O Horario de Decolagem eh de: %s\n",pAux->Voo.H_decolagem);
        printf("O Horario de Pouso eh de: %s\n",pAux->Voo.H_pouso);
        pAux = pAux->pProx;
    }
}
