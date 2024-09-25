#include <stdio.h>
#include <string.h> // fgets e strcspn
#include <stdlib.h> // usa a função atoi que transforma string em int

int main() {
    int casos;
    char nomeheroi[999];
    int numartefatos;
    char nomeartefatos[999];
    int danoartefato;
    int danototal;

    // Leitura da quantidade de casos
    scanf("%d", &casos);
    getchar(); // Limpa o \n residual

    // Loop para cada caso
    for (int i = 0; i < casos; i++) {
        // Reinicia os valores a cada loop
        numartefatos = 0;
        danoartefato = 0;
        danototal = 0;

        // Lê o nome do héroi
        fgets(nomeheroi, sizeof(nomeheroi), stdin);
        nomeheroi[strcspn(nomeheroi, "\n")] = '\0';

        // Scan os números de artefatos
        scanf("%d", &numartefatos);
        getchar();

        // Verificar o último espaço para somar a parte do final que será int das string
        for(int j = 0; j < numartefatos; j ++){
            // Le tudo do numero dos artefatos e o numeros
            fgets(nomeartefatos, sizeof(nomeartefatos), stdin);
            nomeartefatos[strcspn(nomeartefatos, "\n")] = '\0';

            int tamanho = strlen(nomeartefatos);
            int indices = tamanho - 1;

            // Percorrer a string de trás para frente para encontrar o último número
            for (int k = indices; k >= 0; k--) {
                if (nomeartefatos[k] == ' ') {
                    // Encontrou o primeiro espaço vindo do final
                    // Vamos isolar apenas o número que vem após o espaço, encontramos o primeiro caractere após o espaco k + 1
                    // Ai copiamos a parte da string após o primeiro espaco &nomeartefatos[k+1], iniciando no primeiro caractere apos o espaco
                    strcpy(nomeartefatos, &nomeartefatos[k + 1]);  // Copia a parte do número para o início da string
                    break;
                }
            }

            // Converte o número restante para inteiro e soma no danototal
            danoartefato = atoi(nomeartefatos);  // Transforma o número de string para int
            danototal += danoartefato;
        }
        printf("%s: %d DPS\n", nomeheroi, danototal);
    }
    return 0;
}