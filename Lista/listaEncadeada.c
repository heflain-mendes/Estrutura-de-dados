#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
}tipoInfo;

typedef struct Lista
{
    tipoInfo info;
    struct Lista *proximo;
}tipoNo;

int fazVazia(tipoNo **L);
int insereInicio(tipoNo **L, tipoInfo info);
int insereFinal(tipoNo **L, tipoInfo info);
int imprime(tipoNo *L);
int imprimeRercursivo(tipoNo *L);
int imprimeInversoRercursivo(tipoNo *L);
int inserePosicao(tipoNo **L, tipoInfo info, int pos);
int removePossicao(tipoNo **L, int pos);
int limparLista(tipoNo **L);
int divideLista(tipoNo **L, tipoNo **H, int pos);
tipoInfo resgatar(tipoNo *L, int pos);
tipoNo* intercalaListas(tipoNo **x, tipoNo **y);
tipoNo* intercalaListasrecursiva(tipoNo **x, tipoNo **y);
tipoNo* separa(tipoNo **L, int n);

int main(){
    tipoNo *l, *h;
    tipoInfo info;
    fazVazia(&l);
    fazVazia(&h);

    info.chave = 4;
    insereInicio(&l, info);

    info.chave = 3;
    insereInicio(&l, info);

    info.chave = 2;
    insereInicio(&l, info);

    info.chave = 1;
    insereInicio(&l, info);

    info.chave = 8;
    insereInicio(&l, info);

    info.chave = 20;
    insereInicio(&l, info);

    info.chave = 3;
    insereInicio(&l, info);

    imprime(l);
    putchar('\n');

    h = separa(&l, 2);
    
    imprime(h);
    putchar('\n');

    imprime(l);
    putchar('\n');

    limparLista(&l);
    limparLista(&h);
    return 0;
}

tipoNo* separa(tipoNo **L, int n){
    tipoNo *retorno, *atual, *seguinte;
    
    for(atual = *L;atual->info.chave != n && atual->proximo != NULL; atual = atual->proximo){
    }

    seguinte = atual->proximo;
    atual->proximo = NULL;

    return seguinte;
}

int fazVazia(tipoNo **L){
    *L = NULL;
    return 0;
}

int insereInicio(tipoNo **L, tipoInfo info){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else{
        novoNo->info = info;
        novoNo->proximo = *L;
        *L = novoNo;
    }

    return 0;
}

int insereFinal(tipoNo **L, tipoInfo info){
    tipoNo *no_anterior, *no_atual;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else{
        novoNo->info = info;
        novoNo->proximo = NULL;

        if (*L == NULL)
        {
            *L = novoNo;
        }else{
            no_atual = (*L)->proximo;
            no_anterior = *L;

            while (no_atual != NULL)
            {
                no_anterior = no_atual;
                no_atual = no_atual->proximo;
            }
            
            no_anterior->proximo = novoNo;
        }
    }
}


int inserePosicao(tipoNo **L, tipoInfo info, int pos){
    tipoNo *no_anterior, *no_atual;
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL){
        return -1;
    }else{
        novoNo->info = info;
        if (*L == NULL || pos == 1){
            novoNo->proximo = *L;
            *L = novoNo;
        }else{
            no_anterior = *L;
            no_atual = (*L)->proximo;
            for (int i = 2; i < pos && no_atual != NULL; i++)
            {
                no_anterior = no_atual;
                no_atual = no_atual->proximo;
            }
            no_anterior->proximo = novoNo;
            novoNo->proximo = no_atual;
        }

        return 0;
    }
    
}
int removePossicao(tipoNo **L, int pos){
    tipoNo *anterior;
    tipoNo *atual;
    tipoNo *aux;

    if (pos == 1)
    {
        if (*L == NULL)
        {
            return 2;
        }else{
            atual = *L;
            *L = (*L)->proximo;
            free(atual);
        }
    }else{
        atual = *L;
        for (int i = 1; i < pos && atual != NULL; i++)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual == NULL){
            return 2;
        }else{
            if (atual->proximo == NULL)
            {
                free(atual);
                anterior->proximo = NULL;
            }else{
                aux = atual;
                atual = atual->proximo;
                anterior->proximo = atual;
                free(aux);
            }
            return 0;
        }
    }
}

int imprime(tipoNo *L){
    while (L != NULL)
    {
        printf("%d, ", L->info.chave);
        L = L->proximo;
    }
    
    return 0;
}

int limparLista(tipoNo **L){
    tipoNo *no_anterior, *no_atual;

    no_atual = *L;

    while (no_atual != NULL){
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
        free(no_anterior);
    }

    *L = NULL;

    return 0;
}

int divideLista(tipoNo **L, tipoNo **H, int pos){
    tipoNo *atual, *anterior;
    if (pos == 0)
    {
        *H = *L;
        *L = NULL;
    }
    else
    {
        atual = (*L)->proximo;
        for (int i = 0;i < pos && atual != NULL;i++)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        anterior->proximo = NULL;
        *H = atual;
    }

    return 0;
}

int imprimeInversoRercursivo(tipoNo *L){
    if (L != NULL)
    {
        imprimeInversoRercursivo(L->proximo);
        printf("%d", L->info.chave);
    }
    
    return 0;
}

int imprimeRercursivo(tipoNo *L){
    if(L != NULL){
        printf("%d, ",L->info.chave);
        imprimeRercursivo(L->proximo);
    }

    return 0;
}

tipoInfo resgatar(tipoNo *L, int pos){
    for (int i = 1; i < pos && L->proximo != NULL; i++)
    {
        L = L->proximo;
    }

    return L->info;
}

tipoNo* intercalaListas(tipoNo **x, tipoNo **y){
    tipoNo *par, *impar, *aux, *retorno;
    par = *y;
    impar = *x;

    retorno = impar;//pode retorna diretamente o *x
    aux = impar;
    impar = impar->proximo;

    for(int i = 2;par != NULL || impar != NULL ;i++){
        if(i % 2 == 0 && par != NULL){
            aux->proximo = par;
            aux = aux->proximo;
            par = par->proximo;
        }else{
            if(impar != NULL){
                aux->proximo = impar;
                aux = aux->proximo;
                impar = impar->proximo;
            }
        }
    }

    return retorno;
}

tipoNo* intercalaListasrecursiva(tipoNo **x, tipoNo **y){
    if(*x != NULL){
        (*x)->proximo = intercalaListasrecursiva(y, &((*x)->proximo));
        return *x;
    }else
    {
        if(*y != NULL){
            (*y)->proximo = intercalaListasrecursiva(x, &((*y)->proximo));
            return *y;
        }
    }
}