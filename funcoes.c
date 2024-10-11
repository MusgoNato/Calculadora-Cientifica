# include <stdio.h>
# include <math.h>
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