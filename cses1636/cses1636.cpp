#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
//#include <map>
#include <vector>
using namespace std;

//typedef long long ll;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
typedef vector<int> vi;
//#define INF 1000000000;


//memset(memo, -1, sizeof memo); // initialize table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); // for rounding to nearest integer

int NMOD = 1000000007;
int n, x, current;
vi v;
int memo[101][1000001];

int main()
{
	v.reserve(101);
	//memset(memo, -1, sizeof memo);

	while(scanf("%d %d", &n, &x))
	{
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k <= x; k++)
			{
				memo[i][k] = 0;
			}
		}
		int cursor = n;
		v.clear();
		while (cursor--)
		{
			scanf("%d", &current);
			v.push_back(current);

		}

		//sort(v.begin(), v.begin() + n);

		for (int value = 0; value <= x; value += v[0] )
		{
			memo[0][value] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			for (int value = 0; value <= x; value++)
			{
				for (int k = 0; k <= value; k += v[i])
				{
					memo[i][value] = (memo[i][value] + memo[i - 1][value - k] % NMOD) % NMOD;
				}
			}
		}

		printf("%d\n", memo[n - 1][x]);
	}

	return 0;
}
