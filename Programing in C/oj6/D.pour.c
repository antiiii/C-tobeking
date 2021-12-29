#include <stdio.h>

int v_max[3], a, b, c, v_last[3]; 
int judge = 0;
void Pour (int, int, int, int, int, int);
void Back (int v[3]);
int main ()
{
    int k;
    scanf ("%d", &k);
    for (int i = 0; i < 3; i ++) scanf ("%d", &v_max[i]);
    scanf ("%d %d %d", &a, &b, &c);
    for (int i = 0; i < 3; i ++) scanf ("%d", &v_last[i]);
    Pour (a, b, c, 3, 3, k);
    if (judge == 1) printf("Yes\n");
    else printf("No\n");    
}

void Pour (int a, int b, int c, int cup1, int cup2, int k)
{
    if (a == v_last[0])
    if (b == v_last[1])
    if (c == v_last[2])
        judge = 1;
    if (k > 0)
    {
        int v[3];
        v[0] = a;
        v[1] = b;
        v[2] = c;
        if (cup1 != cup2)
        {
            v[cup2] += v[cup1];
            v[cup1] = 0;
            if (v[cup2] > v_max[cup2]) v[cup2] = v_max[cup2];
            k --;
        }
        a = v[0];
        b = v[1];
        c = v[2];
        if (a == v_last[0])
        if (b == v_last[1])
        if (c == v_last[2])
        judge = 1;
        if (k > 0)
        {
            for (int i = 0; i < 3; i ++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (i != j && !(i == cup1 && j == cup2)) 
                    {
                        Pour (a, b, c, i, j, k);
                    }
                }
            }
        }    
    }   
}
