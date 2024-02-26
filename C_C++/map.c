#include <stdbool.h>
#include <stdio.h>

void print_map(char **map)
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
    int i = 0;
    do
    {
        if (map[i][0] == 'X' && map[i][1] == 'X' && map[i][2] == 'X')
            return 1;
        if (map[i][0] == 'O' && map[i][1] == 'O' && map[i][2] == 'O')
            return 2;
        i++;
    } while (i < 3);

    i = 0;
    do
    {
        if (map[0][i] == 'X' && map[1][i] == 'X' && map[2][i] == 'X')
            return 1;
        if (map[0][i] == 'O' && map[1][i] == 'O' && map[2][i] == 'O')
            return 2;
        i++;
    } while (i < 3);
    if (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X')
        return 1;
    if (map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O')
        return 2;
    if (map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X')
        return 1;
    if (map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O')
        return 2;

    return 0;
}