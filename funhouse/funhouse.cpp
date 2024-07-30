#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int T, W, L, x, y, xdir, ydir;
char room[21][21];

int main()
{

    T = 0;
    while (scanf("%d %d", &W, &L) && (W && L))
    {
        for (int i = 0; i < L; i++)
            scanf("%s", &room[i]);

        xdir = ydir = 0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < W; j++)
                if (room[i][j] == '*')
                {
                    x = i;
                    y = j;

                    if (x == 0)
                        xdir = 1;
                    else if (x == L - 1)
                        xdir = -1;
                    else if (y == 0)
                        ydir = 1;
                    else
                        ydir = -1;
                }

        do
        {
            x += xdir;
            y += ydir;

            if (room[x][y] == '/')
            {
                if (xdir != 0)
                {
                    ydir = -xdir;
                    xdir = 0;
                }
                else if (ydir != 0)
                {
                    xdir = -ydir;
                    ydir = 0;
                }
            }
            else if (room[x][y] == '\\')
            {
                if (xdir != 0)
                {
                    ydir = xdir;
                    xdir = 0;
                }
                else if (ydir != 0)
                {
                    xdir = ydir;
                    ydir = 0;
                }
            }
            
        } while (room[x][y] != 'x');

        room[x][y] = '&';

        printf("HOUSE %d\n", ++T);
        for (int i = 0; i < L; i++)
            printf("%s\n", room[i]);

    }
}
