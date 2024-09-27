#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int missaoCompleta;
    float tamanhoObstaculos;
    int tamanhoObstaculosCorrigido;

    char string1[999];
    char string2[999];

    int numeroCasos;
    scanf("%d",&numeroCasos);

    for(int n=0; n<numeroCasos; n++){
        missaoCompleta = 1;
        while(1){
            tamanhoObstaculos = 0;
            scanf("%s",string1);
            if(!strcmp(string1,"fim")){
                break;
            }
            scanf("%s",string2);

            for(int i = 0; i<strlen(string1); i++){

                tamanhoObstaculos += (int)string1[i];
            }

            tamanhoObstaculos /= 15*strlen(string1);
            tamanhoObstaculosCorrigido = (int)floor(tamanhoObstaculos);

            if(!strcmp(string2,"botaoesquerdo")){
                if(tamanhoObstaculosCorrigido%2 == 0){
                    missaoCompleta = 0;
                }
            }
            else{
                if(tamanhoObstaculosCorrigido%2 != 0){
                    missaoCompleta = 0;
                }
            }
        }

        if(missaoCompleta == 1){
            printf("MISSAO COMPLETA!! RESPECT + B)\n");
        }
        else{
            printf("TUDO QUE A GENTE PRECISAVA FAZER ERA SEGUIR O MALDITO TREM, CJ!\n");
        }
    }
}
