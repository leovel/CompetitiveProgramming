#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

int NMOD = 1000000007;
int n, x, current;
vi v;
int memo[1000001];

int main()
{
	v.reserve(101);

	while(scanf("%d %d", &n, &x) != EOF)
	{
		memset(memo, 0, sizeof memo);
		int cursor = n;
		v.clear();
		while (cursor--)
		{
			scanf("%d", &current);
			v.push_back(current);

		}

		sort(v.begin(), v.end());

		for (int value = 0; value <= x; value += v[0] )
		{
			if(value != 0 || x % v[0] == 0)
				memo[value] = 1;
		}
		int result = 0;
		for (int i = 1; i < n; i++)
		{
			int current = v[i];
			if (current % x == 0)
				result = (result + 1) % NMOD;
			for (int value = current; value <= x; value += current)
			{
				memo[value] = (memo[value] + 1) % NMOD;
			}

			for (int value = 1; value < x; value++)
			{
				if (memo[value] != 0 && (x - value) % current == 0)
				{
					result = (result + memo[value]) % NMOD;
				}
			}
		}

		printf("%d\n", result);
	}
}
