#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int buscaSequencialSentinela(int *vet, int k);

int main(){
    int vet[TAM], i, tamanhoVet, chave, retorno;

           //0                   5           4
    for (i = 0, tamanhoVet = TAM - 1; i < tamanhoVet; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite a chave a ser encontrada: ");
    scanf("%d", &chave);

    retorno = buscaSequencialSentinela(vet, chave);

    if (retorno == -1)
    {
        printf("numero não encontrado na sequencia!!!");
    }else{
        printf("numero encontrado -> %d",retorno);
    }   
    
    return 0;
}

int buscaSequencialSentinela(int *vet, int k){
    int i;
    
    //TAM -1 por causa do index que começa em zero
    vet[TAM - 1] = k;

    for (i = 0; vet[i] != k; i++){}

    if (i == TAM - 1)
    {
        return -1;
    }else{
        return i;
    }
}