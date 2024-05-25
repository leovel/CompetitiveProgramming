#include <bits/stdc++.h>
using namespace std;

int N, M, times[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
		{
			if (i == 0 || j == 0)
				times[i][j] = 0;
			else
		{
				cin >> times[i][j];
				times[i][j] += max(times[i - 1][j], times[i][j - 1]);
				if (j == M)
				i == 0 ? cout << times[i][j] : cout << " " << times[i][j];
		}
		}
	cout << "\n";
}

