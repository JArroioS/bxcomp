#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool par(int n){ // função para verificar se é par, meio trivial né
    if(n % 2 == 0) return true;
    return false;
}


/*conversao para binario, recapitulando o binario é a divisao do numero por 2 
e vendo se o resto é 1 ou 0 e a prox divisao sera feita pela metade desse numero, 
por exemplo 
8 % 2 = 0
4 % 2 = 0, 
2 % 2 = 0 
1 % 2  = 1 
entao o 8 em binario é = 1000
*/

int convertbin(int n){ 
    int i = 0;
    int vetorbin[50] = {0}; //zerando o vetor para verificar os "uns (1)" depois, deve ter um jeito mais facil sem ter q alocar tanta memoria.
    int sum = 0; //obrigatorio zera esse numero dai.

    while(n > 0){ // colocando os 0 e 1 dentro de uma array.
        vetorbin[i] = n % 2;
        i++;
        n = n/2;
    }

    for(int i = 0; i < 50; i++){ // somando todos os "uns (1)" dentro dessa array.
        if(vetorbin[i] == 1){
            sum++;
        }
    }
    return sum;
}


int main(){
    int casos;
    int num1, num2, resultado;

    scanf("%d", &casos);

    while(casos--){ // loop de casos

        scanf("%d %d" , &num1, &num2);

        resultado = convertbin(num1) - convertbin(num2); //resultado da subtracao das somas dos uns dos binarios desses numeros.

        if(par(resultado) == true){ //retorno booleano da função par e verificando se é true ou nao.
            puts("DEU GREEN MARCHAAAA ESTOREI NA BET VAMO PRA DUBAI");
        }else{
        puts("Vermelhou aqui, ja era. Pai vou ter que vender a casa");
        }
    }
}

