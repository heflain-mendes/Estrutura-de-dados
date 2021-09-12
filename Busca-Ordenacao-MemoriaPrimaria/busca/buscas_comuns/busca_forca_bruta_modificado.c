#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int forca_burta(char *texto, char *padrao);
int busca(char *texto, char *padrao );

int main(){
    char texto[] = " roma roeu roma roma";
    char p[] = "roma";

    int retorno = busca(texto, p);

    if (retorno == 0){
        printf("palavra não encontrada!!!\n");
    }else{
        printf("palavra encontrada %d vezes\n", retorno);
   }

    return 0;
}

int forca_burta(char *texto,  char *padrao){
    int tam_padrao = strlen(padrao);
    int tam_max = strlen(texto) - tam_padrao;
    int i,j; //auxiliares

    for (i = 0; i <= tam_max; i++){
        for (j = 0; j < tam_padrao && texto[i + j] == padrao[j]; j++){}

        if(j == tam_padrao){
            return i;
        }
    }

    return -1; //possição não encontrada
}

int busca(char *texto, char *padrao ){
    int i = 0;
    int j = 0;
    int tam_texto = strlen(texto);
    int tam_padrao = strlen(padrao);

    j = forca_burta(texto, padrao);

    while(j != -1){
        i++;
        if (j + tam_padrao < tam_texto){
            texto += j + tam_padrao;
            j = forca_burta(texto, padrao);
            tam_texto = strlen(texto);
        }else{
            j = -1;
        }
    }

    return i;
}