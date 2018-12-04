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
        printf("# [a] Ativar modo automatico                                               #\n");
        printf("# [n] Sair                                                                 #\n");
        printf("############################################################################\n");
        printf("# Escolha: ");
        getchar();
        scanf("%c", &escolha);
        printf("\n");

        switch (escolha) {
            case 'a':
                printf("############################################################################\n");
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
                printf("#                                                                          #\n");
                printf("# [0] Sair   [1] Menu principal                                            #\n");
                printf("# ");
                scanf("%d", &desvio);
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