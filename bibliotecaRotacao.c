/*
    Biblioteca de rotações das árvores
    autor: Vítor Corrêa
*/
#include "prototipos.h"

/*
    Rodada simples a direita arvore de ChAR
    autor: Vítor Corrêa
*/
treeChar rodaUmDireitaChar(treeChar raiz){

      treeChar raizTemp;

      raizTemp = raiz->right;
      raiz->right = raizTemp->left;
      raizTemp->left = raiz;
      return raizTemp;  /* nova raiz */
}
/*
    Rodada simples a direita arvore de ChAR
    autor: Vítor Corrêa
*/
treeChar rodaUmEsquerdaChar(treeChar raiz){
         
      treeChar raizTemp;

      raizTemp = raiz->left;
      raiz->left = raizTemp->right;
      raizTemp->right = raiz;
      return raizTemp;  /* nova raiz */
}
/*
      Rodada Dupla a esquerda arvore CHAR
      autor: Vítor Corrêa
*/
treeChar rodaDuploEsquerdaChar(treeChar raizTmp){
         
    raizTmp->left = rodaUmDireitaChar(raizTmp->left);
	return rodaUmEsquerdaChar(raizTmp);
}
/*
      Rodada Dupla a direita arvore CHAR
      autor: Vítor Corrêa
*/
treeChar rodaDuploDireitaChar(treeChar raizTmp){
         
    raizTmp->right = rodaUmEsquerdaChar(raizTmp->right);
	return rodaUmDireitaChar(raizTmp);
}

/*
    Rodada simples a direita arvore de Inteiro
    autor: Vítor Corrêa
*/
treeInt rodaUmDireitaInt(treeInt raiz){

      treeInt raizTemp;

      raizTemp = raiz->right;
      raiz->right = raizTemp->left;
      raizTemp->left = raiz;
      return raizTemp;  /* nova raiz */
}
/*
    Rodada simples a direita arvore de ChAR
    autor: Vítor Corrêa
*/
treeInt rodaUmEsquerdaInt(treeInt raiz){
         
      treeInt raizTemp;

      raizTemp = raiz->left;
      raiz->left = raizTemp->right;
      raizTemp->right = raiz;
      return raizTemp;  /* nova raiz */
}
/*
      Rodada Dupla a esquerda arvore Inteiro
      autor: Vítor Corrêa
*/
treeInt rodaDuploEsquerdaInt(treeInt raizTmp){
         
    raizTmp->left = rodaUmDireitaInt(raizTmp->left);
	return rodaUmEsquerdaInt(raizTmp);
}
/*
      Rodada Dupla a direita arvore Inteiro
      autor: Vítor Corrêa
*/
treeInt rodaDuploDireitaInt(treeInt raizTmp){
         
    raizTmp->right = rodaUmEsquerdaInt(raizTmp->right);
    return rodaUmDireitaInt(raizTmp);
}
/*
    Rodada simples a direita arvore de Float
    autor: Vítor Corrêa
*/
treeFloat rodaUmDireitaFloat(treeFloat raiz){

    treeFloat raizTemp;

    raizTemp = raiz->right;
    raiz->right = raizTemp->left;
    raizTemp->left = raiz;
    return raizTemp;  /* nova raiz */
} 
/*
    Rodada simples a esquerda arvore de Float
    autor: Vítor Corrêa
*/
treeFloat rodaUmEsquerdaFloat(treeFloat raiz){

    treeFloat raizTemp;

    raizTemp = raiz->left;
    raiz->left = raizTemp->right;
    raizTemp->right = raiz;
    return raizTemp;  /* nova raiz */
}
/*
      Rodada Dupla a esquerda arvore Float
      autor: Vítor Corrêa
*/
treeFloat rodaDuploEsquerdaFloat(treeFloat raizTmp){
    
    raizTmp->left = rodaUmDireitaFloat(raizTmp->left);
	return rodaUmEsquerdaFloat(raizTmp);
}
/*
      Rodada Dupla a direita arvore Float
      autor: Vítor Corrêa
*/
treeFloat rodaDuploDireitaFloat(treeFloat raizTmp){
          
    raizTmp->right = rodaUmEsquerdaFloat(raizTmp->right);
    return rodaUmDireitaFloat(raizTmp);          
}
