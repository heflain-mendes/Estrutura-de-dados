#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
}tipoInfo;

typedef struct Fila
{
    tipoInfo info;
    struct Fila *proximo;
}tipoNo;

int fazVazia(tipoNo **F);
int enfileira(tipoNo **F, tipoInfo info);
int desenfileira (tipoNo **F);
int imprime(tipoNo *F);
int limparFila(tipoNo **F);
int comparaFilas(tipoNo *F1, tipoNo *F2);

int main(){ 
    tipoNo *f;
    tipoInfo info;

    fazVazia(&f);

    info.chave = 1;
    enfileira(&f, info);

    info.chave = 2;
    enfileira(&f, info);

    info.chave = 3;
    enfileira(&f, info);

    imprime(f);

    tipoNo *g;

    fazVazia(&g);

    info.chave = 1;
    enfileira(&g, info);

    info.chave = 2;
    enfileira(&g, info);

    info.chave = 1;
    enfileira(&g, info);

    if (comparaFilas(f,g) == 0)
    {
        printf("As lista são iguais\n");
    }else{
        printf("As lista são diferentes\n");
    }
    

    return 0;
}

int fazVazia(tipoNo **F){
    *F = NULL;
    return 0;
}

int enfileira(tipoNo **F, tipoInfo info){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novoNo == NULL)
    {
        return -1;
    }else{
        novoNo->info = info;
        novoNo->proximo = *F;
        *F = novoNo;
    }

    return 0;
}

int desenfileira (tipoNo **F){
    tipoNo *anterior, *atual;
    
    if (*F != NULL)// fila contem elementos
    {
        atual = *F;
        if (atual->proximo == NULL)// a fila contém apena um elemento
        {
            free(atual);
            *F = NULL;

            return 0;//sucesso
        }else{//a fila contém mais de um elemento;
            anterior = atual;
            atual = atual->proximo;


            //chegando ao fim da fila
            while (atual->proximo != NULL)
            {
                anterior = atual;
                atual = atual->proximo;
            }

            anterior->proximo = NULL;
            free(atual);

            return 0; //sucesso
        }
    }

    return 1;//lista vazia
}

int imprime(tipoNo *F){
   if (F != NULL)//Fim da fila ou fila vazia
   {
       imprime(F->proximo);
       printf("%d, ", F->info.chave);
       return 0; //sucesso
   }
   return -1;   
}

int limparFila(tipoNo **F){
    tipoNo *no_anterior, *no_atual;

    no_atual = *F;

    while (no_atual != NULL){
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
        free(no_anterior);
    }

    *F = NULL;

    return 0;
}

int comparaFilas(tipoNo *F1, tipoNo *F2){
    if (F1 != NULL && F2 != NULL)//Filas vazias
    {
        while(F1->info.chave == F2->info.chave)
        {
            F1 = F1->proximo;
            F2 = F2->proximo;

            if (F1 == NULL && F2 == NULL)//chegaram juntas ao final, 
            {
                return 0;// são iguais
            }   
        }

        return 1; //são diferentes
        
    }else{
        return 1;//mesmo que ambas sejam vazias a função ira retorna que são diferentes
    }
}