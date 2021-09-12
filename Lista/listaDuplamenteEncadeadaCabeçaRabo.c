#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int chave;
}tipoInfo;

typedef struct k
{
    struct k *proximo;
    tipoInfo info;
    struct k *anterior;
}tipoNo;

int criarLista(tipoNo **L);
int adicionarInicio(tipoNo **L, tipoInfo info);
int adicionarfinal(tipoNo **L, tipoInfo info);
int adicionarPosicao(tipoNo **L, tipoInfo info, int pos);
int removerElemento(tipoNo **L, int pos);
int removerLista(tipoNo **L);
int imprimirLista(tipoNo *L);
int divideLista(tipoNo **L, tipoNo **H, int pos);
int imprimirListaInverso(tipoNo *L);

int main(){
    tipoInfo info;
    tipoNo *L, *H;
    criarLista(&L);

    info.chave = 2;
    adicionarInicio(&L, info);

    info.chave = 1;
    adicionarPosicao(&L, info, 1);

    info.chave = 3;
    adicionarPosicao(&L, info, 3);

    info.chave = 4;
    adicionarPosicao(&L, info, 4);

    info.chave = 5;
    adicionarPosicao(&L, info, 5);

    info.chave = 6;
    adicionarPosicao(&L, info, 6);

    divideLista(&L, &H, 3);

    imprimirLista(L);
    putchar('\n');
    imprimirListaInverso(L);
    putchar('\n');

    imprimirLista(H);
    putchar('\n');
    imprimirListaInverso(H);
    putchar('\n');

    removerLista(&L);
    removerLista(&H);
    return 0;
}

int criarLista(tipoNo **L){
    tipoNo *fim;
    tipoNo *ini = (tipoNo*) malloc(sizeof(tipoNo));
    if (ini == NULL)
    {
        return -1;
    }else
    {
        ini->anterior = NULL;
        fim = (tipoNo*) malloc(sizeof(tipoNo));
        if (fim == NULL)
        {
            return -1;
        }else
        {
            fim->proximo = NULL;
            ini->proximo = fim;
            fim->anterior = ini;
            *L = ini;
        }
    }
    return 0;
}

int adicionarInicio(tipoNo **L, tipoInfo info){
    tipoNo *anterior, *atual;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        anterior = *L;
        atual = anterior->proximo;

        novoNo->info = info;
        novoNo->anterior = anterior;
        novoNo->proximo = atual;
        
        anterior->proximo = novoNo;
        atual->anterior = novoNo;
    }
    
    return 0;
}

int adicionarfinal(tipoNo **L, tipoInfo info){
    tipoNo *anterior, *atual;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        anterior = *L;
        atual = anterior->proximo;
        while (atual->proximo != NULL)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        novoNo->info = info;
        novoNo->anterior = anterior;
        novoNo->proximo = atual;

        anterior->proximo = novoNo;
        atual->anterior = novoNo;
    }
    return 0;
}

int imprimirLista(tipoNo *L){
    L = L->proximo;
    while (L->proximo != NULL)
    {
        printf("%d, ",L->info.chave);
        L = L->proximo;
    }
    return 0;
}

int imprimirListaInverso(tipoNo *L){
    L = L->proximo;
    while (L->proximo != NULL)
    {
        L = L->proximo;
    }
    L = L->anterior;
    while (L->anterior != NULL)
    {
        printf("%d, ",L->info.chave);
        L = L->anterior;
    }
    
    return 0;
}

int adicionarPosicao(tipoNo **L, tipoInfo info, int pos){
    tipoNo *anterior, *atual;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        novoNo->info = info;

        anterior = *L;
        atual = anterior->proximo;

        for (int i = 1; i < pos && atual->proximo != NULL; i++)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        novoNo->anterior = anterior;
        novoNo->proximo = atual;

        anterior->proximo = novoNo;
        atual->anterior = novoNo;
    } 
    return 0;
}
int removerElemento(tipoNo **L, int pos){
    tipoNo *anterior = *L;
    tipoNo *atual = anterior->proximo;
    tipoNo *aux;

    if (atual->proximo == NULL)
    {
        return -1;// Lista vazia
    }

    for (int i = 1; i < pos; i++)
    {
        anterior = atual;
        atual = atual->proximo;

        if (atual->proximo == NULL)
        {
            return -2;// posição invalida
        }
    }

    aux = atual;
    atual = atual->proximo;

    anterior->proximo = atual;
    atual->anterior = anterior;

    free(aux);

    return 0;
}

int removerLista(tipoNo **L){
    tipoNo *anterior = *L;
    tipoNo *atual = anterior->proximo;

    while (atual != NULL)
    {
        free(anterior);
        anterior = atual;
        atual = atual->proximo;
    }

    *L = NULL;

    return 0;
}

int divideLista(tipoNo **L, tipoNo **H, int pos){
    tipoNo *aux;
    tipoNo *anterior, *atual;
    anterior = *L;
    atual = anterior->proximo;

    *H = (tipoNo*)malloc(sizeof(tipoNo));
    aux = (tipoNo*)malloc(sizeof(tipoNo));

    if ((*H) == NULL || aux == NULL)
    {
        return -1;
    }else{
        (*H)->anterior = NULL;
        aux->proximo = NULL;

        if (atual->proximo == NULL)
        {
            return -2; //problema no tamanho da lista
        }
        
        for ( int i = 1; i < pos; i++)
        {
            anterior = atual;
            atual = atual->proximo;

            if (atual->proximo == NULL)
            {
                return -2; //problema no tamanho da lista
            }
        }

        anterior->proximo = aux;
        aux->anterior = anterior;

        (*H)->proximo = atual;
        atual->anterior = *H;
    }

    return 0;
}