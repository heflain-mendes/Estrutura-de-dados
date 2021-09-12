#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int buscaSequencial_mover_para_frente(int *vet, int k);

int main(){
    int vet[TAM], i, chave, retorno;

    for (i = 0; i < TAM; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite a chave a ser encontrada: ");
    scanf("%d", &chave);

    retorno = buscaSequencial_mover_para_frente(vet, chave);

    if (retorno == -1)
    {
        printf("numero não encontrado na sequencia!!!\n");
    }else{
        printf("numero encontrado-%d\n",retorno);
    }

    //verificando se a ordenação aconteceu com sucesso
    for ( i = 0; i < TAM; i++)
    {
        printf("%d ",vet[i]);
    }
    
    
    return 0;
}

int buscaSequencial_mover_para_frente(int *vet, int k){
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (vet[i] == k)
        {
            while(i > 0){
                vet[i] = vet[i - 1];
                i--;
            }

            vet[0] = k;

            return 0;//index de onde o valor se encontra no vetor
        }
    }
    
    return -1;
}