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

typedef struct kk
{
    int qtd;
    tipoNo
 *primeiro;
    tipoNo
 *ultimo;
}Descritor;

int criarLista(Descritor **L);
int adicionarInicio(Descritor *L, tipoInfo info);
int adicionarfinal(Descritor *L, tipoInfo info);
int imprimirLista(Descritor *L);
int imprimirListaInverso(Descritor *L);
int adicionarPosicao(Descritor *L, tipoInfo info, int pos);
int removerElemento(Descritor *L, int pos);
int limparLista(Descritor *L);

int main(){
    tipoInfo info;
    Descritor *L;
    criarLista(&L);

    info.chave = 2;
    adicionarPosicao(L, info, 1);

    info.chave = 1;
    adicionarPosicao(L, info, 1);

    info.chave = 4;
    adicionarPosicao(L, info, 4);

    info.chave = 3;
    adicionarPosicao(L, info, 3);

    removerElemento(L, 4);

    imprimirLista(L);
    putchar('\n');
    imprimirListaInverso(L);

    limparLista(L);
    
    return 0;
}

int criarLista(Descritor **L){
    tipoNo
 *primeiro, *ultimo;

    primeiro = (tipoNo
*) malloc(sizeof(tipoNo
));
    ultimo = (tipoNo
*) malloc(sizeof(tipoNo
));

    *L = (Descritor*) malloc(sizeof(Descritor));

    if (*L == NULL || primeiro == NULL || ultimo == NULL)
    {
        return -1;
    }else
    {
        primeiro->anterior = NULL;
        primeiro->proximo = ultimo;
        ultimo->proximo = NULL;
        ultimo->anterior = primeiro;

        (*L)->primeiro = primeiro;
        (*L)->ultimo = ultimo;
        (*L)->qtd = 0;
    }
    
    return 0;
}

int adicionarInicio(Descritor *L, tipoInfo info){
    tipoNo
 *aux;
    tipoNo
 *novoNo = (tipoNo
*) malloc(sizeof(tipoNo
));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        aux = L->primeiro;

        novoNo->anterior = aux;
        novoNo->info = info;
        novoNo->proximo = aux->proximo;

        aux->proximo->anterior = novoNo;
        aux->proximo = novoNo;

        L->qtd++;
    }
    return 0;
}

int adicionarfinal(Descritor *L, tipoInfo info){
    tipoNo
 *aux;
     tipoNo
     *novoNo = (tipoNo
    *) malloc(sizeof(tipoNo
    ));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        aux = L->ultimo;

        novoNo->proximo = aux;
        novoNo->info = info;
        novoNo->anterior = aux->anterior;

        aux->anterior->proximo = novoNo;
        aux->anterior = novoNo;

        L->qtd++;
    }
}

int imprimirLista(Descritor *L){
    tipoNo
* aux = L->primeiro->proximo;
    while (aux->proximo != NULL)
    {
        printf("%d, ",aux->info.chave);
        aux = aux->proximo;
    }
    return 0;
}

int imprimirListaInverso(Descritor *L){
    tipoNo
* aux = L->ultimo->anterior;
    while (aux->anterior != NULL)
    {
        printf("%d, ",aux->info.chave);
        aux = aux->anterior;
    }
    return 0;
}

int adicionarPosicao(Descritor *L, tipoInfo info, int pos){
    int num = L->qtd;
    tipoNo
 *aux;
    tipoNo
 *novoNo = (tipoNo
*) malloc(sizeof(tipoNo
));
    if (novoNo == NULL)
    {
        return -1;
    }else
    {
        if (pos > num)
        {
            aux = L->ultimo;

            novoNo->proximo = aux;
            novoNo->info = info;
            novoNo->anterior = aux->anterior;

            aux->anterior->proximo = novoNo;
            aux->anterior = novoNo;

            L->qtd++;
        }else
        {
            aux = L->primeiro->proximo;

            for (int i = 1; i < pos; i++)
            {
                aux= aux->proximo;
            }

            novoNo->proximo = aux;
            novoNo->info = info;
            novoNo->anterior = aux->anterior;

            aux->anterior->proximo = novoNo;
            aux->anterior = novoNo;

            L->qtd++;
        }
    }
    return 0;
}

int removerElemento(Descritor *L, int pos){
    tipoNo
 *aux, *anterior, *atual;

    atual = L->primeiro;

    if (pos <= L->qtd)
    {
        for (int i = 0; i < pos; i++)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        aux = atual;
        atual = atual->proximo;

        anterior->proximo = atual;
        atual->anterior = anterior;

        free(aux);

        L->qtd--;
    }

    return 0;
}

int limparLista(Descritor *L){
    tipoNo
 *anterior, *atual;
    atual = L->primeiro;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    
    free(L);

    return 0;
}