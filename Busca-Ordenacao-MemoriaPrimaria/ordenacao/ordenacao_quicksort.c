#include <stdio.h>
#include <stdlib.h>

void particao(int *dados, int esq, int dir, int *i, int *j);
void quicksort(int *dados, int esq, int dir);

int main(){
    int vet[10] = {1, 3, 5, 64, 8, 9, 5, 0, -5, 6};
    quicksort(vet, 0, 9);

    for(int i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}

void particao(int *dados, int esq, int dir, int *i, int *j){
    //printf("fui chamada\n");
    int pivo, aux;
    *i = esq;
    *j = dir;
    pivo = dados[(esq + dir) / 2];

    while (*i <= *j){
        while (dados[*i] < pivo && *i < dir){
            (*i)++;
        }
        
        while (dados[*j] > pivo && *j > esq){
            (*j)--;
        }

        if (*i <= *j){
            aux = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

void quicksort(int *dados, int esq, int dir){
    int i, j;
    particao(dados, esq, dir, &i, &j);
    if(i < dir){
        quicksort(dados, i, dir);
    } 
    if (j > esq)
    {
        quicksort(dados, esq, j);
    }
}