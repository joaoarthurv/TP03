#include "TADMatrizVoo.h"

const char alphabet[] = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
const char hora_p[] = "012";
const char hora_q1[] = "0123456789";
const char hora_q2[] = "0123";
const char hora_r[] = "012345";
const char hora_s[] = "0123456789";
/* InicializarMatriz - Essa função é responsável por inicializar a matriz.
 * @param Recebe endereço para a estrutura TipoMatriz.
 */
void InicializarMatriz (TipoMatriz* pMatriz){
    int i,j;
    pMatriz->qtdTotalDeVoo = 0;
    pMatriz->dia = 0;
    pMatriz->mes = 0;
    pMatriz->horas = 0;
    pMatriz->minutos =0;
    pMatriz->ChaveIdentificacao = 0;
    for(i=0;i<MAXMATRIZ;i++){
        for(j=0;j<MAXMATRIZ;j++){
            InicializarItemMatriz(&(pMatriz->Matriz[i][j]));
        }
    }
}
/* InicializarMatriz - Essa função é responsável por inicializar a matriz.
 * @param Recebe endereço para a estrutura TipoMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 */
int setInsereVooMatriz (TipoMatriz* pMatriz,TipoVoo *pVoo){
    int h_1,h_2,horas_d,horas_p;

    /* O número 0 na tabela ascci corresponde a 48, como os numeros estao em
     *  ordem na tabela ascci é necessario subtrair 48 para encontrar o inteiro
     * correspondente.
     */
    h_1 = pVoo->H_decolagem[0] - 48;
    h_2 = pVoo->H_decolagem[1] - 48;
    horas_d = h_1*10 +h_2;
    /* Após a operacao utilizando o elemento da tabela ascci nas linhas
     * anteriores,  eu multipliquei o valor h_1 * 10 para obter o algarismo
     * das dezenas e somei ao algorismo da unidade.
     */
    h_1 = pVoo->H_pouso[0] - 48;
    h_2 = pVoo->H_pouso[1] - 48;
    horas_p = h_1*10 +h_2;


    setInsereDadosLista (&(pMatriz->Matriz[horas_d][horas_p]), pVoo);
    if(pMatriz->Matriz[horas_d][horas_p].QTDVoos!=0){
        pMatriz->qtdTotalDeVoo= pMatriz->qtdTotalDeVoo + 1;
    }else{
    pMatriz->qtdTotalDeVoo =  pMatriz->qtdTotalDeVoo + pMatriz->Matriz[horas_d][horas_p].QTDVoos;
    }
    pMatriz->horas = getHorarioAtualizacao_Horas (&(pMatriz->Matriz[horas_d][horas_p]));
    pMatriz->minutos = getHorarioAtualizacao_Minutos (&(pMatriz->Matriz[horas_d][horas_p]));
    return 0;
}
/* setRemoverVooMatriz - Essa função é responsável por remover o Voo na Matriz.
 * @param Recebe endereço para a estrutura TipoMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 *///https://github.cohttps://github.com/joaoarthurv/TPAedes.gitm/joaoarthurv/TPAedes.git
int setRemoverVooMatriz (TipoMatriz *pMatriz,TipoVoo *pVoo,int VIDRemove){
    int i,j,i_retorno,j_retorno, saida = 0;

    for(i=0;i<MAXMATRIZ;i++){
        for(j=0;j<MAXMATRIZ;j++){
            if((setRemoveDadosLista (&(pMatriz->Matriz[i][j]),pVoo,VIDRemove))== 1){
                i_retorno = i;
                j_retorno = j;
                saida = 1;
                pMatriz->horas = getHorarioAtualizacao_Horas (&(pMatriz->Matriz[i_retorno][j_retorno]));
                pMatriz->minutos = getHorarioAtualizacao_Minutos (&(pMatriz->Matriz[i_retorno][j_retorno]));
                pMatriz->qtdTotalDeVoo = pMatriz->qtdTotalDeVoo - 1;
                return 1;
                break;
            }
        }
        if(saida == 1){
          break;
        }
    }
  
    return 0;
}

