#include <stdio.h>

int main()
{
    int m,n;
    long money=0;
    long cha = 0;
    long bin,wei= 0;
    scanf("%d", &n);
    for (bin =0 ; n >0; n--)
    {
        scanf("%d %ld", &m, &money);
        if (m == 1 )
        {
            bin += money; 
        }
        if (m == 2)
        {
            wei += money;
        }
    }
    cha = wei - bin;
    printf("%ld", cha);

    return 0;
}