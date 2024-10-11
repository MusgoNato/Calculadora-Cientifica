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
# include <math.h>
# include "funcoes.h"

/*PENDENTE:
VERIFICAR A IMPRESSAO DA PRECISAO E SE O CALCULO ESTA CORRETO MESMO!*/

int main(int argc, char *argv[])
{
    double x;
    int precisao;

    argc = argc;
    argv = argv;

    printf("Insira o x: ");
    scanf("%lf", &x);
    printf("\nInsira a precisao: ");
    scanf("%d", &precisao);

    printf("MEU ------- : %f\n", seno(x, precisao));
    printf("MATH.H ---- : %f", sin(x));

    return 0;
}