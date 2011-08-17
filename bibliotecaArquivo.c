/*
    Biblioteca de arquivo
*/
#include "prototipos.h"

/*
  Ler outras linhas da coluna
  e indexar na arvore 
  autor: Vítor Corrêa
*/
void indexarArquivo(celulaColuna *inicio,FILE *fp){
     
     char linha[650];               
     char *dado;               
     celulaColuna temp = NULL;          
     long int posicao=0;
               
     while(!feof(fp)){
         posicao = ftell(fp);                         
         if(fgets(linha,650,fp) != NULL){                                                                                              
             linha[strlen(linha)-1] = '\0';                                             
             dado = (char*)malloc(strlen(linha)*sizeof(char));              
             temp = (*inicio);
             while(temp != NULL){                        
                 getDado(dado,linha);                 
                 inserirArvore(&temp,dado,posicao); // Insere na arvore
                 if(strlen(linha) != 0){                  
                     strcpy(linha,linha+(strlen(dado)+1));                                                    
                     dado = realloc(dado,sizeof(char)*strlen(linha));
                 }                 
                 temp = temp->proximo;
             }
             free(dado);
         } 
     }
     rewind(fp);          
}
/*
     Getdado
     autor: Vítor Corrêa
*/
void getDado(char *dado,char *linha){
     
     int cont = 0;
        
     while((linha[cont] != '\0')&&(linha[cont] != ';')){
          dado[cont] = linha[cont];
          cont++;
     }
     dado[cont] = '\0';                 
}
/*
  Ler primeira linha da coluna e 
      alocar as celulas das colunas
  autor: Vítor Corrêa
*/
celulaColuna lerPrimeiraLinha(FILE *fp){
    
    char linha[1000];     
    int qtdColunas=0;
    char nomeColuna[10];
    char tipo[6];
    int aux;
    celulaColuna inicio=NULL;
    
    fscanf(fp,"%d",&qtdColunas);
    fgets(linha,1000,fp);    
    linha[strlen(linha)-1] = '\0';
    for(aux=0;aux<qtdColunas;aux++){
        sscanf(linha,"%s %s",nomeColuna,tipo);   
        inserirCelula(&inicio,nomeColuna,tipo); // Inserir Lista                    
        if(strlen(linha) != 0)
            strcpy(linha,linha+(strlen(nomeColuna)+strlen(tipo))+2);          
    }   
    return inicio;    
}
/*
    Inserir a posicao do dado na lista encadeada
    autor: Vítor Corrêa
*/
void inserirPosicao(celulaArquivo *inicio,long posicao){
    
    celulaArquivo nova=NULL,nova2=NULL;    

    if((*inicio) == NULL){
        nova = (celulaArquivo)malloc(sizeof(celFile)); 
        nova->posicao = posicao;
        nova->proximo = NULL;        
        (*inicio) = nova;
        return ;
    }     
    nova = (*inicio);
    while(nova->proximo != NULL){        
        nova = nova->proximo;
    }
    nova2 = (celulaArquivo)malloc(sizeof(celFile));
    nova2->posicao = posicao;
    nova2->proximo = NULL;
    nova->proximo = nova2;
    return ;
}
/*
  Fechar arquivo
  autor: Vítor Corrêa
*/
void fecharArquivo(FILE **fp){
     fclose((*fp));}

/*
  Abrir arquivo
  autor: Vítor Corrêa
*/
void abrirArquivo(FILE **fp){
    
    char nomeArquivo[40];     
    
    puts("Informe o nome do arquivo");
    gets(nomeArquivo);
    fflush(stdin);
    (*fp) = fopen(nomeArquivo,"r");      
    if((*fp) == NULL){
        printf(" Problema na abertura do arquivo\n");
        system("Pause");
        exit(1);
    }
}
