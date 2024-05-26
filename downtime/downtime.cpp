#include <bits/stdc++.h>
using namespace std;

int request[100002], n, k, lindex = 0, max_requests = 0, current = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> k) {
        lindex = 0; max_requests = 0; current = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> request[i];

            max_requests = max(max_requests, current);

            while (request[i] >= request[lindex] + 1000)
            {
                lindex++;
                if (current > 0) current--;
            };

            if (request[i] < request[lindex] + 1000)
                current++;
        }
        max_requests = max(max_requests, current);

        cout << (max_requests % k == 0 ? max_requests / k : max_requests / k + 1) << "\n";
    }
}