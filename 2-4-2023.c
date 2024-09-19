#include <stdio.h>
#include <math.h> // para abs

int main() {
    int casos;
    int matriz[5][5]; // Corrigido para ser uma matriz 5x5
    int cobrax = -1, cobray = -1; // Posições da cobra
    int corujax[5], corujay[5];  // Arrays para guardar as posições das corujas (supondo no máximo 5)
    int sehacoruja; // Contador de corujas
    int distancia;

    // Leitura da quantidade de casos
    scanf("%d", &casos);
    getchar(); // Limpa o \n residual

    // Loop para cada caso
    for (int i = 0; i < casos; i++) {
        sehacoruja = 0; // Inicializa o contador de corujas a cada novo caso

        // Leitura da matriz 5x5
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%d", &matriz[j][k]);

                // Encontrar a posição da cobra
                if (matriz[j][k] == 42) {
                    cobrax = j;
                    cobray = k;
                }

                // Encontrar a posição de uma coruja
                if (matriz[j][k] == 13) {
                    corujax[sehacoruja] = j;
                    corujay[sehacoruja] = k;
                    sehacoruja++;
                }
            }
        }

        // Se houver corujas, calcular as distâncias
        if (sehacoruja > 0) {
            for (int l = 0; l < sehacoruja; l++) {
                distancia = fabs(cobrax - corujax[l]) + fabs(cobray - corujay[l]); //abs retorna valor absoluto, calcula a distancia de um até o outro
                printf("A cobrinha percorreu %d casas para salvar a coruja %d\n", distancia, l);
            }
        }

        // Se não houver corujas
        if (sehacoruja == 0) {
            printf("Todas as corujas foram resgatadas XD\n");
        }
    }

    return 0;
}
