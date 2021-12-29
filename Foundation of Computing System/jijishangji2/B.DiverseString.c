#include <stdio.h>

#define N 50
int main (void)
{
    int numb;
    scanf ("%d", &numb);
    char str[numb][N];
    int sum[numb], min[numb], stacknum[numb], num[numb];

    for (int i = 0; i < numb; i++)//初始化
    {
        for (int j = 0; j < N; j++)
        {
            str[i][j] = 0;
        }
        sum[i] = min[i] = stacknum[i] = num[i] = 0;
        min[i] = 123;
    }

    for (int i = 0; i < numb; i++)
    {
        getchar();
        scanf("%s", &str[i]);
    }

    for (int i = 0; i < numb; i++)// 求出每个字符串的ascii和和数目
    {
        for (int j = 0; j < N; j++)
        {
            if (str[i][j] != 0) num[i]++;
        }
    }
    
    for (int i = 0; i < numb; i++)// 求出每个字符串最小值和累加
    {
        for (int j = 0; j < num[i]; j++)
        {
            if (str[i][j] < min[i]) min[i] = str[i][j];
            sum[i] += str[i][j];
        }
        for (int j = 1; j < num[i]; j++)
        {
            stacknum[i] += j;
        }
    }

    for (int i = 0; i < numb; i++)
    {
        if (sum[i] == (min[i] * num[i] + stacknum[i])) 
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }
}