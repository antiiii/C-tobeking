#include <stdio.h>

int charge (int, int, int);
int main ()
{
    int n, row, line;
    scanf ("%d", &n);
    int square[n][n];
    int m = n-1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            square[i][j] = 0;
        }
    }

    { row = 0;
      line = n / 2;}
    square[row][line] = 1;
    for (int i = 2; i <= n*n; i++)
    {
        int oldrow, oldline;
        if (row-1 < 0 && line+1 > m)// 超出双界
        {
            oldrow = row;
            oldline = line;
        }
        else if (row-1 < 0 && line+1 <= m)// 超出上界
        {
            oldrow = row;
            oldline = line;
            row = m;
            line ++;
        }
        else if (row-1 >= 0 && line+1 > m)// 超出右界
        {
            oldrow = row;
            oldline = line;
            line = 0;
            row --;
        }
        else // 正常调转
        {
            oldrow = row;
            oldline = line;
            row --;
            line ++;
        }
        while ((square[row][line] != 0) || ((oldrow == 0) && (oldline == m)))
        {
            row = oldrow;
            line = oldline;
            row ++;
            oldrow = row;
        }
        square[row][line] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf ("%d ", square[i][j]);
        }
        printf("\n");
    }
}
