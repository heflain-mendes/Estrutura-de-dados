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
	int k = -1;
	if (!pi)
		return -1;
	for (i = 0; i < ttam; i++) {
		while (k > -1 && padrao[k+1] != texto[i])
			k = pi[k];
		if (texto[i] == padrao[k+1])
			k++;
		if (k == ptam - 1) {
			libera(pi);
			return i-k;
		}
	}
	libera(pi);
	return -1;
}

int main(int argc, const char *argv[])
{
	//char texto[] = "ABC ABCDAB ABCDABCDABDE";
    char texto[] = "abacaabaccabacabaabb";
	char *ch = texto;
	//char padrao[] = "ABCDABD";
	char padrao[] = "abacab";

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