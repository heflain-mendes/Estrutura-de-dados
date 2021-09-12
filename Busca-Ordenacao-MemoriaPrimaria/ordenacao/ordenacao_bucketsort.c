#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10

typedef struct
{
    int topo;
    int *balde;
}conteiner;

int comparador(const void *a, const void *b);
void bucketsort(int *vet, int tam);

int main(){
    int v[TAM] = {30,20,50,8,5,9,-5,-30,7,0};

    bucketsort(v,TAM);

    for (int  i = 0; i < TAM; i++)
    {
        printf("%d, ",v[i]);
    }
    

    return 0;
}

int comparador(const void *a, const void *b){
    int va = *((int*)a);
    int vb = *((int*)b);

    return va-vb;
}

void bucketsort(int *vet, int tam){
    int qtdBaldes;
    int amplitude;
    int menor, maior;
    int j;

    /*para definir a quantidade de baldes eu use a tecnica de raiz quadrada,
    que aprendi na meteria de estatistica*/
    qtdBaldes = ceil(sqrt((double) tam));
    //printf("qtdBaldes: %d\n", qtdBaldes);

    /*para calcular a amplitude também usei um conhecimento de estatistica*/
    menor = maior = vet[0];
    for (int i = 1; i < tam; i++)
    {
        if (vet[i] < menor)
        {
            menor = vet[i];
        }else if (vet[i] > maior)
        {
            maior = vet[i];
        }
    }
    
    amplitude = ceil((maior - menor) * 1.0 / qtdBaldes);
    //printf("amplitude: %d\n", amplitude);

    conteiner *baldes = (conteiner*) malloc(sizeof(conteiner)*qtdBaldes);

    for (int i = 0; i < qtdBaldes; i++)
    {
        baldes[i].balde = (int*) malloc(sizeof(int)*tam);
        baldes[i].topo = 0;
    }

    for (int i = 0; i < tam; i++)
    {
        j = qtdBaldes - 1;
        while (j >= 0)
        {
            //printf("entrei %d\n",j);
            if (vet[i] >= menor + j * amplitude) //((j+1) * amplitude) - amplitude)
            {
                //printf("  entrei\n");
                baldes[j].balde[baldes[j].topo] = vet[i];
                baldes[j].topo++;
                break;
            }
            j--;
        }
    }

    for (int i = 0; i < qtdBaldes; i++)
    {
        //usando a função nativa qsort, achei interresante usa-la para ver como funciona
        qsort(baldes[i].balde, baldes[i].topo, sizeof(int), comparador);
    }

    int aux;
    /*for (int i = 0; i < qtdBaldes; i++)
    {
        aux = baldes[i].topo;
        for (int k = 0; k < aux; k++)
        {
            printf("%d, ",baldes[i].balde[k]);
        }
        printf(".\n");
    }*/

    j = 0;
    for (int i = 0; i < qtdBaldes; i++)
    {
        aux = baldes[i].topo;
        for (int k = 0; k < aux; k++)
        {
            vet[j] = baldes[i].balde[k];
            j++;
        }
    }

    for (int i = 0; i < qtdBaldes; i++)
    {
        free(baldes[i].balde);
    }
    free(baldes);   
}