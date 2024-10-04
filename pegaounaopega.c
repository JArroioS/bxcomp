#include <stdio.h>
#include <stdlib.h>

int solve(){
    char letra;
    float xPolicia, yPolicia, xLadrao, yLadrao, velocidadePolicia, velocidadeLadrao, tempo;

    scanf("%f %f",&velocidadePolicia, &velocidadeLadrao);
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            scanf(" %c",&letra);
            if(letra == 'P'){
                xPolicia = j;
                yPolicia = i;
            }
            else if(letra == 'L'){
                xLadrao = j;
                yLadrao = i;
            }
        }
    }

    if(xPolicia == xLadrao && yPolicia > yLadrao){return 2;}

    if(velocidadePolicia == 0 && velocidadeLadrao == 0){return 3;}

    if(velocidadePolicia == 0){
        if((9-yLadrao)/velocidadeLadrao <= 3){return 1;}
        else{return 3;}
    }

    if(velocidadeLadrao == 0){
        if((abs(xLadrao-xPolicia)+abs(yLadrao-yPolicia))/velocidadePolicia <= 3){return 2;}
        else{return 3;}
    }

    if((9-yLadrao)/velocidadeLadrao <= 3){
        tempo = abs(xLadrao - xPolicia)/velocidadePolicia;
        xPolicia = xLadrao;
        yLadrao = velocidadeLadrao*tempo+yLadrao;
        if(yLadrao >= 9){return 1;}
        if(yPolicia >= yLadrao){return 2;}
        tempo = (9-yLadrao)/velocidadeLadrao;
        yLadrao = velocidadeLadrao*tempo+yLadrao;
        yPolicia = velocidadePolicia*tempo+yPolicia;
        if(yPolicia > yLadrao){return 2;}
        else{return 1;}
    }
    else{
        tempo = abs(xLadrao - xPolicia)/velocidadePolicia;
        xPolicia = xLadrao;
        yLadrao = velocidadeLadrao*tempo+yLadrao;
        if(tempo > 3){return 3;}
        if(yLadrao >= 9){return 3;}
        if(yPolicia >= yLadrao){return 2;}
        tempo = 3-tempo;
        yPolicia = velocidadePolicia*tempo+yPolicia;
        yLadrao = velocidadeLadrao*tempo+yLadrao;
        if(yPolicia >= yLadrao){return 2;}
        else{return 3;}
    }
}

int main(){
    int resultado;
    int numeroCasos;
    scanf("%d",&numeroCasos);

    for(int n = 0; n<numeroCasos; n++){
        resultado = solve();

        if(resultado == 1){printf("Dessa vez o crime compensou...\n");}
        else if(resultado == 2){printf("Hoje nao, essa cidade eh pequena demais para nos dois\n");}
        else if(resultado == 3){printf("Olha so, nem preciso me mexer!\n");}
    }
}
