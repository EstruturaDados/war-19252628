#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Aqui eu digo como é um território
typedef struct {
    char nomeLocal[30];
    char corTime[10];
    int qtdTropas;
} Territorio;

int main() {
    int n, i;
    Territorio *meusTerritorios;

    printf("Quantos territorios voce quer cadastrar? ");
    scanf("%d", &n);

    // CALLOC: Pede um espaço na memória para guardar os territórios
    meusTerritorios = (Territorio *)calloc(n, sizeof(Territorio));

    // Laço para perguntar o nome de cada um
    for (i = 0; i < n; i++) {
        printf("\nNome do %d o lugar: ", i + 1);
        scanf(" %[^\n]s", meusTerritorios[i].nomeLocal);
        printf("Cor do exercito: ");
        scanf("%s", meusTerritorios[i].corTime);
        printf("Quantidade de tropas: ");
        scanf("%d", &meusTerritorios[i].qtdTropas);
    }

    printf("\nPronto! Tudo guardado na memoria.\n");

    // FREE: Devolve o espaço que usamos
    free(meusTerritorios);
    
    return 0;
}
