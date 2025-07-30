#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, rings[103][103], _total,total;
char tree[102][102];

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s", &tree[i]);

        memset(&rings, 0, sizeof(rings));
         total = -1;
        do
        {
            _total = total;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                    if (tree[i - 1][j - 1] == 'T')
                    {
                        rings[i][j] = min(min(rings[i - 1][j], rings[i][j - 1]), min(rings[i + 1][j], rings[i][j + 1])) + 1;
                        if (total < rings[i][j])
                            total = rings[i][j];
                    }
                }
        } while (_total != total);

        
        if (total < 10)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (rings[i][j] == 0)
                        printf("..");
                    else
                        printf(".%d", rings[i][j]);
                }
                printf("\n");
            }
                
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (rings[i][j] == 0)
                        printf("...");
                    else if(rings[i][j] < 10)
                        printf("..%d", rings[i][j]);
                    else
                        printf(".%d", rings[i][j]);
                }
                printf("\n");
            }

        }
    }
}

