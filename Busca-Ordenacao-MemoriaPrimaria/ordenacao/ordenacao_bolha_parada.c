#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacao_bolha_parada(char *vet);
int main(){
	char nome[] = "abdce";

	ordenacao_bolha_parada(nome);

	printf("%s", nome);
	return 0;
}


//função para ordenar caracteres
void ordenacao_bolha_parada(char *vet){
	char aux;
	int i;
	//int indice;
	int mudou = 1;
	int qtd_comp = strlen(vet) - 1;

	while(mudou){
		mudou = 0;
		i = 0;
		while(i < qtd_comp){
			if(vet[i] > vet[i + 1]){
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				mudou = 1;
			}
			/*quando o laço while terminar o valor do indice sera i - 1, que é de qtd_comp - 1
			então coloquei diretamente no qtd_comp*/
			//indice = i; 
			i++;
		}
		qtd_comp--;
	}
}