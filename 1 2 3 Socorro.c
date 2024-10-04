#include <stdio.h>
#include <stdlib.h>


int main() {
  int casos;
  int matriz[7][7] = {0}; //zera matriz

  scanf("%d", &casos);

  while(casos--){

    for(int i = 0; i < 7; i++){ //popula a matriz
      for(int j = 0; j < 7; j++){
        scanf("%d", &matriz[i][j]);
      }
    }

    for(int i = 0; i < 7; i++){ 
      for(int j = 0; j < 7; j++){
        matriz[j][i] = matriz[i][j]; //pega a diagonal de cima e copia para a diagonal de baixo
      }
    }

    printf("\n");

    for(int i = 0; i < 7; i++){
      for(int j = 0; j < 7; j++){
        printf("%d " , matriz[i][j]);
      }

      printf("\n");
    }

    printf("\n");
  }
    return 0;
}
