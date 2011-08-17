/*
    Structs e protótipos
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Lista encadeada arquivo
typedef struct s_file{
    long posicao;
    struct s_file *proximo;            
}celFile;
typedef celFile *celulaArquivo;

// Estrutura de arvore CHAR
typedef struct char_tree{
    char *string;
    int altura;
    celulaArquivo inicio;
    struct char_tree *left,*right;       
}celChar;
typedef celChar *treeChar;

// Arvore INT
typedef struct int_tree{
    long int valorInteiro;
    int altura;
    celulaArquivo inicio;
    struct int_tree *left,*right;       
}celInt;
typedef celInt *treeInt;

// Arvore FLOAT
typedef struct float_tree{
    double valorFloat;
    int altura;
    celulaArquivo inicio;
    struct float_tree *left,*right;       
}celFloat;
typedef celFloat *treeFloat;

// Lista encadeada Coluna 
typedef struct s_cel{            
    char *nomeColuna;        
    char *tipo;
    struct s_cel *proximo;
    void *pArvore;
}cel;
typedef cel *celulaColuna;

// Lista encadeada de busca
typedef struct search_cel{                    
    char *dado;        
    char *tipo;
    celulaArquivo inicio;
    struct search_cel *proximo;    
}scel;
typedef scel *searchCelula;

// Protótipo
void abrirArquivo(FILE **fp);
celulaColuna lerPrimeiraLinha(FILE *fp);
celulaColuna alocarCelula(char *nomeColuna,char *tipo);
void inserirCelula(celulaColuna *inicio,char nomeColuna[],char tipo[]);
void inserirArvore(celulaColuna *temp,char *dado,long posicao);
void fecharArquivo(FILE **fp);
void indexarArquivo(celulaColuna *inicio,FILE *fp); 
void verificarArvore(celulaColuna inicio);
void percorrerFloat(treeFloat raiz);
void percorrerChar(treeChar raiz);
void percorrerInt(treeInt raiz);
void excecaoFloat(char *dado);
void getDado(char *dado,char *linha);
int verificarLinha(char linha[]);
void excecaoInteiro(char *dado);
celulaArquivo verificarMatch(celulaColuna inicio,searchCelula begin);
void binSearchChar(treeChar raiz,char *dado,celulaArquivo *nova);
void binSearchInt(treeInt raiz,long int dado,celulaArquivo *nova);
void binSearchFloat(treeFloat raiz,double dado,celulaArquivo *nova);
void apresentarHit(celulaArquivo inicio,FILE *fp);

// Indexação
treeChar inserirArvoreChar(treeChar pArvore,char *dado,long posicao);
treeInt inserirArvoreInt(treeInt pArvore,long int dado,long posicao);
treeFloat inserirArvoreFloat(treeFloat pArvore,double dado,long posicao);
treeChar alocarRaizChar(char *dado);
treeInt alocarRaizInteiro(long int dado);
treeFloat alocarRaizFloat(double dado);
void inserirPosicao(celulaArquivo *inicio,long posicao);
int alturaArvoreChar(treeChar pArvore);
int alturaArvoreInt(treeInt pArvore);
int alturaArvoreFloat(treeFloat pArvore);
int fatorBalanceamento(int leftHand,int rightHand);

treeChar rodaUmDireitaChar(treeChar raiz) ;
treeChar rodaUmEsquerdaChar(treeChar raiz);
treeChar rodaDuploEsquerdaChar(treeChar raizTmp);
treeChar rodaDuploDireitaChar(treeChar raizTmp);

treeInt rodaUmDireitaInt(treeInt raiz) ;
treeInt rodaUmEsquerdaInt(treeInt raiz);
treeInt rodaDuploEsquerdaInt(treeInt raizTmp);
treeInt rodaDuploDireitaInt(treeInt raizTmp);

treeFloat rodaUmDireitaFloat(treeFloat raiz) ;
treeFloat rodaUmEsquerdaFloat(treeFloat raiz);
treeFloat rodaDuploEsquerdaFloat(treeFloat raizTmp);
treeFloat rodaDuploDireitaFloat(treeFloat raizTmp);

// Busca
void abrirBusca(FILE *fp,celulaColuna inicio);
void inserirSearchcel(searchCelula *search,char *dado,char *tipo);
searchCelula alocarSearch(char *dado,char *tipo);
