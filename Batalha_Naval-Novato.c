#include <stdio.h>
// definindo constantes

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5


// Desafio novato - tabuleiro com 2 navios ok
// Desafio Aventureiro - Tabuleiro com 4 navios ok 
// Desafio Mestre - Matrizes de habilidade (Cone, Cruz, octaedro) ok
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

// Criando uma matriz com o formato de CONE

void Hab_CONE(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE])
{
    for (int i = 0; i < TAMANHO_HABILIDADE; i++){
        for (int j = 0; j < TAMANHO_HABILIDADE; j++){
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i && i < TAMANHO_HABILIDADE / 2 + 1){
                habilidade[i][j] = 1; // começa no centro e enradia
            } else {
                habilidade[i][j] = 0;
            }
            
        }
        
    }
    
}

// Criando a matriz CRUZ

void Hab_CRUZ(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Afetado pela habilidade
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Criando a matriz em Octa

void Hab_OCTA(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Coloca desde o centro de i e j
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// integrando a matriz habilidade ao tabuleiro

void AplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int l = origem_linha + i - (TAMANHO_HABILIDADE / 2);
            int c = origem_coluna + j - (TAMANHO_HABILIDADE / 2);

            if (l >= 0 && l < TAMANHO_TABULEIRO && c >= 0 && c < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[l][c] != NAVIO) {
                    tabuleiro[l][c] = HABILIDADE; // Marca como área de efeito
                }
            }
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

// Onde as coisas começam

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octa[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa o tabuleiro

    Tabuleiro_inicial(tabuleiro);
    printf("TABULEIRO INICIAL\n");

    MostrarTabuleiro(tabuleiro);

    //criando habilidades

    Hab_CONE(cone);
    Hab_CRUZ(cruz);
    Hab_OCTA(octa);

    // Definindo as coordenadas das habilidades em campo

    AplicarHabilidade(tabuleiro, cone, 4, 4);
    AplicarHabilidade(tabuleiro, cruz, 7, 2);
    AplicarHabilidade(tabuleiro, octa, 2, 7);
    
    // Definindo as coordenadas dos 4 navios em campo
    
    //Posicionar os quatro navios (horizontal, vertical, diagonal crescente, diagonal decrescente)

    PosicionarNavio(tabuleiro, 3, 5, 0); // Horizontal "começa 3,5"
    PosicionarNavio(tabuleiro, 5, 2, 1); // Vertical "começa em 5,2"
    PosicionarNavio(tabuleiro, 1, 1, 2); // Diagonal crescente "começa em 1,1"
    PosicionarNavio(tabuleiro, 5, 7, 3); // Diagonal decrescente "começa em 5,7"

    // Exibir o tabuleiro atualizado
    printf("\nTABULEIRO ATUALIZADO: \n");
       

    // Exibir o tabuleiro com os navios posicionados
    MostrarTabuleiro(tabuleiro);
    
    return 0;
}