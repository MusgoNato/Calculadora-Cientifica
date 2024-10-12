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
    char **linhas_entrada;
    int cont_linhas = 0;

    /*Alocacao inicial para os valores*/
    linhas_entrada = (char **)malloc(TAM_LINHA * sizeof(char *));
    input = (ENTRADA_USUARIO **)malloc(sizeof(ENTRADA_USUARIO *));

    argc = argc;
    argv = argv;
    
    /*Chamada da funcao para pegar os valores do usuario*/
    Obter_entrada_usuario(linhas_entrada, &cont_linhas);

    /*Chamada da funcao para converter os dados de string para os tipos correspondentes*/
    Converte_dados(linhas_entrada, input, &cont_linhas);

    

    return 0;
}