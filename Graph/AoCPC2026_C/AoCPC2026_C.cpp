// #include <bits/stdc++.h>
#include <__msvc_all_public_headers.hpp>;
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, B, u, v, maxValue;
vi values;
vi weights;

enum { UNVISITED = -1, VISITED = -2 };

vector<vii> AL;
vi dfs_num;

void dfs(int u, int current_value, int current_weight) { 
    if (current_weight + weights[u] > B) return; 

	maxValue = max(maxValue, current_value + values[u]);

    dfs_num[u] = VISITED;
    for (auto& [v, w] : AL[u])
        if (dfs_num[v] == UNVISITED)
            dfs(v, current_value + values[u], current_weight + weights[u]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n >> B)
    {
        maxValue = 0;

        values.assign(n, 0);
        weights.assign(n, 0);
        AL.assign(n, vii());

		for (int i = 0; i < n; i++)
		{
			cin >> values[i] >> weights[i];
		}

        for (int i = 1; i < n; i++)
        {
			cin >> u >> v; u--; v--;
            AL[u].emplace_back(v, 0); // add edge to AL
            AL[v].emplace_back(u, 0); // add edge to AL
        }

        dfs_num.assign(n, UNVISITED);
		dfs(0, 0, 0);

        cout << maxValue << "\n";
		
    }
}
