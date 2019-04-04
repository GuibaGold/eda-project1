#include <stdio.h>

int *recebe_notas(double *NOTAS, int input_size, int *APR);
void conta_notas(int *APR, int input_size, int *q_apr_rep);
int percent_aprov(int *q_apr_rep, float *per_apr_rep);

int main(int argc, char const *argv[])
{
	double NOTAS[10];
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("Olá, digite o valor da nota %d: \n", i+1);
		scanf("%lf", &NOTAS[i]);
	}

	int *APR, vet[10];
	
	APR = recebe_notas(NOTAS, 10, vet);

	int q_apr_rep[2];//pos[0] = quantidade aprovados e pos[1] = quantidade reprovados
	conta_notas(APR, 10, q_apr_rep);

	printf("Quantidade aprovados : %d\nQuantidade reprovados: %d\n", q_apr_rep[0], q_apr_rep[1]);

	float per_apr_rep[2];//pos[0] = percentual aprovados e pos[1] = percentual reprovados
	int mais_da_metade_rep = percent_aprov(q_apr_rep, per_apr_rep);

	printf("Percentual de aprovados: %.2f%%\tPercentual de reprovados: %.2f%%\n", per_apr_rep[0], per_apr_rep[1]);

	if(mais_da_metade_rep == 1)
		printf("Mais da metade da turma aprovada!!\n");

	return 0;
	
}

int *recebe_notas(double *NOTAS, int input_size, int *APR)
{

	for(int index = 0; index < input_size; index++){
		if(NOTAS[index] >= 6.0){
			*(APR + index) = 1;
		}
		else{
			*(APR + index) = 0;
		}
	}
	return APR;
}

void conta_notas(int *APR, int input_size, int *q_apr_rep)
{

	int quant_aprovados = 0, quant_reprovados = 0;

	for(int i = 0; i < 10; i++)
	{
		if(*(APR + i) == 1)
		{
			quant_aprovados++;
		}
		else{
			quant_reprovados++;
		}
	}
	
	*q_apr_rep = quant_aprovados;
	*(q_apr_rep + 1) = quant_reprovados;
}

int percent_aprov(int *q_apr_rep, float *per_apr_rep)
{
	float p_aprovado = 0, p_reprovado = 0;

	p_aprovado = *q_apr_rep * 100 / 10;
	p_reprovado = *(q_apr_rep + 1) * 100 / 10;
	*per_apr_rep = p_aprovado;
	*(per_apr_rep + 1) = p_reprovado;

	if(per_apr_rep[0] > 50)
		return 1;
	else
		return 0;
}