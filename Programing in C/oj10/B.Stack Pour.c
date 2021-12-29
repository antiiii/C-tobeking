#include <stdio.h>
#include <stdlib.h>

int **bar = NULL;

void Pour (int , int );
int main (void)
{
    int sum, opera;
    scanf("%d %d", &sum, &opera);

    bar = (int **)malloc(sizeof(int * ) * sum);
    for (int i = 0; i < sum; i++)
    {
        *(bar + i) = (int *)malloc(sizeof(int) * 2);
        bar[i][0] = 1;
        bar[i][1] = i + 1;
    }

    for (int index = 0; index < opera; index ++)
    {
        int pour,poured;
        scanf ("%d %d", &pour, &poured);
        Pour(pour-1, poured-1);
    }

    for (int i = 0; i < sum; i++)
    {
        if (bar[i][0] == 0)
            printf("0");
        else
            for (int j = 0; j < bar[i][0]; j++)
                printf("%d ",bar[i][j+1]);
        printf("\n");
    }
}

void Pour (int pour, int poured)
{
    int sum_poured = bar[poured][0];
    int sum_pour = bar[pour][0];
    int sum = sum_pour + sum_poured;

    *(bar + poured) = (int *)realloc(*(bar + poured), (sum + 1) * sizeof(int));
    for (int i = sum ; i > sum_poured; i--)
        bar[poured][i] = bar[pour][sum - i + 1];
    bar[poured][0] = sum;
    
    *(bar + pour) = (int *)realloc(*(bar + pour), sizeof(int));
    bar[pour][0] = 0;
}