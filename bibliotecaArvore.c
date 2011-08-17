/*
    Biblioteca de alocacao de celulas
    e arvores
*/
#include "prototipos.h"

/*
  Inserir celula na lista encadeada de colunas
  autor: Vítor Corrêa
*/
void inserirCelula(celulaColuna *inicio,char nomeColuna[],char tipo[]){
     
     celulaColuna temp=NULL,temp2=NULL;          
     
     if((*inicio) == NULL){
         temp = alocarCelula(nomeColuna,tipo);                                  
         (*inicio) = temp;
         return ;             
     }            
     temp = (*inicio);        
     while(temp->proximo != NULL)
         temp = temp->proximo;    
     temp2 = alocarCelula(nomeColuna,tipo);     
     temp->proximo = temp2;                    
     return;     
}
/*
  Verifica o tipo de arvore
  autor: Vítor Corrêa
*/
void inserirArvore(celulaColuna *temp,char *dado,long posicao){                                                                        
     
     char dadoFloat[strlen(dado)];         
     int aux=0;     

     if(strcmp((*temp)->tipo,"char") == 0) {                      
         (*temp)->pArvore = inserirArvoreChar((*temp)->pArvore,dado,posicao);               
         return;
     }
     if(strcmp((*temp)->tipo,"int") == 0) {      
         (*temp)->pArvore = inserirArvoreInt((*temp)->pArvore,atoi(dado),posicao);        
         return;
     }
     if(strcmp((*temp)->tipo,"float") == 0) {         
         strcpy(dadoFloat,dado);    
         excecaoFloat(dadoFloat);         
         (*temp)->pArvore = inserirArvoreFloat((*temp)->pArvore,atof(dadoFloat),posicao);                            
         return;
     }          
}
/*
  Alocar celula da lista encadeada
  de colunas
  autor: Vítor Corrêa
*/
celulaColuna alocarCelula(char *nomeColuna,char *tipo){    
     
    celulaColuna nova;
    nova = (celulaColuna)malloc(sizeof(cel));
    nova->proximo = NULL;
    nova->nomeColuna = (char*)malloc(strlen(nomeColuna)*sizeof(char));
    strcpy(nova->nomeColuna,nomeColuna);
    nova->tipo = (char*)malloc(strlen(tipo)*sizeof(char));
    strcpy(nova->tipo,tipo);
    nova->pArvore = NULL;
    return nova;
}
/*
     Tratar valores Float do arquivo
     autor: Vítor Corrêa
*/
void excecaoFloat(char *dado){
     
    int cont=0,aux=0;    
      
    while(cont <= strlen(dado)){
        if(dado[cont]=='.'){        
           for(aux=cont;aux<=strlen(dado);aux++) {
               dado[aux]=dado[aux+1];                     
           }
        }
        cont++;
    }
    cont=0;
    while(cont <= strlen(dado)){
        if(dado[cont]==','){
           dado[cont]='.';
        }
        cont++;
    }    
}
/*
    Tratar Excecao  de inteiros
    autor: Vítor Corrêa
*/
void excecaoInteiro(char *dado){
     
     int cont=0,aux;
     
     while(cont <= strlen(dado)){
         if(dado[cont] == ',')
             for(aux=cont;aux<=strlen(dado);aux++)
                 dado[aux] = dado[aux+1];
         cont++;
     }     
}
