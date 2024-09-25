#include <stdio.h>
#include <string.h>

int main() {
    char stringmaior[255];
    char stringmenor[255];
    int contador = 0;
    char *temp;

    // Lê a maior string e substitui o \n por NULL
    fgets(stringmaior, sizeof(stringmaior), stdin);
    stringmaior[strcspn(stringmaior, "\n")] = '\0';

    // Lê a menor string e substitui o \n por NULL
    fgets(stringmenor, sizeof(stringmenor), stdin);
    stringmenor[strcspn(stringmenor, "\n")] = '\0';

    // Inicializa temp com a stringmaior
    temp = stringmaior;

    // Faz um loop para procurar a menor string dentro da maior
    while ((temp = strstr(temp, stringmenor)) != NULL) {
        // Verifica se a palavra está isolada, ou seja, se antes e depois são espaços ou o fim da string
        if ((temp == stringmaior || *(temp - 1) == ' ') && (*(temp + strlen(stringmenor)) == ' ' || *(temp + strlen(stringmenor)) == '\0')) {
            contador++;
        }
        // Avança o ponteiro para procurar a próxima ocorrência
        temp += strlen(stringmenor);
    }

    printf("A palavra '%s' aparece %d vez(es)\n", stringmenor, contador);

    return 0;
}