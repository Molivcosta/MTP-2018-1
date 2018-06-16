//Aluno: Mateus Oliveira Costa
//Matricula: 11711EAU018

#include <stdio.h>

unsigned int Tamanho(char *seq);
void invert(char *seq, char *seq1);
unsigned int Bity(char *seq,int x);
unsigned int Hex_Dec(char *seq, int x);
void Bits(char *seq);
unsigned int Potencia(int base, int exp);
void _Bits(unsigned int num, int x);
void dec_oct(unsigned int num, int y);
void dec_hex(unsigned int num, int y);

int main(int argc, char *argv[])
{
	int x = 0, nb;
	char seq[256] = {0},seq1[256] = {0};
	printf("Conversao de Bases:\n"
			"1. Binário para Decimal\n"
			"2. Binário para Hexadecimal\n"
			"3. Hexadecimal para Decimal\n"
			"4. Hexadecimal para Binário\n"
			"5. Decimal para Binário\n"
			"6. Decimal para Hexadecimal\n"
			"7. Octal para Decimal\n"
			"8. Decimal para Octal\n"
			"Digite uma opcao: ");
	scanf("%d", &x);getchar();
	switch(x)
	{
		case 1:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%s",seq);getchar();
		invert(seq, seq1);
		x=2;
		printf("\nO resultado da conversao eh: %d\n\n", Bity(seq1,x));
		break;
		case 2:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%s",seq);getchar();
		invert(seq, seq1);
		x=2;
		printf("\nO resultado da conversao eh: %X\n\n", Bity(seq1,x));
		break;
		case 3:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%s",seq);getchar();
		invert(seq, seq1);
		x=16;
		printf("\nO resultado da conversao eh: %d\n\n", Hex_Dec(seq1, x));
		break;
		case 4:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%s",seq);getchar();
		printf("\nO resultado da conversao eh: ");
		Bits(seq);
		printf("\n\n");
		break;
		case 5:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%d", &x);
		for(nb = 0; x >= (1 << nb); nb++);
		printf("\nO resultado da conversao eh: ");
		_Bits(x,nb);
		printf(" (para %d bits)\n\n",nb);
		break;
		case 6:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%d", &x);
		for(nb = 0; x >= (1 << nb); nb++);
		printf("\nO resultado da conversao eh: ");
		dec_hex(x,nb);
		printf("\n\n");
		break;
		case 7:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%s",seq);getchar();
		invert(seq, seq1);
		x=8;
		printf("\nO resultado da conversao eh: %d\n\n", Bity(seq1,x));
		break;
		case 8:printf("\nDigite a sequencia numerica para a conversao escolhida: ");
		scanf("%d", &x);
		for(nb = 0; x >= (1 << nb); nb++);
		printf("\nO resultado da conversao eh: ");
		dec_oct(x,nb);
		printf("\n\n");
		break;
	}
	return 0;
}

void invert(char *seq, char *seq1)
{
	int i,j = Tamanho(seq);
	for(i = 0;seq[i] != '\0';++i,--j)
	{
		seq1[j] = seq[i];
	}
	seq1[i] = '\0';
}

unsigned int Tamanho(char *seq)
{
	int i = 0;
	while(seq[i] != '\0')
		++i;
	return --i;
}

unsigned int Bity(char *seq,int x)
{
	int i;
	unsigned int res = 0;
	for(i = 0;seq[i] != '\0';++i)
	{
		res += ((seq[i]-'0')*Potencia(x,i));
	}
	return res;
}

unsigned int Potencia(int base, int exp)
{
	return (exp == 0) ? 1 : base*Potencia(base, exp-1);	
}

unsigned int Hex_Dec(char *seq, int x)
{
	int i;
	unsigned int res = 0;
	for(i = 0;seq[i] != '\0';++i)
	{
		if(seq[i] == 'A' || seq[i] == 'a')
			res += (10*Potencia(x, i));
		else if(seq[i] == 'B' || seq[i] == 'b')
			res += (11*Potencia(x, i));
		else if(seq[i] == 'C' || seq[i] == 'c')
			res += (12*Potencia(x, i));
		else if(seq[i] == 'D' || seq[i] == 'd')
			res += (13*Potencia(x, i));
		else if(seq[i] == 'E' || seq[i] == 'e')
			res += (14*Potencia(x, i));
		else if(seq[i] == 'F' || seq[i] == 'f')
			res += (15*Potencia(x, i));
		else
			res += ((seq[i]-'0')*Potencia(x, i));
	}
	return res;
}

void Bits(char *seq)
{
	int i;
	for(i = 0;seq[i] != '\0';++i)
	{
		if(seq[i] == 'A' || seq[i] == 'a')
			_Bits(10, 4);
		else if(seq[i] == 'B' || seq[i] == 'b')
			_Bits(11, 4);
		else if(seq[i] == 'C' || seq[i] == 'c')
			_Bits(12, 4);
		else if(seq[i] == 'D' || seq[i] == 'd')
			_Bits(13, 4);
		else if(seq[i] == 'E' || seq[i] == 'e')
			_Bits(14, 4);
		else if(seq[i] == 'F' || seq[i] == 'f')
			_Bits(15, 4);
		else
			_Bits(seq[i], 4);
	}
}

void _Bits(unsigned int num, int y) {
	if(y != 0) {
		_Bits(num/2, y-1);
		printf("%d", (num%2));
	}
}

void dec_oct(unsigned int num, int y) {
	if(y != 0 && num != 0) {
		dec_oct(num/8, y-1);
		printf("%d", (num%8));
	}
}

void dec_hex(unsigned int num, int y) {
	if(y != 0 && num != 0) {
		dec_hex(num/16, y-1);
		printf("%X", (num%16));
	}
}
