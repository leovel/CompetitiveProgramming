#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>

int N, R, C, K, kingdom[2][100][100], current, next, rival;
int main()
{
    int dr[4]{ -1, 0, 1, 0 }, dc[4]{0, 1, 0, -1};
    while(scanf("%d %d %d %d", &N, &R, &C, &K), N || R || C || K)
    {
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                scanf("%d", &(kingdom[0][i][j]));

        current = 0; next = 1;
        for (int k = 0; k < K; k++)
        {
            memset(&kingdom[next], -1, sizeof(kingdom[next]));
            for (int r = 0; r < R; r++)
                for (int c = 0; c < C; c++)
                {
                    rival = (kingdom[current][r][c] + N - 1) % N;
                    for (int i = 0; i < 4; i++)
                    {
                        if (r + dr[i] >= 0 && r + dr[i] < R &&
                            c + dc[i] >= 0 && c + dc[i] < C &&
                            kingdom[current][r + dr[i]][c + dc[i]] == rival)
                        {
                            kingdom[next][r][c] = rival;
                        }
                    }

                    if (kingdom[next][r][c] < 0)
                        kingdom[next][r][c] = kingdom[current][r][c];
                }

            std::swap(current, next);
        }

        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
                printf(c == 0 ? "%d" : " %d", kingdom[current][r][c]);
            printf("\n");
        }
    }
}
