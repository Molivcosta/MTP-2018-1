//Aluno: Mateus Oliveira Costa
//Matricula: 11711EAU018

#include <stdio.h>

void Binario_neg(int num, int x, int*);
void Binario_pos(int num, int x, int*);
int AND(int*, int*, int, int*);
int OR(int*, int*, int, int*);
int XOR(int*, int*, int, int*);
unsigned int Potencia(int base, int exp);

int main(int argc, char *argv[])
{
	int x = 0, num = 0, num1 = 0, valor = 0;
	int seq[256] = {0},seq1[256] = {0};
	printf("Calculadora Bitwise:\n"
			"1. NOT\n"
			"2. AND\n"
			"3. OR\n"
			"4. XOR\n"
			"5. Right Shift\n"
			"6. Left Shift\n"
			"Digite uma opcao: ");
	scanf("%d", &x);getchar();	
	switch(x)
	{
		case 1:
		printf("\nDigite o argumento para a execucao da operacao desejada: ");
		scanf("%d", &num);getchar();
		printf("\n\"NOT %d (",num);
		(num < 0) ? Binario_neg(~num,0,seq) : Binario_pos(num,0,seq);
		printf(") : %d (", ~num);
		(~num < 0) ? Binario_neg(num,0,seq) : Binario_pos(~num,0,seq);
		printf(")\"");
		break;
		case 2:
		printf("\nDigite dois argumentos para a execucao da operacao desejada: ");
		scanf("%d %d", &num, &num1);getchar();
		printf("\"%d (", num);
		(num < 0) ? Binario_neg(~num, 0, seq) : Binario_pos(num, 0, seq);
		printf(") AND %d (",num1);
		(num1 < 0) ? Binario_neg(~num1, 0, seq1) : Binario_pos(num1, 0, seq1);
		AND(seq, seq1, 0, &valor);
		printf(") : %d (",valor);
		(valor < 0) ? Binario_neg(~valor, 0, seq) : Binario_pos(valor, 0, seq);
		printf(")\"");
		break;
		case 3:
		printf("\nDigite dois argumentos para a execucao da operacao desejada: ");
		scanf("%d %d", &num, &num1);getchar();
		printf("\"%d (", num);
		(num < 0) ? Binario_neg(~num, 0, seq) : Binario_pos(num, 0, seq);
		printf(") OR %d (",num1);
		(num1 < 0) ? Binario_neg(~num1, 0, seq1) : Binario_pos(num1, 0, seq1);
		OR(seq, seq1, 0, &valor);
		printf(") : %d (",valor);
		(valor < 0) ? Binario_neg(~valor, 0, seq) : Binario_pos(valor, 0, seq);
		printf(")\"");
		break;
		case 4:
		printf("\nDigite dois argumentos para a execucao da operacao desejada: ");
		scanf("%d %d", &num, &num1);getchar();
		printf("\"%d (", num);
		(num < 0) ? Binario_neg(~num, 0, seq) : Binario_pos(num, 0, seq);
		printf(") XOR %d (",num1);
		(num1 < 0) ? Binario_neg(~num1, 0, seq1) : Binario_pos(num1, 0, seq1);
		XOR(seq, seq1, 0, &valor);
		printf(") : %d (",valor);
		(valor < 0) ? Binario_neg(~valor, 0, seq) : Binario_pos(valor, 0, seq);
		printf(")\"");
		break;
		case 5:
		printf("\nDigite dois argumentos para a execucao da operacao desejada: ");
		scanf("%d %d", &num, &num1);getchar();
		printf("\"%d (", num);
		(num < 0) ? Binario_neg(~num, 0, seq) : Binario_pos(num, 0, seq);
		printf(") >> %d (",num1);
		(num1 < 0) ? Binario_neg(~num1, 0, seq1) : Binario_pos(num1, 0, seq1);
		printf(") : %d (",valor = num >> num1);
		(valor < 0) ? Binario_neg(~valor, 0, seq) : Binario_pos(valor, 0, seq);
		printf(")\"");
		break;
		case 6:
		printf("\nDigite dois argumentos para a execucao da operacao desejada: ");
		scanf("%d %d", &num, &num1);getchar();
		printf("\"%d (", num);
		(num < 0) ? Binario_neg(~num, 0, seq) : Binario_pos(num, 0, seq);
		printf(") << %d (",num1);
		(num1 < 0) ? Binario_neg(~num1, 0, seq1) : Binario_pos(num1, 0, seq1);
		printf(") : %d (",valor = num << num1);
		(valor < 0) ? Binario_neg(~valor, 0, seq) : Binario_pos(valor, 0, seq);
		printf(")\"");		
		break;
	}
	
	return 0;
}

void Binario_neg(int num, int y, int *vet) {
	if(y < 32){
		Binario_neg(num/2, y+1,vet);
		vet[y] = ((num%2 == 0) ? 1 : 0);
		printf("%d", vet[y]);
	}
}

void Binario_pos(int num, int x, int *vet)
{
	if(x < 32){
		Binario_pos(num/2, x+1,vet);
		vet[x] = (num%2);
		printf("%d", vet[x]); 
	}
}

int AND(int *vet, int *vet1, int x, int *valor)
{
	if(x < 32){
		if(vet[x] == 1 && vet1[x] == 1)
			*valor += Potencia(2, x);
		AND(vet, vet1, x+1 , valor);
	}
}

int OR(int *vet, int *vet1, int x, int *valor)
{
	if(x < 32){
		if(vet[x] == 1 || vet1[x] == 1)
			*valor += Potencia(2, x);
		OR(vet, vet1, x+1 , valor);
	}
}

int XOR(int *vet, int *vet1, int x, int *valor)
{
	if(x < 32){
		if(vet[x] ^ vet1[x])
			*valor += Potencia(2, x);
		XOR(vet, vet1, x+1 , valor);
	}
}

unsigned int Potencia(int base, int exp)
{
	return (exp == 0) ? 1 : base*Potencia(base, exp-1);	
}
