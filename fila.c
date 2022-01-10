#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int elementos[TAM]={};
int primeiro=0, ultimo=0, total=0;

int isEmpty(){
  if(total==0){
    return 1;
  } else{
    return 0;
  }
}

int isFull(){
  if(total==TAM){
    return 1;
  } else{
    return 0;
  }
}

void inserir(int n){
  if(isFull()){
    printf("A Fila está cheia\n");
  } else{
    elementos[ultimo] = n;
    ultimo = (ultimo + 1) % TAM;
    total++;
  }
}

int retirar(){
  if(isEmpty()){
    printf("A Fila está vazia");
    return 1;
  } else{
    int n = elementos[primeiro];
    elementos[primeiro] = 0;
    total--;
    primeiro = primeiro + 1;
    return primeiro;
  }
}

int primeiro_fila(){
  if(isEmpty()){
    printf("A Fila está vazia\n");
    return 1;
  } else{
    return elementos[primeiro];
  }
}

void exibirPrimeiro(){
  printf("\nValor do início da Fila = %d (%d)\n", primeiro_fila(), primeiro);
}

void listar(){
  int i;
  system("clear");
  printf("Lista da Fila:  ");
  for(i=0; i<TAM; i++){
    printf("| %2d ", elementos[i]);
  }
}

void listar_ordem(){
  int i = primeiro, aux;
  system("clear");
  printf("Fila Ordenada:  ");

  for(aux=0; aux<total; aux++){
    printf("| %2d ", elementos[i]);
    i++;
    if(i==TAM){
      i=0;
    }
  }
}

void preenche_fila(){
  
}

int menu(){
  int n;
  printf("\n--------------\n");
  printf("\nSistema de Fila:");
  printf("\n1 - Inserir valor");
  printf("\n2 - Retirar valor");
  printf("\n3 - Listar Fila");
  printf("\n4 - Exibir o primeiro da fila");
  printf("\n5 - Listar Fila Ordenada");
  printf("\n0 - Sair");
  printf("\n\nEscolha uma operação: ");
  scanf("%d", &n);
  return n;
}

int valor(){
  int n;
  system("clear");
  printf("Digite um valor: ");
  scanf("%d", &n);

  return n;
}

int main(void) {
  int opcao;

  do{
    opcao = menu();

    switch(opcao){
      case 1: inserir(valor());
      break;
      case 2: retirar();
      break;
      case 3: listar();
      break;
      case 4: exibirPrimeiro();
      break;
      case 5: listar_ordem();
      break;
    }
  }while(opcao!=0);
  return 0;
}