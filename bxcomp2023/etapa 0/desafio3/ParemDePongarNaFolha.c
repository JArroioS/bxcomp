#include <stdio.h>

int main()
{
    int numeroCasos;
    int quantidadePartidas;
    int pontuacaoJogador1, pontuacaoJogador2, vitoriasJogador1, vitoriasJogador2;
    
    scanf("%d",&numeroCasos);

    for(int i = 0; i<numeroCasos; i++)
    {
        vitoriasJogador1 = 0;
        vitoriasJogador2 = 0;
        scanf("%d",&quantidadePartidas);
        for(int j = 0; j<quantidadePartidas; j++)
        {
            scanf("%d %d",&pontuacaoJogador1,&pontuacaoJogador2);
            if(pontuacaoJogador1 > pontuacaoJogador2)
            {
                printf("%d-1 ",pontuacaoJogador1);
                vitoriasJogador1++;
            }
            else if(pontuacaoJogador2 > pontuacaoJogador1)
            {
                printf("%d-2 ",pontuacaoJogador2);
                vitoriasJogador2++;
            }
            else
            {
                printf("%d-Empate ",pontuacaoJogador1);
            }
        }
        if(vitoriasJogador1 > vitoriasJogador2)
        {
            printf("Resultado: 1\n");
        }
        else if(vitoriasJogador2 > vitoriasJogador1)
        {
            printf("Resultado: 2\n");
        }
        else
        {
            printf("Resultado: Empate\n");
        }
    }
}