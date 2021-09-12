#include <stdio.h>
#include <stdlib.h>

int forca_burtaDE(char *texto, char *padrao);

int main(){
    
    char texto[] = "abelabelrocha";
    char p[] = "abel";

    int retorno = forca_burtaDE(texto, p);

    if (retorno == -1)
    {
        printf("palavra não encontrada!!!\n");
    }else{
        printf("palavra encontrada no index %d\n",retorno);//o index inicia a contagem em zero(0)
    }
    


    return 0;
}

int forca_burtaDE(char *texto, char *padrao){
    int p = strlen(padrao) - 1;
    int t =  strlen(texto) - 1;
    int i, j; //auxiliares

    for (i = p; t > i; t--)
    {
        for (p = i, j = t; p >= 0 && texto[j] == padrao[p]; p--,j--){}

        if(p == -1){
            return j + 1;
        }
    }

    return -1; //possição não encontrada
}