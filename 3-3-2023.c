#include <stdio.h>
#include <string.h>

int main() {
    int casos;
    char sequencia[999];

    // Leitura da quantidade de casos
    scanf("%d", &casos);
    getchar(); // Limpa o \n residual

    // Loop para cada caso
    for (int i = 0; i < casos; i++) {
        
        // Lê a sequência
        fgets(sequencia, sizeof(sequencia), stdin);
        sequencia[strcspn(sequencia, "\n")] = '\0';

        int tamanho = strlen(sequencia);

        // Se for ímpar retorna Fallen, senão reorganiza a string de forma decrescente
        if(tamanho % 2 != 0){
            printf("Fallen guarda a AWP porque vai explodir.\n");
        }else{ 
            // Ordenação usando Bubble Sort
            for(int j = 0; j < tamanho-1; j++) { // Loop externo para percorrer o vetor/string
                for(int k = 0; k < tamanho-j-1; k++) { // Loop interno para comparar elementos adjacentes
                    if(sequencia[k] < sequencia[k+1]) { // Se k for menor que o proximo
                        // Trocando os caracteres
                        char temp = sequencia[k]; // Salva o k no temp
                        sequencia[k] = sequencia[k+1]; // Coloca o k no k+1
                        sequencia[k+1] = temp; // Substitui o k+1 pelo k salvo no temp anteriormente
                    }
                }
            }
            printf("%s\n", sequencia);
        }
    }

    return 0;
}