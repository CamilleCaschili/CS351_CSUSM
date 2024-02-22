#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "map.h"

int main()
{
    char **map = (char **)malloc(3 * sizeof(char *));
    int pos_x, pos_y;
    bool is_player_1 = true;
    int winner = 0;

    for (int i = 0; i < 3; i++)
        map[i] = (char *)malloc(3 * sizeof(char));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            map[i][j] = '.';

    while (1)
    {
        if (is_player_1)
            printf("PLAYER 1 TURN\n\n");
        else
            printf("PLAYER 2 TURN\n\n");
        print_map(map, is_player_1);
        printf("Enter the column (between 1 and 3): ");
        scanf("%d", &pos_x);
        printf("Enter the row (between 1 and 3): ");
        scanf("%d", &pos_y);

        if (is_player_1 && map[pos_x - 1][pos_y - 1] == '.')
        {
            map[pos_x - 1][pos_y - 1] = 'X';
            is_player_1 = !is_player_1;
        }
        else if (map[pos_x - 1][pos_y - 1] == '.')
        {
            map[pos_x - 1][pos_y - 1] = 'O';
            is_player_1 = !is_player_1;
        }
        else
            printf("\nPlease select an other place!\n");

        winner = check_map(map);

        if (winner == 1 || winner == 2)
        {
            printf("\n|-------------------|");
            printf("\n|                   |\n");
            printf("| ");
            if (winner == 1)
                printf("PLAYER 1 WON !!!!");
            else
                printf("PLAYER 2 WON !!!!");
            
            printf(" |");
            printf("\n|                   |\n");
            printf("|-------------------|\n");
            break;
        }

        printf("\n---------------------\n\n");
    }

    return 0;
}
