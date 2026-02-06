#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h> // Para os dados funcionarem

typedef struct {
    char nomeLocal[30];
    char corTime[10];
    int qtdTropas;
} Territorio;

// FUNÇÃO DE ATAQUE: Onde a mágica da batalha acontece
void simularAtaque(Territorio *atacante, Territorio *defensor) {
    int dadoAtaque = (rand() % 6) + 1; // Sorteia 1 a 6
    int dadoDefesa = (rand() % 6) + 1;

printf("\nBatalha: %s vs %s\n", atacante->nomeLocal, defensor->nomeLocal);
    printf("Dados: Atacante %d | Defensor %d\n", dadoAtaque, dadoDefesa);

    // Se o atacante ganhar ou empatar
    if (dadoAtaque >= dadoDefesa) {
        printf("O atacante ganhou! O defensor perdeu 1 tropa.\n");
        defensor->qtdTropas--;

        // Se o defensor ficar sem nada, o atacante ganha o lugar
        if (defensor->qtdTropas <= 0) {
            printf("VITÓRIA! %s conquistou o territorio!\n", atacante->nomeLocal);
            strcpy(defensor->corTime, atacante->corTime);
            defensor->qtdTropas = 1;
        }
    } else {
        printf("A defesa ganhou! O atacante perdeu 1 tropa.\n");
        if (atacante->qtdTropas > 1) atacante->qtdTropas--;
    }
}

int main() {
    int n, i;
    Territorio *meusTerritorios;
    srand(time(NULL)); // Liga o sorteio de dados

    printf("Quantos territorios voce quer cadastrar? ");
    scanf("%d", &n);

    meusTerritorios = (Territorio *)calloc(n, sizeof(Territorio));

    for (i = 0; i < n; i++) {
        printf("\nNome do %d o lugar: ", i + 1);
        scanf(" %[^\n]s", meusTerritorios[i].nomeLocal);
        printf("Cor do exercito: ");
        scanf("%s", meusTerritorios[i].corTime);
        printf("Quantidade de tropas: ");
        scanf("%d", &meusTerritorios[i].qtdTropas);
    }

    // Agora vamos brincar de atacar!
    int at, df;
    printf("\nEscolha o numero do Atacante (1 a %d): ", n);
    scanf("%d", &at);
    printf("Escolha o numero do Defensor (1 a %d): ", n);
    scanf("%d", &df);

    // Faz a batalha acontecer usando os endereços (&)
    simularAtaque(&meusTerritorios[at-1], &meusTerritorios[df-1]);

    // Devolve a memória no final
    free(meusTerritorios);
    printf("\nTrabalho finalizado e memoria limpa!\n");
    
    return 0;
}

