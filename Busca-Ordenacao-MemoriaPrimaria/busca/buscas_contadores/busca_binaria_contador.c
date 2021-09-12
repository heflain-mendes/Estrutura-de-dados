#include <stdio.h>
#include <stdlib.h>

#define TAM 12

int buscaBinaria(int *vetor, int num);

int main()
{
    int vet[TAM] = {2, 4, 7, 11, 12, 20, 23, 25, 32, 33, 34, 44};
    int chave = 30;
    int retorno;

    /*for (int i = 0; i < TAM; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }*/

    printf("Digite uma chave: ");
    scanf("%d", &chave);

    retorno = buscaBinaria(vet, chave);

    if (retorno > -1)
    {
        printf("Objeto encontrado!!!\n");
    }
    else
    {
        printf("Chave não encontrada!!!\n");
    }

    return 0;
}

int buscaBinaria(int *vetor, int num)
{
    int esquerda = 0;
    int direita = TAM - 1;
    int meio;
    int contador = 0;

    while (esquerda <= direita)
    {
        meio = (esquerda + direita) / 2;
        contador++;//contando as comparações do if
        if (num == vetor[meio])
        {
            printf("ocorreram %d verificacoes, e encontrou a sequencia\n", contador);
            return meio;
        }
        else
        {
            contador++;//contando as comparações do if
            if (vetor[meio] < num)
            {
               esquerda = meio + 1;
            }
            else
            {
                contador++;//só deu os resultados iguais o do professor colocando esse contador
                direita = meio - 1;
            }
        }
    }
    printf("ocorreram %d verificacoes, e NAO encontrou a sequencia\n", contador);
    return -1;
}