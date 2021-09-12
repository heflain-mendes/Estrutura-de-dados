#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int buscaBinariaRecursiva(int *vetor, int num, int inicio, int fim);

int main(){
    int vet[TAM], chave, retorno;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite uma chave: ");
    scanf("%d", &chave);

    retorno = buscaBinariaRecursiva(vet, chave,0, TAM);

    if (retorno > -1){
        printf("Objeto encontrado!!!\n");
    }else{
        printf("Chave não encontrada!!!\n");
    }

    return 0;
}

int buscaBinariaRecursiva(int *vetor, int num, int inicio, int fim){
    int meio = (inicio + fim) / 2;
    if(inicio > fim){
        return -1;
    }else if(num == vetor[meio]){
        return meio;
    }else if(num < vetor[meio]){
        return buscaBinariaRecursiva(vetor, num, inicio, meio - 1);
    }else{
        return buscaBinariaRecursiva(vetor, num, meio + 1, fim);
    }
}