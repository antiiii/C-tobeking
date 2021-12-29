#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i <n; i++){
        scanf("%d", &num[i]);
    }
    for (int j = 0; j < n-1; j++){
        for (int i = 0; i < n-1; i++){
            if (num[i] > num [i+1]){
                int a = num[i];
                num[i] = num[i+1];
                num[i+1] = a;
            }
        }
    }    
    int i;
    for (i = 1; i < 1000000; i++){
        int judge = 1;
        for (int j = 0; j < n; j++){
            if (i == num[j]) judge = 0; 
        }
        if (judge == 1) break;
    }
    printf("%d", i);
    
}