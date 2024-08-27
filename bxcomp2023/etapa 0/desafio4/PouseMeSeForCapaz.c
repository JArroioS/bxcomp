#include <stdio.h>
#include <string.h>

int main()
{
    char codigo[3];
    char endereco[999];
    int tamanhoDoEndereco;
    int quantidadeDeRuido;
    scanf("%s",codigo);
    while(strcmp(codigo,"QTH") == 0)
    {
        scanf("\n%[^\n]",endereco);
        tamanhoDoEndereco = strlen(endereco);
        quantidadeDeRuido = 0;
        
        for(int i = 0; i<tamanhoDoEndereco; i++)
        {
            if(endereco[i]=='@' || endereco[i]=='&' || endereco[i]=='!' || endereco[i]=='*')
            {
                quantidadeDeRuido++;
            }
        }

        if(quantidadeDeRuido > tamanhoDoEndereco/2)
        {
            printf("Base T, estou com muito QRT na mensagem, poderia reenviar ?\n");
        }
        else
        {
            printf("Imperatriz, o pouso sera na zona %s\n",endereco);
        }

        scanf("%s",codigo);
    }
}