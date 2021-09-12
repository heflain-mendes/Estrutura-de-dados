#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int buscaSequencial_transposicao(int *vet, int k);

int main(){
    int vet[TAM], i, chave, retorno;

    for (i = 0; i < TAM; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite a chave a ser encontrada: ");
    scanf("%d", &chave);

    retorno = buscaSequencial_transposicao(vet, chave);

    if (retorno == -1)
    {
        printf("numero não encontrado na sequencia!!!\n");
    }else{
        printf("numero encontrado -> %d\n",retorno);
    }

    //verificando se a ordenação aconteceu com sucesso
    for ( i = 0; i < TAM; i++)
    {
        printf("%d ",vet[i]);
    }
    
    
    return 0;
}

int buscaSequencial_transposicao(int *vet, int k){
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (vet[i] == k)
        {
            vet[i] = vet[i - 1];
            vet[i - 1] = k;

            return i - 1;//index atual de onde o valor se encontra no vetor
        }
    }
    
    return -1;
}