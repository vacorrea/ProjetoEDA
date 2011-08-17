/*
    Biblioteca de inser��o na avl
*/
#include "prototipos.h"

/*
  Inserir na arvore binaria balanceada de char o dado
  autor: V�tor Corr�a
*/
treeChar inserirArvoreChar(treeChar pArvore,char *dado,long posicao){                   
            
    if(pArvore == NULL) {
		pArvore = alocarRaizChar(dado);				
        pArvore->altura = fatorBalanceamento(alturaArvoreChar(pArvore->left),alturaArvoreChar(pArvore->right))+1;
        inserirPosicao(&pArvore->inicio,posicao);                
        return pArvore;	
    }
	else { 
        if(strcmp(dado,pArvore->string) < 0) {
			pArvore->left = inserirArvoreChar(pArvore->left,dado,posicao);
			if(alturaArvoreChar(pArvore->left) - alturaArvoreChar(pArvore->right) == 2) 
                if(strcmp(dado,pArvore->string) < 0)
					pArvore = rodaUmEsquerdaChar(pArvore);
				else
					pArvore = rodaDuploEsquerdaChar(pArvore);
		}
		else  {
           if(strcmp(dado,pArvore->string) > 0) {
           pArvore->right = inserirArvoreChar(pArvore->right,dado,posicao); 
           if(alturaArvoreChar(pArvore->right) - alturaArvoreChar(pArvore->left) == 2) 
				if(strcmp(dado,pArvore->string) > 0)
					pArvore = rodaUmDireitaChar(pArvore);
				else
					pArvore = rodaDuploDireitaChar(pArvore);
		   }		   
		   else 
		       if(strcmp(dado,pArvore->string) == 0){                   
                   inserirPosicao(&pArvore->inicio,posicao);                   
                   return pArvore;
               }                    
       }
    }
	pArvore->altura = fatorBalanceamento(alturaArvoreChar(pArvore->left),alturaArvoreChar(pArvore->right))+1;
	return pArvore;
}
/*
    Alocar raiz de char
    autor: V�tor Corr�a
*/
treeChar alocarRaizChar(char *dado){
    
    treeChar raiz = NULL;    
        
    raiz = (treeChar)malloc(sizeof(celChar));   
    raiz->string = (char*)malloc(strlen(dado)*sizeof(char));
    strcpy(raiz->string,dado);    
    raiz->altura = 0;
    raiz->inicio = NULL;
    raiz->left = NULL;
    raiz->right = NULL;    
    return raiz;                       
}
/*
    Calcular Altura de uma arvore Char
    autor: V�tor Corr�a
*/
int alturaArvoreChar(treeChar pArvore){
    
    if(pArvore)
        return pArvore->altura;
    return -1;
}
/*
  Inserir na arvore binaria balanceada de Inteiro o dado
  autor: V�tor Corr�
*/
treeInt inserirArvoreInt(treeInt pArvore,long int dado,long posicao){                             
    
    if(pArvore == NULL) {
		pArvore = alocarRaizInteiro(dado);
		pArvore->altura = fatorBalanceamento(alturaArvoreInt(pArvore->left),alturaArvoreInt(pArvore->right))+1;		
		inserirPosicao(&pArvore->inicio,posicao);
        return pArvore;
    }	
	else {                 
		if(dado < pArvore->valorInteiro) {
			pArvore->left = inserirArvoreInt(pArvore->left,dado,posicao);
			if(alturaArvoreInt(pArvore->left) - alturaArvoreInt(pArvore->right) == 2) 
				if(dado < pArvore->left->valorInteiro)
					pArvore = rodaUmEsquerdaInt(pArvore);
				else
					pArvore = rodaDuploEsquerdaInt(pArvore);
		}
		else {             
		    if(dado > pArvore->valorInteiro) {
            pArvore->right = inserirArvoreInt(pArvore->right,dado,posicao); 
            if(alturaArvoreInt(pArvore->right) - alturaArvoreInt(pArvore->left) == 2) 
		    	if(dado > pArvore->right->valorInteiro)
			 		pArvore = rodaUmDireitaInt(pArvore);
				else
					pArvore = rodaDuploDireitaInt(pArvore);
		   }
		   else 
                if(dado == pArvore->valorInteiro){
                     inserirPosicao(&pArvore->inicio,posicao);
                     return pArvore;        
                } 
        }
    }
	pArvore->altura = fatorBalanceamento(alturaArvoreInt(pArvore->left),alturaArvoreInt(pArvore->right))+1;
	return pArvore;     
}
/*
    Alocar raiz de Inteiro
    autor: V�tor Corr�a
*/
treeInt alocarRaizInteiro(long int dado){
    
    treeInt raiz = (treeInt)malloc(sizeof(celInt));    
    
    raiz->valorInteiro = dado;
    raiz->altura = 0;
    raiz->inicio = NULL;
    raiz->left = NULL;
    raiz->right = NULL;  
    return raiz;
}
/*
    Calcular Altura de uma arvore Int
    autor: V�tor Corr�a
*/
int alturaArvoreInt(treeInt pArvore){
    
    if(pArvore)
        return pArvore->altura;
    return -1;
}
/*
  Inserir na arvore binaria balanceada de Float o dado
  autor: V�tor Corr�a
*/
treeFloat inserirArvoreFloat(treeFloat pArvore,double dado,long posicao){                            

    if(pArvore == NULL) {
		pArvore = alocarRaizFloat(dado);
		pArvore->altura = fatorBalanceamento(alturaArvoreFloat(pArvore->left),alturaArvoreFloat(pArvore->right))+1;
        inserirPosicao(&pArvore->inicio,posicao);        
        return pArvore;
    }	
	else {                 
		if(dado < pArvore->valorFloat) {
			pArvore->left = inserirArvoreFloat(pArvore->left,dado,posicao);
			if(alturaArvoreFloat(pArvore->left) - alturaArvoreFloat(pArvore->right) == 2) 
				if(dado < pArvore->left->valorFloat)
					pArvore = rodaUmEsquerdaFloat(pArvore);
				else
					pArvore = rodaDuploEsquerdaFloat(pArvore);
		}
		else {
		    if(dado > pArvore->valorFloat) {
                pArvore->right = inserirArvoreFloat(pArvore->right,dado,posicao); 
                if(alturaArvoreFloat(pArvore->right) - alturaArvoreFloat(pArvore->left) == 2) 
			  	    if(dado > pArvore->right->valorFloat)
					    pArvore = rodaUmDireitaFloat(pArvore);
				    else
					    pArvore = rodaDuploDireitaFloat(pArvore);
		    }
		    else 
		        if(dado == pArvore->valorFloat){
                    inserirPosicao(&pArvore->inicio,posicao);
                    return pArvore;
                }
        }
    }
	pArvore->altura = fatorBalanceamento(alturaArvoreFloat(pArvore->left),alturaArvoreFloat(pArvore->right))+1;
	return pArvore;     
}
/*
    Alocar raiz de Float
    autor: V�tor Corr�a
*/
treeFloat alocarRaizFloat(double dado){
    
    treeFloat raiz = (treeFloat)malloc(sizeof(celFloat));    
   
    raiz->valorFloat = dado;
    raiz->altura = 0;
    raiz->inicio = NULL;
    raiz->left = NULL;
    raiz->right = NULL;    
    return raiz;
}
/*
    Calcular Altura de uma arvore Float
    autor: V�tor Corr�a
*/
int alturaArvoreFloat(treeFloat pArvore){
    
    if(pArvore)
        return pArvore->altura;
    return -1;
}
/*
    Testa se a arvore foi desbalanceada apos a insers��o
    autor: V�tor Corr�a    
*/
int fatorBalanceamento(int leftHand,int rightHand) {
        return leftHand > rightHand ? leftHand : rightHand;
}
