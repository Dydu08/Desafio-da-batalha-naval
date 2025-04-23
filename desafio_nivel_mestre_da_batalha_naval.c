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
    int navio_diag_p[3] = {3, 3, 3};
    int navio_diag_s[3] = {3, 3, 3};
    
    
    //Declaração das habilidade(1 = área afetada)
    
    //Na exibição do tabuleiro a área afetada do cone = 7
    int cone [3][5] ={{0,0,1,0,0},
                      {0,1,1,1,0},
                      {1,1,1,1,1}};
    
    //Na exibição do tabuleiro a área afetada da cruz = 5
    int cruz [3][5] ={{0,0,1,0,0},
                      {1,1,1,1,1},
                      {0,0,1,0,0}};

    //Na exibição do tabuleiro a área afetada do octaedro = 4 
    int octaedro [3][3] ={{0,1,0},
                          {1,1,1},
                          {0,1,0}};
    

    //Processo de alocação do navio horizontal no tabuleiro
    
    if(6 + 3 <= 10) 
    { 
        int h_liberado = 1;
    
        for(int h = 0; h < 3; h++)//Para verificar se o barco não estara sobrepondo outro
        {
            if(tabuleiro[9][1 + h] != 0)
            {
                h_liberado = 0;
                break;
            }
        }
    
        if(h_liberado == 1)//Alocação do barco na horizontal
        {
            for(int h = 0; h < 3; h++)
            {
            tabuleiro[9][1 + h] = navio_hori[h];
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
            if(tabuleiro[5 + v][0] != 0) 
            {
                v_liberado = 0;
                break;
            }       
        }

        if(v_liberado == 1)//Alocação do barco na vertical 
        { 
            for(int v = 0; v < 3; v++)
            {
                tabuleiro[5 + v][0] = navio_vert[v];
            }
        } else{
            printf("Ocorreu uma sobreposição nos navios\n");
        }
    } else{
        printf("Navio vertical fora dos limites\n");
    }
    

    
    //Processo de alocação do navio na diagonal principal
    
    if(0 + 3 <= 10)//Para verificar se o barco vai estar nos limites do tabuleiro 
    {
        int dp_liberado = 1;
        
        for(int i = 0; i < 3; i++)//Para verificar se o barco não estara sobrepondo outro
        {
            if(tabuleiro[i][i] != 0)
            {
                dp_liberado = 0;
                break;
            }
        }

        if(dp_liberado == 1)//Alocação do barco na diagonal principal
        {
            for(int pri = 0; pri < 10; pri++)
            {
                if(pri < 3)
                {
                    tabuleiro[0 + pri][0 + pri] = navio_diag_p[pri];
                }
            }
        } else{
            printf("Ocorreu uma sobreposição nos navios\n");
        }       
    } else{
        printf("Navio da diagonal principal fora dos limites\n");
    }
    
    
    
    //Processo de alocação do navio na diagonal secundaria

    if(5 - 2 >= 0 && 4 + 3 <= 10) //Para verificar se o barco vai estar nos limites do tabuleiro  
    {
        int ds_liberado = 1;

        for(int i = 0; i < 3; i++) //Para verificar se o barco não estará sobrepondo outro 
        {
            if(tabuleiro[6 - i][3 + i] != 0) 
            {
                ds_liberado = 0;
                break;
            }
        }

        if(ds_liberado == 1) //Alocação do barco na diagonal secundaria
        {
            for(int sec = 0; sec < 3; sec++)
            {
                if((6 - sec) + (3 + sec) == 9)
                {
                    tabuleiro[6 - sec][3 + sec] = navio_diag_s[sec];
                }
            }
        }
        else
        {
            printf("Ocorreu uma sobreposição nos navios\n");
        }
    }
    else
    {
        printf("Diagonal secundária fora dos limites\n");
    }


    
    //Processo de alocação da habilidade em Cone

    int origem_cone_l = 7;
    int origem_cone_c = 6;
    int aplicacao_cone = 1; 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int tab_cone_l = origem_cone_l - 1 + i;
            int tab_cone_c = origem_cone_c - 2 + j;

            if (tab_cone_l >= 0 && tab_cone_l < 10 && tab_cone_c >= 0 && tab_cone_c < 10)//Para verificar se a habilidade não estara fora dos limites do tabuleiro
            {
                if (tabuleiro[tab_cone_l][tab_cone_c] == 0)//Para verificar se a habilidade não estara sobrepondo outro elemento
                {
                    if (cone[i][j] == 1)//Para definir o numero da area afetada pela habilidade
                    {
                        tabuleiro[tab_cone_l][tab_cone_c] = 7;//Alocação da área afetada pela habilidade 
                    } else{
                        tabuleiro[tab_cone_l][tab_cone_c] = cone[i][j]; 
                    }
                
                } else{
                    printf ("A habilidade esta sobrepondo outro elemento\n");
                    aplicacao_cone = 0;
                    break;
                }
                    
            } else {
                printf ("Habilidade fora dos limites do tabuleiro\n");
                aplicacao_cone = 0;
                break;
            }
            
        }
        
        if (aplicacao_cone == 0)
        {
            break;
        }
        
    }


    
    //Processo de alocação da habilidade em Cruz

    int origem_cruz_l = 1;
    int origem_cruz_c = 6;
    int aplicacao_cruz = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int tab_cruz_l = origem_cruz_l - 1 + i;
            int tab_cruz_c = origem_cruz_c - 2 + j;

            if (tab_cruz_l >= 0 && tab_cruz_l < 10 && tab_cruz_c >= 0 && tab_cruz_c < 10)//Para verificar se a habilidade não estara fora dos limites do tabuleiro
            {
                if (tabuleiro[tab_cruz_l][tab_cruz_c] == 0)//Para verificar se a habilidade não estara sobrepondo outro elemento
                {
                    if (cruz[i][j] == 1)//Para definir o numero da area afetada pela habilidade
                    {
                        tabuleiro[tab_cruz_l][tab_cruz_c] = 5;//Alocação da área afetada pela habilidade 
                    } else{
                        tabuleiro[tab_cruz_l][tab_cruz_c] = cruz[i][j]; 
                    }
                } else{
                    printf ("A habilidade esta sobrepondo outro elemento\n");
                    aplicacao_cruz = 0;
                    break;
                }

            } else {
                printf ("Habilidade fora dos limites do tabuleiro\n");
                aplicacao_cruz = 0;
                break;
            }

        }

        if (aplicacao_cruz == 0)
        {
            break;
        }

    }



    //Processo de alocação da habilidade em Octaedro

    int origem_octaedro_l = 4;
    int origem_octaedro_c = 2;
    int aplicacao_octaedro = 1; 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int tab_octa_l = origem_octaedro_l - 1 + i;
            int tab_octa_c = origem_octaedro_c - 1 + j;

            if (tab_octa_l >= 0 && tab_octa_l < 10 && tab_octa_c >= 0 && tab_octa_c < 10)//Para verificar se a habilidade não estara fora dos limites do tabuleiro
            {
                if (tabuleiro[tab_octa_l][tab_octa_c] == 0)//Para verificar se a habilidade não estara sobrepondo outro elemento
                {
                    if (octaedro[i][j] == 1)//Para definir o numero da area afetada pela habilidade
                    {
                        tabuleiro[tab_octa_l][tab_octa_c] = 4;//Alocação da área afetada pela habilidade 
                    } else{
                        tabuleiro[tab_octa_l][tab_octa_c] = octaedro[i][j]; 
                    }
                } else{
                    printf ("A habilidade esta sobrepondo outro elemento\n");
                    aplicacao_octaedro = 0;
                    break;
                }
                    
            } else {
                printf ("Habilidade fora dos limites do tabuleiro\n");
                aplicacao_octaedro = 0;
                break;
            }
            
        }
        
        if (aplicacao_octaedro == 0)
        {
            break;
        }
        
    }


    
    //Exibição do titulo
    printf("__JOGO DA BATALHA NAVAL__\n");
    
    
    //Exibição das letras de coordenadas
    printf("   ");
    
    for(int l = 0; l < 10; l++)
    {
        printf("%c ", letras[l]);
    }
    printf("\n");
    
    
    //Exibição do tabuleiro
    for(int i = 0; i < 10; i++)
    {
        
        printf("%2d ", i + 1);
        
        for(int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]); 
        }
        
        printf("\n");
        
    }
    
    
    
    
    
    return 0;


}