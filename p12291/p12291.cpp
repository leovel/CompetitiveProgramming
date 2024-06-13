#include <bits/stdc++.h>
using namespace std;

int n, m, si, sj, _si, _sj, mask[10][10];
char large[10][11], small[10][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m && (n || m))
    {
        for (int i = 0; i < n; i++)
            cin >> large[i];
        for (int i = 0; i < m; i++)
            cin >> small[i];

        si = -1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                if (small[i][j] == '*')
                {
                    if (si < 0) { si = i; sj = j; }
                    _si = i; _sj = j;
                }

        bool match2 = false;
        for (int i = 0; i < n && !match2; i++)
            for (int j = 0; j < n && !match2; j++)
            {
                bool match1 = false;
                if (large[i][j] == '*')
                {
                    match1 = true;
                    memset(&mask, 0, sizeof(mask));
                    for (int ii = si; ii <= _si && match1; ii++)
                        for (int jj = (ii == si ? sj : 0); jj <= (ii == _si ? _sj : m) && match1; jj++)
                        {
                            if (small[ii][jj] == '*')
                            {
                                if (i + ii - si < n && j + jj - sj >= 0 && j + jj - sj < n && large[i + ii - si][j + jj - sj] == '*')
                                    mask[i + ii - si][j + jj - sj] = 1;
                                else
                                    match1 = false;
                            }
                        }

                    if (match1)
                    {
                        for (int k = i; k < n && !match2; k++)
                            for (int l = (k == i ? j : 0); l < n && !match2; l++)
                            {
                                match1 = true;
                                for (int ii = si; ii <= _si && match1; ii++)
                                    for (int jj = (ii == si ? sj : 0); jj <= (ii == _si ? _sj : m) && match1; jj++)
                                    {
                                        if (small[ii][jj] == '*')
                                        {
                                            if (k + ii - si >= n || l + jj - sj < 0 || l + jj - sj >= n || large[k + ii - si][l + jj - sj] != '*' || mask[k + ii - si][l + jj - sj] == 1)
                                                match1 = false;
                                        }
                                    }

                                match2 = match1;
                            }
                    }

                }
            }
        match2 ? cout << "1\n" : cout << "0\n";
    }
}
