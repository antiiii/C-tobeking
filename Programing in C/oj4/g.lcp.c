#include <stdio.h>
#include <string.h>

#define N 100
int smnumb (int, int, char str[][N]);
int main (void)
{
    int n, p;
    scanf("%d %d", &n, &p);
    char str[n][N];
    int asks[p][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
        {
            str[i][j] = '\0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%s", &str[i]);
    }
    for (int i = 0; i < p; i++)
    {
        scanf ("%d %d",&asks[i][0], &asks[i][1]);
    }
    for (int i = 0; i < p; i++)
    {
        printf("%d\n", smnumb(asks[i][0], asks[i][1], str));
    }
}

int smnumb(int p, int q, char str[][N])
{
    int index = 0;
    while (str[p-1][index] == str[q-1][index] && str[q-1][index] != '\000')
    {
        index++;
    }
    return index;
}