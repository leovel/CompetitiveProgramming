#include <bits/stdc++.h>
using namespace std;

int H, W, N, M, image[20][20], kernel[20][20], result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> H >> W >> N >> M)
    {
        for (int x = 0; x < H; x++)
            for (int y = 0; y < W; y++)
                cin >> image[x][y];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> kernel[i][j];

        for (int x = 0; x < H - N + 1; x++)
        {
            for (int y = 0; y < W - M + 1; y++)
            {
                result = 0;
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < M; j++)
                        result += image[x + i][y + j] * kernel[N - i - 1][M - j - 1];
                y == 0 ? cout << result : cout << " " << result;
            }
            cout << "\n";
        }    
    }

}

