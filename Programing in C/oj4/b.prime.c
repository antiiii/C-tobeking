#include <stdio.h>
#include <math.h>

int prime (int);
int main (void)
{
    int n, judge;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)//从2开始遍历到n
    {
        judge = 1;
        judge = prime(i);
        int flip = 0;
        if (judge == 1) 
        {
            //判断位数
            int fakei = i;
            int digits = 0;
            while (fakei >= 1)
            {
                fakei /= 10;
                digits ++;
            }
            //翻转
            fakei = i;
            int flipi = 0;
            for (int j = 0; j < digits; j++)
            {
                flip = fakei % 10;
                flipi += pow (10 , digits-1-j) * flip;
                fakei /= 10;
            }
            judge = prime(flipi);
        }
        if (judge == 1) cnt++;
    }
    printf("%d\n", cnt);
}

int prime (int i)
{
    int judge = 1;
    for (int j = 2; j < i; j++)//判断是不是素数
        {
            if (i % j == 0)
            { 
                judge = 0;
                break;
            }
        }
    return judge;
}