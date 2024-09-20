//Leia a fun��o main antes da fun��o palin.

#include <stdio.h>
#include <string.h>

//Essas linhas s�o usadas apenas para simularmos uma vari�vel do tipo booleana e n�o s�o totalmente necess�rias para o funcionamento do c�digo
#define true 1
#define false 0
typedef int bool;



bool palin(char texto[100], int posicaoInicial, int posicaoFinal) //Assinatura da fun��o que recebe como par�metros uma string de 100 caracteres, as posi��es iniciais e finais do que queremos verificar se � palindromo
{

    //O c�digo abaixo ir� iterar e comparar os caracteres nos sentidos "inicial at� final" e "final at� inicial" (primeiro com o �ltimo, segundo com pen�ltimo, terceiro com antepen�ltimo, ..., antepen�ltimo com terceiro, pen�ltimo com segundo e �ltimo com primeiro)
    //NOTA: Poderiamos diminuir o loop pela metade deixando i = (posicaoFinal-PosicaoInicial)/2 que teoricamente daria certo da mesma maneira, mas estou com pregui�a de testar/sono e n�o foi como eu fiz na etapa 1 (*s�mbolo de joinha*)
    for(int i = posicaoFinal-posicaoInicial; i>0; i--)
    {
        if(texto[posicaoInicial+i] != texto[posicaoFinal-i])//Caso uma compara��o d� 2 caract�res diferentes a fun��o retornar� falso, uma vez que a parte da string delimitada pelas posi��es passadas como par�metro n�o � um pal�ndromo
        {
            return false;
        }
    }

    return true; //Se n�o foi retornado falso nenhuma vez, todas as compara��es foram verdades e portanto a string delimitada � um pal�ndromo (h� um pal�ndromo na string) e � retornado true
}

int main()
{
    bool verificacao; // vari�vel que ser� utilizada para receber o valor da fun��o palin
    verificacao = false;

    char string[100]; // string que iremos utilizar como inst�ncia da nossa fun��o
    scanf("%[^\n]%*c", string);

    int tamanhoString; // vari�vel utilizada para receber o tamanho da nossa string
    tamanhoString = strlen(string);

    for(int i = 0; i<tamanhoString-2; i++) // itera��o de todos os caracteres do primeiro caract�re at� o anterior do antepen�ltimo, visto que um palindromo possui ao menos 3 letras (ex: Em "PARARABO" a itera��o ser�: P > A > R > A > R > A)
    {
        for(int j = tamanhoString-1; j > (i+1); j--) // itera��o dos caract�res do final at� i+1 (� preciso ser i+1 visto que um pal�ndromo possui ao menos 3 letras, logo n�o podemos verificar o valor seguido do i e muito menos o pr�prio i) (ex: Em "PARARABO", se i = 2 a itera��o ser�: O > B > A > R)
        {
            if(string[i] == string[j]) // verifica se o caractere da primeira iteracao � igual ao da segunda, caso sejam iguais esses caracteres s�o respectivamente o primeiro e o �ltimo do nosso poss�vel palindromo (ex: Em "PABREARABO" os primeiros i e j que iriam dariam a compara��o como verdadeira seriam 1 e 7 (ABREARA), embora o palindromo esteja delimitado apenas entre 5 e 7(ABA) )
            {
                verificacao = palin(string, i, j); // chama a fun��o palin passando a string e as posi��es iniciais e finais da parte que queremos ver se � um pal�ndromo

                //Se tiver um palindromo na string esse bloco quebra a "repeti��o j"
                if(verificacao == true)
                {
                    break;
                }
            }
        }

        //Se tiver um palindromo na string esse bloco quebra a "repeti��o i"
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

/*
RESUMO:

CASO A ENTRADA SEJA "BMEVEMRAFM56&" O C�DIGO FAR� O SEGUINTE:
B (pos 0) == & (pos 12) -> N�O
B (pos 0) == 6 (pos 11) -> N�O
B (pos 0) == 5 (pos 10) -> N�O
B (pos 0) == M (pos 9) -> N�O
B (pos 0) == F (pos 8) -> N�O
B (pos 0) == A (pos 7) -> N�O
B (pos 0) == R (pos 6) -> N�O
B (pos 0) == M (pos 5) -> N�O
B (pos 0) == E (pos 4) -> N�O
B (pos 0) == V (pos 3) -> N�O
B (pos 0) == E (pos 2) -> N�O
M (pos 1) == & (pos 12) -> N�O
M (pos 1) == 6 (pos 11) -> N�O
M (pos 1) == 5 (pos 10) -> N�O
M (pos 1) == M (pos 9) -> SIM
    PALIN(pos 1 a 9):
    M (pos 1) == M (pos 9) -> SIM
    E (pos 2) == F (pos 8) -> N�O
    RETORNA FALSO
M (pos 1) == F (pos 8) -> N�O
M (pos 1) == A (pos 7) -> N�O
M (pos 1) == R (pos 6) -> N�O
M (pos 1) == M (pos 5) -> SIM
    PALIN(pos 1 a 5):
    M (pos 1) == M (pos 5) -> SIM
    E (pos 2) == E (pos 4) -> SIM
    V (pos 3) == V (pos 3) -> SIM
    E (pos 4) == E (pos 2) -> SIM
    M (pos 5) == M (pos 1) -> SIM
    RETORNA VERDADEIRO
TEM PALINDROMO!!!


CASO A ENTRADA SEJA "01234" O C�DIGO FAR� O SEGUINTE:
0 == 4 -> N�O
0 == 3 -> N�O
0 == 2 -> N�O
1 == 4 -> N�O
1 == 3 -> N�O
2 == 4 -> N�O
N�O TEM PALINDROMO
*/
