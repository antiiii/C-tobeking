#include <stdio.h>
int Joseph(int n,int m)/*计算约瑟夫环的递归函数*/
{    if(n <= 1 || m <= 1)//设置游戏人数限定值        
return -1;    if(n == 2)//设置边界值    {        
    if(m % 2 == 0)      
          return 1;  
                else            return 2;    }   
                 else    {        return (Joseph(n-1,m) + m-1) % n+1;//递归调用    }}
                 int main(){    int n,m,x;    scanf("%d %d",&n,&m);    x=Joseph(n,m);    printf("最后一个数为：%d\n",x);    return 0;}