#include <stdio.h>
#include <stdlib.h>

typedef struct I
{
    int chave;
} tipoInfo;

typedef struct N
{
    tipoInfo info;
    struct N *esquerda;
    struct N *direita;
} tipoNo;

int criarArvore(tipoNo **R);
int removeArv(tipoNo **R);
int arvoreVazia(tipoNo **R);
int alturaArvore(tipoNo *R);
int totalNo(tipoNo *R);
int preOrdem(tipoNo *R);
int emOrdem(tipoNo *R);
int posOrdem(tipoNo *R);
int invertiOrdem(tipoNo *R);
int insereNo(tipoNo **R, tipoInfo inf);
int insereNoRecursivo(tipoNo **R, tipoInfo inf);
int removeNo(tipoNo **R, int cod);
tipoNo *removeAtual(tipoNo *R);
int busca(tipoNo *R, int cod);

int main()
{
    tipoNo *arv;
    tipoInfo info;
    criarArvore(&arv);

    info.chave = 5;
    insereNo(&arv, info);

    info.chave = 2;
    insereNoRecursivo(&arv, info);

    info.chave = 7;
    insereNoRecursivo(&arv, info);

    info.chave = 6;
    insereNo(&arv, info);

    printf("%d ", busca(arv, 5));
    printf("%d\n", busca(arv, 10));

    removeNo(&arv, 10);

    emOrdem(arv);
    putchar('\n');
    posOrdem(arv);
    putchar('\n');
    invertiOrdem(arv);
    putchar('\n');

    removeArv(&arv);
}

int criarArvore(tipoNo **R)
{
    *R = NULL;
    return 0;
}

int removeArv(tipoNo **R)
{
    if (*R != NULL)
    {
        removeArv(&(*R)->esquerda);
        removeArv(&(*R)->direita);
        free(*R);
        R = NULL;
        return 0;
    }
    else
    {
        return 1;
    }
}

int arvoreVazia(tipoNo **R)
{
    if (*R != NULL)
    {
        return 0; //arvore vazia
    }
    else
    {
        return 1; //arvore possui elemento
    }
}

int alturaArvore(tipoNo *R)
{
    if (R = NULL)
    {
        return 0;
    }
    else
    {
        int esq = alturaArvore(R->esquerda);
        int dir = alturaArvore(R->direita);
        if (esq >= dir)
        {
            return esq + 1;
        }
        else
        {
            return dir + 1;
        }
    }
}

int totalNo(tipoNo *R)
{
    if (R = NULL)
    {
        return 0;
    }
    else
    {
        int total = alturaArvore(R->esquerda);
        total += alturaArvore(R->direita);

        return total;
    }
}

int preOrdem(tipoNo *R)
{
    if (R != NULL)
    {
        printf("%d ", R->info.chave);
        preOrdem(R->esquerda);
        preOrdem(R->direita);
        return 0;
    }
    else
    {
        return 1;
    }
}
int emOrdem(tipoNo *R)
{
    if (R != NULL)
    {
        emOrdem(R->esquerda);
        printf("%d ", R->info.chave);
        emOrdem(R->direita);
        return 0;
    }
    else
    {
        return 1;
    }
}
int posOrdem(tipoNo *R)
{
    if (R != NULL)
    {
        posOrdem(R->esquerda);
        posOrdem(R->direita);
        printf("%d ", R->info.chave);
        return 0;
    }
    else
    {
        return 1;
    }
}

int invertiOrdem(tipoNo *R)
{
    if (R != NULL)
    {
        invertiOrdem(R->direita);
        printf("%d ", R->info.chave);
        invertiOrdem(R->esquerda);
        return 0;
    }
    else
    {
        return 1;
    }
}

