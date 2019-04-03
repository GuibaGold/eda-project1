
#include <stdio.h>

int fneuronio(float *entradas, int *pesos, float limiar_t, int input_size);

int main(){
  printf("Ola bem vindo ao modelo matematico de neuronios (Neuronio Logico)\n");

  float entradas[10], limiar_t;
  int i, pesos[10];

  printf("Digite 10 valores reais para as ENTRADAS:\n");
  for(i = 0; i < 10; i++){
    scanf(" %f", &entradas[i]);
  }

  printf("Digite 10 valores inteiros para os PESOS:\n");
  for(i = 0; i < 10; i++){
    scanf(" %d", &pesos[i]);
  }

  printf("Digite o valor do LIMIAR T:\n");
  scanf("%f", limiar_t);

  if(fneuronio(&entradas[0], &pesos[0],limiar_t, 10) == 1){
    printf("Neurônio   ativado! \n");
  }
  else{
    printf("Neurôno   inibido!");
  }


  return 0;
}

int fneuronio(float *entradas, int *pesos, float limiar_t, int input_size){
    float somap = 0;
    int i = 0;

    for(i = 0; i < input_size; i++){
      somap += (*entradas) * (*pesos);
      entradas++;
      pesos++;
    }

    if(somap >= limiar_t){
      return 1;
    }
    else{
      return 0;
    }

}
