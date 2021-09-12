#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int mergeSort(int *vetor, int inicio, int fim);
int merge(int *vetor,int inicio, int meio, int fim);

int main(){
    int vet[] = {6,5,4,3,2,1};
    mergeSort(vet, 0, TAM - 1);

    for (int i = 0; i < TAM; i++)
    {
        printf("%d ",vet[i]);
    }
    
    return 0;
}

int mergeSort(int *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor,inicio, meio, fim);
    }
}

int merge(int *vetor,int inicio, int meio, int fim){
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int *tmp = (int *) malloc(sizeof(int) * (fim + 1 - inicio));

    while(i <= meio || j <= fim){
        if(i == meio + 1 || vetor[j] < vetor[i] && j != fim + 1){
            tmp[k] = vetor[j];
            k++;
            j++;
        }else{
            tmp[k] = vetor[i];
            k++;
            i++;
        }
    }

    for(i = inicio; i <= fim; i++){
        vetor[i] = tmp[i - inicio];
    }

    free(tmp);
}