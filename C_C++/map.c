#include <stdbool.h>
#include <stdio.h>

void print_map(char **map, bool is_player_1)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (map[i][j] == '.')
                printf("%c", map[i][j]);
            else
            {
                if (map[i][j] == 'X')
                {
                    printf("\033[1;31m");
                    printf("%c", map[i][j]);
                    printf("\033[0m");
                }
                else if (map[i][j] == 'O')
                {
                    printf("\033[1;34m");
                    printf("%c", map[i][j]);
                    printf("\033[0m");
                }
            }
        printf("\n");
    }
    printf("\n");
}

int check_map(char **map)
{
    int player_1 = 0;
    int player_2 = 0;

    // temporary
    if (map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X')
        return 1;
    if (map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X')
        return 1;
    if (map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X')
        return 1;
    if (map[0][0] == 'X' && map[1][0] == 'X' && map[2][0] == 'X')
        return 1;
    if (map[0][1] == 'X' && map[1][1] == 'X' && map[2][1] == 'X')
        return 1;
    if (map[0][2] == 'X' && map[1][2] == 'X' && map[2][2] == 'X')
        return 1;
    if (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X')
        return 1;
    if (map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X')
        return 1;

    if (map[0][0] == 'O' && map[0][1] == 'O' && map[0][2] == 'O')
        return 2;
    if (map[1][0] == 'O' && map[1][1] == 'O' && map[1][2] == 'O')
        return 2;
    if (map[2][0] == 'O' && map[2][1] == 'O' && map[2][2] == 'O')
        return 2;
    if (map[0][0] == 'O' && map[1][0] == '0' && map[2][0] == '0')
        return 2;
    if (map[0][1] == 'O' && map[1][1] == 'O' && map[2][1] == '0')
        return 2;
    if (map[0][2] == 'O' && map[1][2] == 'O' && map[2][2] == '0')
        return 2;
    if (map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == '0')
        return 2;
    if (map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == '0')
        return 2;
    return 0;
}