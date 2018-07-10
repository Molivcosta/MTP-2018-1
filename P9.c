/* Aluno: Mateus Oliveira Costa
   Matricula: 11711EAU018 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef 
	struct Dimensoes{
		float largura;
		float profundidade;
		float altura;
	}
Dimensoes;

typedef 
	struct Produto{
		char nome[64];
		float preco;
		Dimensoes dim;
	}
Produto;

Produto produto[2];
	
void Cadastro(int numprod)
{
	printf("\nCadastro do produto %d\n",numprod+1);
	printf("\nDigite o nome do produto: ");
	fgets(produto[numprod].nome, 64, stdin);
	printf("Digite o preco do produto: ");
	scanf("%f", &produto[numprod].preco);getchar();
	printf("Digite a largura do produto: ");
	scanf("%f", &produto[numprod].dim.largura);
	getchar();
	printf("Digite a profundidade do produto: ");
	scanf("%f", &produto[numprod].dim.profundidade);
	getchar();
	printf("Digite a altura do produto: ");
	scanf("%f", &produto[numprod].dim.altura);
	getchar();
	printf("\n\"Produto %d cadastrado com sucesso\"\n\n",numprod+1);
}

void Consulta(int numprod)
{
	printf("\n\"%s,",produto[numprod].nome);
	printf(" R$ %.2f,",produto[numprod].preco);
	printf(" L: %gm x",produto[numprod].dim.largura);
	printf(" P: %gm x",produto[numprod].dim.profundidade);
	printf(" A: %gm\"\n\n",produto[numprod].dim.altura);
}

int main(int argc, char *argv[])
{
	int i = 0, op = 0, nprod = 0, p = 0, s =0;
	
	for(i=0;i<N;++i)
		produto[i].nome[i] = '\0';
	
	while (s == 0)
	{
	
		printf("Digite:\n"
					"1 - Cadastro\n"
					"2 - Consulta\n"
					"Escolha uma opcao: ");
		scanf("%d", &op);
		getchar();
		printf("Digite o numero do produto (1 ou 2): ");
		scanf("%d",&nprod);
		getchar();
		
		if(op == 2 && produto[nprod-1].nome[nprod-1] == '\0')
		{
			printf("\n\"Produto nao cadastrado!\"\n\n");
			
		}
		else{
			
			switch (op)
			{
				case 1:
					Cadastro(nprod-1);
					break;
				case 2:
					Consulta(nprod-1);
					break;
			
			}
		}
	}

	return 0;
}