#include <bits/stdc++.h>
using namespace std;

string line;
bool board[5][5];
int di[]{ -2, -2, -1, 1, 2, 2, 1, -1 }, dj[]{ -1, 1, 2, 2, 1, -1, -2, -2 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        getline(cin, line);
        for (int j = 0; j < 5; j++)
            board[i][j] = line[j] == 'k';
    }

    bool valid = true; int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == true)
            {
                count++;
                for (int k = 0; k < 8; k++)
                {
                    if (i + di[k] >= 0 && i + di[k] < 5 &&
                        j + dj[k] >= 0 && j + dj[k] < 5 &&
                        board[i + di[k]][j + dj[k]])
                    {
                        cout << "invalid\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << (count == 9 ? "valid\n" : "invalid\n");
}
