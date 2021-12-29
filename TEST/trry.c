#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *arr;
    arr = (int * )malloc(sizeof(int) * 8);
    printf("%d", sizeof(arr));
    return 0;
}

/*
arr[0]=1
arr[1]=2
arr[2]=3
arr[3]=4
arr[4]=5
arr[5]=6
arr[6]=7
arr[7]=8

*/