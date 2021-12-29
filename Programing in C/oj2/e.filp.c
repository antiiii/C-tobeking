#include <stdio.h>

int main ()
{
    int n,targett = 1;
    scanf("%d", &n);
    int cnt = 3;
    int target[1000] = {0};
    target[0] = 1;
    for (int i = 1; targett < n; cnt += 2)
    {
        target [i] = target [i-1] + cnt;
        targett = target[i];
        i ++;
    }
    int i = 0;
    while (target[i] < n){
        printf("%d ", target[i]);
        i++;
    }

    return 0;
}