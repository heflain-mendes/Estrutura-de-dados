#include <stdio.h>
#include <stdlib.h>

#define tamMaximo 15

typedef struct s_info
{
    int chave;
} tipoInfo;

typedef struct s_lista
{
    tipoInfo elementos[tamMaximo];
    int posUltimo;

} tipoLista;

void fazVazia(tipoLista *l)
{
    l->posUltimo = -1;
}

int insereFinal(tipoLista *l, tipoInfo info)
{
    int retorno = 0;

    if (l->posUltimo == tamMaximo - 1)
        retorno = -1;
    else
    {
        l->posUltimo++;
        l->elementos[l->posUltimo] = info;
    }

    return retorno;
}

void imprimeLista(tipoLista l)
{
    int pos;

    pos = 0;

    while (pos <= l.posUltimo)
    {
        printf("%d, ", l.elementos[pos].chave);
        pos++;
    }
    putchar('\n');
}

int inserePosicao (tipoLista *l, tipoInfo info,  int p)
{
    int retorno = -1;
    tipoInfo aux0, aux1;
    int count;

    if (p > l->posUltimo){
        l->elementos[l->posUltimo];
        l->posUltimo++;
    }else{
        aux0 = l->elementos[p];//aux0 recebe o valor da posição que vai receber o novo valor 
        l->elementos[p] = info;//a posição recebendo o novo valor
        /*
            incremetando posUltimo para a lista poder alocar o novo valor
            incrementando p para alocar o novo valor na lista
        */
        count = l->posUltimo++;
        
        for (p++;p <= count; p++)
        {
            aux1 = l->elementos[p];//aux1 recebe o valor da posição incrementada
            l->elementos[p] = aux0;//a possição incrementada recebe no primeiro ciclo o valor de aux) que foi extraido na linha seguinte ao else
            aux0 = aux1;
        }
        retorno = 0;//adiciona na posição com sucesso 
    }
    return retorno;
}    

//4 – Inserir um item no início da lista
int insereInicio(tipoLista *l, tipoInfo info)
{
    int retorno;
    retorno = inserePosicao(l,info, 0);//chamando a função que insere em uma posição e passando a posição inicial 
    return retorno;
}

//5 - Retirar o i-ésimo item da lista
int retirarItem(tipoLista *l, int p)
{
    int retorno;
    if (p > l->posUltimo)
    {
        retorno = -1;//elemento inexistente  
    }else{
        for (;p < l->posUltimo; p++)
        {
            l->elementos[p] = l->elementos[p+1];//re-coloca o elemento da posição seguinte na posição anterior
        }
        l->posUltimo--;//decrementa a qtd de elemento da lista
        retorno = 0;
    }
    return retorno;
}

//6 – Recuperar o i-ésimo elemento da lista
//Essa função nessecita de uma verificação na chamada, pois, se o posição for maior que posição do ultimo elemento vai ser precisso alerta ao usuário 
tipoInfo recuperaItem (tipoLista *l, int p)
{
    return l->elementos[p];
}

//7 – Dividir uma lista em duas na i-ésima posição
//a posição indicada vai pertence a segunda lista 
int divideLista(tipoLista *l1, tipoLista *l2, int p)
{
    int retorno = -1;
    int aux = p - 1;
    int count;
    int i;

    if (p > l1->posUltimo)
    {
        retorno = 0;
    }else{
        count = l1->posUltimo;
        for (int i = 0;p <= count; p++, i++)
        {
            l2->elementos[i] = l1->elementos[p];
        }
        l1->posUltimo = aux;
        l2->posUltimo = --i;//cuida!! com a posição do decremento
        retorno = 1;
    }
    return retorno;
}

int main()
{
    tipoLista lista;
    tipoLista lista2;
    tipoInfo info;

    fazVazia(&lista);

    info.chave = 5;
    insereFinal(&lista, info);

    info.chave = 10;
    insereFinal(&lista, info);

    info.chave = 8;
    insereFinal(&lista, info);

    info.chave = 3;
    insereFinal(&lista, info);

    info.chave = 1;
    insereFinal(&lista, info);


    info.chave = 2;
    insereInicio(&lista, info);
    imprimeLista(lista);

    retirarItem(&lista, 3);
    imprimeLista(lista);

    divideLista(&lista, &lista2, 2);
    imprimeLista(lista);
    imprimeLista(lista2);

    inserePosicao(&lista, info, 5);


    return 0;
}