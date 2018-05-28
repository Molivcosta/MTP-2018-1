//Aluno: Mateus Oliveira Costa
//Matricula: 11711EAU018

#include <stdio.h>

int soma(int vet[], int x);
float Dividi(int x, int y);
void entrada_dados(int vet[],int x);

int main(int argc, char *argv[])
{
	int num[20] = {0}, x = 0, y = 0;
	printf("Digite uma quantidade de 5 e 20 numeros: ");
	scanf("%d", &x);getchar();
	entrada_dados(num, x);
	y = soma(num,x);
	printf("\nA media dos numeros digitados eh: %g",Dividi(y,x));
	return 0;
}

void entrada_dados(int vet[], int x)
{
	int i;
	printf("\nDigite os numeros referente a quantidade escolhida.\n\n");
	for(i = 0;i < x;i++)
	{
		printf("Numero %d: ",i+1);
		scanf("%d", &vet[i]);
	}
}

int soma(int vet[], int x)
{
	int resp = 0;
	
	return (x >= 0) ? resp += (vet[x] + soma(vet, x-1)) : 0;
}

float Dividi(int y, int x)
{
	float resp = 0, j = (float)y, i = (float) x;
	return resp = (j/i);
}
