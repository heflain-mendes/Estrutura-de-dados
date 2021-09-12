#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int criarHeap(int *vet, int i, int fim);
int heapSort(int *vet, int tam);


int main(int argc, char const *argv[])
{
    int vetor[TAM] = {1, 6, 2, 6 , 8 , 9 ,0, -6,-8};

    heapSort(vetor, TAM);

    for (int i = 0; i < TAM; i++)
    {
        printf("%d, ",vetor[i]);
    }
    
    
    return 0;
}

int criarHeap(int *vet, int i, int fim){
    int aux = vet[i];
    int j = i * 2 + 1;

    while(j <= fim)
    {
        if (j < fim && vet[j] < vet[j + 1])
        {
            j++;
        }
        if (aux < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else
        {
            j = fim + 1;
        }
    }
    vet[i] = aux;
}

int heapSort(int *vet, int tam){
    int aux;

    //faz de tras para frente
    for (int i = (tam - 1) / 2; i >= 0; i--)
    {
        criarHeap(vet, i, tam - 1);
    }

    for (int i = tam - 1; i >= 1; i--)
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criarHeap(vet,0,i - 1);
    }
}