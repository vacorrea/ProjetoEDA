/*
    Biblioteca Atravessamento da arvore
    autor: Vítor Corrêa
*/
#include "prototipos.h"

/*
  Percorrer e apresentar arvore Infixa Float
  Autor: Vítor Corrêa
*/
void percorrerFloat(treeFloat raiz){               
     if(raiz == NULL)
         return;     
     percorrerFloat(raiz->left);
     while(raiz->inicio != NULL){
         printf("%d ",raiz->inicio->posicao);               
         raiz->inicio = raiz->inicio->proximo;                   
     }
     printf("- %.2f\n",raiz->valorFloat);                  
     percorrerFloat(raiz->right);     
}
/*
  Percorrer e apresentar arvore Infixa Char
  Autor: Vítor Corrêa
*/
void percorrerChar(treeChar raiz){
     if(raiz == NULL)
         return;     
     percorrerChar(raiz->left);
     while(raiz->inicio != NULL){
         printf("%d ",raiz->inicio->posicao);               
         raiz->inicio = raiz->inicio->proximo;                   
     }
     printf("- %s\n",raiz->string);         
     percorrerChar(raiz->right);
}
/*
  Percorrer e apresentar arvore Infixa Int
  Autor: Vítor Corrêa
*/
void percorrerInt(treeInt raiz){
     if(raiz == NULL)
         return;     
     percorrerInt(raiz->left);
     while(raiz->inicio != NULL){
         printf("%d ",raiz->inicio->posicao);               
         raiz->inicio = raiz->inicio->proximo;                   
     }
     printf("- %d\n",raiz->valorInteiro);         
     percorrerInt(raiz->right);
}
/*
     Procuras binarias
     Autor: Vítor Correa
*/
void binSearchChar(treeChar raiz,char *dado,celulaArquivo *nova){         
     
     if(raiz == NULL)
         return ;
     if(stricmp(dado,raiz->string) == 0)  {
         puts(raiz->string);
         if((*nova) == NULL)
             (*nova) = raiz->inicio;
         else
             (*nova)->proximo = raiz->inicio;             
     }
     else 
          if(stricmp(dado,raiz->string) < 0)
              binSearchChar(raiz->left,dado,&(*nova));
          else
              if(stricmp(dado,raiz->string) > 0)
                  binSearchChar(raiz->right,dado,&(*nova));             
    return ;
}
void binSearchInt(treeInt raiz,long int dado,celulaArquivo *nova){      

     if(raiz == NULL)
         return ;
     if(dado == raiz->valorInteiro){                     
         printf("%d \n",raiz->valorInteiro);
         if((*nova) == NULL)
             (*nova) = raiz->inicio;
         else
             (*nova)->proximo = raiz->inicio;
     }
     else 
         if(dado < raiz->valorInteiro)
             binSearchInt(raiz->left,dado,&(*nova));
         else
             binSearchInt(raiz->right,dado,&(*nova));    
     return ;
}
void binSearchFloat(treeFloat raiz,double dado,celulaArquivo *nova){
     if(raiz == NULL)
         return ;
     if(dado == raiz->valorFloat){
         printf("%f \n",raiz->valorFloat);
         if((*nova) == NULL)
             (*nova) = raiz->inicio;
         else
             (*nova)->proximo = raiz->inicio;
     }    
     else 
         if(dado < raiz->valorFloat)
             binSearchFloat(raiz->left,dado,&(*nova));
         else
             binSearchFloat(raiz->right,dado,&(*nova));    
     return ;
}
