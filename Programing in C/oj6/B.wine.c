// 1.找出最贵到最便宜的酒并排序
// 2.从最贵到最便宜放
#include <stdio.h>

void Swap (int a[], int );
int main ()
{
    int species, volume, price, volumed;
    scanf ("%d %d", &species, &volume);
    volumed = price = 0;

    int value[species];
    for (int i = 0; i < species; i++) 
        scanf ("%d", &value[i]);
    
    int max_volume[species];
    for (int i = 0; i < species; i++)
        scanf ("%d", &max_volume[i]);
    
    for (int i = 0; i < species - 1; i++)
    {
        for (int j = 0; j < species - 1 -i; j++)
        {
            if (value[j] < value[j+1])
            {
                Swap (value, j);
                Swap (max_volume, j);
            }
        }
    }

    for (int i = 0; i < species; i++)
    {
        if (volume - volumed > max_volume[i])
        {
            price += value[i] * max_volume[i];
            volumed += max_volume[i];
        }
        else 
        {
            price += value[i] * (volume - volumed);
            break;
        }
    }
    printf ("%d", price);
}

void Swap (int numb[], int n)
{
    int tmp = numb[n];
    numb[n] = numb[n+1];
    numb[n+1] = tmp;
}