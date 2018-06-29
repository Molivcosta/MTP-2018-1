/* Aluno: Mateus Oliveira Costa
   Matricula: 11711EAU018 */

#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float *ini_vet, float *fim_vet)
{
	*ini_vet = (float) rand()/(float) RAND_MAX + 0.5f;
	if(ini_vet < fim_vet) gera_numeros(ini_vet+1, fim_vet);
}

float  reduce(float *pini, float *pfim, float (*funcao)(float,float)) {
	return (pini == pfim) ? 1 : (*funcao)(*pini, reduce(pini+1, pfim, funcao));
};

float soma(float a, float b)
{
	return a+b;
}

float produto(float a, float b)
{
	return a*b;
}

int main(int argc, char *argv[])
{
	srand(123456);
	int x = 0;
	float vetor[100] = {0};
	printf("Digite\n"
			"1 - Somatorio\n"
			"2 - Produtorio\n"
			"Escolha uma das opcoes: ");
	scanf("%d", &x);getchar();
	gera_numeros(vetor,vetor+100);
	switch(x)
	{
		case 1:
		printf("\nO resultado da soma e: \"%g\"\n",reduce(vetor, vetor+100, soma)-1);
		break;
		case 2:
		printf("\nO resultado do produto e: \"%f\"\n",reduce(vetor, vetor+100, produto));
		break;
	}
	return 0;
}

