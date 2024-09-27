#include <stdio.h>
#include <string.h>
#include <stdlib.h> //para atoi

int main(){
    int casos;
    int matriz[3][3];
    char string[255];
    int salvarnumeros[255];
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){

        salvarnumeros[0] = f1;
        salvarnumeros[1] = f2;
        salvarnumeros[2] = f3;
        salvarnumeros[3] = f4;
        salvarnumeros[4] = f5;
        salvarnumeros[5] = f6;

        // Scan matriz, aumenta os valores de f1, f2,f3,f4,f5,f6
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                scanf("%d", &matriz[j][k]);
                if(matriz[j][k] == 1){
                    f1++;
                }else if(matriz[j][k] == 2){
                    f2++;
                }else if(matriz[j][k] == 3){
                    f3++;
                }else if(matriz[j][k] == 4){
                    f4++;
                }else if(matriz[j][k] == 5){
                    f5++;
                }else if(matriz[j][k] == 6){
                    f6++;
                }
            }
        }

        // Lê as 9 strings
        for(int l = 0; l < 9; l++){
            fgets(string, sizeof(string), stdin);
            string[strcspn(string, "\n")] = '\0'; // Remover a nova linha

            int indice = strlen(string) - 1; // Último caractere da string

            char ultimo_digito[2]; 
            ultimo_digito[0] = string[indice]; // Pegar o último caractere
            ultimo_digito[1] = '\0'; // Garantir que é uma string válida

            int numero = atoi(ultimo_digito); // Converter para inteiro

            if(numero == 1){
                f1--;
            }else if(numero == 2){
                f2--;
            }else if(numero == 3){
                f3--;
            }else if(numero == 4){
                f4--;
            }else if(numero == 5){
                f5--;
            }else if(numero == 6){
                f6--;
            }
        }

        // Verificação final
        if(f1 <= 0 && f2 <= 0 && f3 <= 0 && f4 <= 0 && f5 <= 0 && f6 <= 0){
            printf("Bingoo\n");
        }else{
            salvarnumeros[0] = f1;
            salvarnumeros[1] = f2;
            salvarnumeros[2] = f3;
            salvarnumeros[3] = f4;
            salvarnumeros[4] = f5;
            salvarnumeros[5] = f6;

            if(f1 < 0) f1 = 0;
            if(f2 < 0) f2 = 0;
            if(f3 < 0) f3 = 0;
            if(f4 < 0) f4 = 0;
            if(f5 < 0) f5 = 0;
            if(f6 < 0) f6 = 0;

            printf("Ih, parece que temos um problema\n");
            printf("f1: %d\n", f1);
            printf("f2: %d\n", f2);
            printf("f3: %d\n", f3);
            printf("f4: %d\n", f4);
            printf("f5: %d\n", f5);
            printf("f6: %d\n", f6);
        }
    }
    return 0;
}
