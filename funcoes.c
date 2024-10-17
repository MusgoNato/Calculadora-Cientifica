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

        /*Precisao das cadas decimais*/
        substring = strtok(NULL, " ");
        input[i]->precisao = atoi(substring);

        /*Numero do n para raiz*/
        substring = strtok(NULL, " ");
        input[i]->n_raiz = atoi(substring);
    }
    
}

double Corrige_arredondamento(double x, int precisao)
{
    double aux;
    double valor_truncado;

    /*Calculo para determinar o fator 10^precisao*/
    aux = pow(10, precisao);

    /*Trunca, depois devolve ao lugar, mantendo a precisao desejada sem arredondamentos*/
    valor_truncado = trunc(x * aux)/aux;

    return valor_truncado;

}

/*Calculo do cosseno*/
double Cosseno(double x, int precisao)
{
    int n = 0;
    double termo = 1;
    double resultado_cosseno = 1;

    x = x * M_PI/180;

    /*Loop para o calculo do cosseo, caso o valor absoluto do termo ultrapasse a quantidade de precisao desejada, sai do loop*/
    while(fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = -termo * x * x/((2 * n - 1) * 2 * n);
        resultado_cosseno += termo;
    }

    return resultado_cosseno;
}

/*Exibe o resultado das funcoes a serem chamadas*/
void Exibe_Resultados_Funcoes(ENTRADA_USUARIO **input, int *cont_linhas)
{
    int i = 0;
    double valor_sem_arredondamento = 0.0;

    /*Loop para chamar as funcoes de acordo com o valor passado pela entrada padrao e apresentar seu resultado*/
    while(i < *cont_linhas)
    {
        switch(input[i]->id_funcao)
        {
            case SENO:
            {
                /*A chamada da funcao poderia ter sido feita dentro do printf. Porem, por organizacao existe a variavel 'valor_sem_arredondamento'
                para guardar o valor retornado pela funcao que corrige o valor para ser usado pela funcao printf()*/
                valor_sem_arredondamento = Corrige_arredondamento(Seno(input[i]->x, input[i]->precisao), input[i]->precisao);
                printf("SENO: %.*f\n", input[i]->precisao, valor_sem_arredondamento);
                break;
            }

            case COS:
            {
                valor_sem_arredondamento = Corrige_arredondamento(Cosseno(input[i]->x, input[i]->precisao), input[i]->precisao);
                printf("COSSENO: %.*f\n", input[i]->precisao, valor_sem_arredondamento);
                break;
            }

            case LOGARITMO_NATURAL:
            {
                valor_sem_arredondamento = Corrige_arredondamento(Logaritmo_Natural(input[i]->x, input[i]->precisao), input[i]->precisao);
                printf("Logaritmo Natural: %.*f\n", input[i]->precisao, valor_sem_arredondamento);
                break;
            }

            case RAIZ:
            {
                printf("Raiz antes da funcao: %.*f\n", input[i]->precisao, Raiz(input[i]->x, input[i]->n_raiz, input[i]->precisao));
                valor_sem_arredondamento = Corrige_arredondamento(Raiz(input[i]->x, input[i]->n_raiz, input[i]->precisao), input[i]->precisao);
                printf("Raiz: %.*f\n", input[i]->precisao, valor_sem_arredondamento);
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

/*Calculo do Logaritmo Natural*/
double Logaritmo_Natural(double x, int precisao)
{
    int n = 1;
    double termos = 0.0;   
    double resultado = 0.0;

    /*Transformando o valor de x, devido a limitacao de x de -1 e 1. Pra evitar a criacao de mais uma variavel,
    somente foi feita a atribuicao para o proprio x, pois seguindo a formula seria y = (x - 1)/(x + 1)*/
    x = (x - 1)/(x + 1);
    resultado = x;

    /*Calculo do Logaritmo Natural*/
    do
    {
        n++;
        termos = pow(x, 2 * n - 1)/(2 * n - 1);
        resultado += termos;    

    /*Verifico se o valor absoluto do termo que foi calculado ultrapassa o valor da precisao desejada,
    obtendo o calculo final correto do Logaritmo*/    
    }while(fabs(termos) > pow(10, -precisao));

    return 2 * resultado;
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

}

/*Calculo da Raiz*/
double Raiz(double x, int n_raiz, int precisao)
{
    x = x;
    n_raiz = n_raiz;
    precisao = precisao;
    return 0.0;
}


/*Calculo do seno*/
double Seno(double x, int precisao)
{
    int n = 0;
    double resultado_seno = 0.0;
    double termo = 0.0;

    x = x * M_PI/180;

    /*Calculo*/
    while(n < precisao)
    {
        termo = pow((-1), n) * pow(x, (2 * n + 1))/Fat(2 * n + 1);
        resultado_seno += termo;
        n++;
    }

    return resultado_seno;
}