/*
 Sintese
        Dar carga na primeira linha do arquivo e criar a lista encadeada
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int main(void){

    celulaColuna inicio=NULL;
    FILE *fp;    

    abrirArquivo(&fp);    
    inicio = lerPrimeiraLinha(fp); 
    indexarArquivo(&inicio,fp);       
    abrirBusca(fp,inicio);
    fecharArquivo(&fp);    
    system("PAUSE");
    return 0;
}
