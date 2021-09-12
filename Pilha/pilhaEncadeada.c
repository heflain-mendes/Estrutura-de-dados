#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int chave;
}tipoInfo;

typedef struct p
{
    tipoInfo info;
    struct p *proximo;
}tipoNo;

int criarVazia(tipoNo **P);
int adicionarNo(tipoNo **P, tipoInfo info);
int removerNo(tipoNo **P);
int imprime(tipoNo *P);
int limpar(tipoNo **P);

int main(){
    tipoInfo inf;
    tipoNo *p;

    criarVazia(&p);

    inf.chave = 1;
    adicionarNo(&p, inf);

    inf.chave = 2;
    adicionarNo(&p, inf);

    inf.chave = 3;
    adicionarNo(&p, inf);

    inf.chave = 4;
    adicionarNo(&p, inf);

    removerNo(&p);

    imprime(p);

    limpar(&p);

    return 0;
}

int criarVazia(tipoNo **P){
    *P = NULL;

    return 0;
}

int adicionarNo(tipoNo **P, tipoInfo info){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo != NULL)
    {
        novoNo->info = info;
        novoNo->proximo = *P;
        *P = novoNo;

        return 0;//sucesso
    }

    return -1;//falha na criação da pilha
}

int removerNo(tipoNo **P){
    tipoNo *aux;
    if(*P != NULL){//pilha não vazia
        aux = *P;
        *P = aux->proximo;

        free(aux);

        return 0;//sucesso
    }else{
        return -1;//pilha vazia
    }
}

int imprime(tipoNo *P){
    printf("Topo da pilha\n");
    for (tipoNo *a = P ; a != NULL; a = a->proximo)
    {
        printf("  %d\n", a->info.chave);
    }
    printf("base da pilha\n");

    return 0;
}

int limpar(tipoNo **P){
    tipoNo *anterio;
    tipoNo *atual;

    if (*P != NULL)//lista não vazia
    {
        atual = *P;

        while (atual != NULL)
        {
            anterio = atual;
            atual = atual ->proximo;
            free(anterio);
        }

        *P = NULL;

        return 0;//sucesso
    }
    else{
        return 1;//lista já estava vazia
    }
}