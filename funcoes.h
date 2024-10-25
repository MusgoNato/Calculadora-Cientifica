/*Constantes*/
# define TAM_LINHA 10000

/*Registro responsavel pelo armazenamento dos dados do usuario*/
typedef struct _entrada_user
{
    int id_funcao;
    double x;
    int precisao;
    int n_raiz;
}ENTRADA_USUARIO;

/*Registro responsavel pela enumeracao das funcoes*/
enum
{
    SENO = 1,
    COS,
    LOGARITMO_NATURAL,
    RAIZ,
    EXP_EULER,
    SEN_H
};

/*Responsavel por transferir os dados pegos da entrada do usuario para a struct responsavel pelo armazenamento com seus tipos corretos
Parametros:
1 : Um tipo (char **), referente a linha de entrada do usuario 
2 : Vetor de ponteiros para structs, com o objetivo de guardar as linhas lidas do usuario, armazenando cada valor com seu respectivo campo da struct
3 : Um tipo (int *), responsavel por armazenar a contagem da quantidade de linhas lidas do usuario.
Retorno:
Nenhum.*/
void Converte_dados(char **, ENTRADA_USUARIO **, int *);

/*Responsavel por calcular o Cosseno
Parametros:
1 : Um tipo (double), referente ao x passado em graus.
2 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor do calculo da funcao*/
double Cosseno(double, int);

/*Responsavel pelo calculo exponencial de Euler
Parametros:
1 : Um tipo (double), referente ao x passado em graus.
2 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor do calculo da funcao*/
double Euler(double, int);

/*Responsavel por exibir o resultado das funcoes que estao presentes no programa
1 : Vetor de ponteiros para structs, referente aos valores guardados com seus respectivos tipos pela funcao Converte_dados().
2 : Um tipo (int *), responsavel por armazenar a contagem da quantidade de linhas lidas do usuario.
Retorno:
Nenhum*/
void Exibe_Resultados_Funcoes(ENTRADA_USUARIO **, int *);

/*Responsavel pelo calculo do fatorial de um numero n
1 : Um tipo (int), referente ao fatorial de um numero qualquer a ser calculado.
Retorno:
Valor do tipo (int), referente ao valor do calculo da funcao*/
int Fat(int);

/*Responsavel pelo calculo do Logaritmo Natural
Parametros:
1 : Um tipo (double), referente ao x passado em graus.
2 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor do calculo da funcao
*/
double Logaritmo_Natural(double, int);

/*Responsavel pela alocacao da entrada do usuario
Parametros:
1 : Um tipo (char **), referente a linha lida da entrada do usuario
2 : Um tipo (int *), referente a quantidade de linhas que serao lidas da entrada
Retorno:
Nenhum*/
void Obter_entrada_usuario(char **, int *);

/*Responsavel pelo calculo da raiz
Parametros:
1 : Um tipo (double), referente ao valor de x.
2 : Um tipo (int), referente ao valor da n da raiz.
3 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor do calculo da funcao.
*/
double Raiz(double, int, int);

/*Responsavel pelo calculo do seno
Parametros:
1 : Um tipo (double), referente ao x passado em graus.
2 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor do calculo da funcao.
*/
double Seno(double, int);

/*Responsavel pelo calculo do seno Hiperbolico
Parametros:
1 : Um tipo (double), referente ao x passado em graus.
2 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor do calculo da funcao.
*/
double Sen_Hiperbolico(double, int);

/*Responsavel por corrigir o valor para imprimir corretamente sem o arredondamento da funcao printf(). 
O que acontece na funcao eh que adiciona zeros a direita do valor, tendo em vista isso, ao imprimir pela funcao printf(),
como tem zeros a direita, nao ocorre o arredondamento, pois nao tem valores a serem arredondados, somente zeros. Isso evita o comportamento do printf()
de arredondar numeros usando o formato %f.
Parametros:
1 : Um tipo (double), referente ao valor de retorno de algum calculo das funcoes do programa. 
2 : Um tipo (int), referente as casas decimais de precisao.
Retorno:
Valor do tipo (double), referente ao valor corrigido dos calculos para nao apresentar arredondamentos pelo printf().
*/
double Corrige_arredondamento(double, int);