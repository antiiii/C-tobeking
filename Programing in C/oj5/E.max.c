#include <stdio.h>

void search (int j, int k, int i, int answer[k][2], int permuta[k], int found[k]);
int main (void)
{
    int n;
    scanf ("%d", &n);
    int permuta[n];
    int found[n];
    int answer[n][2];
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &permuta[i]);
        found[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!found[i])
        {
            search (-1, n, i, answer, permuta, found);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf ("%d ", answer[i][0]);
        printf ("%d\n", answer[i][1]);
    }
}

void search (int j, int k, int i, int answer[k][2], int permuta[k], int found[k])
{
    int min = j;
    int max = k;
    for (j = i; j > min; j--)
    {
        if (permuta[j] > permuta[i]) break;
    }
    for (k = i; k < max; k++)
    {
        if (permuta[k] > permuta[i]) break;
    }
    answer[i][0] = j+2;
    answer[i][1] = k;
    found[i] = 1;
    for (int l = j + 1; l < k; l++)
    {
        if (!found[l])
        search (j, k, l, answer, permuta, found);
    }
}