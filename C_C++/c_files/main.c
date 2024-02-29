#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "map.h"
#include "main.h"

int main()
{
    char **map = (char **)malloc(3 * sizeof(char *));
    bool is_player_1 = true;
    int pos_x = 0, pos_y = 0, winner = 0, nbr_total_games = 0, player_1_score = 0, player_2_score = 0;
    float percentage_player_1 = 0, percentage_player_2 = 0;
    const char *start = "\nPlease select", *end = " an other place!\n";
    char concat[32];
    char restart;

    for (int i = 0; i < 3; i++)
        map[i] = (char *)malloc(3 * sizeof(char));

    strcat(concat, start);
    strcat(concat, end);

    initialize_map(map);

    while (1)
    {
        if (is_player_1)
            print_colored_text("PLAYER 1 TURN\n\n", 1);
        else
            print_colored_text("PLAYER 2 TURN\n\n", 2);
        print_map(map);
        get_player_input(&pos_x, &pos_y);

        update_map_and_turn(map, &is_player_1, pos_x, pos_y, concat);

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
                initialize_map(map);
                if (nbr_total_games % 2 == 0)
                    is_player_1 = true;
                else
                    is_player_1 = false;
            }
        }
        printf("\n---------------------\n\n");
    }
    return 0;
}

void get_player_input(int *pos_x, int *pos_y) {
    printf("Enter the row (between 1 and 3): ");
    scanf("%d", pos_x);
    printf("Enter the column (between 1 and 3): ");
    scanf("%d", pos_y);
}

void display_winner(int winner)
{
    printf("\n---------------------");
    printf("\n|                   |\n");
    printf("| ");
    if (winner == 1)
        print_colored_text("PLAYER 1 WON !!!!", 1);
    else
        print_colored_text("PLAYER 2 WON !!!!", 2);
    printf(" |");
    printf("\n|                   |\n");
    printf("---------------------\n");
}

float percentage(int score, int total)
{
    return (float)score / total * 100;
}
