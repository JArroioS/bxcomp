#include <stdio.h>
#include <string.h>

int main() {
    char linha[100]; // Defina um tamanho adequado para a linha
    int i, j;

    // Lendo uma linha incluindo os espaços
    printf("Digite uma linha: ");
    fgets(linha, sizeof(linha), stdin);

    // Substituindo o \n final por NULL
    linha[strcspn(linha, "\n")] = '\0'; // Remove o \n que fgets captura

    // Removendo espaços
    j = 0; // Índice para construir a nova string sem espaços
    for (i = 0; linha[i] != '\0'; i++) {
        if (linha[i] != ' ') {
            linha[j++] = linha[i]; // Copia o caractere não-espaço
        }
    }
    linha[j] = '\0'; // Finaliza a nova string sem espaços

    // Exibindo o resultado
    printf("Resultado sem espacos: %s\n", linha);
    printf("Tamanho da string sem espacos: %d\n", j);
    return 0;
}