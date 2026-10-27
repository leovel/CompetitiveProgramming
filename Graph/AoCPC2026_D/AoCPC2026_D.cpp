// #include <bits/stdc++.h>
#include <__msvc_all_public_headers.hpp>;
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAXA = 1000005;
int freq[MAXA];

int t, n, u_i, v_i, numPairs;
vi a, sz, heavy, modified_vals;

vector<vi> AL;

// Calcular dimenssão de cada subárvore e o filho pesado (maior dimensão) de cada nó
void bfs_sz(int u, int parent)
{
	sz[u] = 1;
	for (auto& v : AL[u])
		if (v != parent)
		{
			bfs_sz(v, u);
			sz[u] += sz[v];
			if (heavy[u] == -1 || sz[v] > sz[heavy[u]])
				heavy[u] = v;
		}
}

// Modificar a frequência de cada valor na subárvore de u
void dfs_add(int u, int parent, int delta)
{
	if(freq[a[u]] == 0)
		modified_vals.push_back(a[u]);

	freq[a[u]] += delta;
	for (auto& v : AL[u])
		if (v != parent)
			dfs_add(v, u, delta);
}

// Contar o número de pares válidos na subárvore de u que tem root como mínimo ancestro comum
void dfs_count_pairs(int u, int root, int parent)
{
	numPairs += freq[a[u] ^ a[root]];
	
	for (auto& v : AL[u])
		if (v != parent)
			dfs_count_pairs(v, root, u);
}

// Algoritmo DSU on Tree (Sack)
void dfs_dsu(int u, int parent, bool keep)
{
	for (auto& v : AL[u])
		if (v != parent && v != heavy[u])
			dfs_dsu(v, u, false);

	if (heavy[u] != -1)
		dfs_dsu(heavy[u], u, true);

	for (auto& v : AL[u])
		if (v != parent && v != heavy[u])
		{
			dfs_count_pairs(v, u, u);
			dfs_add(v, u, 1);
		}
			
	freq[a[u]]++;
	if (freq[a[u]] == 1)
		modified_vals.push_back(a[u]);

	numPairs += freq[0] - (a[u] == 0 ? 1 : 0);

	if (!keep)
		dfs_add(u, parent, -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	cin >> t;
    while (t--)
    {
		cin >> n;
		a.assign(n, 0);
		heavy.assign(n, -1);
		sz.assign(n, 0);

		AL.assign(n, vi());

		for (int i = 0; i < n; i++)
			cin >> a[i];

		
		for (int i = 1; i < n; i++)
		{
			cin >> u_i >> v_i; u_i--; v_i--;
			AL[u_i].emplace_back(v_i);
			AL[v_i].emplace_back(u_i);
		}

		numPairs = 0;

		bfs_sz(0, -1);
		dfs_dsu(0, -1, true);

		cout << numPairs << "\n";

		// Reset de frequências em O(|modified_vals|)
		for (auto& k : modified_vals)
		{
			freq[k] = 0;
		}
		modified_vals.clear();
    }

}

