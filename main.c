#include "TADMatrizVoo.h"
#include <math.h>

//int LerArquivoVoo(TipoMatriz* pMatriz, TipoVoo* pVoo,int IdentificadorVoo,int VIDRemove,int VIDProcura, int *verificador_matriz_inicializada);

int main (void){
  int IdentificadorVoo,VIDRemove,VIDProcura, desvio=1,IdentificadorPista,i,n,j,g,verificador_matriz_inicializada=0,contador=0, flag_quebra_for_externo = 0, *VIdentificador=NULL;
  char horarioDecolagem[TAM],horarioPouso[TAM], escolha,AeroportoDecolagem[TAM],AeroportoPouso[TAM],*p, *q, *r, *s;
  TipoVoo Voo, *pVoo=NULL,*VetorVoo=NULL;
  TLista Lista;
  TCelula* pCelula= NULL;
  TipoItemMatriz ItemMatriz;
  TipoMatriz Matriz,*pMatriz=NULL,*Vm =NULL,*VmCopia=NULL;
  
 
  Vm= (TipoMatriz*)malloc(36500*sizeof(TipoMatriz));
  
  VIdentificador = (int*)malloc(36500*sizeof(TipoMatriz));
  VmCopia = (TipoMatriz*)malloc(36500*sizeof(TipoMatriz));
  
  VetorVoo = (TipoVoo*)malloc(10*sizeof(TipoVoo));
  
  srand(time(NULL));  
  
  for(i =0;i<36500;i++){
    VIdentificador[i] = i;
  }
  
  shuffle(VIdentificador,36500);
  
  for(i=0 ; i<365;i++){
      InicializarMatriz (&Vm[i]);
      InicializarMatriz (&VmCopia[i]);
      Vm[i].ChaveIdentificacao = VIdentificador[i];
      VmCopia[i] = Vm[i];
  }
  for(i=0;i<73;i++){
        for(j=0;j<10;j++){
            p = randomStringHoraP(1);
            q = randomStringHoraQ1(1);
            r = randomStringHoraR(1);
            s = randomStringHoraS(1);
            if(strcmp(p, "0") != 0){
               horarioDecolagem[0] = *p;
            } else{
               horarioDecolagem[0] = '0';  
            }
            if(strcmp(p, "2") == 0 && strcmp(q, "3") > 0)
            {
               q = randomStringHoraQ2(1);
               horarioDecolagem[1] = *q;
            }
            else
            {
               horarioDecolagem[1] = *q;
            }
            horarioDecolagem[2] = ':';
           if(strcmp(r, "0") != 0){
                horarioDecolagem[3] = *r;
            } else{
            horarioDecolagem[3] = '0';
            }
            horarioDecolagem[4] = *s;
            setH_decolagem(&VetorVoo[j],horarioDecolagem);
            free(p);free(q);free(r);free(s);  
            p = randomStringHoraP(1);
            q = randomStringHoraQ1(1);
            r = randomStringHoraR(1);
            s = randomStringHoraS(1);
            if(strcmp(p, "0") != 0)
            {
                horarioPouso[0] = *p;
            } else{
                horarioPouso[0] = '0';
            }
            if(strcmp(p, "2") == 0 && strcmp(q, "3") > 0)
            {
               q = randomStringHoraQ2(1);
               horarioPouso[1] = *q;
            }
            else
            {
               horarioPouso[1] = *q;
            }
            horarioPouso[2] = ':';
             if(strcmp(r, "0") != 0){
                horarioPouso[3] = *r;
            } else{
                horarioPouso[3] = '0';
             }
            horarioPouso[4] = *s;
            setH_pouso(&VetorVoo[j],horarioPouso);  
            free(p);free(q);free(r);free(s);
            p = randomStringLetras(3);                        
            setAeroporto_Decolagem(&VetorVoo[j],p);
            free(p);
            p = randomStringLetras(3);                        
            setAeroporto_Pouso(&VetorVoo[j],p);
            free(p);
            n = 1 + rand()%19;
            setIdentificadorPistas_Decolagem(&VetorVoo[j],n);
            getIdentificador_voo (&VetorVoo[j], IdentificadorVoo);                
            setInsereVooMatriz (&Vm[i],&VetorVoo[j]);
        }
    }
  printf("Vetor desordenado: ");
  for(i=0 ; i<10;i++){
       printf(" %d",VmCopia[i].ChaveIdentificacao);
   }
  printf("\n\n\n");
  getchar();
  printf("Vetor ordenado: ");
  bubbleSort(VmCopia,10);
   for(i=0 ; i<10;i++){
      
       printf(" %d",VmCopia[i].ChaveIdentificacao);
    }
  getchar();
  do {
    #ifdef linux
      system("clear");
    #elif defined WIN32
      system("cls");
    #endif
    printf("############################################################################\n");
    printf("#                                                                          #\n");
    printf("# [0] Sair                                                                 #\n");
    printf("# [1] Automatico                                                           #\n");
    printf("# [2] Arquivo                                                              #\n");
    printf("#                                                                          #\n");
    printf("############################################################################\n");
    printf("# Opcao: ");
    scanf("%d",&desvio);
    printf("\n");

    if (desvio == 0) {
      desvio = -1;
    }

    if (desvio == 1) {
      while(desvio ==1){
        #ifdef linux
          system("clear");
        #elif defined WIN32
          system("cls");
        #endif
        printf("############################## Menu principal ##############################\n");
        printf("# [a] Inicializar Matriz                                                   #\n");
        printf("# [b] Inserir Voo                                                          #\n");
        printf("# [c] Remover Voo                                                          #\n");
        printf("# [d] Procurar Voo                                                         #\n");
        printf("# [e] Imprimir Voos pelo horario de decolagem e pouso                      #\n");
        printf("# [f] Imprimir Voos pelo horario de decolagem                              #\n");
        printf("# [g] Imprimir Voos pelo horario de pouso                                  #\n");
        printf("# [h] Imprimir todos os Voos                                               #\n");
        printf("# [i] Horario com maior numero de Voos                                     #\n");
        printf("# [j] Horario com menor numero de Voos                                     #\n");
        printf("# [k] Horario de Voo alterada mais recente                                 #\n");
        printf("# [l] Horario de Voo alterada menos recente                                #\n");
        printf("# [m] Verificar se numero de voo eh esparca                                #\n");
        printf("# [n] Sair                                                                 #\n");
        printf("############################################################################\n");
        printf("# Escolha: ");
        getchar();
        scanf("%c", &escolha);
        printf("\n");

        if(escolha != 'a' && escolha < 'n'){
            if(verificador_matriz_inicializada == 0){
                printf("#**A matriz nao foi inicializada!                                          #\n");
                printf("#                                                                          #\n");
                printf("# [0] Sair   [1] Menu principal                                            #\n");
                printf("# ");
                scanf("%d", &desvio);
                continue; //interrompe o fluxo de execucao e passa para a proxima interacao do while.
            }
        }
        switch (escolha) {
            case 'a':
                printf("############################################################################\n");
                if(verificador_matriz_inicializada == 0){
                    InicializarMatriz (&Matriz);
                    verificador_matriz_inicializada++;
                    printf("# Matriz inicializada com sucesso                                           #\n");
                }
                else{
                    flag_quebra_for_externo = 0;
                    for(i= 0;i<24;i++){
                        for(j=0;j<24;j++){
                            if(LEhVazia(&(Matriz.Matriz[i][j].Lista))){
                                contador++;
                            }
                            else{
                                printf("\n**A lista nao esta vazia, favor remover dados antes de inicializar**\n");
                                flag_quebra_for_externo = 1;
                                break;
                            }
                        }
                        if(flag_quebra_for_externo == 1){
                            break;
                        }
                    }
                }
                printf("#                                                                          #\n");
                printf("# [0] Sair   [1] Menu principal                                            #\n");
                printf("# ");
                scanf("%d", &desvio);
            break;
            case 'b':
                
                
                    #ifdef linux
                      system("clear");
                    #elif defined WIN32
                      system("cls");
                    #endif
                    printf("############################## Preencher Voos ##############################\n");
                    printf("#                                                                          #\n");
                    printf("#################### Insira a pista de decolagem ###########################\n");
                    printf("#                                                                          #\n");
                    printf("# Pista: ");
                    getIdentificador_voo (&Voo, IdentificadorVoo);
                    scanf("%d",&IdentificadorPista);
                    setIdentificadorPistas_Decolagem (&Voo,IdentificadorPista);
                    printf("#                                                                          #\n");
                    printf("######################## Insira o areoporto Decolagem ######################\n");
                    printf("#                                                                          #\n");
                    printf("# Digite: ");
                    scanf(" %[^\n]s",AeroportoDecolagem);
                    setAeroporto_Decolagem (&Voo,AeroportoDecolagem);
                    printf("#                                                                          #\n");
                    printf("######################## Insira o areoporto Pouso ##########################\n");
                    printf("#                                                                          #\n");
                    printf("# Digite: ");
                    scanf(" %[^\n]s",AeroportoPouso);
                    setAeroporto_Pouso (&Voo,AeroportoPouso);
                    printf("####################### Insira Horario do Voo ##############################\n");
                    printf("#                                                                          #\n");
                    printf("# Horario de decolagem HH:MM: ");
                    scanf(" %[^\n]s",horarioDecolagem);
                    setH_decolagem (&Voo,horarioDecolagem);
                    printf("#                                                                          #\n");
                    printf("# Horario do pouso HH:MM: ");
                    scanf(" %[^\n]s",horarioPouso);
                    setH_pouso (&Voo,horarioPouso);
                    printf("#                                                                          #\n");
                    printf("##################### Identificador Voo Inserido: %d ######################", getIdentificador_voo(&Voo,IdentificadorVoo));
                    printf("\n#                                                                          #\n");
                    setInsereVooMatriz (&Matriz,&Voo);
                    printf("#                                                                          #\n");
                    printf("# [0] Sair   [1] Menu principal                                            #\n");
                    printf("# ");
                    scanf("%d", &desvio);
                
                printf("####################### Itens Inseridos com sucesso! #######################\n");
            break;
            case 'c':
                do {
                    #ifdef linux
                      system("clear");
                    #elif defined WIN32
                      system("cls");
                    #endif
                    printf("############################### Remover Voo ################################\n");
                    printf("#                                                                          #\n");
                    printf("# Insira o identificador a ser removido: ");
                    scanf("%d",&VIDRemove);
                    if(setRemoverVooMatriz (&Matriz, &Voo, VIDRemove) == 1){
                        printf("\n##### Removido com sucesso #####\n");
                    }else{
                        printf("\n##### Nao existe voo com esse identificador #####\n");
                    }
                    printf("#                                                                          #\n");
                    printf("# [0] Sair   [1] Menu principal   [2] Continuar Romocoes                   #\n");
                    printf("# ");
                    scanf("%d", &desvio);
                }while(desvio == 2);
            break;
            case 'd':
                do {
                    #ifdef linux
                      system("clear");
                    #elif defined WIN32
                      system("cls");
                    #endif
                    printf("############################### Procurar Voo ###############################\n");
                    printf("#                                                                          #\n");
                    printf("# Informe o Identificador do Voo: ");
                    scanf("%d",&VIDProcura);
                    pVoo = getProcuraVooMatriz (&Matriz,&Voo,VIDProcura);
                    
                    if(pVoo != NULL){
                        printf("\n\n\n############################################################################\n");
                        printf("\n**Item Achado com Sucesso**\n");
                        printf("\n############################################################################\n");
                        printf("\nIdentificador de Voo: %d\n",pVoo->Identificador_voo);
                        printf("A pista de decolagem eh: %d\n",pVoo->IdentificadorPistas_Decolagem);
                        printf("O Aeroporto de Decolagem: %s\n",pVoo->Aeroporto_Decolagem);
                        printf("O Aeroporto De Pouso: %s\n",pVoo->Aeroporto_Pouso);
                        printf("O Horario de Decolagem eh de: %s\n",pVoo->H_decolagem);
                        printf("O Horario de Pouso eh de: %s\n",pVoo->H_pouso);
                        printf("\n#                                                                          #\n");
                    }else{
                        printf("\n\n##### Item Nao Encontrado #####\n\n");
                    }

                    printf("# [0] Sair   [1] Menu principal   [2] Continuar Busca                      #\n");
                    printf("# ");
                    scanf("%d", &desvio);
                }while(desvio == 2);
            break;
            case 'e':
                do {
                    #ifdef linux
                      system("clear");
                    #elif defined WIN32
                      system("cls");
                    #endif
                    printf("################# Imprimir Voo Horario Pouso e Decolagem ###################\n");
                    printf("#                                                                          #\n");
                    printf("# Informe o Horário de decolagem: ");
                    scanf(" %[^\n]s",horarioDecolagem);
                    setH_decolagem(&Voo,horarioDecolagem);
                    printf("# Informe o Horário de pouso: ");
                    scanf(" %[^\n]s",horarioPouso);
                    setH_pouso(&Voo,horarioPouso);
                    imprimirVooHorario_Decolagem_Pouso (&Matriz,&Voo,horarioDecolagem,horarioPouso);
                    printf("\n############################################################################\n");
                    printf("#                                                                          #\n");
                    printf("# [0] Sair   [1] Menu principal   [2] Imprimir Novamente                   #\n");
                    printf("# ");
                    scanf("%d", &desvio);
                }while(desvio == 2);
            break;
            case 'f':
                do {
                    #ifdef linux
                      system("clear");
                    #elif defined WIN32
                      system("cls");
                    #endif
                    printf("###################### Imprimir Voo Horario Decolagem ######################\n");
                    printf("#                                                                          #\n");
                    printf("#                                                                          #\n");
                    printf("# Informe o Horarário de decolagem: ");
                    scanf(" %[^\n]s",horarioDecolagem);
                    setH_decolagem(&Voo,horarioDecolagem);
                    imprimirVooHorario_Decolagem_Apenas (&Matriz,&Voo,horarioDecolagem);
                    printf("\n############################################################################\n");
                    printf("#                                                                          #\n");
                    printf("# [0] Sair   [1] Menu principal   [2] Imprimir novamente                   #\n");
                    printf("# ");
                    scanf("%d", &desvio);
                }while(desvio == 2);
            break;
            case 'g':
                do {
                  #ifdef linux
                    system("clear");
                  #elif defined WIN32
                    system("cls");
                  #endif
                  printf("##################### Imprimir Voo Horario Pouso ###########################\n");
                  printf("#                                                                          #\n");
                  printf("# Informe o Horario de pouso: ");
                  scanf(" %[^\n]s",horarioPouso);
                  setH_pouso(&Voo,horarioPouso);
                  imprimirVooHorario_Pouso_Apenas (&Matriz,&Voo,horarioPouso);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Imprimir novamente                   #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                } while(desvio == 2);
            break;
            case 'h':
                do {
                  #ifdef linux
                    system("clear");
                  #elif defined WIN32
                    system("cls");
                  #endif
                  printf("########################### Imprimir TODA Lista ############################\n");
                  printf("#                                                                          #\n");
                  imprimirTodaMatriz(&Matriz);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Imprimir novamente                   #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                }while(desvio == 2);
            break;
            case 'i':
                do {
                  #ifdef linux
                    system("clear");
                  #elif defined WIN32
                    system("cls");
                    #endif
                  printf("##################### Horario com maior numero de voos #####################\n");
                  printf("#                                                                          #\n");
                  encontrarFaixaHorarioMaiorQtdVoo (&Matriz);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Verificar novamente                  #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                } while (desvio == 2);
            break;
            case 'j':
                do {
                  #ifdef linux
                    system("clear");
                  #elif defined WIN32
                    system("cls");
                    #endif
                  printf("##################### Horario com menor numero de voos #####################\n");
                  printf("#                                                                          #\n");
                  encontrarFaixaHorarioMenorQtdVoo (&Matriz);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Verificar novamente                  #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                }while (desvio == 2);
            break;
            case 'k':
                do {
                  #ifdef linux
                    system("clear");
                  #elif defined WIN32
                    system("cls");
                  #endif
                  printf("#################### Horario com alteração mais recente ####################\n");
                  printf("#                                                                          #\n");
                  encontrarListaVooAlteradaMaisRecente (&Matriz);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Verificar novamente                  #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                } while (desvio == 2);
            break;
            case 'l':
                do {
                  #ifdef linux
                  system("clear");
                  #elif defined WIN32
                  system("cls");
                  #endif
                  printf("################### Horario com alteração mmenos recente ###################\n");
                  printf("#                                                                          #\n");
                  encontrarListaVooAlteradaMenosRecente(&Matriz);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Verificar novamente                  #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                }while (desvio == 2);
            break;
            case 'm':
                do {
                  #ifdef linux
                  system("clear");
                  #elif defined WIN32
                  system("cls");
                  #endif
                  printf("########################## Numero de Voos esparca ##########################\n");
                  printf("#                                                                          #\n");
                  verificarseMatrizEhEsparca(&Matriz);
                  printf("\n############################################################################\n");
                  printf("#                                                                          #\n");
                  printf("# [0] Sair   [1] Menu principal   [2] Verificar novamente                  #\n");
                  printf("# ");
                  scanf("%d", &desvio);
                }while (desvio == 2);
            break;
            case 'n':
                desvio = 0;
            break;
        }
      }
    }

    if (desvio == 2) {
      do {
        #ifdef linux
          system("clear");
        #elif defined WIN32
          system("cls");
        #endif
       // LerArquivoVoo(&Matriz, &Voo,IdentificadorVoo,VIDRemove,VIDProcura, &verificador_matriz_inicializada);
       
        printf("\n############################################################################\n");
        printf("#                                                                          #\n");
        printf("# [0] Sair   [1] Menu principal   [2] Verificar novamente                  #\n");
        printf("# ");
        scanf("%d", &desvio);
      } while(desvio == 2);
      if (desvio == 0) {
        desvio = -1;
      }
    }

  } while(desvio != -1);

  #ifdef linux
  system("clear");
  #elif defined WIN32
  system("cls");
  #endif
  printf("\n#############################################################################\n");
  printf("#                                                                            #\n");
  printf("#                       Obrgado pela Preferencia                             #\n");
  printf("#                                                                            #\n");
  printf("##############################################################################\n");
  return 0;
}
/*

int LerArquivoVoo(TipoMatriz* pMatriz, TipoVoo* pVoo,int IdentificadorVoo,int VIDRemove, int VIDProcura, int *verificador_matriz_inicializada){
    int numeroPalavras = 0,i=0;
    char leitura[999],opcao,horarioDecolagem[TAM],horarioPouso[TAM],arq[50],*indice=NULL;
    FILE *ptrArquivo;
    TipoVoo *pAux =NULL;
    TipoMatriz vMatriz[36500];

    scanf("%s",arq);
    ptrArquivo = fopen(arq, "r");

    if(ptrArquivo == NULL)
    {
        printf("ERRO");
    }
    else{
        printf("**Arquivo Aberto com Sucesso!**");
    }
    if(ptrArquivo)
    {
        while(fscanf(ptrArquivo, "%s", leitura)!=EOF && numeroPalavras<(365*0,2))
        {
         
            
            *indice = strdup("72");
            
            i++;
                 
        }
        for (i = 0; i < 365; i++)
        printf("%s", palavras[j]);
    }
    fclose(ptrArquivo);
    return 0;
}
*/


 //  opcao = leitura[0];
//            InicializarMatriz (pMatriz);
//            if (opcao == 'b')
//            {
//                printf("\n\n> Opcao: %s <", leitura);
//                if(fscanf(ptrArquivo, "%s", leitura))
//                {
//                    strcpy(pVoo->H_decolagem, leitura);  
//                }
//                if(fscanf(ptrArquivo, "%s", leitura))
//                {
//                    strcpy(pVoo->H_pouso, leitura);   
//                }
//                if(fscanf(ptrArquivo, "%s", leitura))
//                {
//                    strcpy(pVoo->Aeroporto_Decolagem, leitura);
//                }
//                if(fscanf(ptrArquivo, "%s", leitura))
//                {
//                    strcpy(pVoo->Aeroporto_Pouso, leitura);
//                }
//                if(fscanf(ptrArquivo, "%s", leitura))
//                {
//                    N_pista = atoi(leitura);
//                    getIdentificador_voo (pVoo, IdentificadorVoo);
//                    pVoo->IdentificadorPistas_Decolagem = N_pista;
//                }
//                tempo = clock();
//                while(clock() - tempo <2000){
//                }
//                setInsereVooMatriz (pMatriz, pVoo);
//            }