//Aluno: Mateus Oliveira Costa
//Matricula: 11711EAU018

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0, cum = 0;
	char numero[256] = {0};
	printf("Digite um numero: ");
	scanf("%s", numero);
	printf("\nO numero digitado e imprimido como um inteiro eh: ");
	while(numero[i] != '\0')
	{
		if(numero[i] >= '0' && numero[i] <= '9')
		{
			numero[i] = (numero[i] - '0');
			printf("%d",(int) numero[i]);
			cum++;
		}
		++i;
	}
	(cum == 0) ? printf("%d",0) : printf("\n");
	return 0;
}
