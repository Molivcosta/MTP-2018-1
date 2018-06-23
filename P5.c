/* Aluno: Mateus Oliveira Costa
   Matricula: 11711EAU018 */

#include <stdio.h>

void Entrada_dados_1(char str[]);
unsigned int Entrada_dados_2(int vet[]);

int main(void)
{
	char str[256] = {'\0'};
	int x = 0, i = 0,t = 0;
	int vet[64] = {0};
	printf("Digite\n\n"
		"1. Codificar\n"
		"2. Decodificar\n\n"
		"Escolha a Opcao: ");
	scanf("%d", &x);getchar();
	switch(x)
	{
		case 1:
		Entrada_dados_1(str);
		int *ps = (int *) str;
		printf("\n\n\" ");
		for(i = 0;ps[i] != '\0';++i)
		{
			printf("%d ", ps[i]);
		}
		printf("\"");
		break;
		
		case 2:
		t = Entrada_dados_2(vet);
		char *pg = (char *) &vet;
		printf("\n\"");
		printf("%s", pg);
		printf("\"");
		break;
	}
	
	
	return 0;
}
					
void Entrada_dados_1(char str[])
{
	int i = 0;
	printf("\nDigite a frase para a codificacao: ");
	for(i;(str[i] = getchar()) != '\n' && i < 255;++i);
	str[i] = '\0';
}

unsigned int Entrada_dados_2(int vet[])
{
	printf("\nDigite a frase numerica para a decodificacao: ");
	int i;
	for( i = 0; i < 64; ++i)
	{
		scanf("%d", &vet[i]);
		if(vet[i] == 0)
			break;
	}
	return i;
}
