#include <stdio.h>
#include <string.h>

int main(){
	char stringmaior[255];
	char stringmenor[255];
	int contador = 0;
	char *temp = stringmaior;

	// Lê a maior string e sibstitui o \n por NULL
	fgets(stringmaior, sizeof(stringmaior), stdin);
	stringmaior[strcspn(stringmaior, "\n")] = '\0';
	
	// Lê a menor string e sibstitui o \n por NULL
	fgets(stringmenor, sizeof(stringmenor), stdin);
	stringmenor[strcspn(stringmenor, "\n")] = '\0';

	// Faz um loop que funciona quando é diferente de NULL a quantidade da string menor na maior
	while ((temp = strstr(temp, stringmenor)) != NULL) {
        contador++;
    	// Avança o ponteiro para procurar a próxima ocorrência
        temp += strlen(stringmenor);
    }

	printf("A palavra ''%s'' aparece %d vezes\n", stringmenor, contador);

	return 0;
}
