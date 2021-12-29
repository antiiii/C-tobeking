#include <stdio.h>

int main ()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int num[n];
    int num1[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    k = k % n;
    for (int i = 0; i < n; i++){
        if (i+k < n) num1[i+k] = num[i];
        else num1[i+k-n] = num[i];
    }
    for (int i = 0; i < n; i++){
        printf("%d ", num1[i]);
    }
}