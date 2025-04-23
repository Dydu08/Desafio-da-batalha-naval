#include <stdio.h>

int main(){

    //Letras de coordenadas do tabuleiro
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    
    //Declaração do tabuleiro (0 = água)
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
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    
    //Declaração dos navios (333 = navio)
    int navio_hori[3] = {3, 3, 3};
    int navio_vert[3] = {3, 3, 3};

    
    
    //Processo de alocação do navio horizontal no tabuleiro
    
    if(6 + 3 <= 10) 
    { 
        int h_liberado = 1;
    
        for(int h = 0; h < 3; h++)//Para verificar se o barco não estara sobrepondo outro
        {
            if(tabuleiro[1][6 + h] != 0)
            {
                h_liberado = 0;
                break;
            }
        }
    
        if(h_liberado == 1)//Alocação do barco na horizontal
        {
            for(int h = 0; h < 3; h++)
            {
            tabuleiro[1][6 + h] = navio_hori[h];
            }
        } else{
            printf("Ocorreu uma sobreposição nos navios\n");
        }
    } else{
        printf("Navio horizontal fora dos limites\n");
    }
    
    
    
    //Processo de alocação do navio vertical no tabuleiro
    
    if(6 + 3 <= 10)//Para verificar se o barco vai estar nos limites do tabuleiro
    { 
        int v_liberado = 1;

        for(int v = 0; v < 3; v++)//Para verificar se o barco não estará sobrepondo outro
        { 
            if(tabuleiro[6 + v][1] != 0) 
            {
                v_liberado = 0;
                break;
            }       
        }

        if(v_liberado == 1)//Alocação do barco na vertical 
        { 
            for(int v = 0; v < 3; v++)
            {
                tabuleiro[6 + v][1] = navio_vert[v];
            }
        } else{
            printf("Ocorreu uma sobreposição nos navios\n");
        }
    } else{
        printf("Navio vertical fora dos limites\n");
    }
    
    
    //Exibição do titulo
    printf ("__JOGO DA BATALHA NAVAL__\n");
    
    
    //Exibição das letras de coordenadas
    printf ("   ");
    
    for (int l = 0; l < 10; l++)
    {
        printf ("%c ", letras[l]);
    }
    printf ("\n");
    
    
    //Exibição do tabuleiro
    for (int i = 0; i < 10; i++)
    {
        
        printf("%2d ", i + 1);
        
        for (int j = 0; j < 10; j++)
        {
            printf ("%d ", tabuleiro[i][j]); 
        }
        
        printf("\n");
        
    }
    
    
    
    
    
    return 0;


}