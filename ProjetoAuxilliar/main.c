/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: arthur
 *
 * Created on 2 de Dezembro de 2018, 00:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i = 0;
    int numPalavras = 0;
    char* palavras[36500];
    char line[50],arq[50];
    
    scanf("%s",arq);

    FILE *arquivo;
    arquivo = fopen(arq, "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fscanf(arquivo,"%s",line) != NULL )
    {
        //Adiciona cada palavra no vetor
        *palavras = strdup(line);


        //Conta a quantidade de palavras
        numPalavras++;
    }

 
        printf("%s", *palavras); //Exibi as palavras que estao no vetor.

    printf("\n\n");

    fclose(arquivo);
    return (EXIT_SUCCESS);
}