/**
 * getProcuraVooMatriz - Essa função é responsável por retornar o voo para a utilização.
 * @param Recebe endereço para a estrutura TipoMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @param Recebe o identificador de voo.
 * @return Retorna um endereço de uma estrutura do TipoVoo.
 */
TipoVoo* getProcuraVooMatriz (TipoMatriz* pMatriz,TipoVoo* pVoo,int VIDProcura){
    int i,j;
   
    
    for(i=0;i<MAXMATRIZ;i++){
       for(j=0;j<MAXMATRIZ;j++){
           if(( ProcuraItem(&(pMatriz->Matriz[i][j]),pVoo,VIDProcura)) != NULL){
               return ProcuraItem(&(pMatriz->Matriz[i][j]),pVoo,VIDProcura);
               
            }
        }
    }
    return NULL;
}

/**
 * imprimirVooHorario_Decolagem_Pouso- Função responsável por imprimir voos, pelo horário de decolagem e horário de pouso previsto.
 * @param Recebe endereço para a estrutura TipoMatriz.
 * @param Recebe endereço para a estrutura TipoVoo.
 * @param Horario de decolagem do voo.
 * @param Horario previsto da chegada do voo.
 */
void imprimirVooHorario_Decolagem_Pouso (TipoMatriz* pMatriz,TipoVoo *pVoo,char* horarioDecolagem,char* horarioPouso){
    int h_1,h_2,horas_d,horas_p;
    struct tm* dataSistema;
    time_t Dia;
    Dia = time(NULL);
    dataSistema = localtime(&Dia);
    pMatriz ->dia = dataSistema ->tm_mday;
    pMatriz->mes = dataSistema ->tm_mon;
    pMatriz->mes = pMatriz->mes + 1;
    printf("\nData de impressao da Lista de Voo: (%d/0%d/2018)\n",pMatriz->dia,pMatriz->mes);
    printf("\n############################################################################\n");
    
    h_1 = pVoo->H_decolagem[0] - 48;
    h_2 = pVoo->H_decolagem[1] - 48;
    horas_d = h_1*10 +h_2;

    h_1 = pVoo->H_pouso[0] - 48;
    h_2 = pVoo->H_pouso[1] - 48;
    horas_p = h_1*10 +h_2;
    
    ImprimirListaItemMatrizVoo (&(pMatriz->Matriz[horas_d][horas_p]));
}
/**
 * imprimirVooHorario_Decolagem_Apenas - Função responsável por imprimir voos, pelo horário de decolagem apenas. Considerando todos os horários de pouso previsto.
 * @param Recebe endereço para a estrutura TipoMatriz.
 * @param Endereço de um elemento do Tipo Voo.
 * @param Horario de decolagem do voo.
 */
void imprimirVooHorario_Decolagem_Apenas (TipoMatriz* pMatriz,TipoVoo *pVoo,char* horarioDecolagem){
    int h_1,h_2,horas_d,horas_p;
    struct tm* dataSistema;
    time_t Dia;
    Dia = time(NULL);
    dataSistema = localtime(&Dia);
    pMatriz ->dia = dataSistema ->tm_mday;
    pMatriz->mes = dataSistema ->tm_mon;
    pMatriz->mes = pMatriz->mes + 1;
    printf("\nData de impressao da Lista de Voo: (%d/0%d/2018)\n",pMatriz->dia,pMatriz->mes);
    printf("\n############################################################################\n");
   
    h_1 = pVoo->H_decolagem[0] - 48;
    h_2 = pVoo->H_decolagem[1] - 48;
    horas_d = h_1*10 +h_2;

    for(horas_p = 0;horas_p<24;horas_p++){
        ImprimirListaItemMatrizVoo (&(pMatriz->Matriz[horas_d][horas_p]));
    }
}

/**
 * imprimirVooHorario_Pouso_Apenas -  Imprimir voos, dado horário previsto de pouso apenas. Considerando todos os horários de decolagem.
 * @param Recebe endereço para a estrutura TipoMatriz.
 * @param Endereço de um elemento do Tipo Voo.
 * @param Horario previsto da chegada do voo.
 */
