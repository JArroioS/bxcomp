#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int quantidadeCasos;
    float raioPlaneta;
    double circunferenciaPlaneta;
    int circunferenciaPlanetaTruncada;
    char mensagem[23];
    char stringCircunferencia[6];

    scanf("%d",&quantidadeCasos);
    
    for(int i = 0; i<quantidadeCasos; i++)
    {
        scanf("%f",&raioPlaneta);
        scanf("%s",mensagem);
        
        circunferenciaPlaneta = 2*3.14159265*raioPlaneta;
        circunferenciaPlanetaTruncada = trunc(circunferenciaPlaneta);
        
        if(circunferenciaPlanetaTruncada > 40075)
        {
            printf("OLHA O TAMANHO DESSE PLANETA\n");
        }
        
        else
        {
            sprintf(stringCircunferencia, "%d", circunferenciaPlanetaTruncada);
            char *subString = strstr(mensagem, stringCircunferencia);
            
            if(subString == NULL)
            {
                printf("Ferrou, estamos no planeta errado\n");
            }
            else
            {
                printf("Foguete nao tem marcha re, vamo bora fml\n");
            }
        }
    }
}