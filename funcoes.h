# define TAM_LINHA 10000

typedef struct _entrada_user
{
    int id_funcao;
    double x;
    double precisao;
    int n_raiz;
}ENTRADA_USUARIO;



/*Calcula seno*/
double seno(double, int precisao);

/*Calcula Fatorial*/
int fat(int);

/*Alocacao da entrada do usuario*/
void Obter_entrada_usuario(char **, int *);

/*Transfere os dados pegos da entrada do usuario para a struct responsavel pelo armazenamento com seus tipos corretos*/
void Converte_dados(char **, ENTRADA_USUARIO **, int *);