void imprimirVooHorario_Pouso_Apenas (TipoMatriz* pMatriz,TipoVoo *pVoo,char* horarioPouso){
  int h_1, h_2, horas_p, horas_d;
  struct tm* dataSistema;
  time_t Dia;
  Dia = time(NULL);
  dataSistema = localtime(&Dia);
  pMatriz ->dia = dataSistema ->tm_mday;
  pMatriz->mes = dataSistema ->tm_mon;
  pMatriz->mes = pMatriz->mes + 1;
  
  printf("\nData de impressao da Lista de Voo: (%d/0%d/2018)\n",pMatriz->dia,pMatriz->mes);
  printf("\n############################################################################\n");
  
  h_1 = pVoo->H_pouso[0] - 48;
  h_2 = pVoo->H_pouso[1] - 48;
  horas_p = h_1*10 +h_2;

  for ( horas_d=0 ; horas_d<24; horas_d++) {
    ImprimirListaItemMatrizVoo(&(pMatriz->Matriz[horas_d][horas_p]));
  }

}

/**
 * imprimirTodaMatriz - Função responsável por imprimir toda a matriz, exibindo todos os voos de todas as listas cadastradas.
 * @param Endereço para a estrutura TipoMatriz.
 */
void imprimirTodaMatriz(TipoMatriz* pMatriz){
    int i,j;
    struct tm* dataSistema;
    time_t Dia;
    Dia = time(NULL);
    dataSistema = localtime(&Dia);
    pMatriz ->dia = dataSistema ->tm_mday;
    pMatriz->mes = dataSistema ->tm_mon;
    pMatriz->mes = pMatriz->mes + 1;
    
    printf("\nData de impressao da Lista de Voo: (%d/0%d/2018)\n",pMatriz->dia,pMatriz->mes);
    printf("\n############################################################################\n");
    
    for(i= 0;i<24;i++){
        for(j=0;j<24;j++){
            ImprimirListaItemMatrizVoo (&(pMatriz->Matriz[i][j]));
        }
    }
}

/**
 * encontrarFaixaHorarioMaiorQtdVoo - Função responsável por encontrar faixa de horário de decolagem e previsão de pouso com maior número de voos cadastrados.
 * @param Endereço para a estrutura TipoMatriz.
 * @return Retorna 0 para indicar que ocorreu com sucesso.
 */
int encontrarFaixaHorarioMaiorQtdVoo (TipoMatriz* pMatriz){
    int i,j,qtdVoo=0,i_salva,j_salva;

    for(i= 0;i<24;i++){
        for(j=0;j<24;j++){
            if (pMatriz->Matriz[i][j].QTDVoos > qtdVoo){
              qtdVoo = pMatriz->Matriz[i][j].QTDVoos;
              i_salva = i;
              j_salva = j;
            }
        }
    }
    printf("Indices com a Lista que detem a maior quantidade de Voos ** %d **\n",qtdVoo);
    printf("Indice i (Horario_Decolagem): %d\n",i_salva);
    printf("Indice j (Horario_Pouso): %d",j_salva);
    return 0;
}
/**
 * encontrarFaixaHorarioMenorQtdVoo - Função responsável por encontrar faixa de horário de decolagem e previsão de pouso com maior número de voos cadastrados.
 * @param Endereço para a estrutura TipoMatriz.
 * @return Retorna 0 para indicar que ocorreu com sucesso.
 */
int encontrarFaixaHorarioMenorQtdVoo (TipoMatriz* pMatriz){
    int i,j,qtdVoo=1,i_salva,j_salva;

    for(i= 0;i<24;i++){
        for(j=0;j<24;j++){
            if(LEhVazia(&(pMatriz->Matriz[i][j].Lista))!= 1){
                if (pMatriz->Matriz[i][j].QTDVoos <= qtdVoo ){
                    qtdVoo = pMatriz->Matriz[i][j].QTDVoos;
                    i_salva = i;
                    j_salva = j;
                }
            }
        }
    }
    printf("Indices com a Lista que detem a menor quantidade de Voos ** %d **\n",qtdVoo);
    printf("Indice i (Horario_Decolagem): %d\n",i_salva);
    printf("Indice j (Horario_Pouso): %d",j_salva);
    return 0;
}
/**
 * encontrarListaVooAlteradaMaisRecente - Função responsável por encontrar lista de voos mais recentemente alterada.
 * @param Endereço para a estrutura TipoMatriz.
 * @return Retorna 0 para indicar que ocorreu com sucesso.
 */
