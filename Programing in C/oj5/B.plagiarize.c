#include <stdio.h>

int find (int *, int );
int main (void)
{
    int n;
    scanf ("%d", &n);
    int students[n];
    for (int i = 0; i < n; i++) scanf ("%d", &students[i]);
    for (int i = 0; i < n; i++)
    {
        printf ("%d ", find(students, i));
    }
}

int find (int students[], int i)
{
    int target = students[i];
    if (students[i] == i+1) return i+1;
    else 
    {
        return find(students, target-1);
    }
}