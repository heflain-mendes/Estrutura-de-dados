#include<stdio.h>
#include<string.h>

int TAM = 20;

int busca_ternaria(int *tabela, int chave);

int main(){
	int vet[TAM];

	for (int i = 0; i < TAM; ++i)
	{
		vet[i] = i + 1;
	}

	int retorno = busca_ternaria(vet, 11);

	if (retorno == -1)
	{
		printf("não encontrou\n");
	}else{
		printf("encontrou na posicao %d\n",retorno);
	}

	return 0;
}

int busca_ternaria(int *tabela, int chave){
	int esquerda = 0;
	int direita = TAM;
	int m1 = direita / 2;
	int m2 = 2 * direita / 3;

	while(esquerda <= direita){
		m1 = (direita - esquerda) / 2 + esquerda;
		m2 = (direita - esquerda) * 2 / 3 + esquerda;
		if(chave ==  tabela[m1])
		{
			return m1;
		}else if(chave == tabela[m2]){
			return m2;
		}else if(chave < tabela[m1]){
			direita = m1 - 1;
		}else if(chave > tabela[m1] && chave < tabela[m2]){
			esquerda = m1 + 1;
			direita = m2 - 1;
		}else{
			esquerda = m2 + 1;
		}
			printf("D = %d  E = %d  M1 = %d  M2 = %d  Valor M1 =  %d  Valor M2 = %d\n",direita, esquerda, m1, m2, tabela[m1], tabela[m2]);

	}

	return -1;
}