#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3


// Desafio novato - tabuleiro com 2 navios
// Adeildo Espíndola Belisário
//tabuleiro iniciando
void Tabuleiro_inicial(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = AGUA;// está definindo tudo como água
        }
        
    }
    

}

// navio posicionado horizontal

int NavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna){
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;// percebe o limite
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha][coluna + i] == NAVIO) return 0; //percebendo a sobreposição
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha][coluna + i] = NAVIO; // coloca o navio
    }
    return 1;
}

// navio posicionado vertival

int NavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // percebe o limite

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == NAVIO) return 0; //percebendo  sobreposição
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO; // Posiciona navio (3)
    }

    return 1; // Sucesso
}

// Vamos exibir o tabuleiro
void MostrarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTABULEIRO BATALHA NAVAL:\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    Tabuleiro_inicial(tabuleiro);

    // Defini as coordenadas dos 2 navios
    int linhaNavioH = 2, colunaNavioH = 3; // Navio horizontal na linha 2 coluna 3
    int linhaNavioV = 5, colunaNavioV = 2; // Navio vertical na coluna 2 linha 5

    // Posicionar navios com validação
    if (!NavioHorizontal(tabuleiro, linhaNavioH, colunaNavioH)) {
        printf("Erro ao posicionar o navio horizontal!\n");
    }

    if (!NavioVertical(tabuleiro, linhaNavioV, colunaNavioV)) {
        printf("Erro ao posicionar o navio vertical!\n");
    }

    // Exibir o tabuleiro com os navios posicionados
    MostrarTabuleiro(tabuleiro);

    return 0;
}