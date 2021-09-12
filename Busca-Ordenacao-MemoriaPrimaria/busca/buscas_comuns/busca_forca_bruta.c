#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int forca_burta(char *texto, char *padrao);
int tamString(char *texto);

int main(){
    
    char texto[] = "o rato roeu a roupa do rei de roma";
    char p[] = "roma";

    int retorno = forca_burta(texto, p);

    if (retorno == -1)
    {
        printf("palavra não encontrada!!!\n");
    }else{
        printf("palavra encontrada no index %d\n",retorno);//o index inicia a contagem em zero(0)
    }
    


    return 0;
}

int forca_burta(char *texto, char *padrao){
    int tam_padrao = strlen(padrao);
    int tam_max = strlen(texto) - tam_padrao;
    int i, j; //auxiliares

    for (i = 0; i <= tam_max; i++)
    {
        for (j = 0; j < tam_padrao && texto[i + j] == padrao[j]; j++){}

        if(j == tam_padrao){
            return i;
        }
    }

    return -1; //possição não encontrada
}