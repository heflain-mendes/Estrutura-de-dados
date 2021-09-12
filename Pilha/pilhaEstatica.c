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
}tipoPila;

int criarVazia(tipoPila *P);
int adicionarNo(tipoPila *P, tipoInfo info);
int imprimir(tipoPila *P);
int removeNo(tipoPila *P);
int limpa(tipoPila *P);

int main(){
    tipoInfo inf;
    tipoPila p;

    criarVazia(&p);

    inf.chave = 1;
    adicionarNo(&p, inf);

    inf.chave = 2;
    adicionarNo(&p, inf);

    inf.chave = 3;
    adicionarNo(&p, inf);

    inf.chave = 4;
    adicionarNo(&p, inf);

    removeNo(&p);

    imprimir(&p);



    return 0;
}

int criarVazia(tipoPila *P){
    P->ultimo = -1;

    return 0;
}

int adicionarNo(tipoPila *P, tipoInfo info){
    int a = P->ultimo;
    a++;
    if (a < TAM && a >= 0)// a segunda parte da verificação serve para não permitir que seja usada pilha não "criadas"
    {
        P->info[a] = info;
        P->ultimo++;

        return 0;//sucesso
    }else{
        return -1;//falha
    }   
}

int removeNo(tipoPila *P){
    int a = P->ultimo;
    if (a > -1)//a pilha possui elemntos
    {
        P->ultimo--;
        return 0;//remoção bem sucedida
    }else{
        return -1;//pilha vazia
    }
}

int imprimir(tipoPila *P){
    int a = P->ultimo;
    if (a > -1)//pilha contém elementos
    {
        printf("Topo da pilha\n");
        for (; a >= 0; a--)
        {
            printf("  %d\n", P->info[a].chave);
        }
        printf("Base da pilha\n");

        return 0;//sucesso
    }else{
        return -1;//pilha vazia
    }
}

int limpa(tipoPila *P){
    P->ultimo = -1;
    return 0;
}
