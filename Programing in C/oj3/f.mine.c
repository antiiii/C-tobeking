#include <stdio.h>

int main (void)
{
      int n;
      scanf("%d", &n);
      char mine[n][n];
      int map[n][n];

      for (int i = 0; i < n; i++)
      {
          scanf("%s", mine[i]);
      }    
      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < n; j++)
          {
              map[i][j] = 0;
          }
      }

      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < n; j++)
          {
              if (mine[i][j] != 'o')
              {
                  for (int k = i-1; k <= i+1; k++)
                  {
                      if (k >= 0 && k < n)
                      {
                          for (int l = j-1; l <= j+1; l++)
                          {
                              if (l >= 0 && l < n)
                              map[k][l] ++;
                          }
                      }
                  }
                  map[i][j] = 9;
              }
          }
      }

      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < n; j++)
          {
              if (map[i][j] <= 8) printf("%d", map[i][j]);
              else printf("*");
          }
          if (i < n-1) printf("\n");
      }
}