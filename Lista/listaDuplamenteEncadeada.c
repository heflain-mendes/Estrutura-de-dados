#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int chave;
}tipoInfo;

typedef struct k
{
    struct k *anterior;
    tipoInfo info;
    struct k *proximo;
}tipoNo;

int iniciarLista(tipoNo **L);
int adicionarInicio(tipoNo **L, tipoInfo info);
int adicionarFim(tipoNo **L, tipoInfo info);
int adicionarPos(tipoNo **L, tipoInfo info, int pos);
int removerNo(tipoNo **L, int pos);
int limparLista(tipoNo **L);
int imprimirLista(tipoNo *L);
int imprimirListaInverso(tipoNo *L);
//exercício 02
//int maiores(NoLista** l, int n); prototipo original
int maiores(tipoNo **L, int n);
//exercício 07
//void liberarLista(NoLista** l);
void liberarListaRercursiva(tipoNo **L);
//exercicio 08;
//NoLista* buscaRecursiva(NoLista** l, int v);
tipoNo* buscaRecursiva(tipoNo **L, int v);

int main(){
    tipoNo *L;
    iniciarLista(&L);
    tipoNo *aux;

    tipoInfo info;

    info.chave = 2;
    adicionarPos(&L, info, 1);
    info.chave = 1;
    adicionarPos(&L, info, 1);
    info.chave = 4;
    adicionarPos(&L, info, 4);
    info.chave = 3;
    adicionarPos(&L, info, 3);

    removerNo(&L, 1);

    imprimirLista(L);
    putchar('\n');

    imprimirListaInverso(L);
    putchar('\n');

    aux = buscaRecursiva(&L, 3);
    if(aux != NULL){
        printf("\n%d\n",aux->info.chave);
    }else{
        printf("elemento não encontrado\n");
    }

    liberarListaRercursiva(&L);

    return 0;
}

int iniciarLista(tipoNo **L){
    *L = NULL;
    return 0;
}

int adicionarInicio(tipoNo **L, tipoInfo info){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo)); 
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        novoNo->anterior = NULL;
        novoNo->info = info;
        novoNo->proximo = *L;

        if (novoNo->proximo != NULL)
        {
            (*L)->anterior = novoNo;
        }

        *L = novoNo;   
    }

    return 0;
}

int adicionarFim(tipoNo **L, tipoInfo info){
    tipoNo *aux;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        novoNo->proximo = NULL;
        novoNo->info = info;
        if (*L == NULL)
        {
            *L = novoNo;
            novoNo->anterior = NULL;
        }else
        {
            aux = *L;
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            novoNo->anterior = aux;
            aux->proximo = novoNo;
        }
    }
    return 0;
}

int adicionarPos(tipoNo **L, tipoInfo info, int pos){
    tipoNo *atual;
    tipoNo *anterior;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        if (pos == 1 || *L == NULL)
        {
            novoNo->proximo = *L;
            novoNo->info = info;
            novoNo->anterior = NULL;
            if (novoNo->proximo != NULL)
            {
                (*L)->anterior = novoNo;
            }
            *L = novoNo;
        }else
        {
            atual = *L;
            for (int i = 1; i < pos && atual != NULL; i++)
            {
                anterior = atual;
                atual = atual->proximo;
            }

            if (atual == NULL)
            {
                novoNo->proximo = atual;
                novoNo->info = info;
                novoNo->anterior = anterior;
                anterior->proximo = novoNo;
            }else{
                novoNo->proximo = atual;
                novoNo->info = info;
                novoNo->anterior = anterior;

                atual->anterior = novoNo;
                anterior->proximo = novoNo;
            }
        }
    }
    return 0;
}

int removerNo(tipoNo **L, int pos){
    tipoNo *anterior;
    tipoNo *atual;

    if (*L != NULL & pos == 1)
    {
        atual = *L;
        *L = atual->proximo;
        if (atual->proximo != NULL)
        {
            atual->proximo->anterior = NULL;
        }
        free(atual);
    }else
    {
        atual = *L;
        for (int i = 1; i < pos; i++)
        {
            anterior = atual;
            atual = atual->proximo;
            if (atual == NULL)
            {
                return -2;//posição invalida
            }
        }
        anterior->proximo = atual->proximo;
        if (atual->proximo != NULL)
        {
            atual->proximo->anterior = anterior;
        }
        free(atual);
    }
    

}

int imprimirLista(tipoNo *L){
    while (L != NULL)
    {
        printf("%d, ", L->info.chave);
        L = L->proximo;
    }
    return 0;
}

int imprimirListaInverso(tipoNo *L){
    if(L != NULL){
        while (L->proximo != NULL)
        {
            L = L->proximo;
        }

        while (L != NULL)
        {
            printf("%d, ", L->info.chave);
            L = L->anterior;
        }
    }
    return 0;
}

int limparLista(tipoNo **L){
    tipoNo *atual;
    tipoNo *anterior;

    if (*L != NULL){
        atual = *L;
        while (atual != NULL)
        {
            anterior = atual;
            atual = atual->proximo;
            free(anterior);
        }
        *L = NULL;
    }
    return 0;
}

int maiores(tipoNo **L, int n){
    int cont = 0;//contador
    tipoNo *atual;

    if(*L != NULL){
        for(atual = *L; atual != NULL; atual = atual->proximo){
            if(atual->info.chave > n){
                cont++;
            }
        }
    }

    return cont;
}


void liberarListaRercursiva(tipoNo **L){
    tipoNo *atual, *anterior;
    if(*L != NULL){
        atual = (*L)->proximo;
        anterior = *L;
        free(anterior);
        *L = NULL;
        liberarListaRercursiva(&atual);
    }
}

tipoNo* buscaRecursiva(tipoNo **L, int v){
    tipoNo *atual;

    if(*L != NULL){
        atual = *L;
        if(atual->info.chave == v){
            return atual;
        }
        return buscaRecursiva(&(atual->proximo), v);
    }else{
        return NULL;
    }
}