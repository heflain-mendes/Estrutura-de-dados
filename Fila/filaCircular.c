#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct k
{
    int chave;
}tipoInfo;

typedef struct{
    tipoInfo info[TAM];
    int ultimo;
    int primeiro;
    int qtdItens;
}tipoFila;

int criarVazia(tipoFila *F);
int adicionarNo(tipoFila *F, tipoInfo info);
int imprimir(tipoFila *F);
int remove01(tipoFila *F);

int main(){
    tipoFila fila;
    tipoInfo info;

    criarVazia(&fila);
    
    info.chave = 1;
    adicionarNo(&fila, info);

    info.chave = 2;
    adicionarNo(&fila, info);

    info.chave = 3;
    adicionarNo(&fila, info);

    remove01(&fila);

    info.chave = 3;
    adicionarNo(&fila, info);

    remove01(&fila);

    info.chave = 4;
    adicionarNo(&fila, info);

    remove01(&fila);

    imprimir(&fila);

    return 0;
}

int criarVazia(tipoFila *F){
    F->primeiro = 0;
    F->ultimo = -1;
    F->qtdItens = 0;
}

int adicionarNo(tipoFila *F, tipoInfo info){
    if (F->qtdItens < TAM)//verificando se a lista tem espaço disponível, obs: tem que ser o <, pois se for o <= ao incrementa vai da TAM + 1, o que vai apagar o primeiro item da lista
    {
        F->ultimo++;
        if (F->ultimo == TAM)//se após o incremento F->ultimo for igual a TAM, retornamos para a posição 0;
        {
            F->ultimo = 0;
        }
        
        F->info[F->ultimo] = info;
        F->qtdItens++;

        return 0;
    }else{
        return -1;
    }
}

int imprimir(tipoFila *F){
    int a = F->primeiro;

    for (int i = F->qtdItens; i > 0 ; i--, a++)//esse for vai percorrer o vetor, de forma circula.
    {
        if (a == TAM)
        {
            a = 0;
        }
        
        printf("%d, ", F->info[a].chave);
    }
}

int remove01(tipoFila *F){
    if (F->qtdItens > 0)
    {
        F->primeiro++;
        F->qtdItens--;
        return 0;//sucesso
    }
    else{
        return -1;//falha, provavelmente pq a lista ainda não foi criada
    }
}

