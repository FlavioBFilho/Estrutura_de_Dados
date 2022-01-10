#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pilha[10]={0,0,0,0,0,0,0,0,0,0};
int topo = -1;

int menu(){
  int n;
  printf("\n-----------------");
  printf("\nSistema de PILHA\n");
  printf("\n1 - Inserir valor (push)\n");
  printf("\n2 - Retirar valor (pop)\n");
  printf("\n3 - Exibir pilha (todos)\n");
  printf("\n4 - Valor do topo\n");
  printf("\n5 - Preencher pilha automaticamente\n");
  printf("\n6 - Limpar a pilha\n");
  printf("\n0 - Sair\n");
  printf("\n\nEscolha uma opção: ");
  scanf("%d", &n);

  return n;
}

int isFull(){
  if(topo==9){
    return 1;
  } else{
    return 0;
  }
}

int isEmpty(){
  if(topo==-1){
    return 1;
  } else{
    return 0;
  }
}

void push(int n){
  if(isFull()){
    printf("Pilha cheia\n");
  } else{
    topo++;
    pilha[topo] = n;
  }
}

int pop(){
  int e;
  if(isEmpty()){
    printf("Pilha vazia\n");
    return 0;
  } else{
    e = pilha[topo];
    pilha[topo] = 0;
    topo--;
    return e;
  }
  return 0;
}

int top(){
  if(isEmpty()){
    printf("Pilha vazia\n");
    return 0;
  } else{
    return pilha[topo];
  }
}

void listar(){
  int i;
  printf("Lista da Pilha:");
  for(i=9; i>=0; i--){
    printf("\n -----\n |%2d | (%d)", pilha[i], i);
    if(i==topo)
      printf(" <");
  }
  printf("\n -----\n");
}

void exibiTopo(){
  printf("\nValor do topo = %d", top());
  printf("\nÍndice do topo = %d", topo);
}

int valor(){
  int x;
  system("clear");
  printf("\nEscolha um valor: ");
  scanf("%d", &x);
  return x;
}

void preenche(){
  if(isFull()){
    printf("Pilha cheia\n");
  } else{
    int i;
    srand(time(NULL));
    for(i=topo+1; i<10; i++){
      int x = rand() % 50;
      push(x);
    }
  }
}

void limpa(){
  if(isEmpty()){
    printf("Pilha vazia\n");
  } else{
    int i;
    for(i=topo; i>=0; i--){
      pop();
    }
  }
}

int main(void) {
  int opcao;

  do{
    opcao = menu();

    switch(opcao){
      case 1: push(valor());
      break;
      case 2: pop();
      break;
      case 3: listar();
      break;
      case 4: exibiTopo();
      break;
      case 5: preenche();
      break;
      case 6: limpa();
      break;
      case 0: printf("Obrigado por utilizar a PILHA\n");
      break;
      default: printf("OPÇÃO INVÁLIDA");
    }
  } while(opcao!=0);

  return 0;
}