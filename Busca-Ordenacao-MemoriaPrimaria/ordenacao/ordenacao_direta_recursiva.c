#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacaoDiretaRecursiva(char *vet, int tam);

int main(){
    char vetor[] = "heflain";
    ordenacaoDiretaRecursiva(vetor, 7);

    for (int i = 0, tam = strlen(vetor); i < tam; i++)
    {
        printf("%c ", vetor[i]);
    }
    putchar('\n');

    return 0;
}

void ordenacaoDiretaRecursiva(char *vet,int tam){
    if(tam > 1){
        ordenacaoDiretaRecursiva(vet, tam-1);
        int i = tam - 1;
        int j = i - 1;
        int aux = vet[i];
        
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