#include <stdio.h>
#include <stdlib.h>

#define TAM 12

int buscaBinaria(int *vetor, int num);

int main(){
    int vet[TAM];
    int chave = 30; 
    int retorno;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite uma chave: ");
    scanf("%d", &chave);

    retorno = buscaBinaria(vet, chave);

    if (retorno > -1){
        printf("Objeto encontrado!!!\n");
    }else{
        printf("Chave não encontrada!!!\n");
    }
    
    return 0;
}

int buscaBinaria(int *vetor, int num){
    int esquerda = 0;
    int direita = TAM;
    int meio;
    int contador = 0;

    while (esquerda <= direita){
        meio = (esquerda + direita) / 2;
    
        contador++;
        if (num < vetor[meio])
        {
            direita = meio - 1;
        }else if(num > vetor[meio]){
            esquerda = meio + 1;
        }else{
            return meio;
        }
    }
    return -1;
}