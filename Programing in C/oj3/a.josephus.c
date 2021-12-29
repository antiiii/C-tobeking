#include <stdio.h>

int main (void)
{
    int n,k,i;
    scanf("%d %d", &n, &k);
    int person[n];

    for (int index = 0; index < n; index++){
        person[index] = 1;
    }

    int sum = 0;
    int cnt = 0;
    for (i = 0; i < n; i ++){
        sum += person[i];
        if (sum == k){
            person[i] = 0;
            sum = 0;
            cnt ++;
            if (cnt == n-1) break;
        }
        if (i+1 == n) i = i-=n;
    }

    for (i = 0; i < n; i++){
        if (person[i] == 1) break;
    }  
    printf("%d", i+1);
}