#include <stdio.h>

int main()
{
    // Variaveis para o tabuleiro coluna e linha
    char coluna[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char linha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // variavel para o tabuleiro, onde 0 representa água.
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Definir os navios no tabuleiro como vetores unidimensionais, onde cada elemento representa o tamanho do navio.
    int navioHorizontal[3] = {3, 3, 3};  // Navio horizontal de tamanho 3
    int navioVertical[3] = {3, 3, 3};    // Navio vertical de tamanho 3
    int navioDiagonal[3] = {3, 3, 3};    // Navio diagonal de tamanho 3
    int navioDiagonalInv[3] = {3, 3, 3}; // Navio diagonal inverso de tamanho 3

    int linhaNavioHorizontal = 5, colunaNavioHorizontal = 2;   // Posição inicial do navio horizontal
    int linhaNavioVertical = 5, colunaNavioVertical = 8;       // Posição inicial do navio vertical
    int linhaNavioDiagonal = 2, colunaNavioDiagonal = 2;       // Posição inicial do navio Diagonal
    int linhaNavioDiagonalInv = 6, colunaNavioDiagonalInv = 3; // Posição inicial do navio Diagonal Invertido

    // Verificar se o navio HORIZONTAL pode ser posicionado sem ultrapassar os limites do tabuleiro
    if (colunaNavioHorizontal + 3 <= 10)
    {
        for (int validadorH = 0; validadorH < 3; validadorH++)
        {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + validadorH] != 0)
            {
                printf("Não é possivel posicionar o navio horizontal na pocição %d %d, escolha outra posição.\n", linhaNavioHorizontal, colunaNavioHorizontal);
                return 0; // Encerra o programa se houver sobreposição
            }
        }
        for (int h = 0; h < 3; h++)
        {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + h] = navioHorizontal[h];
        }
    }
    else
    {
        printf("Não é possivel posicionar o navio horizontal na pocição %d %d, escolha outra posição.\n", linhaNavioHorizontal, colunaNavioHorizontal);
    }

    // Verificar se o navio VERTICAL pode ser posicionado sem ultrapassar os limites do tabuleiro
    if (linhaNavioVertical + 3 <= 10)
    {
        // Verificar se o navio VERTICAL pode ser posicionado sem sobrepor outro navio
        for (int validadorV = 0; validadorV < 3; validadorV++)
        {
            if (tabuleiro[linhaNavioVertical + validadorV][colunaNavioVertical] != 0)
            {
                printf("Não é possivel posicionar o navio vertical na pocição %d %d, escolha outra posição.\n", linhaNavioVertical, colunaNavioVertical);
                return 0; // Encerra o programa se houver sobreposição
            }
        }
        for (int v = 0; v < 3; v++)
        {
            tabuleiro[linhaNavioVertical + v][colunaNavioVertical] = navioVertical[v];
        }
    }
    else
    {
        printf("Não é possivel posicionar o navio vertical na pocição %d %d, escolha outra posição.\n", linhaNavioVertical, colunaNavioVertical);
    }

    // Verificar se o navio DIAGONAL pode ser posicionado sem ultrapassar os limites do tabuleiro
    if ((linhaNavioDiagonal + 3 < 10) && (colunaNavioDiagonal + 3 < 10))
    {   
        // Verificar se o navio DIAGONAL pode ser posicionado sem sobrepor outro navio
        for (int validadorD = 0; validadorD < 3; validadorD++)
        {
            if (tabuleiro[linhaNavioDiagonal + validadorD][colunaNavioDiagonal + validadorD] != 0)
            {
                printf("Não é possivel posicionar o navio Diagonal na pocição %d %d, escolha outra posição.\n", linhaNavioDiagonal, colunaNavioDiagonal);
                return 0; // Encerra o programa se houver sobreposição
            }
        }

        for (int d = 0; d < 3; d++)
        {
            tabuleiro[linhaNavioDiagonal + d][colunaNavioDiagonal + d] = navioDiagonal[d];
        }
    }
    else
    {
        printf("Não é possivel posicionar o navio Diagonal na pocição %d %d, escolha outra posição.\n", linhaNavioDiagonal, colunaNavioDiagonal);
    }

    // Verificar se o navio DIAGONAL INVERTIDO pode ser posicionado sem ultrapassar os limites do tabuleiro
    if ((linhaNavioDiagonalInv + 3 < 10) && (colunaNavioDiagonalInv - 3 >= 0))
    {   
        // Verificar se o navio DIAGONAL INVERTIDO pode ser posicionado sem sobrepor outro navio
        for (int validadorDI = 0; validadorDI < 3; validadorDI++)
        {
            if (tabuleiro[linhaNavioDiagonalInv + validadorDI][colunaNavioDiagonalInv - validadorDI] != 0)
            {
                printf("Não é possivel posicionar o navio Diagonal Invertido na pocição %d %d, escolha outra posição.\n", linhaNavioDiagonalInv, colunaNavioDiagonalInv);
                return 0; // Encerra o programa se houver sobreposição
            }
        }

        for(int dI = 0; dI < 3; dI++){
            tabuleiro[linhaNavioDiagonalInv + dI][colunaNavioDiagonalInv - dI] = navioDiagonalInv[dI];
        }
    }
    else
    {
        printf("Não é possivel posicionar o navio Diagonal Invertido na pocição %d %d, escolha outra posição.\n", linhaNavioDiagonalInv, colunaNavioDiagonalInv);
    }

    // Imprime o tabuleiro
    for (int l = 0; l < 10; l++)
    {
        // Imprime a linha de cabeçalho apenas na primeira iteração
        if (l == 0)
        {
            for (int i = 0; i < 11; i++)
            {
                printf(" %c ", coluna[i]);
            }
            printf("\n");
        }

        // Imprime o número da linha e os valores do tabuleiro
        printf(" %c ", linha[l]);
        for (int c = 0; c < 10; c++)
        {
            printf(" %d ", tabuleiro[l][c]);
        }

        // Imprime uma nova linha após cada linha do tabuleiro
        printf("\n");
    }
    return 0;
}
