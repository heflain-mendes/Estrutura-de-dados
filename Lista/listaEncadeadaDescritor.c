#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
}TipoInfo;

typedef struct kk
{
    TipoInfo dado;
    struct kk *proximo;
}tipoNo;

typedef struct 
{
    tipoNo *primeiro;
    int qtdElem;
    tipoNo *ultimo;
}Descritor;

int criarListaVazia(Descritor *d);
int insereInicio(Descritor *d, TipoInfo info);
int insereFinal(Descritor *d, TipoInfo info);
int inserePossicao(Descritor *d, TipoInfo info, int pos);
int imprimeLista(Descritor *d);
int limparLista(Descritor *d);
int removerElemento(Descritor *d, int pos);
int divideLista(Descritor *d, Descritor **g, int pos);
int resgataElemento(Descritor *d,TipoInfo *b, int pos);


int main(){
    Descritor des;
    TipoInfo dado;
    criarListaVazia(&des);

    dado.chave = 1;
    insereInicio(&des, dado);

    dado.chave = 2;
    insereFinal(&des, dado); 

    dado.chave = 3;
    insereFinal(&des, dado); 

    dado.chave = 4;
    insereFinal(&des, dado); 

    removerElemento(&des, 4);
    removerElemento(&des, 1);

    dado.chave = 4;
    insereFinal(&des, dado);


    imprimeLista(&des);

    limparLista(&des);

    return 0;
}

int criarListaVazia(Descritor *d){
    d->primeiro = NULL;
    d->qtdElem = 0;
    d->ultimo = NULL;

    return 0;
}

int insereInicio(Descritor *d, TipoInfo info){
    tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));

    if (aux == NULL)
    {
        return -1;
    }else{
        aux->dado = info;
        aux->proximo = d->primeiro;
        d->primeiro = aux;

        d->qtdElem++;

        if (d->ultimo == NULL)
        {
            d->ultimo = aux;
        }   
    }
}

int insereFinal(Descritor *d, TipoInfo info){
    tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));

    if (aux == NULL){
        return -1;
    }else{
        aux->dado = info;
        aux->proximo = NULL;

        if (d->ultimo == NULL)
        {
            d->primeiro = aux;
            d->qtdElem++;
            d->ultimo = aux;
        }else{
            d->ultimo->proximo = aux;
            d->ultimo = aux;
            d->qtdElem++;
        }
    }
}

int inserePossicao(Descritor *d, TipoInfo info, int pos){
    tipoNo *anterior;
    tipoNo *atual;
    tipoNo *novono;

    if (pos == 1)
    {
        insereInicio(d, info);
    }else{
        if (pos > d->qtdElem)
        {
            insereFinal(d, info);
        }else{
            novono = (tipoNo*) malloc(sizeof(tipoNo));
            if (novono = NULL)
            {
                return -1;
            }else{
                atual = d->primeiro;
                for (int i = 1; i < pos; i++)
                {
                    anterior = atual;
                    atual = atual->proximo;
                }
                novono->proximo = atual;
                anterior->proximo = novono;
            }
            
        }
        
    }
    return 0;
}

int imprimeLista(Descritor *d){
    tipoNo *aux = d->primeiro;
    while (aux != NULL)
    {
        printf("%d, ", aux->dado.chave);
        aux = aux->proximo;
    }
    return 0;
}

int limparLista(Descritor *d){
    tipoNo *atual = d->primeiro;
    tipoNo *anterior;

    while (atual != NULL){
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }

    d->qtdElem = 0;
    d->primeiro = NULL;
    d->ultimo = NULL;
    return 0;
}

int removerElemento(Descritor *d, int pos){
    tipoNo *atual;
    tipoNo *anterior;

    if (d->qtdElem < pos){
        return 1;
    }else{
        if (pos == 1)
        {
            atual = d->primeiro;
            d->primeiro = atual->proximo;
            free(atual);
            if (pos == d->qtdElem){
                d->ultimo = NULL;
            }
            
        }else{
            atual = d->primeiro->proximo;
            anterior = d->primeiro;
            for (int i = 2; i < pos; i++){
                anterior = atual;
                atual = anterior->proximo;
            }
            if (d->qtdElem == pos){
                d->ultimo = anterior;
            }
            
            anterior->proximo = atual->proximo;
            free(atual);
        }
        d->qtdElem--;

    }
}

int divideLista(Descritor *d, Descritor **g, int pos){
    tipoNo *a;
    a = d->primeiro;

    *g = (Descritor*) malloc(sizeof(Descritor));

    if (*g == NULL){
        return -1;
    }else{
        if (pos == 0)
        {
            **g = *d;
            d->primeiro = NULL;
            d->ultimo = NULL;
            d->qtdElem = 0;
        }else{
            for (int i = 1; i < pos && a->proximo != NULL; i++){
                a = a->proximo;
            }

            if (a->proximo != NULL)
            {
                (*g)->primeiro = a->proximo;
                (*g)->ultimo = d->ultimo;
                (*g)->qtdElem = d->qtdElem - pos;

                d->qtdElem = pos;
                a->proximo = NULL;
                d->ultimo = a;

            }else{
                return -2;
            }
        }
    }

    return 0;
}

int resgataElemento(Descritor *d,TipoInfo *b, int pos){
    tipoNo *a = d->primeiro;

    for (int i = 1; i < pos; i++){
        a = a->proximo;
    }
    b->chave = a->dado.chave;

    return 0;
}
