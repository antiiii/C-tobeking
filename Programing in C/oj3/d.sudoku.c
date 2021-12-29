#include <stdio.h>

#define row 9
#define line 9
int main (void)
{
    int num;
    int judge = 0;
    int sudo[row][line] = {0};
    int nob[10] = {0};

    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j <  line; j++)
        {
            scanf("%d", &sudo[i][j]);
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        int j = 0;
        for (int m = 1; m < 10; m++)
        {
            nob[m] = 0;
        }
        for ( ; j < line; j++)
        {
            num = sudo[i][j];
            if (nob[num] == 0) nob[num] = 1;
            else judge = 1;
        }
    }

    for (int i = 0; i < line; i++)
    {
        int j = 0;
        for (int m = 1; m < 10; m++)
        {
            nob[m] = 0;
        }
        for (int j = 0; j < row; j++)
        {
            num = sudo[j][i];
            if(nob[num] == 0) nob[num] = 1;
            else judge =1;
        }
    }

    for (int i = 0; i < row; i += 3)
    {
        for (int j = 0; j < line; j+=3)
        {
            for (int m = 1; m < 10; m++)
                {
                    nob[m] = 0;
                }
            for (int k = i; k < i+3; k++)
            {
                for (int l = j; l < j+3; l++)
                {
                    num = sudo[k][l];
                    if (nob[num] == 0) nob[num] = 1;
                    else judge =1;
                }
            }
        }
    }

    if (judge == 1) printf("NO");
    else printf("YES");
}