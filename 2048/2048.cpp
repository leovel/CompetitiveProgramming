#include <bits/stdc++.h>
using namespace std;
#define N  4
int state[4][4], operation, result[4][4];
stack<int> temp;
bool merged;

static void rotate90Clockwise(int mat[][N])
{
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = temp;
        }
    }
}

static void rotate90AntiClockwise(int mat[][N])
{
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = temp;
        }
    }
}

static void fill_result(int& op)
{
    memset(&result, 0, sizeof(result));

    for (int r = 0; r < op; r++)
        rotate90AntiClockwise(state);

    
    for (int i = 0; i < 4; i++)
    {
        merged = false;
        for (int j = 0; j < 4; j++)
        {
            if (state[i][j] != 0)
            {
                if (!temp.empty() && !merged && temp.top() == state[i][j])
                {
                    temp.pop();
                    temp.push(2 * state[i][j]);
                    merged = true;
                }
                else
                {
                    temp.push(state[i][j]);
                    merged = false;
                }
            }
        }

        if (!temp.empty())
        {
            for (int p = temp.size() - 1; p >= 0; p--)
            {
                result[i][p] = temp.top(); temp.pop();
            }
        }
    }
    
    for (int r = 0; r < op; r++)
        rotate90Clockwise(result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> state[i][j];
    cin >> operation;

    fill_result(operation);

    for (int i = 0; i < 4; i++)
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << "\n";
}

