# CALCULADORA CIENTÍFICA

![GitHub repo size](https://img.shields.io/github/repo-size/iuricode/README-template?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/iuricode/README-template?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/iuricode/README-template?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/iuricode/README-template?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/iuricode/README-template?style=for-the-badge)

<img src="/video-programa/video.gif" alt="Programa Rodando">

> Programa Calculadora Científica

## 💻 Pré-requisitos

Antes de começar, verifique se você atendeu aos seguintes requisitos:

- Você instalou a versão mais recente da linguagem `<C>`
- Você instalou a versão mais recente do `<GCC>`
- Link para Download <a href="https://sourceforge.net/projects/gcc-win64/" title="Download gcc-win64">
- Você tem uma máquina `<Windows / Linux / Mac>`.

## 🚀 Veja o Projeto

Siga estas etapas:

- Baixe os arquivos do repositório.
- Instale o gcc mais recente para compilar e executar o programa.
- Abra o CMD na pasta aonde foi baixado o repositório e insira os seguintes comandos para compilar e executar o código:

Compilação:

``` 
gcc main.c -o main.exe funcoes.c -Wall -pedantic -Wextra -Werror
```

Execução:

```
main.exe
```

## ℹ️ Funcionamento

Cada função apresentada na calculadora científica segue o comportamento de somas por polinômios de acordo com a série de Taylor.

Explicação de cada valor da linha
- [ID] [VALOR_DO_X] [PRECISAO_DESEJADA] [EXPOENTE_DA_RAIZ]

ID: 
* SENO -> 1
* COSSENO -> 2
* LOGARITMO_NATURAL -> 3
* RAIZ -> 4
* EXPONENCIAL DE EULER -> 5
* SENO HIPERBOLICO -> 6

VALOR_DO_X:

- Referente ao número em graus do X passado para qualquer função (O valor é corrigido para radianos pelo programa caso seja necessário).

PRECISAO_DESEJADA:

- Valor correspondente a precisão que o usuário quer que o valor seja apresentado na tela. Quanto maior a precisão, mais perto o valor impresso chegará ao valor real do cálculo.

EXPOENTE_DA_RAIZ:

- O valor EXPOENTE_DA_RAIZ somente é passado para o cálculo da função RAIZ. Porém, caso não seja passado o valor, será atribuído 1, mantendo o valor original da função.

Exemplos:

``` 
1 2 3
2 3 4
3 4 5
4 4 4 4
0
``` 

Você pode inserir quantas linhas quiser no programa, já que a alocação dinâmica presente no código permite esse comportamento, então é possível o cálculo da mesma função em linhas diferentes com valores diferentes. Para encerrar as leituras das linhas, insira em uma nova linha o ID 0.

## 🤝 Desenvolvedor
<table>
    <td align="center">
      <a href="https://github.com/MusgoNato" title="Perfil Github">
        <img src="https://avatars.githubusercontent.com/u/131496781?v=4" width="100px;" alt="Foto do Hugo"/><br>
        <sub>
          <b>Hugo Josué Lema Das Neves</b>
        </sub>
      </a>
    </td>
  </tr>
</table>