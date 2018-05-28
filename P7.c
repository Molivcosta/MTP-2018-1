//Aluno: Mateus Oliveira Costa
//Matricula: 11711EAU018

#include <stdio.h>

double Acker(double m, double n);

int main(int argc, char *argv[])
{
	double m = 0, n = 0;
	printf("Digite os valores de m e n nesta respectiva ordem: ");
	scanf("%lf %lf", &m, &n);getchar();
	printf("\nO resultado da funcao eh: %g", Acker(m, n));
	return 0;
}

double Acker(double m, double n)
{
	return (m == 0) ? (n+1) : (m > 0 && n == 0) ? Acker(m-1, 1) : Acker(m-1, Acker(m, n-1));
}