/*
    Arquivo de busca da arvore
    autor: Vítor Corrêa
*/

#include "prototipos.h"

/*
    Controla as buscas
    autor: Vítor Corrêa
*/
void abrirBusca(FILE *fp,celulaColuna inicio){               

     char dado[400];                     
     searchCelula search = NULL;
     celulaColuna temp = inicio;
     
     while(temp != NULL){
         printf(" Coluna ( %s ) ( %s )\n",temp->tipo,temp->nomeColuna);
         fgets(dado,400,stdin);
         dado[strlen(dado)-1] = '\0';                             
         if(strlen(dado) == 0)  {
             inserirSearchcel(&search,"NULLPOINTER","NULLPOINTER");                 
             verificarArvore(temp);   
         }
         else              
             inserirSearchcel(&search,dado,temp->tipo);                         
         temp = temp->proximo;
     }          
     printf("\n\n");
     search->inicio = verificarMatch(inicio,search);     
     if(search->inicio != NULL)
         apresentarHit(search->inicio,fp);     
     else
         puts("Nenhum Valor Encontrado");
     return;          
}
/*
     Verificar o tipo e procura binaria
     autor: Vìtor Corrêa
*/
celulaArquivo verificarMatch(celulaColuna inicio,searchCelula begin){  
     
     celulaArquivo nova = NULL;
     char *dadoFloat;
              
     while(begin != NULL){      
          if(nova != NULL){
              while(nova->proximo != NULL){
                  nova = nova->proximo;
              }
          }                                   
          if(strcmp(begin->tipo,"char") == 0)
               binSearchChar(inicio->pArvore,begin->dado,&nova);         
          else {
              if(strcmp(begin->tipo,"int") == 0) 
                   binSearchInt(inicio->pArvore,atoi(begin->dado),&nova);
              else
                  if(strcmp(begin->tipo,"float") == 0) {         
                       strcpy(dadoFloat,begin->dado);    
                       excecaoFloat(dadoFloat);         
                       binSearchFloat(inicio->pArvore,atof(dadoFloat),&nova);                     
                  }               
          }
          inicio = inicio->proximo;
          begin = begin->proximo;
     }            
     return nova;
}
/*
    Verifica quais posicoes sao iguais le do arquivo e imprime
    autor: Vítor Corrêa
*/
void apresentarHit(celulaArquivo inicio,FILE *fp){
     
     int cont=0;
     long int pCompare;
     celulaArquivo temp = inicio;
     char dado[600];
     
     printf("\n\n");
     while(temp != NULL){     
        fseek(fp,temp->posicao,SEEK_SET);                                                 
        fgets(dado,600,fp);
        dado[strlen(dado)-1] = '\0';
        puts(dado);
        printf("\n\n");
        system("PAUSE");
        strcpy(dado,"");
        temp = temp->proximo;
     }
}
/*
     Inserir na lista de procura
     autor : Vítor Corrêa
*/
void inserirSearchcel(searchCelula *search,char *dado,char *tipo){
     
     searchCelula temp,temp2;
     
     if((*search) == NULL){
         temp = alocarSearch(dado,tipo);             
         (*search) = temp;
         return;
     }
     temp = (*search);
     while(temp->proximo != NULL){
        temp = temp->proximo;
     }     
     temp2 = alocarSearch(dado,tipo);
     temp->proximo = temp2;
     return;
}
/*
     Alocar dados na lista de procura
     autor: Vìtor Corrêa
*/
searchCelula alocarSearch(char *dado,char *tipo){

    searchCelula nova;    

    nova = (searchCelula)malloc(sizeof(scel));
    nova->proximo = NULL;
    nova->dado = (char*)malloc(strlen(dado)*sizeof(char));
    strcpy(nova->dado,dado);
    nova->tipo = (char*)malloc(strlen(tipo)*sizeof(char));
    strcpy(nova->tipo,tipo);
    nova->inicio = NULL;
    return nova;
}
/*
     verifica a arvore e Atravessa a arvore
     autor: Vítor Corrêa
*/
void verificarArvore(celulaColuna inicio){    

    if(strcmp(inicio->tipo,"int") == 0)
        percorrerInt(inicio->pArvore);
    else {
        if(strcmp(inicio->tipo,"char") == 0)
            percorrerChar(inicio->pArvore);
        else 
            if(strcmp(inicio->tipo,"float") == 0)
                percorrerFloat(inicio->pArvore);
    }
    system("PAUSE");    
}
