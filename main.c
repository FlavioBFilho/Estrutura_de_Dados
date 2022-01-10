#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 5000
#define C 6
#define MAX 3

//Funções e Métodos - Assinatura

int repete(int n, int v[], int len);

int *sort_vetor(int v[], int n, int asc);

void sort_matriz(int m[][MAX], int l, int c, int by_index, int asc);

void forma_duplas(int v[], int len, int d[][2]);

int contem(int v[], int x, int len);

//Main

int main(void) {
  
  int sorteios[L][C]; //Armazena os sorteios e seus números
  int rep_nums[60][MAX]; //Armazena as quantidades de vezes que cada número se repetirá nos sorteios
  int rep_dups[1770][MAX];

  //Inicializa o vetor de repetição de números 
  for(int i=0; i<60; i++){
    rep_nums[i][0] = i+1;
    rep_nums[i][1] = 0;
    rep_nums[i][2] = 0;
  }

  //Inicializa a matriz de repetição de duplas
  int k=0;
  for(int i=1; i<=60; i++){
    for(int j=i+1; j<=60; j++){
      if(i!=j){
        rep_dups[k][0] = 0;
        rep_dups[k][1] = i;
        rep_dups[k][2] = j;
        k++;
      }
    }
  }

  //Geração, processamento e apresentação dos dados dos sorteios

  srand(time(NULL));
  for(int i=0; i<L; i++){

    printf("SORTEIO #%02d: ", i+1);
    for(int j=0; j<C; j++){
      
      //Confere se o número já existe no sorteio i antes de armazená-lo definitivamente  

      do{
        sorteios[i][j] = (rand() % 60) + 1;
      }while(repete(sorteios[i][j], sorteios[i], j)==1);

      //Contabiliza a repetição do número sorteado
      rep_nums[sorteios[i][j]-1][1] += 1;

      printf("%02d ", sorteios[i][j]);    

    }
    printf("\n");

    int dpls[15][2];
    forma_duplas(sorteios[i], C, dpls);

    //Contabiliza a repetição de cada dupla do sorteio
    for(int k=0; k<15; k++){
      for(int l=0; l<1770; l++){
        if((dpls[k][0] == rep_dups[l][1]) && (dpls[k][1] == rep_dups[l][2])){
          rep_dups[l][0]++;
        }
      }
    }

    //Contabiliza a não-repetição de números azarados
    for(int k=0; k<60; k++){
      if(contem(sorteios[i], rep_nums[k][0], C)){
        rep_nums[k][2] = 0;
      } else{
        rep_nums[k][2]++;
      }
    }
  }

  //Saídas pertinentes ao programa

  //Quantas vezes cada número foi sorteado
  printf("\nQuantidade de vezes que cada número saiu:\n");
  for(int i=0; i<60; i++){
    printf("Número %02d = %2d vezes\n", rep_nums[i][0], rep_nums[i][1]);
  }

  //15 duplas que mais saíram nos sorteios
  printf("\n15 duplas que mais saíram:\n");
  sort_matriz(rep_dups, 1770, 3, 0, 0);
  for(int i=0; i<15; i++){
    printf("%02d e %02d = %2d vezes\n", rep_dups[i][1], rep_dups[i][2], rep_dups[i][0]);
  }

  //15 números que mais saíram nos sorteios
  printf("\n15 números únicos que mais saíram:\n");
  sort_matriz(rep_nums, 60, 3, 1, 0);
  for(int i=0; i<15; i++){
    printf("Número %02d = %2d vezes\n", rep_nums[i][0], rep_nums[i][1]);
  }

  sort_matriz(rep_nums, 60, 3, 0, 1);
  //Quantidade de jogadas desde a última vez que cada número foi sorteado
  printf("\nQuantidade de jogadas desde a última vez que cada número saiu:\n");
  for(int i=0; i<60; i++){
    printf("Nº %02d = ", rep_nums[i][0]);
    if(rep_nums[i][2]==0){
      printf("saiu no último sorteio.");
    }
    else{
      printf("não sai a %3d sorteios seguidos.", rep_nums[i][2]);
    }
    printf("\n");
  }
  
  return 0;
}

//Funções e Métodos - Implementação

int repete(int n, int v[], int len){

  int achou=0;
  for(int i=0; i<len; i++){
    if(n==v[i]){
      achou=1;
      break;
    }
  }

  return achou;
}

int *sort_vetor(int v[], int n, int asc){
  int teste;
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1; j++){
      if(asc){
        teste = v[j] > v[j+1];
      } else{
        teste = v[j] < v[j+1];
      }

      if(teste){
        int x = v[j];
        v[j] = v[j+1];
        v[j+1] = x;
      }
    }
  }

  return v;
}

void sort_matriz(int m[][MAX], int l, int c, int by_index, int asc){
  int teste;

  for(int i=0; i<l-1; i++){
    for(int j=0; j<l-1; j++){
      if(asc){
        teste = m[j][by_index] > m[j+1][by_index];
      } else{
        teste = m[j][by_index] < m[j+1][by_index];
      }

      if(teste){
        int x[c];
        for(int k=0; k<c; k++){
          x[k] = m[j][k];
        }

        for(int k=0; k<c; k++){
          m[j][k] = m[j+1][k];
          m[j+1][k] = x[k];
        }
      }
    }
  }
}

void forma_duplas(int v[], int len, int d[][2]){
    int *sort_v = v, k;
    sort_vetor(sort_v, len, 1);

    k=0;
    for(int i=0; i<len; i++){
      for(int j=i+1; j<len; j++){
        if(i!=j){
          //printf("%d e %d\n", v[i], v[j]);
          d[k][0] = sort_v[i];
          d[k][1] = sort_v[j];
          k++;
        }
      }
    }
}

int contem(int v[], int x, int len){
  int achou = 0;
  for(int i=0; i<len; i++){
    if(v[i] == x){
      achou = 1;
      break;
    }
  }
  return achou;
}