#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII 255

int BMH(char *padrao, char *texto);

int main(){
    char t[] = "CORROCOCOGAOCOR";
    char p[] = "COGA";

    int a = BMH(p, t);

    printf("%d\n",a);

    return 0;
}

int BMH(char *padrao, char *texto){
    int tam_padrao = strlen(padrao);
    int tam_texto = strlen(texto);
    int tabela[ASCII];
    int i, index_padrao, index_texto;


    //pré processamento
    for (i = 0; i < ASCII; i++){
        tabela[i] = tam_padrao;
    }

    tam_padrao--;//evitando calculos reduntantes

    for (i = 0; i < tam_padrao; i++){
        tabela[padrao[i]] = tam_padrao - i;
    }

    //busca
    i = tam_padrao;
    
    int comp = 0;

    while(i < tam_texto){
        index_texto = i;//index para o texto
        index_padrao = tam_padrao;//index para o padrao

        //verificação
        while(padrao[index_padrao] == texto[index_texto] && index_padrao > -1){
            index_texto--;
            index_padrao--;
            comp++;
        }

        //se encontrou o padrao
        if (index_padrao == -1)
        {
            comp++;
            printf("ENONTROU com %d verificações\n",comp);
            return index_texto + 1;//retorno o index, contando a parti de 0
        }
        
        i = i + tabela[texto[i]];
    }
    printf("NÂO ENONTROU com %d verificações\n",comp);
    return -1;
}