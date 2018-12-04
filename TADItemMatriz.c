#include "TADItemMatriz.h"
/* InicializarItemMatriz - Essa função é responsável por inicializar o
 * TADItemMatriz. Foi necessário criar a lista encadeada para realizar as
 * inserções e demais operações através deste tad.
 * @param Recebe endereço para a estrutura pItemMatriz.
 */
void InicializarItemMatriz(TipoItemMatriz* pItemMatriz){
    pItemMatriz->QTDVoos= 0;
    pItemMatriz->horas = -1;
    pItemMatriz->minutos = -1;
    pItemMatriz->segundos = -1;
    FLVazia (&(pItemMatriz->Lista));
}
/* getHorarioAtualizacao_Horas - Essa função é responsável identificar o horario de
 * atualização da lista de voos das Horas.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @return Retorna em inteiro o valor das horas correspondente.https://github.com/joaohttps://github.com/joaoarthurv/TPAedes.githttps://github.com/joaoarthurv/TPAedes.githttps://github.com/joaoarthurv/TPAedes.gitarthurv/TPAedes.git
 */
int getHorarioAtualizacao_Horas (TipoItemMatriz* pItemMatriz){
    struct tm* HorarioSistema;
    time_t Horario_Horas;
    Horario_Horas = time(NULL);
    HorarioSistema = localtime(&Horario_Horas);
    return (HorarioSistema->tm_hour);
}
/* getHorarioAtualizacao_Minutos - Essa função é responsável identificar o horario de
 * atualização da lista de voos das Minutos.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @return Retorna em inteiro o valor de minutos correspondente.
 */
int getHorarioAtualizacao_Minutos (TipoItemMatriz* pItemMatriz){
    struct tm* HorarioSistema;
    time_t Horario_Minutos;
    Horario_Minutos = time(NULL);
    HorarioSistema = localtime(&Horario_Minutos);
    return (HorarioSistema->tm_min);
}
/* getHorarioAtualizacao_Segundos - Essa função é responsável identificar o horario de
 * atualização da lista de voos das Segundos.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @return Retorna em inteiro o valor de Segundos correspondente.
 */
int getHorarioAtualizacao_Segundos(TipoItemMatriz* pItemMatriz){
    struct tm* HorarioSistema;
    time_t Horario_Segundos;
    Horario_Segundos = time(NULL);
    HorarioSistema = localtime(&Horario_Segundos);
    return ( HorarioSistema->tm_sec);
}
/* getQtdeVoo - Essa função é responsável retornar o numero de voos na lista.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @return Retorna em inteiro o valor da quantidade de voos correspondente.
 */
int getQtdeVoo ( TipoItemMatriz* pItemMatriz){
    pItemMatriz->QTDVoos = pItemMatriz->QTDVoos +1;
    return (pItemMatriz->QTDVoos);
}
/* setInsereDadosLista - Essa função é responsável inserir voos na lista.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @return Retorna em inteiro o valor de minutos correspondente.
 */
int setInsereDadosLista (TipoItemMatriz* pItemMatriz, TipoVoo* pVoo){
    
    setVooEmOrdemDecolagem   (&(pItemMatriz->Lista),pVoo);
    getQtdeVoo (pItemMatriz);
    pItemMatriz->horas = getHorarioAtualizacao_Horas (pItemMatriz);
    pItemMatriz->minutos = getHorarioAtualizacao_Minutos (pItemMatriz);
    pItemMatriz->segundos = getHorarioAtualizacao_Segundos(pItemMatriz);
    return 0;
}
/* setRemoveDadosLista - Essa função é responsável inserir voos na lista.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @return Retorna em inteiro o valor de minutos correspondente.
 */
int setRemoveDadosLista (TipoItemMatriz* pItemMatriz,TipoVoo* pVoo,int VIDRemove){
    TipoVoo* pSaida= NULL;
    pSaida = RemoverVooIdentificador (&(pItemMatriz->Lista), pVoo,VIDRemove);
    if(pSaida == NULL){
      return 0;
    }
  
    pItemMatriz->horas = getHorarioAtualizacao_Horas (pItemMatriz);
    pItemMatriz->minutos = getHorarioAtualizacao_Minutos (pItemMatriz);
    pItemMatriz->segundos = getHorarioAtualizacao_Segundos(pItemMatriz);
    pItemMatriz->QTDVoos= pItemMatriz->QTDVoos - 1;
    return 1;
}

/* ImprimirListaVoo- Essa função é responsável por imprimir a Lista de voo.
 * @param Recebe endereço para a estrutura pItemMatriz.
 */
void ImprimirListaItemMatrizVoo (TipoItemMatriz* pItemMatriz){
   ImprimeListaVoo(&(pItemMatriz->Lista));
}
/* ProcuraItem - Essa função é responsável inserir voos na lista.
 * @param Recebe endereço para a estrutura pItemMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @param Recebe o inteiro VIDProcura.
 * @return Retorna o Voo, no ponteiro pSaida;
 */
TipoVoo* ProcuraItem(TipoItemMatriz* pItemMatriz,TipoVoo* pVoo,int VIDProcura){
    TipoVoo* pSaida =NULL;
     
    pSaida = ProcuraVooPeloIdentificador(&(pItemMatriz->Lista), pVoo,VIDProcura);
    if(pSaida == NULL){
        return NULL;
    }
    return pSaida ;
    
}