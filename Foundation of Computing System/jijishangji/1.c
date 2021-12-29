#include <stdio.h>

int main ()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int nums1[n];
    int nums2[m];
    int nums[m+n];
    for (int i = 0; i < n; i++){
        scanf("%d", &nums1[i]);
    }
    for (int i = 0; i < m; i++){
        scanf("%d", &nums2[i]);
    }
    for (int i = 0; i < n; i++){
        nums[i] = nums1[i];
    }
    for (int i = n; i < n+m; i++){
        nums[i] = nums2[i-n];
    }
    for (int j = 0; j < m+n-1; j++){
        for (int i = 0; i < m+n-1; i++){
            if (nums[i] > nums [i+1]){
                int a = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = a;
            }
        }
    }
    for (int i = 0; i <m+n-1; i++){
        if (nums[i] == nums[i+1]){
            for (int cnt = i+2; cnt < m+n; cnt++){
                nums[cnt-1] = nums[cnt];
            }
            n--;
        }
    }    
    for (int i = 0; i < m+n; i++){
        printf("%d ", nums[i]);
    }

    return 0;
}