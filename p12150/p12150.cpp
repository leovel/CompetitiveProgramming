#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int N;
    int grid[1001];

    while (scanf("%d", &N) && N) {
        int k = N, C, P; bool possible = true;
        memset(&grid, 0, sizeof(grid));
        while (k--)
        {
            scanf("%d %d", &C, &P);
            int initial_pos = N - k + P;

            if (initial_pos < 1 || initial_pos > N || grid[initial_pos - 1] != 0)
                possible = false;
            else
                grid[initial_pos - 1] = C;
        }

        if (possible)
        {
            for (int i = 0; i < N; i++)
            {
                printf(i == 0 ? "%d" : " %d", grid[i]);
            }
            printf("\n");
        }
        else
            printf("-1\n");
    }
}
