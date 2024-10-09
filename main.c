/* 
Programa: Calculadora Cientifica.
Descrição: [...]
Programador: [Hugo Josue Lema Das Neves] 
RGM: [47159] 
Data da última modificação: 09/10/2024
*/

# include <stdio.h>
# include <math.h>


int main()
{
    double x;
    double seno;

    printf("Insira um numero: ");
    scanf("%lf", &x);
    x = x * (M_PI/180.0);

    seno = sin(x);
    printf("Valor seno : %f\n", seno);

    return 0;
}