#include <stdio.h>

int main ()
{
    int n,t= 0;
    int num[26] = {0};
    scanf("%d", &n);
    char str[n];
    int judge[n];
    scanf("%s", str);
    for (int i = 0; i < n; i++){
        int t = str[i] - 97;./..
        num[t] ++; 
    }
    for (int i = 0; i < 26; i++){
        if (num[i] > t) t = num[i];
    }
    for (int i = t; i > 0; i--){
        for (int cnt = 0; cnt < 26; cnt++){
            if (num[cnt] >= i) printf(" = ");
            else printf("   ");    
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------------------\n");
    printf(" a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z ");

    return 0;
}
