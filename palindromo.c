#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

bool palin(char texto[100], int posicaoInicial, int posicaoFinal)
{

    for(int i = posicaoFinal-posicaoInicial; i>0; i--)
    {
        if(texto[posicaoInicial+i] != texto[posicaoFinal-i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    bool verificacao;

    char string[100];
    scanf("%[^\n]%*c", string);

    int tamanhoString = strlen(string);

    for(int i = 0; i<tamanhoString-2; i++)
    {
        for(int j = tamanhoString-1; j > (i+1); j--)
        {
            if(string[i] == string[j])
            {
                verificacao = palin(string, i, j);
                if(verificacao == true)
                {
                    break;
                }
            }
        }

        if(verificacao == true)
        {
            break;
        }
    }

    if(verificacao == true)
    {
        printf("Tem palindromo");
    }
    else
    {
        printf("Nao tem palindromo");
    }

    return 0;
}