int insereNo(tipoNo **R, tipoInfo inf)
{
    tipoNo *novoNo = (tipoNo *)malloc(sizeof(tipoNo));

    if (novoNo == NULL)
    {
        return 1; //falha na criação do novoNo
    }
    else
    {
        novoNo->info = inf;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        if (*R == NULL) //lista vazia
        {
            *R = novoNo;
        }
        else
        {
            tipoNo *atual = *R;
            tipoNo *anterior;
            while (atual != NULL)
            {
                anterior = atual;
                if (inf.chave < atual->info.chave)
                {
                    atual = atual->esquerda;
                }
                else
                {
                    if (inf.chave > atual->info.chave)
                    {
                        atual = atual->direita;
                    }
                    else
                    { //codigo já cadastrado
                        free(novoNo);
                        return 1;
                    }
                }
            }

            if (inf.chave < anterior->info.chave)
            {
                anterior->esquerda = novoNo;
            }
            else
            {
                anterior->direita = novoNo;
            }
            return 0;
        }
    }
}

int insereNoRecursivo(tipoNo **R, tipoInfo inf)
{
    if (*R == NULL)//lista vazia
    {
        tipoNo *novoNo = (tipoNo *)malloc(sizeof(tipoNo));
        if (novoNo != NULL) //novo no criado com sucesso
        {
            novoNo->direita = NULL;
            novoNo->esquerda = NULL;
            novoNo->info = inf;
            *R= novoNo;
            return 0;// sucesso
        }
        return -1;//novoNo não pode ser criado
    }
    else
    {
        if ((*R)->info.chave == inf.chave)// chave já cadastrada
        {
            return -1;
        }else{
           if ((*R)->info.chave > inf.chave)//chave maior que a do no atual
           {
               return insereNoRecursivo(&(*R)->esquerda, inf);
           }else{//chave menor que a do no atual
               return insereNoRecursivo(&(*R)->direita, inf);
           }
        }
    }
}

tipoNo *removeAtual(tipoNo *R)
{
    //essa função remove o nó e retorna uma sub arvore.
    tipoNo *proximo = R;
    tipoNo *anterior;

    if (R->esquerda == NULL)// se não tiver nó a esquerda do atual
    {
        proximo = R->direita;
        free(R);
        return proximo;
    }
    else//se existir nó a esquerda
    {
        anterior = proximo;
        proximo = proximo->esquerda;
        while (proximo->direita != NULL)//busca o elemento mais a direita a partir do primeiro nó a esquerda
        {
            anterior = proximo;//o endereço do nó mais a direita a parti do no a esquerda do *R ficara armazenado em anterior
            proximo = proximo->direita;
        }

        //tomar cuidado nessa parte
        if (anterior != R)//caso anterior seja diferente de R
        {   
            anterior->direita = proximo->esquerda;
            proximo->esquerda = R->esquerda;
        }
        proximo->direita = R->direita;

        free(R);
        return proximo;
    }
}

int removeNo(tipoNo **R, int cod)
{
    if (*R != NULL) //lista não vazia
    {
        tipoNo *atual = *R;
        tipoNo *anterior;

        while (atual != NULL)//loop até o fim da lista
        {
            anterior = atual;
            if (atual->info.chave == cod)//comparando cod
            {
                if (atual == *R)//se atual apontar para o primeiro nó da arvore
                {
                    *R = removeAtual(atual);
                }
                else
                {
                    //vendo qual o ponteiro do anteiro que aponta para atual
                    if (anterior->esquerda == atual)
                    {
                        anterior->esquerda = removeAtual(atual);
                    }
                    else
                    {
                        anterior->direita = removeAtual(atual);
                    }
                }
            }

            //movendo-se na arvore
            if (cod < atual->info.chave)
            {
                atual = atual->esquerda;
            }
            else
            {
                atual = atual->direita;
            }
        }
    }

    return 1;
}

int busca(tipoNo *R, int cod)
{
    while (R != NULL)//fim da arvore ou arvore vazia
    {
        if (R->info.chave == cod)//cod encontrado
        {
            return 0;
        }
        else//movendo-se na arvore
        {
            if (cod < R->info.chave)
            {
                R = R->esquerda;
            }
            else
            {
                R = R->direita;
            }
        }
    }
    return 1;
}