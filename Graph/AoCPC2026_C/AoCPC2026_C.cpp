// #include <bits/stdc++.h>
#include <__msvc_all_public_headers.hpp>
using namespace std;

int n, B, u, v;
vector<long long> values, weights;
vector<vector<int>> AL;
vector<vector<long long>> dp;

void dfs(int u, int p) {
    for (int b = weights[u]; b <= B; ++b) {
        dp[u][b] = values[u];
    }

    for (int v : AL[u]) {
        if (v == p) continue;

        dfs(v, u);

        vector<long long> next_dp = dp[u];
        for (int b = 0; b <= B; ++b) {
            if (dp[u][b] < 0) continue;

            for (int j = 0; j <= B - b; ++j) {
                if (dp[v][j] < 0) continue;

                next_dp[b + j] = max(next_dp[b + j], dp[u][b] + dp[v][j]);
            }
        }
        dp[u] = next_dp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> B)
    {
        values.assign(n, 0); weights.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> values[i] >> weights[i];
        }

        AL.assign(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v; u--; v--;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }


        dp.assign(n, vector<long long>(B + 1, -1));

        // Root is planet 1 (index 0)
        dfs(0, -1);


        long long max_val = 0;
        for (int b = 0; b <= B; ++b) {
            if (dp[0][b] > max_val) {
                max_val = dp[0][b];
            }
        }

        cout << max_val << "\n";
    }
}