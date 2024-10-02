#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int casos;
  int count = 0;
  char frase[255];
  char stop[6] = "stop";
  char *temp = frase;

  scanf("%d", &casos);

  while(casos--){
    fgets(frase, 255, stdin);
    frase[strlen(frase) - 1] = '\0';

    for(int i = 0; i < strlen(frase); i++){
        frase[i] = tolower(frase[i]);
    }

    int j = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (i == 0 || frase[i] != frase[i - 1]) {
            frase[j++] = frase[i];
        }
    }
    frase[j] = '\0';

    while ((temp = strstr(temp, stop)) != NULL){
        count++;
        temp += strlen(stop);
    }
    printf("%d", count);
    
    return 0;
    }
}