#define _CRT_SECURE_NO_DEPRECATE

#include <bits/stdc++.h>
using namespace std;

int dx, dy, n, q, city_grid[1001][1001], xi, yi, m;

int main()
{
    int tcase = 0;
    while (scanf("%d %d %d %d", &dx, &dy, &n, &q), dx || dy || n || q)
    {
        memset(city_grid, 0, sizeof city_grid);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &xi, &yi);
            city_grid[xi - 1][yi - 1] = 1;
        }

        for (int i = 0; i < dx; ++i)
            for (int j = 0; j < dy; ++j) {
                if (i > 0) city_grid[i][j] += city_grid[i - 1][j];
                if (j > 0) city_grid[i][j] += city_grid[i][j - 1];
                if (i > 0 && j > 0) city_grid[i][j] -= city_grid[i - 1][j - 1];
            }

        printf("Case %d:\n", ++tcase);
        for (int i = 0; i < q; ++i)
        {
            scanf("%d", &m);
            m = 2 * m + 1;
            //m = min(m, dx + dy);
            int maxSubRect = -1;

            int x = 0, y = 0;

            for (int l = 0; l < dx; ++l)
                for (int r = l; r < min(l + m + 1, dy); ++r) {
                    int w = r - l;
                    for (int row = 0; row < dx; ++row) {
                        int a = row, b = l, c = min(dx - 1, row + m - w), d = r;

                        int subRect = city_grid[c][d];
                        if (a > 0) subRect -= city_grid[a - 1][d];
                        if (b > 0) subRect -= city_grid[c][b - 1];
                        if (a > 0 && b > 0) subRect += city_grid[a - 1][a - 1];

                        if (subRect > maxSubRect)
                        {
                            maxSubRect = subRect;
                            x = max(a, c - m/2); y = max(b, d - m/2);
                        }
                    }
                }

            printf("%d (%d,%d)\n",maxSubRect, x + 1, y + 1);
        }
                
    }
}
