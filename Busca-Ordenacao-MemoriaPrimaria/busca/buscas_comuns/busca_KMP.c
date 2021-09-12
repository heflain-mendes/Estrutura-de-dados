#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *preProcessamento(char *texto, int tam);
int kmp(char *texto, char *padrao);
int main()
{
    char nome[] = "CORROCOCOGAOCOR";
    char encon[] = "COA";

    int resul = kmp(nome, encon);

    if(resul != -1){
        printf("padrao encontradao %d", resul);
    }else{
        printf("padrao NAO encontrado\n");
    }

    return 0;
}

int *preProcessamento(char *texto, int tam)
{
    int *aux = (int *)malloc(sizeof(int) * tam);
    aux[0] = 0;

    int j = 0;
    int i = 1;

    while (i < tam)
    {
        if (texto[i] == texto[j])
        {
            j++;
            aux[i] = j;
            i++;
        }
        else{ 
            if (j == 0){
                aux[i] = j;//ou 0
                i++;
            }else{
                j = aux[j-1];// ou j = 0
            }
        }
    }

    for ( i = 0; i < tam; i++)
    {
        printf("%d ",aux[i]);
    }
    
    return aux;
}

int kmp(char *texto, char *padrao){
    int tam_texto = strlen(texto);
    int tam_padrao = strlen(padrao);

    int *aux = preProcessamento(padrao, tam_padrao);

    int index_texto = 0;
    int index_padrao = 0;

    while(index_texto < tam_texto && index_padrao < tam_padrao){
        if (texto[index_texto] == padrao[index_padrao]){
            index_padrao++;
            index_texto++;
        }else{
            index_texto += (index_padrao == 0) ? 1 : 0;
            index_padrao = aux[index_padrao];
        }
    }

    free(aux);

    if (index_padrao == tam_padrao)
        return index_texto - index_padrao;
    else
        return -1;
}