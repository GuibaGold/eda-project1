#include <stdio.h>

void torre_de_hanoi(int numeros_discos, char torre_origem, char torre_destino, char torre_auxiliar);
int main()
{
	printf("Olá bem vindo ao solucionador da Torre de Hanoi!\n\tDigite o número de discos da sua torre: \n");
	int numeros_discos;

	scanf(" %d", &numeros_discos);
	torre_de_hanoi(numeros_discos, 'A', 'C', 'B');
	return 0;
}

void torre_de_hanoi(int numeros_discos, char torre_origem, char torre_destino, char torre_auxiliar)
{
	if(numeros_discos == 1)
		printf("mover disco %d da torre %c para %c\n",numeros_discos, torre_origem, torre_destino);
	else
	{
		torre_de_hanoi(numeros_discos - 1, torre_origem, torre_auxiliar, torre_destino);
		printf("mover disco %d a torre %c para %c\n",numeros_discos, torre_origem, torre_destino);
		torre_de_hanoi(numeros_discos - 1, torre_auxiliar, torre_destino, torre_origem);
	}
		
}