#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

struct arquivo{
    FILE *f;
    int pos, MAX, *buffer;
};

void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal);
int comparar(const void *a, const void *b);
int criarAquivosOrdenados(char *nome);
void preencheBuffer(struct arquivo* arq, int K);
int proucuraMenor(struct arquivo *arq, int numArqs, int K, int *menor);
void merge(char *nome, int numArqs, int K);
void criarAquivoTeste(char *nome);
void mergeSortExterno(char *nome);

int main(){
    criarAquivoTeste("dados.txt");
    mergeSortExterno("dados.txt");
    return 0;
}

void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal){
    int i;
    FILE *f = fopen(nome, "a");

    for (i = 0; i < tam - 1; i++){
        fprintf(f,"%d\n",V[i]);
    }

    if (mudaLinhaFinal == 0)
    {
        fprintf(f,"%d", V[tam - 1]); 
    }else{
        fprintf(f,"%d\n", V[tam - 1]); 
    }
    
    fclose(f);
}

int comparar(const void *a, const void *b){
    int va = *((int*)a);
    int vb = *((int*)b);

    return va-vb;
}

int criarAquivosOrdenados(char *nome){
    int V[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");

    while (!feof(f))
    {
        fscanf(f, "%d", &V[total]);
        total++;
        if (total == N)
        {
            cont++;
            sprintf(novo, "Temp%d.txt",cont);
            qsort(V, total, sizeof(int), comparar);
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }   
    }
    if (total > 0)
    {
        cont++;
        sprintf(novo,"Temp%d.txt", cont);
        qsort(V, total, sizeof(int), comparar);
        salvaArquivo(novo, V, total, 0);
    }
    fclose(f);
    return cont;
}

void preencheBuffer(struct arquivo* arq, int K){
    int i;
    if (arq->f == NULL)
    {
        return;
    }
    
    arq->pos = 0;
    arq->MAX = 0;

    for (i = 0; i < K; i++)
    {
        if (!feof(arq->f))
        {
            fscanf(arq->f,"%d",&arq->buffer[arq->MAX]);
            arq->MAX++;
        }
        else
        {
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
    
}

int proucuraMenor(struct arquivo *arq, int numArqs, int K, int *menor){
    int i, idx = -1;
    for (i = 0; i < numArqs; i++)
    {
        if (arq[i].pos < arq[i].MAX)
        {
            if (idx == -1)
            {
                idx = i;
            }
            else
            {
                if (arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                {
                    idx = i;
                }
            }
        }
        
    }
    if (idx != -1)
    {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if (arq[idx].pos == arq[idx].MAX)
        {
            preencheBuffer(&arq[idx], K);
        }
        return 1;
    }else
    {
        return 0;
    }
    
    
}
void merge(char *nome, int numArqs, int K){
    char novo[20];
    int i;
    int *buffer = (int*) malloc (K*sizeof(int));

    struct arquivo* arq;

    arq = (struct arquivo*) malloc(sizeof(struct arquivo) * numArqs);

    for (i = 0; i < numArqs; i++)
    {
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*) malloc (K*sizeof(int));
        preencheBuffer(&arq[i], K);
    }

    int menor, qtdBuffer = 0;
    while (proucuraMenor(arq, numArqs,K , &menor) == 1)
    {
        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if (qtdBuffer == K)
        {
            salvaArquivo(nome, buffer, K, 1);
            qtdBuffer = 0;
        }
    }

    if (qtdBuffer != 0)
    {
        salvaArquivo(nome,buffer, qtdBuffer, 1);
    }
        
    for (i = 0; i < numArqs; i++)
    {
        free(arq[i].buffer);
    }

    free(arq);
    free(buffer);
}
void criarAquivoTeste(char *nome){
    int i;
    FILE *f = fopen(nome, "w");
    srand(time(NULL));
    for (i = 0; i < 1000; i++)
    {
        fprintf(f,"%d\n", rand());
    }
    fprintf(f,"%d", rand());
    fclose(f);
}

void mergeSortExterno(char *nome){
    char novo[20];
    int numArgs = criarAquivosOrdenados(nome);
    int i, k = N / (numArgs + 1);

    remove(nome);
    merge(nome, numArgs, k);

    for (i = 0; i < numArgs; i++)
    {
        sprintf(novo,"Temp%d.txt",i+1);
        remove(novo);
    }
}