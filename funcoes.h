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
    E_EULER,
    SEN_H
};

/*Responsavel por transferir os dados pegos da entrada do usuario para a struct responsavel pelo armazenamento com seus tipos corretos*/
void Converte_dados(char **, ENTRADA_USUARIO **, int *);

/*Responsavel por calcular o Cosseno*/
double Cosseno(double, int);

/*Responsavel pelo calculo exponencial de Euler*/
double Euler(double, int);

/*Responsavel por exibir o resultado das funcoes que estao presentes no programa*/
void Exibe_Resultados_Funcoes(ENTRADA_USUARIO **, int *);

/*Responsavel pelo calculo do fatorial*/
int Fat(int);

/*Responsavel pelo calculo do Logaritmo Natural*/
double Logaritmo_Natural(double, int);

/*Responsavel pela alocacao da entrada do usuario*/
void Obter_entrada_usuario(char **, int *);

/*Responsavel pelo calculo da raiz*/
double Raiz(double, int, int);

/*Responsavel pelo calculo do seno*/
double Seno(double, int);

/*Responsavel pelo calculo do seno Hiperbolico*/
double Sen_Hiperbolico(double, int);

/*Responsavel por corrigir o valor para imprimir corretamente sem o arredondamento da funcao printf()*/
double Corrige_arredondamento(double, int);