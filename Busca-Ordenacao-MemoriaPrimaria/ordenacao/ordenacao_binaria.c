#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacaoBinaria(char *vet);

int main(){
    char texto[] = "heflain";
    ordenacaoBinaria(texto);

    printf("%s\n",texto);

    return 0;
}

void ordenacaoBinaria(char *vet){
    int i, j, tam = strlen(vet);
    int meio,dir, esq;
    char aux;

    for (i = 1; i < tam ; i++){
        aux = vet[i];
        esq = 0;
        dir = i;
        //busca binaria
        while (esq < dir){
            meio = (esq + dir) / 2;
            if (vet[meio] <= aux){
                esq = meio + 1;
            }else{
                dir = meio;
            }
        }

        for (j = i; j > esq; j--)
        {
            vet[j] = vet[j -1];
        }
        vet[dir] = aux;//só é ´posivel por que na busca dir só para quando esq < dir

        //printf("direito %d e esquerdo %d\n", dir, esq);
    }
}