# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <windows.h>
# include "funcoes.h"

/*Calculo do seno()*/
double seno(double x, int precisao)
{
    int n = 0;
    double resultado_seno = 0.0;
    double termo = 0.0;

    /*Conversao para radiano*/
    x = x * M_PI/180;

    /*Calculo*/
    while(n < precisao)
    {
        termo = pow((-1), n) * pow(x, (2 * n + 1))/fat(2 * n + 1);
        resultado_seno += termo;
        n++;
    }

    return resultado_seno;
}

/*Funcao recursiva para calculo do fatorial*/
int fat(int valor_num)
{
    if(valor_num == 0 || valor_num == 1)
    {
        return 1;
    }
    else
    {
        return valor_num * fat(valor_num - 1);
    }
}

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
    printf("Contador Obter: %d\n", *cont_linhas);

}

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

    /*Converte meus dados*/
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

        /*Precisao das cadas decimais*/
        substring = strtok(NULL, " ");
        input[i]->precisao = atof(substring);

        /*Numero do n para raiz*/
        substring = strtok(NULL, " ");
        input[i]->n_raiz = atoi(substring);

    }

    /*Impressao caso for preciso depois*/
    for(i = 0; i < *cont_linhas; i++)
    {
        printf("ID: |%d| X: |%f| PRECISAO: |%f| N_RAIZ: |%d|\n", input[i]->id_funcao, input[i]->x, input[i]->precisao, input[i]->n_raiz);
    }
    
}