#include <stdio.h>

int main (void)
{
    int row, line;
    scanf ("%d %d", &line, &row);
    int photo[line][row];
    int max_row[row];
    int max_line[line];
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < row; j++) scanf ("%d", &photo[i][j]);
    }
    for (int i = 0; i < line; i++)
    {
        max_line[i] = photo[i][0];
        for (int j = 0; j < row; j++)
        {
            if (photo[i][j] > max_line[i]) max_line[i] = photo[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        max_row[i] = photo[0][i];
        for (int j = 0; j < line; j++)
        {
            if (photo[j][i] > max_row[i]) max_row[i] = photo[j][i];
        }
    }
    int max = max_row[0];
    for (int j = 0; j < row; j++)
    {
        if (max_row[j] > max) max = max_row[j];
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < row; j++)
        {
            if (max_row[j] >= i) printf("*");
            else printf (" ");
        }
        printf ("\n");
    }
    printf ("\n");
    max = max_line[0];
    for (int j = 0; j < line; j++)
    {
        if (max_line[j] > max) max = max_line[j];
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < line; j++)
        {
            if (max_line[j] >= i) printf("*");
            else printf (" ");
        }
        printf ("\n");
    }
}