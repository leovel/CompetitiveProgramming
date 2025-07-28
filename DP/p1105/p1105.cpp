#define _CRT_SECURE_NO_DEPRECATE

#include <bits/stdc++.h>
using namespace std;

int dx, dy, n, q, rgrid[2024][2024], xi, yi, rx, ry, m;

void rotate(int x, int y, int dx, int dy, int& rx, int& ry) {
    rx = x - y + dy, ry = x + y;
}

int main()
{
    int tcase = 0;
    while (scanf("%d %d %d %d", &dx, &dy, &n, &q), dx || dy || n || q)
    {

        memset(rgrid, 0, sizeof rgrid);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &xi, &yi);
            rotate(xi, yi, dx, dy, rx, ry);
            rgrid[rx][ry] = 1;
        }

        for (int i = 1; i <= dx + dy; ++i)
            for (int j = 1; j <= dx + dy; ++j) {
                rgrid[i][j] += rgrid[i - 1][j];
                rgrid[i][j] += rgrid[i][j - 1];
                rgrid[i][j] -= rgrid[i - 1][j - 1];
            }

        printf("Case %d:\n", ++tcase);
        for (int i = 0; i < q; ++i)
        {
            scanf("%d", &m);

            int maxSubRect = 0;

            int x = 1, y = 1;
            for (int j = 1; j <= dy; ++j) // priority to y-axis
                for (int i = 1; i <= dx; ++i)
                {
                    rotate(i, j, dx, dy, rx, ry);

                    int a = max(rx - m, 1); int b = max(ry - m, 1);
                    int c = min(rx + m, dx + dy); int d = min(ry + m, dx + dy);

                    int subRect = rgrid[c][d];
                    subRect -= rgrid[a - 1][d];
                    subRect -= rgrid[c][b - 1];
                    subRect += rgrid[a - 1][b - 1];

                    if (subRect > maxSubRect)
                    {
                        maxSubRect = subRect;
                        x = i; y = j;
                    }

                }

            printf("%d (%d,%d)\n", maxSubRect, x, y);
        }

    }
}
