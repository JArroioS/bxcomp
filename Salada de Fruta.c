#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int casos;
  int count = 0;
  char frase[255];
  char stop[6] = "stop";
  char *temp = frase;
  int j = 0;
  
  scanf("%d", &casos);

  while(casos--){
    fgets(frase, 255, stdin); // o scanf da Frase
    frase[strlen(frase) - 1] = '\0'; // tira o "resto" da frase, como o \n por exemplo

    for(int i = 0; i < strlen(frase); i++){ // transforma toda a frase em minuscula.
        frase[i] = tolower(frase[i]);
    }
    
    for (int i = 0; frase[i] != '\0'; i++) { // esse for tira repetições de letras, transforma o "stoooooop" em "stop"
        if (i == 0 || frase[i] != frase[i - 1]) {
            frase[j++] = frase[i];
        }
    }
    frase[j] = '\0';

    while ((temp = strstr(temp, stop)) != NULL){ //procura o stop dentro da frase e aumenta o contador
        count++;
        temp += strlen(stop);
    }
    printf("%d", count);
    
    return 0;
    }
}
