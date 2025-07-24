#define _CRT_SECURE_NO_DEPRECATE

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n; pair<int, int> a[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        // Sort by the first element, and if they are equal, by the second element
        sort(a, a + n);

        int k = 0, lis_end = 0;
        vi L(n, 0);

        for (int i = 0; i < n; ++i) {
			int pos = lower_bound(L.begin(), L.begin() + k, a[i].second + 1) - L.begin(); // Longest non-decreasing subsequence
            L[pos] = a[i].second;
            if (pos == k) {
                k = pos + 1;
                lis_end = i;
            }
        }

        cout << k << "\n";
    }
    cout << "*" << "\n";
}

