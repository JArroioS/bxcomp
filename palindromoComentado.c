//Leia a função main antes da função palin.

#include <stdio.h>
#include <string.h>

//Essas linhas são usadas apenas para simularmos uma variável do tipo booleana e não são totalmente necessárias para o funcionamento do código
#define true 1
#define false 0
typedef int bool;



bool palin(char texto[100], int posicaoInicial, int posicaoFinal) //Assinatura da função que recebe como parâmetros uma string de 100 caracteres, as posições iniciais e finais do que queremos verificar se é palindromo
{

    //O código abaixo irá iterar e comparar os caracteres nos sentidos "inicial até final" e "final até inicial" (primeiro com o último, segundo com penúltimo, terceiro com antepenúltimo, ..., antepenúltimo com terceiro, penúltimo com segundo e último com primeiro)
    //NOTA: Poderiamos diminuir o loop pela metade deixando i = (posicaoFinal-PosicaoInicial)/2 que teoricamente daria certo da mesma maneira, mas estou com preguiça de testar/sono e não foi como eu fiz na etapa 1 (*símbolo de joinha*)
    for(int i = posicaoFinal-posicaoInicial; i>0; i--)
    {
        if(texto[posicaoInicial+i] != texto[posicaoFinal-i])//Caso uma comparação dê 2 caractéres diferentes a função retornará falso, uma vez que a parte da string delimitada pelas posições passadas como parâmetro não é um palíndromo
        {
            return false;
        }
    }

    return true; //Se não foi retornado falso nenhuma vez, todas as comparações foram verdades e portanto a string delimitada é um palíndromo (há um palíndromo na string) e é retornado true
}

int main()
{
    bool verificacao; // variável que será utilizada para receber o valor da função palin
    verificacao = false;

    char string[100]; // string que iremos utilizar como instância da nossa função
    scanf("%[^\n]%*c", string);

    int tamanhoString; // variável utilizada para receber o tamanho da nossa string
    tamanhoString = strlen(string);

    for(int i = 0; i<tamanhoString-2; i++) // iteração de todos os caracteres do primeiro caractére até o anterior do antepenúltimo, visto que um palindromo possui ao menos 3 letras (ex: Em "PARARABO" a iteração será: P > A > R > A > R > A)
    {
        for(int j = tamanhoString-1; j > (i+1); j--) // iteração dos caractéres do final até i+1 (é preciso ser i+1 visto que um palíndromo possui ao menos 3 letras, logo não podemos verificar o valor seguido do i e muito menos o próprio i) (ex: Em "PARARABO", se i = 2 a iteração será: O > B > A > R)
        {
            if(string[i] == string[j]) // verifica se o caractere da primeira iteracao é igual ao da segunda, caso sejam iguais esses caracteres são respectivamente o primeiro e o último do nosso possível palindromo (ex: Em "PABREARABO" os primeiros i e j que iriam dariam a comparação como verdadeira seriam 1 e 7 (ABREARA), embora o palindromo esteja delimitado apenas entre 5 e 7(ABA) )
            {
                verificacao = palin(string, i, j); // chama a função palin passando a string e as posições iniciais e finais da parte que queremos ver se É um palíndromo

                //Se tiver um palindromo na string esse bloco quebra a "repetição j"
                if(verificacao == true)
                {
                    break;
                }
            }
        }

        //Se tiver um palindromo na string esse bloco quebra a "repetição i"
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

CASO A ENTRADA SEJA "BMEVEMRAFM56&" O CÓDIGO FARÁ O SEGUINTE:
B (pos 0) == & (pos 12) -> NÃO
B (pos 0) == 6 (pos 11) -> NÃO
B (pos 0) == 5 (pos 10) -> NÃO
B (pos 0) == M (pos 9) -> NÃO
B (pos 0) == F (pos 8) -> NÃO
B (pos 0) == A (pos 7) -> NÃO
B (pos 0) == R (pos 6) -> NÃO
B (pos 0) == M (pos 5) -> NÃO
B (pos 0) == E (pos 4) -> NÃO
B (pos 0) == V (pos 3) -> NÃO
B (pos 0) == E (pos 2) -> NÃO
M (pos 1) == & (pos 12) -> NÃO
M (pos 1) == 6 (pos 11) -> NÃO
M (pos 1) == 5 (pos 10) -> NÃO
M (pos 1) == M (pos 9) -> SIM
    PALIN(pos 1 a 9):
    M (pos 1) == M (pos 9) -> SIM
    E (pos 2) == F (pos 8) -> NÃO
    RETORNA FALSO
M (pos 1) == F (pos 8) -> NÃO
M (pos 1) == A (pos 7) -> NÃO
M (pos 1) == R (pos 6) -> NÃO
M (pos 1) == M (pos 5) -> SIM
    PALIN(pos 1 a 5):
    M (pos 1) == M (pos 5) -> SIM
    E (pos 2) == E (pos 4) -> SIM
    V (pos 3) == V (pos 3) -> SIM
    E (pos 4) == E (pos 2) -> SIM
    M (pos 5) == M (pos 1) -> SIM
    RETORNA VERDADEIRO
TEM PALINDROMO!!!


CASO A ENTRADA SEJA "01234" O CÓDIGO FARÁ O SEGUINTE:
0 == 4 -> NÃO
0 == 3 -> NÃO
0 == 2 -> NÃO
1 == 4 -> NÃO
1 == 3 -> NÃO
2 == 4 -> NÃO
NÃO TEM PALINDROMO
*/
