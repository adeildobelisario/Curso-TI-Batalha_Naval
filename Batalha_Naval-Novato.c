#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3


// Desafio novato - tabuleiro com 2 navios ok
// Desafio Aventureiro - Tabuleiro com 4 navios ok 
// Adeildo Espíndola Belisário
//tabuleiro iniciando

void Tabuleiro_inicial(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = AGUA;// está definindo tudo como água (zerado)
        }
        
    }
    
}

// primeiro, validando posição para não se sobrepor nem ultrapassar limite (condições para colocar o navio)

int PodePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao){
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i; // se for pra horizontal, só aumenta a coluna!
        else if (direcao == 1) l += i; // se for vertical, só aumenta a linha!
        else if (direcao == 2) { l += i; c += i; } //se for na diagonal(direita+cima)
        else if (direcao == 3) { l += i; c -= i; } //se for na diagonal(baixo+esquerda)

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || c < 0) return 0;//se passou para fora do tabuleiro
        if (tabuleiro[l][c] == NAVIO) return 0; // verifica a sobreposição
        }
        return 1;
    }
    
// função para posicionar os navios

void PosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    if (!PodePosicionar(tabuleiro, linha, coluna, direcao)) { //se não for nada correto...
        printf("Erro ao posicionar navio na linha %d, coluna %d!\n", linha, coluna); 
        return;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 0) tabuleiro[linha][coluna + i] = NAVIO; // Horizontal (direita)
        else if (direcao == 1) tabuleiro[linha + i][coluna] = NAVIO; // Vertical (baixo)
        else if (direcao == 2) tabuleiro[linha + i][coluna + i] = NAVIO; // Diagonal (direita+baixo)
        else if (direcao == 3) tabuleiro[linha + i][coluna - i] = NAVIO; // Diagonal (baixo+esquerda)"visualmente direita+cima"
    }
}


// Para exibir o tabuleiro
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
    printf("TABULEIRO INICIAL\n");

    MostrarTabuleiro(tabuleiro);
    // Defini as coordenadas dos 4 navios 
    
    // Posicionar os quatro navios (horizontal, vertical, diagonal crescente, diagonal decrescente)
    PosicionarNavio(tabuleiro, 3, 5, 0); // Horizontal "começa 3,5"
    PosicionarNavio(tabuleiro, 5, 2, 1); // Vertical "começa em 5,2"
    PosicionarNavio(tabuleiro, 1, 1, 2); // Diagonal crescente "começa em 1,1"
    PosicionarNavio(tabuleiro, 5, 7, 3); // Diagonal decrescente "começa em 5,7"

    // Exibir o tabuleiro atualizado
    printf("\nTABULEIRO ATUALIZADO COM NAVIOS:\n");
       

    // Exibir o tabuleiro com os navios posicionados
    MostrarTabuleiro(tabuleiro);
  
    return 0;
}