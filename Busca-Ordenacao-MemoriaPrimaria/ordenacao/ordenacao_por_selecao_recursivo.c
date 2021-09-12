#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenaPoSelecaoRecursivo(char *vet, int i);

int main()
{
    char texto[] = "heflaindarochamendes";
    printf("%s\n", texto);
    ordenaPoSelecaoRecursivo(texto, strlen(texto) - 1);

    printf("%s", texto);

    return 0;
}

void ordenaPoSelecaoRecursivo(char *vet, int i)
{
    int j, menor;
    i--;
    int tam = strlen(vet);
    if (i >= 0){
        ordenaPoSelecaoRecursivo(vet, i);
        menor = i;

        for (j = i + 1; j < tam; j++)
        {
            if (vet[j] < vet[menor])
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            j = vet[menor];
            vet[menor] = vet[i];
            vet[i] = j;
        }
    }
}