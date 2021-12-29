#include <stdio.h>
int main()
{
  int n, k, t;
  scanf("%d %d", &n, &k);
  int a[n];
  t = k;
  for (int i = 0; i < n; i++)
  {
    a[i] = 1;
  }
  int round = n - 1;
  int i = 0;
  while (round > 0)
  {

    if (a[i] == 1)
    {
      t--;
    }
    if (t == 0)
    {
      a[i] = 0;
      round = round - 1;
      t = k;
    }
    if (i == n - 1)
    {
      i = 0;
    }
    else
    {
      i++;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (a[i] == 1)
    {
      printf("%d", i + 1);
    }
  }

  return 0;
}