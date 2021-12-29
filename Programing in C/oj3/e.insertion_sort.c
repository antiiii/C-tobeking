#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    int sort[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sort[i]);
        char c = getchar();
        if (c == '\n') break;
    }

    printf("%d\n", sort[0]);
    for (int i = 2; i <= n; i++)
    {
        for (int j =0; j < i-1; j++)
        {
            for (int k =0; k < i-1; k++)
            {
                if (sort[k] > sort[k+1])
                {
                    int m = sort[k];
                    sort[k] = sort[k+1];
                    sort[k+1] = m;
                }
            }
        }
        for (int j =0; j < i; j++)
        {
            printf("%d ", sort[j]);
        }
        printf("\n");
    }
} 