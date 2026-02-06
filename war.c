#include <stdio.h>
#include <string.h> 

//aqui eu crio o modelo do territorio do jogo war
//usei struct para agrupar as informacoes em um lugar so

typedef struct {
    char nomelocal[30];
    char corTime[10];
    int qtdTropas;
} Territorio;

int main () {
    //criando uma lista para guardar os cinco territorios
    Territorio meusTerritorios[5];
    int i; //variavel para o contador do laco

    printf ("=== SISTEMA DE CADASTRO DO JOGO WAR ===\n\n");
//laco para repetir a pergunta cinco vezes 

for (i=0; i<5; i++){
    printf ("--- Cadastro do %d o lugar---\n", i + 1);

    printf ("Nome do territorio: ");
    //esse espaco no scanf serve para nao pular a leitura do nome
    scanf(" %[^\n]s", meusTerritorios[i].nomelocal);

    printf ("Cor do exercito: ");
    scanf ("%s" , meusTerritorios[i].corTime);

    printf ("Total tropas:");
    scanf ("%d" ,&meusTerritorios[i].qtdTropas);

printf ("Territorio salvo com sucesso!\n\n");
}
//Agora vou mostrar na tela tudo o que foi cadastrado
printf("\n>>> LISTA DE TERRITORIOS NO MAPA <<<\n");
printf("----------------------------------------------\n");
printf("NOME               |COR          |TROPAS         \n");
printf("-------------------------------------------------\n");

for (i=0;  i<5; i++) {
// 0 %-20sserve para alinhar o texo a esquerda e ficar organizado
    printf("%-20s |%-10s |%-6d\n",
    meusTerritorios[i].nomelocal,
meusTerritorios[i].corTime,
meusTerritorios[i].qtdTropas);
}
printf("----------------------------------------------------\n");
printf("Fim do programa.\n");

return 0;
}


    
    
        
    
    




