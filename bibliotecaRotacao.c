/*
    Biblioteca de rota��es das �rvores
    autor: V�tor Corr�a
*/
#include "prototipos.h"

/*
    Rodada simples a direita arvore de ChAR
    autor: V�tor Corr�a
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
    autor: V�tor Corr�a
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
      autor: V�tor Corr�a
*/
treeChar rodaDuploEsquerdaChar(treeChar raizTmp){
         
    raizTmp->left = rodaUmDireitaChar(raizTmp->left);
	return rodaUmEsquerdaChar(raizTmp);
}
/*
      Rodada Dupla a direita arvore CHAR
      autor: V�tor Corr�a
*/
treeChar rodaDuploDireitaChar(treeChar raizTmp){
         
    raizTmp->right = rodaUmEsquerdaChar(raizTmp->right);
	return rodaUmDireitaChar(raizTmp);
}

/*
    Rodada simples a direita arvore de Inteiro
    autor: V�tor Corr�a
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
    autor: V�tor Corr�a
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
      autor: V�tor Corr�a
*/
treeInt rodaDuploEsquerdaInt(treeInt raizTmp){
         
    raizTmp->left = rodaUmDireitaInt(raizTmp->left);
	return rodaUmEsquerdaInt(raizTmp);
}
/*
      Rodada Dupla a direita arvore Inteiro
      autor: V�tor Corr�a
*/
treeInt rodaDuploDireitaInt(treeInt raizTmp){
         
    raizTmp->right = rodaUmEsquerdaInt(raizTmp->right);
    return rodaUmDireitaInt(raizTmp);
}
/*
    Rodada simples a direita arvore de Float
    autor: V�tor Corr�a
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
    autor: V�tor Corr�a
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
      autor: V�tor Corr�a
*/
treeFloat rodaDuploEsquerdaFloat(treeFloat raizTmp){
    
    raizTmp->left = rodaUmDireitaFloat(raizTmp->left);
	return rodaUmEsquerdaFloat(raizTmp);
}
/*
      Rodada Dupla a direita arvore Float
      autor: V�tor Corr�a
*/
treeFloat rodaDuploDireitaFloat(treeFloat raizTmp){
          
    raizTmp->right = rodaUmEsquerdaFloat(raizTmp->right);
    return rodaUmDireitaFloat(raizTmp);          
}
