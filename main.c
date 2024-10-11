/*
    Programa: Calculadora Cientifica.
    Descrição: [...]
    Programador: [Hugo Josue Lema Das Neves] 
    RGM: [47159] 
    Data da última modificação: 09/10/2024
*/


/*
    Compilacao : gcc main.c -o main.exe funcoes.c -Wall -pedantic -Wextra -Werror
    Execucao: main.exe
*/

# include <stdio.h>
# include <stdlib.h>
# include "funcoes.h"

/*PENDENTE:
VERIFICAR A IMPRESSAO DA PRECISAO E SE O CALCULO ESTA CORRETO MESMO!*/

int main(int argc, char *argv[])
{
    ENTRADA_USUARIO **input;
    int i = 0;
    int cont_valores = 0;

    argc = argc;
    argv = argv;


    /*Alocacao para meu vetor de ponteiros*/
    input = (ENTRADA_USUARIO **)malloc(sizeof(ENTRADA_USUARIO *));

    printf("Insira os valores\n");
    while(1)
    {
        /*Leitura da entrada padrao*/
        fscanf(stdin, "%d %lf %lf %lf", &input[i]->id_funcao, &input[i]->x, &input[i]->precisao, &input[i]->n_raiz);
        if(input[i]->id_funcao == 0)
        {
            break;
        }
        i++;
        cont_valores++;

        /*Alocacao para cada ponteiro*/
        input[i] = (ENTRADA_USUARIO *)malloc(sizeof(ENTRADA_USUARIO));
    }
    
    /*Impressao*/
    for(i = 0; i < cont_valores; i++)
    {
        printf("%d linha: ID: |%d| X: |%f| PRECISAO: |%f| N_RAIZ: |%f|\n", i, input[i]->id_funcao, input[i]->x, input[i]->precisao, input[i]->n_raiz);
    }

    return 0;
}