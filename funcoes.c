# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <windows.h>
# include "funcoes.h"

/*Funcao para converter os dados de string para os tipos correspondentes*/
void Converte_dados(char **linhas_entrada, ENTRADA_USUARIO **input, int *cont_linhas)
{ 
    int i = 0;
    char string_aux[TAM_LINHA];
    char *substring;

    /*Alocacao para meus ponteiros*/
    for(i = 0; i < *cont_linhas; i++)
    {
        input[i] = (ENTRADA_USUARIO *)malloc(sizeof(ENTRADA_USUARIO));
    }

    /*Conversao dos meus dados*/
    for(i = 0; i < *cont_linhas; i++)
    {
        /*Copio minha string, devido ao strtok "destruir" minha string original*/
        strcpy(string_aux, linhas_entrada[i]);

        /*ID da Funcao*/
        substring = strtok(string_aux, " ");
        input[i]->id_funcao = atoi(substring);

        /*X em radianos*/
        substring = strtok(NULL, " ");
        input[i]->x = atof(substring);
        input[i]->x = input[i]->x * M_PI/180;

        /*Precisao das cadas decimais*/
        substring = strtok(NULL, " ");
        input[i]->precisao = atoi(substring);

        /*Numero do n para raiz*/
        substring = strtok(NULL, " ");
        input[i]->n_raiz = atoi(substring);
    }
    
}

/*Calculo do cosseno*/
double Cosseno(double x, int precisao)
{
    int n = 0;
    double termo = 1.0;
    double resultado_cosseno = 1.0;

    for(n = 1; n <= precisao; n++)
    {
        termo *= -x * x/(2 * n * (2 * n - 1));
        resultado_cosseno += termo;
    }

    return resultado_cosseno;
}

/*Exibe o resultado das funcoes a serem chamadas*/
void Exibe_Resultados_Funcoes(ENTRADA_USUARIO **input, int *cont_linhas)
{
    int i = 0;

    /*Loop para chamar as funcoes de acordo com o valor passado pela entrada padrao e apresentar seu resultado*/
    while(i < *cont_linhas)
    {
        switch(input[i]->id_funcao)
        {
            case SENO:
            {
                printf("SENO: %.*f\n", input[i]->precisao, Seno(input[i]->x, input[i]->precisao));
                break;
            }

            case COS:
            {
                printf("COSSENO: %.*f\n", input[i]->precisao, Cosseno(input[i]->x, input[i]->precisao));
                break;
            }

            case LOGARITMO_NATURAL:
            {
                printf("Logaritmo Natural: \n");
                break;
            }
        }

        i++;
    }
}

/*Funcao recursiva para calculo do fatorial*/
int Fat(int valor_num)
{
    if(valor_num == 0 || valor_num == 1)
    {
        return 1;
    }
    else
    {
        return valor_num * Fat(valor_num - 1);
    }
}

/*Calculo do Logaritmo Natural
double Logaritmo_Natura(double x, int precisao)
{
    int n = 0;

    return 0.0;
}*/

/*Funcao para alocar a entrada padrao do usuario*/
void Obter_entrada_usuario(char **linhas_entrada, int *cont_linhas)
{
    int i = 0;

    printf("Insira os valores\n");

    while(1)
    {
        /*Aloca para meu ponteiro*/
        linhas_entrada[i] = (char *)malloc(TAM_LINHA * sizeof(char));

        /*Leio a entrada ate o enter pressionado pelo usuario*/
        fgets(linhas_entrada[i], TAM_LINHA, stdin);

        /*Caso seja 0 encerra a leitura*/
        if(linhas_entrada[i][0] == '0')
        {
            break;
        } 
        i++;
        *cont_linhas += 1;
    }

}


/*Calculo do seno*/
double Seno(double x, int precisao)
{
    int n = 0;
    double resultado_seno = 0.0;
    double termo = 0.0;

    /*Calculo*/
    while(n < precisao)
    {
        termo = pow((-1), n) * pow(x, (2 * n + 1))/Fat(2 * n + 1);
        resultado_seno += termo;
        n++;
    }

    return resultado_seno;
}