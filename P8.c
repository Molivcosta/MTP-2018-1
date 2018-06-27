/* Aluno: Mateus Oliveira Costa
   Matricula: 11711EAU018 */

#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float*, float**);
void soma(float*, float**, float*);
void produto(float*, float**, float*);

int main(int argc, char *argv[])
{
	srand(123456);
	int x = 0;
	float vetor[100] = {0}, resultado = 0;
	float *pinicio_vetor = vetor;
	float * *pfim_vetor = pinicio_vetor+100;
	printf("Digite\n"
			"1 - Somatorio\n"
			"2 - Produtorio\n"
			"Escolha uma das opcoes: ");
	scanf("%d", &x);getchar();
	gera_numeros(pinicio_vetor,pfim_vetor);
	switch(x)
	{
		case 1:
		soma(pinicio_vetor,pfim_vetor,&resultado);
		printf("\nO resultado da soma e: \"%f\"\n",resultado);
		break;
		case 2:
		resultado = 1;
		produto(pinicio_vetor,pfim_vetor,&resultado);
		printf("\nO resultado do produto e: \"%f\"\n",resultado);
		break;
	}
	return 0;
}

void gera_numeros(float *ini_vet, float **fim_vet)
{
	*ini_vet = (float) rand()/(float) RAND_MAX + 0.5f;
	if(ini_vet < fim_vet) gera_numeros(ini_vet+1, fim_vet);
}

void soma(float *ini_vet, float **fim_vet, float *resultado)
{
	*resultado += *ini_vet;
	if(ini_vet < fim_vet) soma(ini_vet+1,fim_vet,resultado);
}

void produto(float *ini_vet, float **fim_vet, float *resultado)
{
	*resultado *= *ini_vet;
	if(ini_vet < fim_vet) produto(ini_vet+1,fim_vet,resultado);
}
