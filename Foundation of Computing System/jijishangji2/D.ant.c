#include <stdio.h>

void charge (int ant[], int n);
int main (void)
{
    int n;
    scanf("%d", &n);
    int ant[n];
    for (int i = 0; i < n; i++) scanf("%d", &ant[i]);
    charge(ant, n);
    for (int i = 0; i < n; i++)
    {
        if (ant[i] != 0) printf("%d ", ant[i]);
    }
}

void charge (int ant[], int n)
{
    int judge = 0;
    for (int i = 0; i < n ; i++)
    {
        if ( (ant[i] > 0 && ant[i+1] <= 0) || (ant[i] >= 0 && ant[i+1] < 0) )
        {
            if ( ant[i] > ant[i+1] * -1)
            {
                ant[i+1] = ant[i];
                ant[i] = 0;
            }
            else if ( ant[i] < ant[i+1] * -1)
            {
                ant[i] = ant[i+1];
                ant[i+1] = 0;
            }
            else if ( ant[i] == ant[i+1] *-1)
            {
                ant[i] = ant[i+1] = 0;
            }
            judge = 1;
        }
    }
    if (judge == 1) charge (ant, n);
}