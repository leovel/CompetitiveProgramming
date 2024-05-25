#include <bits/stdc++.h>
using namespace std;

int N, M, duration, workers_delay, stage_delay, times[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			workers_delay = i - 1 < 0 ? 0 : times[i - 1][j];
			stage_delay = j - 1 < 0 ? 0 : times[i][j - 1];
			cin >> duration;
			times[i][j] = duration + max(workers_delay, stage_delay);
			if (j == M - 1)
				i == 0 ? cout << times[i][j] : cout << " " << times[i][j];
		}
	cout << "\n";
}

