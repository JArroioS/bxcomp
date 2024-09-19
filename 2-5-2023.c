#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para toupper

int main() {
    int casos;
    char string[999]; // String que armazenará os comandos

    // Leitura da quantidade de casos
    scanf("%d", &casos);
    getchar(); // Limpa o \n residual

    // Loop para cada caso
    for (int i = 0; i < casos; i++) {
        int contadorhadouken = 0;
        int teclasinvalidas = 0;

        scanf("%s", string); // Lê a string de comandos
        getchar(); // Limpa o \n residual
        int tamanho = strlen(string);

        // Deixar tudo em maiúsculo
        for (int j = 0; j < tamanho; j++) {
            string[j] = toupper(string[j]);
        }

        // Verificar se o combo HADOUKEN aparece na sequência correta (ASDJ)
        for (int k = 0; k < tamanho; k++) {
            // Verifica se há teclas inválidas
            if (string[k] != 'A' && string[k] != 'W' && string[k] != 'S' && string[k] != 'D' && string[k] != 'J' && string[k] != 'K') {
                teclasinvalidas = 1;
            }

            // Verifica a sequência "ASDJ" de forma segura
            if (k >= 3 && string[k] == 'J' && string[k-1] == 'D' && string[k-2] == 'S' && string[k-3] == 'A') {
                contadorhadouken = 1;
            }
        }

        // Saídas de acordo com o resultado
        if (teclasinvalidas) {
            printf("Para de apertar qualquer coisa noob\n");
        } else if (contadorhadouken) {
            printf("HADOUKEEEN\n");
        } else {
            printf("Uuugh Uuugh...Continue? 10, 9, 8, 7, 6, 5, 4, 3, 2, 1...\n");
        }
    }

    return 0;
}