#include <bits/stdc++.h>
using namespace std;

int T, p, q, r, S, j, nA, n, m = 1000000007;
string A;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++)
    {
        S = 0;
        getline(cin, A);
        n = A.length();
        nA = n;
        q = n / 2, p = q - 1;

        while (n)
        {
            if (n&1)
            {
                if(nA - q > p)
                    r = (A[q] - '0'), q++;
                else
                    r = (A[p] - '0'), p--;
            }    
            else
            {
                if (A[p] > A[q])
                    r = (A[p] - '0'), p--;
                else
                    r = (A[q] - '0'), q++;
            }
            S = (S << 1) + r;
            if (S >= m)
                S %= m;

            n--;
        }

        std::cout << "Case #" << i << ": " << S << '\n';
    }
}
