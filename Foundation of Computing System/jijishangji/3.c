#include <stdio.h>

int main ()
{
    int x,i;
    scanf("%d", &x);
    int a[32] = {0};
    if (x >= 0) {
        for (i =31 ; i>-1 ; i--){
        if (x % 2 == 0) a[i]=0;
        else a[i] = 1;
        x/=2;
        }
    }
    else {
        x = -x;
        for (i =31 ; i>-1 ; i--){
        if (x % 2 == 0) a[i]=1;
        else a[i] = 0;
        x/=2;
        }
        if (a[31] == 0) a[31] = 1;
        else {
            for (i =31; i >-1; i--){
                if (a[i] == 1) a[i] = 0;
                else if (a[i] == 0) {
                    a[i] = 1;
                    break;
                }
            }
        }
    }   
    for (i = 0; i < 32; i++){
        printf("%d", a[i]);
    }

    return 0;
}