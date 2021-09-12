#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenaPoSelecao(char *vet);

int main()
{
    char texto[] = "heflaindarochamendes";
    printf("%s\n", texto);
    ordenaPoSelecao(texto);

    printf("%s", texto);

    return 0;
}

void ordenaPoSelecao(char *vet)
{
    int tam = strlen(vet);
    int i, j, menor;

    for (i = 0; i < tam - 1; i++)
    {
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