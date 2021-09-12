#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void libera(int *pi) {
    free(pi);
}

int *preprocessamento(char *padrao, int ptam)
{
	int k = -1;
	int i = 1;
	int *pi = malloc(sizeof(int)*ptam);
	if (!pi)
		return NULL;

	pi[0] = k;
	for (i = 1; i < ptam; i++) {
		while (k > -1 && padrao[k+1] != padrao[i])
			k = pi[k];
		if (padrao[i] == padrao[k+1])
			k++;
		pi[i] = k;
	}
	return pi;
}

int kmp(char *texto, int ttam, char *padrao, int ptam)
{
	int i;
	int *pi = preprocessamento(padrao, ptam);
    int comp = 0;


    printf("\npadrao: ");
    for(int a = 0; a < ptam; a++) printf("%d ", pi[a]);
    printf("\n");


	int k = -1;
	if (!pi)
		return -1;

	for (i = 0; i < ttam; i++) {
        
		while (k > -1 && padrao[k+1] != texto[i]){
            comp++;
			k = pi[k];
        }
        
		if (texto[i] == padrao[k+1]){
            comp++;
			k++;
        }

		//if(k == -1) comp++;
        
		if (k == ptam - 1) {
			libera(pi);
            //acredito que o professor colocou uma incremento da sequencia aki
            //comp++
            printf("\n%d comparacoes e ENCONTROU A SEQUENCIA\n", comp);
			return i-k;
		}
	}
	libera(pi);
    printf("\n%d comparacoes e NAO ENCONTROU A SEQUENCIA\n", comp);
	return -1;
}

int main(int argc, const char *argv[])
{
	//char texto[] = "ABC ABCDAB ABCDABCDABDE";
    char texto[] = "CORROCOCOGAOCOR";
	char *ch = texto;
	//char padrao[] = "ABCDABD";
	char padrao[] = "COGA";

	int i, j;

	i = kmp(texto, strlen(texto), padrao, strlen(padrao));
	if (i >= 0)
		printf("Encontrou: %s\n", ch + i);

    for (j=i; j<i+strlen(padrao); j++)
    {
      printf("%c", texto[j]);
    }
	return 0;
}