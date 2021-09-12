#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct k
{
    int chave;
}tipoInfo;

typedef struct{
    tipoInfo info[TAM];
    int ultimo;
    int primeiro;
}tipoFila;

int criarVavia(tipoFila *F);
int adicionarNo(tipoFila *F, tipoInfo info);
int imprimir(tipoFila *F);
int remove01(tipoFila *F);
int remove02(tipoFila *F);

int main(){
    tipoFila fila;
    tipoInfo info;

    criarVavia(&fila);
    
    info.chave = 1;
    adicionarNo(&fila, info);

    info.chave = 2;
    adicionarNo(&fila, info);

    info.chave = 3;
    adicionarNo(&fila, info);

    remove02(&fila);

    imprimir(&fila);

    return 0;
}

int criarVavia(tipoFila *F){
    F->primeiro = 0;
    F->ultimo = -1;
}

int adicionarNo(tipoFila *F, tipoInfo info){
    if (F->ultimo < TAM - 1)
    {
        F->ultimo++;
        F->info[F->ultimo] = info;
        return 0;
    }else{
        return -1;
    }
}

int imprimir(tipoFila *F){
    int a = F->ultimo;

    for (int i = F->primeiro; i <= a; i++)
    {
        printf("%d, ", F->info[i].chave);
    }
}

int remove01(tipoFila *F){
    if (F->primeiro < TAM)
    {
        F->primeiro++;
        return 0;
    }
    else{
        return -1;
    }
}

int remove02(tipoFila *F){
    int a = F->ultimo;
    
    if (F->primeiro <= a )//existe itens na fila
    {
        for ( int i = F->primeiro; i < a; i++)
        {
            F->info[i] = F->info[i + 1];
        }

        F->ultimo--;
    }  
}

