/* Aluno: Mateus Oliveira Costa
   Matricula: 11711EAU018 */

#include <stdio.h>

int main(void)
{
	int estado = 0, i = 0;
	char bits[256] = {0};
	printf("Digite a sequencia de bits: ");
	scanf("%s", bits);
	while(bits[i] != '\0')
	{
		if(bits[i] == '0' && estado == 0 || bits[i] == '1' && estado == 1)
		{
			estado = 0;
		}
		else if(bits[i] == '1' && estado == 0 ||  bits[i] == '0' && estado == 2)
		{
			estado = 1;
		}
		else if(bits[i] == '0' && estado == 1 ||  bits[i] == '1' && estado == 2)
		{
			estado = 2;
		}
		++i;
	}
	if(estado == 0)
	{
		printf("\n\"%s\" e multiplo de 3",bits);
	}
	else{
		printf("\n\"%s\" nao e",bits);
	}
	return 0;
}
