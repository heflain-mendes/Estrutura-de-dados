#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int buscaSequencial(int *vet, int k);

int main(){
    int vet[TAM], i, chave, retorno;

    for (i = 0; i < TAM; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite a chave a ser encontrada: ");
    scanf("%d", &chave);

    retorno = buscaSequencial(vet, chave);

    if (retorno == -1)
    {
        printf("numero não encontrado na sequencia!!!");
    }else{
        printf("numero encontrado!!! -> %d", retorno);
    }   
    
    return 0;
}

int buscaSequencial(int *vet, int k){
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (vet[i] == k)
        {
            return i;
        }
    }
    
    return -1;
}