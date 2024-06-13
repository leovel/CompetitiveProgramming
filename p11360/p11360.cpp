#include <bits/stdc++.h>
using namespace std;

int T, N, M, a, b;
char matrix[50][51], operation[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int k = 1; k <= T; k++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
                cin >> matrix[i];

        cin >> M;
        while (M--)
        {
            cin >> operation;
            if (operation[0] == 'r')
            {
                cin >> a >> b;
                for (int j = 0; j < N; j++)
                    swap(matrix[a - 1][j], matrix[b - 1][j]);
            }
            else if (operation[0] == 'c')
            {
                cin >> a >> b;
                for (int i = 0; i < N; i++)
                    swap(matrix[i][a - 1], matrix[i][b - 1]);
            }
            else if (operation[0] == 'i')
            {
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        matrix[i][j] = '0' + (matrix[i][j] - '0' + 1) % 10;
            }
            else if (operation[0] == 'd')
            {
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        matrix[i][j] = '0' + (9 + matrix[i][j] - '0') % 10;
            }
            else
            {
                for (int i = 0; i < N; i++)
                    for (int j = i; j < N; j++)
                        swap(matrix[i][j], matrix[j][i]);
            }
        }

        cout << "Case #" << k << '\n';
        for (int i = 0; i < N; i++)
            cout << matrix[i] << '\n';
        cout << '\n';
    }
}
