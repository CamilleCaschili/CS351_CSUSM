#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "map.h"
#include "main.h"

int main()
{
    char **map = (char **)malloc(3 * sizeof(char *));
    bool is_player_1 = true;
    int pos_x = 0, pos_y = 0, winner = 0, nbr_total_games = 0, player_1_score = 0, player_2_score = 0;
    float percentage_player_1 = 0, percentage_player_2 = 0;
    const char *start = "\nPlease select";
    const char *end = " an other place!\n";
    char concat[32];
    char restart;

    snprintf(concat, sizeof(concat), "%s%s", start, end);

    for (int i = 0; i < 3; i++)
        map[i] = (char *)malloc(3 * sizeof(char));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            map[i][j] = ' ';

    while (1)
    {
        if (is_player_1)
            printf("PLAYER 1 TURN\n\n");
        else
            printf("PLAYER 2 TURN\n\n");
        print_map(map);
        printf("Enter the column (between 1 and 3): ");
        scanf("%d", &pos_x);
        printf("Enter the row (between 1 and 3): ");
        scanf("%d", &pos_y);

        if (is_player_1 && map[pos_x - 1][pos_y - 1] == ' ')
        {
            map[pos_x - 1][pos_y - 1] = 'X';
            is_player_1 = !is_player_1;
        }
        else if (map[pos_x - 1][pos_y - 1] == ' ')
        {
            map[pos_x - 1][pos_y - 1] = 'O';
            is_player_1 = !is_player_1;
        }
        else
            printf("%s", concat);

        winner = check_map(map);

        if (winner == 1 || winner == 2)
        {
            display_winner(winner);
            nbr_total_games++;
            if (winner == 1)
                player_1_score++;
            else
                player_2_score++;
            percentage_player_1 = percentage(player_1_score, nbr_total_games);
            percentage_player_2 = percentage(player_2_score, nbr_total_games);
            printf("\nPlayer 1 score: %d, percentage of win: %.1f%%\nPlayer 2 score: %d, percentage of win: %.1f%%\n",
                   player_1_score, percentage_player_1, player_2_score, percentage_player_2);
            printf("\n\nWould you like to restart ? Yes : y | No : n\n");
            scanf(" %c", &restart);
            if (restart == 'n')
                break;
            else
            {
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        map[i][j] = ' ';
                is_player_1 = true;
            }
        }
        printf("\n---------------------\n\n");
    }
    return 0;
}

void display_winner(int winner)
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
}

float percentage(int score, int total)
{
    return (float)score / total * 100;
}
