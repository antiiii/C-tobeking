#include <stdio.h>
#include <math.h>

void VARY (int, char (*)[], int); 
int FROM (int );
int FROMM (int row);
int main (void)
{
    int n;
    scanf ("%d", &n);
    int row = pow (2, n);
    char picture[row][2 * row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2 * row; j++)
        {
            picture[i][j] = 0;
        }
    }

    picture[0][row - 1] = picture[1][row - 2] = '/';
    picture[0][row] = picture[1][row + 1] = '\\';
    picture[1][row - 1] = picture[1][row] = '_';
    
    for (int i = 2; i < row; i++)
    {
        VARY (row, picture, i);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2 * row; j++)
        {
            if (picture[i][j] == '\000') printf (" ");
            else printf("%c", picture[i][j]);
        }
        printf ("\n");
    }
} 

void VARY (int toal, char picture[][16], int row)
{
    int tgt = FROM( row + 1)-1;
    int tgtt = FROMM( row );
    for (int i = 0; i < 2 * toal; i++)
    {
        picture[row][i] = picture[tgt][i + row - tgt];
    }
    for (int i = toal; i < 2 * toal; i++)
    {
        picture[row][i] = picture[row][i-tgtt];
        if (i-tgtt == toal-1) break; 
    }
}

int FROM (int row)
{
    int wtf;
    for (int i = 2; ;i *= 2)
    {
        if (row / i == 1)
        {
            wtf = i;
            if (wtf == row) wtf /= 2;
            break;
        }
    }
    row -= wtf;
    return row;
}

int FROMM (int row)
{
    int wtf;
    for (int i = 2; ;i *= 2)
    {
        if (row / i == 0)
        {
            wtf = i;
            break;
        }
    }
    return wtf;
}