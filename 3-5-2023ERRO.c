#include <stdio.h>
#include <string.h>

int main() {
    int casos;
    char pokemon[999];

    // Leitura da quantidade de casos
    scanf("%d", &casos);
    getchar(); // Limpa o \n residual

    // Loop para cada caso
    for (int i = 0; i < casos; i++) {
        
        int HP = 0;
        int ATK = 0;
        int DEF = 0;
        int SPC = 0;
        int SPE = 0;

        // Lê a sequência
        fgets(pokemon, sizeof(pokemon), stdin);
        pokemon[strcspn(pokemon, "\n")] = '\0';

        // Leitura dos atributos
        scanf("%d %d %d %d %d", &HP, &ATK, &DEF, &SPC, &SPE);

        int BST = HP + ATK + DEF + SPC + SPE;

        // Resultado baseado na verificação
        if (pokemon[0] == 'Q' || pokemon[0] == 'q' || 
            pokemon[0] == 'U' || pokemon[0] == 'u' || 
            pokemon[0] == 'X' || pokemon[0] == 'x' || 
            pokemon[0] == 'Y' || pokemon[0] == 'y' || 
            BST < 195 || BST > 744) {
            printf("%s ta esquisito hein, deve ser um Digimon!\n", pokemon);
        } else {
            printf("%s parece legitimo, da ate pra acreditar.\n", pokemon);
        }
    }

    return 0;
}