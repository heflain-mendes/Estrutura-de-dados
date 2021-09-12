#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacaoDireta(char *vet);

int main(){
    char vetor[] = "heflain";
    ordenacaoDireta(vetor);

    for (int i = 0, tam = strlen(vetor); i < tam; i++)
    {
        printf("%c ", vetor[i]);
    }
    putchar('\n');

    return 0;
}

void ordenacaoDireta(char *vet){
    int i;
    int j;
    int aux;
    int tam = strlen(vet);

    for(i = 1; i < tam;i++)
    {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && aux < vet[j])
        {
            vet[j + 1] = vet[j];
            j--;
        }
        if(j != i - 1){
            vet[j + 1] = aux;
        }
    }
}