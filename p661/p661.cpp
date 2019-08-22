#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
//#include <cmath>
#include <cstdio>
//#include <cstring>
//#include <string>
//#include <map>
//#include <vector>
using namespace std;

//typedef long long ll;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//typedef vector<int> vi;
//#define INF 1000000000

//memset(memo, -1, sizeof memo); // initialize table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); // for rounding to nearest integer

int main()
{
	int n, m, c, currCapacity, currDevice, totalCapacity, maxCapacity, sequence = 0;
	int devices[21], status;
	while (scanf("%d %d %d", &n, &m, &c), n || m || c)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &devices[i]);
		}

		totalCapacity = maxCapacity = status = 0;
		while (m--)
		{
			scanf("%d", &currDevice);

			if (status & (1 << currDevice))
			{
				totalCapacity -= devices[currDevice - 1];
			}
			else
			{
				totalCapacity += devices[currDevice - 1];
			}
			status ^= (1 << currDevice);

			maxCapacity = max(totalCapacity, maxCapacity);
		}

		if (maxCapacity > c)
		{
			printf("Sequence %d\nFuse was blown.\n\n", ++sequence);
		}
		else
		{
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n", ++sequence, maxCapacity);
		}
	}
}
