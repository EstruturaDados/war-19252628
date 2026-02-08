#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do territorio
typedef struct {
    char nomeLocal[30];
    char corTime[10];
    int qtdTropas;
} Territorio;

// FUNÇÃO: Sorteia uma missão da lista e copia para o jogador
void atribuirMissao(char* destino, char* listaMissoes[], int total) {
    int indice = rand() % total;
    strcpy(destino, listaMissoes[indice]);
}

// FUNÇÃO: Verifica se o jogador venceu (Lógica: ter mais de 2 territórios)
int verificarVitoria(Territorio* mapa, int total) {
    int contagem = 0;
    // Para simplificar, vamos contar quantos territorios o primeiro time cadastrado tem
    char* corObjetivo = mapa[0].corTime;
    
    for (int i = 0; i < total; i++) {
        if (strcmp(mapa[i].corTime, corObjetivo) == 0) {
            contagem++;
        }
    }
    // Se o jogador dominar 3 ou mais lugares, ele ganha
    return (contagem >= 3);
}

// FUNÇÃO: Realiza o ataque entre vizinhos
void atacar(Territorio* at, Territorio* df) {
    int dadoAt = (rand() % 6) + 1;
    int dadoDf = (rand() % 6) + 1;

    printf("\n>>> DADOS: Atacante %d | Defensor %d\n", dadoAt, dadoDf);

    if (dadoAt > dadoDf) {
        printf("O atacante venceu! %s perdeu 1 tropa.\n", df->nomeLocal);
        df->qtdTropas--;
        if (df->qtdTropas <= 0) {
            printf("TERRITORIO CONQUISTADO por %s!\n", at->corTime);
            strcpy(df->corTime, at->corTime);
            df->qtdTropas = 1;
        }
    } else {
        printf("A defesa resistiu! O atacante perdeu 1 tropa.\n");
        if (at->qtdTropas > 1) at->qtdTropas--;
    }
}

int main() {
    srand(time(NULL));
    int n, i;

    // 1. Criando as missões
    char* listaDeMissoes[] = {
        "Dominar 3 territorios no mapa",
        "Eliminar a cor vermelha do jogo",
        "Conquistar um continente inteiro",
        "Manter 10 tropas em um unico lugar",
        "Ocupar 2 territorios vizinhos"
    };

    printf("--- WAR: DESAFIO FINAL ---\n");
    printf("Quantos territorios teremos no jogo? ");
    scanf("%d", &n);

    // 2. Alocação Dinâmica dos territórios e da Missão
    Territorio* mapa = (Territorio*)calloc(n, sizeof(Territorio));
    char* missaoJogador = (char*)malloc(100 * sizeof(char));

    // 3. Cadastro e Atribuição de Missão
    atribuirMissao(missaoJogador, listaDeMissoes, 5);
    printf("\nSUA MISSAO SECRETA: %s\n", missaoJogador);

    for (i = 0; i < n; i++) {
        printf("\nTerritorio %d - Nome: ", i + 1);
        scanf(" %[^\n]s", mapa[i].nomeLocal);
        printf("Cor do exercito: ");
        scanf("%s", mapa[i].corTime);
        printf("Tropas: ");
        scanf("%d", &mapa[i].qtdTropas);
    }

    // 4. Rodada de Ataque e Verificação
    int continua = 1;
    while (continua) {
        int a, d;
        printf("\nQuem ataca (1 a %d) e quem defende? (0 0 para sair): ", n);
        scanf("%d %d", &a, &d);

        if (a == 0) break;

        atacar(&mapa[a-1], &mapa[d-1]);

        // Checando se a missão foi cumprida
        if (verificarVitoria(mapa, n)) {
            printf("\n************************************\n");
            printf("PARABENS! Voce cumpriu sua missao:\n[%s]\n", missaoJogador);
            printf("VOCE EH O VENCEDOR DO WAR!\n");
            printf("************************************\n");
            break;
        }
    }

    // 5. Limpeza da Memória (Obrigatório)
    free(mapa);
    free(missaoJogador);
    printf("\nMemoria limpa. Fim do desafio final!\n");

    return 0;
}

