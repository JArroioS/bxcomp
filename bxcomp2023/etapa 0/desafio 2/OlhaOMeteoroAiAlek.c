#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

int main()
{
    bool passamos;
    int numeroCasos,posicaoNave, meteorosNaFrente;
    int vetor[10];
    
    scanf("%d",&numeroCasos);
    
    for(int i = 0; i<numeroCasos; i++)
    {
        posicaoNave = -1;
        meteorosNaFrente = 0;
        passamos = true;
        
        for(int j=0; j<10; j++)
        {
            scanf("%d",&vetor[j]);
            if(vetor[j] == 2)
            {
                posicaoNave = j;
            }
        }
        
        for(int j=posicaoNave+1; j<10; j++)
        {
            if(vetor[j] == 1)
            {
                meteorosNaFrente++;
            }
        }
        if(meteorosNaFrente > 2)
        {
            passamos = false;
        }
        
        for(int j=posicaoNave-1; posicaoNave-j <= 9-posicaoNave; j--)
        {
            if(vetor[j] == 1)
            {
                passamos = false;
            }
        }
        
        if(passamos == true)
        {
            printf("Explorador do espaço para base alpha, conseguimos passar pela chuva de meteoros!\n");
        }
        else
        {
            printf("Nu, vou tascar um beijo numa pedra do espaço se eu entrar ai, paia.\n");
        }
    }
}