/*Programa: Calculadora Cientifica.
Descrição: A calculadora cientifica eh capaz de realizar algumas funcoes especificas. Tais como seno, cosseno, logaritmo natural, raiz,
exponecial de euler e o seno hiperbolico. O usuario entrara por cada linha com 3 valores, o primeiro valor sendo o numero da funcao, o segundo
o valor em graus do x e o terceiro em relacao a precisao desejada. Somente para a funcao raiz eh dado um quarto valor, que corresponde ao n elevado da raiz.
Caso o usuario deseje encerrar a leitura dos valores, o valor 0 deve ser inserido em uma nova linha. 

Programador: Hugo Josue Lema Das Neves 
RGM: 47159
Data da ultima modificação: 24/10/2024
*/


/*
Compilacao : gcc main.c -o main.exe funcoes.c -Wall -pedantic -Wextra -Werror
Execucao: main.exe
*/

# include <stdlib.h> /*malloc()*/
# include "funcoes.h" /*Converte_dados(), Exibe_Resultados_Funcoes(), Obter_entrada_usuario(), TAM_LINHA*/

int main(int argc, char *argv[])
{
    ENTRADA_USUARIO **input;
    char **linhas_entrada;
    int cont_linhas = 0;

    /*Alocacao inicial para os valores*/
    linhas_entrada = (char **)malloc(TAM_LINHA * sizeof(char *));

    argc = argc;
    argv = argv;
    
    /*Chamada da funcao para pegar os valores do usuario*/
    Obter_entrada_usuario(linhas_entrada, &cont_linhas);

    /*Aloco espaco suficiente para meu array de ponteiros, de acordo com as linhas lidas*/
    input = (ENTRADA_USUARIO **)malloc(cont_linhas * sizeof(ENTRADA_USUARIO *));

    /*Chamada da funcao para converter os dados de string para os tipos correspondentes*/
    Converte_dados(linhas_entrada, input, &cont_linhas);

    /*Chamada da funcao para exibir os resultados das funcoes*/
    Exibe_Resultados_Funcoes(input, &cont_linhas);

    return 0;
}