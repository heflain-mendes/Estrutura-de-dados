#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacao_bolha(char *vet);
void bubbleSort(int *v, int n);

int main(){
	int nome[5] = {1,2,3,4,5};

	bubbleSort(nome, 5);

	for(int i = 0;i < 5; i++){
		printf("%d ", nome[i]);
	}
	return 0;
}

void ordenacao_bolha(char *vet){
	char aux;
	for(int qtd_comp = strlen(vet) - 1; qtd_comp > 0; qtd_comp--){
		for (int i = 0; i < qtd_comp; i++){
			if(vet[i] > vet[i + 1]){
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}
		}
	}
}

void bubbleSort(int *v, int n){
	int i, j, aux;
	int mudou = 1;
	for(i=n-1;i >= 1 && mudou == 1; i--){
		mudou = 0;
		for(j=0;j<i;j++){
			if(v[j] > v[j+1]){
				aux = v[j+1];
				v[j] = v[j+1];
				v[j+1] = aux;
				mudou = 1;
			}
		}
	}
}