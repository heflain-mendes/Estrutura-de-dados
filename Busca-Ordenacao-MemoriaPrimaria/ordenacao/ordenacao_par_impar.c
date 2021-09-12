#include <stdio.h>
#include <Stdlib.h>

#define TAM 10

void parImpar(int *vet, int tam);

int main(){
	int vet[TAM] = {10,9,8,7,6,5,4,3,2,1};

	parImpar(vet, TAM);

	for(int i = 0; i < TAM; i++){
		printf("%d ",vet[i]);
	}

	return 0;
}

void parImpar(int *vet, int tam){
	int i = 0;
	int troca = 1;
	int aux;

	while(troca){
		troca = 0;
		i = i % 2 == 0 ? 1 : 0;
		for (; i < tam - 1; i += 1){
			if (vet[i] > vet[i+1]){
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				troca = 1;
			}
		}
	}
}