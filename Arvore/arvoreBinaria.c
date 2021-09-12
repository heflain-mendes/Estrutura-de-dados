#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
}tipoInfo;

struct no
{
    tipoInfo info;
    struct no *esquerda;
    struct no *direita;
};

typedef struct no* arvBi;

arvBi* criarArvore();
int removeNo(struct no *No);
int removeArv(arvBi *raiz);
int arvoreVazia(arvBi *raiz);
int alturaArvore(arvBi *raiz);
int totalNo(arvBi *raiz);
int preOrdem(arvBi *raiz);
int emOrdem(arvBi *raiz);
int posOrdem(arvBi *raiz);
int insere (arvBi *raiz, tipoInfo info);
int removeElemArvore(arvBi *raiz, int chave);
struct no* removeAtual(struct no *Atual);
int busca(arvBi *raiz, int aux);

int main(){
    arvBi *myNo;
    tipoInfo info;

    myNo = criarArvore();

    info.chave = 3;
    insere(myNo,info);

    info.chave = 1;
    insere(myNo,info);

    info.chave = 5;
    insere(myNo,info);

    info.chave = 8;
    insere(myNo,info);

    info.chave = 9;
    insere(myNo,info);

    emOrdem(myNo);

    removeArv(myNo);

    return 0;
}

arvBi* criarArvore(){
    arvBi *raiz = (arvBi*) malloc(sizeof(arvBi));
    if (raiz != NULL)
    {
        *raiz = NULL;
        return raiz;
    }else{
        return NULL;
    }
}

int removeNo(struct no *No){
    if (No != NULL)
    {
        removeNo(No->esquerda);
        removeNo(No->direita);
        free(No);
        No = NULL;
        return 0;
    }else{
        return -1;
    }
}

int removeArv(arvBi *raiz){
    if (*raiz != NULL)
    {
        removeNo(*raiz);
    }
    free(raiz);
}

int arvoreVazia(arvBi *raiz){
    if (raiz == NULL || *raiz == NULL )
    {
        return 1;
    }else{
        return 0;
    }
}

int alturaArvore(arvBi *raiz){
    if (raiz == NULL || *raiz == NULL )
    {
        return 0;
    }else{
        int esq = alturaArvore(&(*raiz)->esquerda);
        int dir = alturaArvore(&(*raiz)->direita);
        if (esq >= dir)
        {
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

int totalNo(arvBi *raiz){
    if(*raiz == NULL || raiz == NULL){
        return 0;
    }else{
        int total =  0;
        total += totalNo(&(*raiz)->esquerda);
        total += total + totalNo(&(*raiz)->direita);
        return total + 1;
    }
}

int preOrdem(arvBi *raiz){
    if (*raiz == NULL || raiz == NULL)
    {
        return 1;
    }else{
        printf("%d ", (*raiz)->info.chave);
        preOrdem(&(*raiz)->esquerda);
        preOrdem(&(*raiz)->direita);
        return 0;
    }
}

int emOrdem(arvBi *raiz){
    if (*raiz == NULL || raiz == NULL)
    {
        return 1;
    }else{
        preOrdem(&(*raiz)->esquerda);
        printf("%d ", (*raiz)->info.chave);
        preOrdem(&(*raiz)->direita);
        return 0;
    }
}

int posOrdem(arvBi *raiz){
    if (*raiz == NULL || raiz == NULL)
    {
        return 1;
    }else{
        posOrdem(&(*raiz)->esquerda);
        posOrdem(&(*raiz)->direita);
        printf("%d ", (*raiz)->info.chave);
        return 0;
    }
}

int insere(arvBi *raiz, tipoInfo info){
    if (raiz == NULL)
    {
        return 1;
    }else{
        struct no *novo = (struct no*) malloc(sizeof (struct no));
        if (novo != NULL)
        {
            novo->info = info;
            novo->direita = NULL;
            novo->esquerda = NULL;

            if (*raiz == NULL)
            {
                *raiz = novo;
            }else{
                struct no *atual = *raiz;
                struct no *anterior;
                while (atual != NULL)
                {
                    anterior = atual;
                    if (atual->info.chave == info.chave)
                    {
                        free(novo);
                        return 1; //elemento existente
                    }
                    if (info.chave < atual->info.chave  )//menor elemento ficaram a esquerda
                    {
                        atual = atual->esquerda;
                    }else{
                        atual = atual->direita;
                    }
                }
                if(info.chave < anterior->info.chave)
                {
                    anterior->esquerda = novo;
                }else{
                     anterior->direita = novo;
                }
            }
            return 0;
        }
    }
}

struct no* removeAtual(struct no *atual){
    struct no *no1;
    struct no *no2;

    if (atual->esquerda == NULL)
    {
        no2 = atual->direita;

        free(atual);
        return no2;
    }else{
        no1 = atual;
        no2 = atual->esquerda;

        while (no2->direita != NULL)
        {
            no1 = no2;
            no2 = no2->direita;
        }

        if (no1 != atual)
        {
            no1->direita = no2->esquerda;
            no2->esquerda = atual->esquerda;
        }
        no2->direita = atual->direita;
        free(atual);
        return no2;
    }
}

int removeElemArvore(arvBi *raiz, int aux){
    if (raiz != NULL)
    {
        struct no *anterior;
        struct no *atual = *raiz;

        while (atual != NULL)
        {
            anterior = atual;

            if (atual->info.chave == aux)
            {
                if (atual == *raiz)
                {
                    *raiz = removeAtual(atual);
                }else{
                    if (anterior->direita == atual)
                    {
                        anterior->direita = removeAtual(atual);
                    }else{
                        anterior->esquerda = removeAtual(atual);
                    }
                }

                return 0;
            }

            if (aux > atual->info.chave)
            {
                atual = atual->direita;
            }else{
                atual = atual->esquerda;
            }
            
        }
    }
    return 1;
}

int busca(arvBi *raiz, int aux){
    struct no *atual;
    if (*raiz == NULL)
    {
        return 1;
    }else{
        atual = *raiz;
        while(atual != NULL)
        {
            if (atual->info.chave == aux)
            {
                return 0;
            }else{
                if (aux > atual->info.chave)
                {
                    atual = atual->direita;
                }else{
                    atual = atual->esquerda;
                }   
            }
        }
    }
    return 1;
}