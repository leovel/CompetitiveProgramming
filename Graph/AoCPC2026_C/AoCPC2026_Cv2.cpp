// #include <bits/stdc++.h>
#include <__msvc_all_public_headers.hpp>
using namespace std;

using ii = std::pair<int, int>;
using vii = std::vector<ii>;
using vi = std::vector<int>;

int n, B, u, v, maxValue;
vi values, weights;

enum { NAO_VISITADO = -1, VISITADO = 1 };

std::vector<vii> AL;
vi dfs_num;

void dfs(int u, int current_value, int current_weight) {
    if (current_weight + weights[u] > B) return;

	maxValue = max(maxValue, current_value + values[u]);
    
    dfs_num[u] = VISITADO;
    for (const auto& [v, w] : AL[u]) {
        if (dfs_num[v] == NAO_VISITADO) {
            dfs(v, current_value + values[u], current_weight + weights[u]);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> B)
    {
        maxValue = 0;

        values.assign(n, 0); weights.assign(n, 0);
        AL.assign(n, vii());

        for (int i = 0; i < n; i++)
            cin >> values[i] >> weights[i];
        

        for (int i = 1; i < n; i++)
        {
            cin >> u >> v; u--; v--;
            AL[u].emplace_back(v, 0);
            AL[v].emplace_back(u, 0);
        }

        dfs_num.assign(n, NAO_VISITADO);
        dfs(0, 0, 0);
        cout << maxValue << '\n';
    }
}