#include <stdio.h>

int solve(){
    int numeroVizinhos,numeroPassesFeitos,vizinhoPasse;

    numeroPassesFeitos = 0;
    scanf("%d",&numeroVizinhos);
    int distanciaVizinho[numeroVizinhos];

    for(int i = 0; i<numeroVizinhos; i++){
        scanf("%d",&distanciaVizinho[i]);
    }

    for(vizinhoPasse = 1; 1; vizinhoPasse++){
        numeroPassesFeitos++;
        if(numeroPassesFeitos >= distanciaVizinho[vizinhoPasse%numeroVizinhos]){return (vizinhoPasse%numeroVizinhos)+1;}
    }
}

int main(){
    int numeroCasos,resultado;
    scanf("%d",&numeroCasos);

    for(int n = 0; n<numeroCasos; n++){
        resultado = solve();
        printf("%d\n",resultado);
    }
}
