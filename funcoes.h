# define TAM_LINHA 10000

typedef struct _entrada_user
{
    int id_funcao;
    double x;
    int precisao;
    int n_raiz;
}ENTRADA_USUARIO;

enum
{
    SENO = 1,
    COS,
    LOGARITMO_NATURAL,
    RAIZ,
    E_EULER,
    SEN_H
};

/*Calcula Cosseno*/
double Cosseno(double, int);

/*Transfere os dados pegos da entrada do usuario para a struct responsavel pelo armazenamento com seus tipos corretos*/
void Converte_dados(char **, ENTRADA_USUARIO **, int *);

/*Rsponsavel por exibiro resultado das funcoes que estao presentes no programa*/
void Exibe_Resultados_Funcoes(ENTRADA_USUARIO **, int *);

/*Calcula Fatorial*/
int Fat(int);

double Logaritmo_Natural(double, int);

/*Alocacao da entrada do usuario*/
void Obter_entrada_usuario(char **, int *);

/*Calcula seno*/
double Seno(double, int);