int encontrarListaVooAlteradaMaisRecente (TipoMatriz* pMatriz){
    int i,j,i_salva,j_salva,horas,minutos,segundos, horas_max, minutos_max, segundos_max;

    horas_max = -1;
    minutos_max = -1;
    segundos_max = -1;
    i_salva=0;
    j_salva=0;
    for(i= 0;i<24;i++){
        for(j=0;j<24;j++){
            if(pMatriz->Matriz[i][j].horas!= -1 && pMatriz->Matriz[i][j].minutos !=-1 && pMatriz->Matriz[i][j].segundos!= -1) {
                horas = pMatriz->Matriz[i][j].horas;
                minutos = pMatriz->Matriz[i][j].minutos;
                segundos = pMatriz->Matriz[i][j].segundos;
                if(horas > horas_max){
                    horas_max = horas;
                    minutos_max = minutos;
                    segundos_max = segundos;
                    i_salva = i;
                    j_salva = j;
                } else{
                    if(horas == horas_max){
                        if(minutos > minutos_max){
                            minutos_max = minutos;
                            segundos_max = segundos;
                            i_salva = i;
                            j_salva = j;
                        } else{
                            if(minutos == minutos_max){
                                if(segundos > segundos_max){
                                    segundos_max = segundos;
                                    i_salva = i;
                                    j_salva = j;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Indices com a Lista alterada mais recentemente ** %d:%d:%d **\n",horas_max,minutos_max,segundos_max);
    printf("Indice i (Horario_Decolagem): %d\n",i_salva);
    printf("Indice j (Horario_Pouso): %d\n",j_salva);
    return 0;
}
/**
 * encontrarListaVooAlteradaMenosRecente - Função responsável por encontrar lista de voos menos recentemente alterada.
 * @param Endereço para a estrutura TipoMatriz.
 * @return Retorna 0 para indicar que ocorreu com sucesso.
 */
int encontrarListaVooAlteradaMenosRecente (TipoMatriz* pMatriz){
    int i,j,i_salva,j_salva,horas,minutos,segundos, horas_min, minutos_min, segundos_min;

    horas_min = 99;
    minutos_min = 99;
    segundos_min = 99;
    i_salva=0;
    j_salva=0;
    
    for(i= 0;i<24;i++){
        for(j=0;j<24;j++){
            if(pMatriz->Matriz[i][j].horas!= -1 && pMatriz->Matriz[i][j].minutos !=-1 && pMatriz->Matriz[i][j].segundos!= -1){
                horas = pMatriz->Matriz[i][j].horas;
                minutos = pMatriz->Matriz[i][j].minutos;
                segundos = pMatriz->Matriz[i][j].segundos;
                if(horas < horas_min){
                    horas_min = horas;
                    minutos_min = minutos;
                    segundos_min = segundos;
                    i_salva = i;
                    j_salva = j;
                } else{
                    if(horas == horas_min){
                        if(minutos < minutos_min){
                            minutos_min = minutos;
                            segundos_min = segundos;
                            i_salva = i;
                            j_salva = j;
                        } else{
                            if(minutos == minutos_min){
                                if(segundos < segundos_min){
                                    segundos_min = segundos;
                                    i_salva = i;
                                    j_salva = j;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Indices com a Lista alterada menos recentemente ** %d:%d:%d **\n",horas_min,minutos_min,segundos_min);
    printf("Indice i (Horario_Decolagem): %d\n",i_salva);
    printf("Indice j (Horario_Pouso): %d",j_salva);
    return 0;
}
/**
 * verificarseMatrizEhEsparca - Função responsável por verificar se a matriz é esparça,
 * verificando se a quantidade de voos preenchidos é o dobro do número de posições de voos não cadsatrados na matriz, 
 * @param Endereço para a estrutura TipoMatriz.
 * @return Retorna 0 para indicar que ocorreu com sucesso.
 */
int verificarseMatrizEhEsparca(TipoMatriz* pMatriz){
    int i, j,qtdListaVazia =0,qtdListaNaoVazia=0;

    for(i=0;i<24;i++){
        for(j=0;j<24;j++){
            if(LEhVazia(&(pMatriz->Matriz[i][j].Lista))){
                qtdListaVazia++;
            }else{
                qtdListaNaoVazia++;
            }
        }
    }
    if(qtdListaNaoVazia <= (2*qtdListaVazia)){
        printf("\n**Lista eh esparca**\n");
    }else{
        printf("\n**Lista nao eh esparca**\n");
       
    }
    return 0;
}




 TipoMatriz* bubbleSort(TipoMatriz* VetorMatriz, int n){
    int i, j;
    TipoMatriz aux;

    for( i = 0; i < n-1 ; i++ ){
        for( j = 1; j < n-i ; j++ ){
            if ( VetorMatriz[j].ChaveIdentificacao< VetorMatriz[j-1].ChaveIdentificacao){
                aux = VetorMatriz[j];
                VetorMatriz[j] = VetorMatriz[j-1];
                VetorMatriz[j-1] = aux;
               
            }
          
        }
    }    
    return VetorMatriz;
    //imprimirListaDePalavras(&list);
}
/*
TListaPalavras selectSort(TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    int i, j, min;
    TPalavra troca;
    TPalavra *v = getPalavraDeListaDePalavras(&list);
    for (i = INICIO_VETOR; i < n - 1; i++){
        min = i;
        for (j = i + 1 ; j < n; j++){
            if ( strcmp(getConteudoPalavra(&v[j]), getConteudoPalavra(&v[min])) < 0)
                min = j;
            *qtd_comparacoes += 1;
        }
        troca = v[min];
        v[min] = v[i];
        v[i] = troca;
        *qtd_movimentacoes += 3;
    }
    return list;
    //imprimirListaDePalavras(&list);
}

TListaPalavras insertSort (TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    int i,j;
    TPalavra troca;
    TPalavra *v = getPalavraDeListaDePalavras(&list);
    for (i = 1 + INICIO_VETOR; i < n; i++)
    {
        troca = v[i];
        j = i - 1;
        while ( ( j >= INICIO_VETOR ) && ( strcmp(getConteudoPalavra(&troca), getConteudoPalavra(&v[j])) < 0 ) ){
            v[j + 1] = v[j];
            j--;
            *qtd_movimentacoes += 1;
            *qtd_comparacoes += 1;
        }
        v[j + 1] = troca;
        *qtd_movimentacoes += 2;
        *qtd_comparacoes += 1;
    }    
    return list;
    //imprimirListaDePalavras(&list);
}

TListaPalavras shellSort (TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    int i, j;
    int h = 1;
    TPalavra troca;
    TPalavra *A = getPalavraDeListaDePalavras(&list);
    do{
        h = h*3 + 1; 
    }while (h < n);
    do{
        h = h/3;
        for( i = h + INICIO_VETOR ; i < n ; i++ ){
            troca = A[i]; 
            j = i;            
            while (strcmp(getConteudoPalavra(&A[j - h]), getConteudoPalavra(&troca)) > 0){
                
                A[j] = A[j - h]; 
                j -= h;
                *qtd_movimentacoes += 1;
                *qtd_comparacoes += 1;
                if (j < h) 
                    break;
            }
            A[j] = troca;
            *qtd_movimentacoes += 2;
            *qtd_comparacoes += 1;
        }
    } while (h != 1);
    return list;
    //imprimirListaDePalavras(&list);
}

TListaPalavras quickSort(TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    Ordena(INICIO_VETOR, n-1, getPalavraDeListaDePalavras(&list), qtd_movimentacoes, qtd_comparacoes);
    return list;
    //imprimirListaDePalavras(&list);
}

TListaPalavras heapSort(TListaPalavras list, int n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){ 
    int Esq, Dir;
    TPalavra troca;
    TPalavra *A = getPalavraDeListaDePalavras(&list);
    Constroi(A, &n, qtd_movimentacoes, qtd_comparacoes);  constroi o heap 
    Esq = INICIO_VETOR; Dir = n-1;
    while (Dir > INICIO_VETOR){ /* ordena o vetor 
        troca = A[INICIO_VETOR]; 
        A[INICIO_VETOR] = A[Dir]; 
        A[Dir] = troca;
        *qtd_movimentacoes += 3;
        Dir--;
        Refaz(Esq, Dir, A, qtd_movimentacoes, qtd_comparacoes);
    }
    return list;
    //imprimirListaDePalavras(&list);
}

void Constroi(TPalavra *A, int *n, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, *n, A, qtd_movimentacoes, qtd_comparacoes);
    }
}

void Refaz(int Esq, int Dir, TPalavra *A, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    int j = Esq * 2;
    TPalavra troca = A[Esq];
    while (j <= Dir){
        if ((j < Dir) && (strcmp(getConteudoPalavra(&A[j]), getConteudoPalavra(&A[j+1])) < 0))
            j++;
        *qtd_comparacoes += 2; // Devido às comparações do "if" acima e do "if" abaixo.
        if (strcmp(getConteudoPalavra(&troca), getConteudoPalavra(&A[j])) >= 0) 
            break;
        A[Esq] = A[j];
        *qtd_movimentacoes += 1;
        Esq = j; 
        j = Esq * 2 ;
    }
    A[Esq] = troca;
    *qtd_movimentacoes += 2;
}

void Ordena(int Esq, int Dir, TPalavra *A, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    int i,j;
    Particao(Esq, Dir, &i, &j, A, qtd_movimentacoes, qtd_comparacoes);
    if (Esq < j) 
        Ordena(Esq, j, A, qtd_movimentacoes, qtd_comparacoes);
    if (i < Dir) 
        Ordena(i, Dir, A, qtd_movimentacoes, qtd_comparacoes);
}

void Particao(int Esq, int Dir, int *i, int *j, TPalavra *A, unsigned long int *qtd_movimentacoes, unsigned long int *qtd_comparacoes){
    TPalavra pivo, troca;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x 
    do{
        while (strcmp(getConteudoPalavra(&pivo), getConteudoPalavra(&A[*i])) > 0){
            (*i)++;
            *qtd_comparacoes += 1;
        }
        while (strcmp(getConteudoPalavra(&pivo), getConteudoPalavra(&A[*j])) < 0){
            (*j)--;
            *qtd_comparacoes += 1;
        }
        *qtd_comparacoes += 2; // devido à última comparação feita pelos dois "whiles"
        if (*i <= *j){
            troca = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = troca;
            *qtd_movimentacoes += 3;
            (*i)++; 
            (*j)--;
            
        }
    } while (*i <= *j);
}
*/ 
 
 int intN(int n) { 
    return rand() % n; 
 }
 
 char *randomStringLetras(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = alphabet[intN(strlen(alphabet))];
  }
  rstr[len] = '\0';
  return rstr;
}

char *randomStringHoraP(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = hora_p[intN(strlen(hora_p))];
  }
  rstr[len] = '\0';
  return rstr;
}

char *randomStringHoraQ1(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = hora_q1[intN(strlen(hora_q1))];
  }
  rstr[len] = '\0';
  return rstr;
}

char *randomStringHoraQ2(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = hora_q2[intN(strlen(hora_q2))];
  }
  rstr[len] = '\0';
  return rstr;
}

char *randomStringHoraR(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = hora_r[intN(strlen(hora_r))];
  }
  rstr[len] = '\0';
  return rstr;
}

char *randomStringHoraS(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = hora_s[intN(strlen(hora_s))];
  }
  rstr[len] = '\0';
  return rstr;
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        rand();
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + (rand()/((RAND_MAX/(n - i)) + 1));
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
