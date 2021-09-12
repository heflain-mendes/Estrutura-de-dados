#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacaoShellsort(char *vet);

int main()
{
    char texto[] = "heflaindarochamendes";

    ordenacaoShellsort(texto);

    printf("%s",texto);
    return 0;
}

void ordenacaoShellsort(char *vet)
{
    int tam = strlen(vet);
    int h = 1;
    int i, j;
    int aux;

    while (h < tam)
    {
        h = h * 3 + 1;
    }

    while (h > 1)
    {
        h = h / 3;
        for (i = h; i < tam; i++)
        {
            aux = vet[i];
            j = i - h;
            while (j >= 0 && aux < vet[j])
            {
                vet[j + h] = vet[j];
                j = j - h;
            }
            vet[j + h] = aux;
        }
    }
}