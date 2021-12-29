#include <stdio.h>

#define digits 16
#define groups 8

int IPV6[groups][digits] = {0};
int IPV6_Hexadecimal[groups][4] = {0};
int judge[8] = {0};

void KillZero (int i, int j);
int Hexadecimal (int , int);
int main (void)
{
    for (int i = 0; i < groups; i++)
    {
        for (int j = 0; j < digits; j++)
            scanf("%1d", &IPV6[i][j]);
    }

    for (int i = 0; i < groups; i++)// 转化为16进制
    {
        int k = 0;
        for (int j = 0; j < digits; j += 4)
        {
            IPV6[i][k] = Hexadecimal(i, j);
            k++;
        }    
    }

    for (int i = 0; i < groups; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            IPV6_Hexadecimal[i][j] = IPV6[i][j];
        }
    }

    for (int i = 0; i < groups; i++) KillZero (i, 0); 

    for (int i = 7; i > 0; i--)
    {
        while (judge[i-1] != 0)
        {
            judge[i-1] += judge[i];
            i--;
            if (i == 0) break;
        }
    }    

    int max = 0;
    int max_nub;
    for (int i = 0; i < groups; i++)
    {
        if (judge[i] > max)
        {
            max =judge[i];
            max_nub = i;
        }    
    }
    
    for (int i = 0; i < groups; i++)
    {
        if (i != max_nub && (i >= max_nub + max || i < max_nub))
        {
            for (int j = 0; j < 4; j++)
            {
                if (IPV6_Hexadecimal[i][j] == 10) printf("a");
                else if (IPV6_Hexadecimal[i][j] == 11) printf("b");
                else if (IPV6_Hexadecimal[i][j] == 12) printf("c");
                else if (IPV6_Hexadecimal[i][j] == 13) printf("d");
                else if (IPV6_Hexadecimal[i][j] == 14) printf("e");
                else if (IPV6_Hexadecimal[i][j] == 15) printf("f");
                else if (IPV6_Hexadecimal[i][j] == -1) printf("");
                else printf("%d", IPV6_Hexadecimal[i][j]);
            }
            if (i < 7) printf(":");
        }
        else if (i == max_nub) printf(":");
    }
}

int Hexadecimal (int group, int digit)
{
    int sum = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (IPV6[group][digit + i - 1] == 1)
            sum += pow (2, 4-i); 
    }

    return sum;
}

void KillZero (int i, int j)
{
    if (IPV6_Hexadecimal[i][j] == 0)
    {
        IPV6_Hexadecimal[i][j] = -1;
        if (j == 2) 
        {
            if (IPV6_Hexadecimal[i][j+1] == 0)
                judge[i] = 1;
            return;
        }    
        KillZero (i, j+1);
    }
}
//01000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000