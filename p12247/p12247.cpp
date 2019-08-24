#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//typedef vector<int> vi;
//#define INF 1000000000

//memset(memo, -1, sizeof memo); // initialize table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); // for rounding to nearest integer

ll bitmask;
int princess[3], prince[2], result;


void findFrom(int card)
{
	for (int i = card; i <= 52; i++)
	{
		if ((bitmask & (1LL << i)) == 0)
		{
			result = i;
			break;
		}
	}
}

int main()
{
	while (scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]),
		princess[0] || princess[1] || princess[2] || prince[0] || prince[1])
	{
		sort(princess, princess + 3); reverse(princess, princess + 3);
		sort(prince, prince + 2); reverse(prince, prince + 2);

		bitmask = 0LL;
		bitmask |= (1LL << princess[0]); bitmask |= (1LL << princess[1]), bitmask |= (1LL << princess[2]);
		bitmask |= (1LL << prince[0]); bitmask |= (1LL << prince[1]);

		result = -1;
		if (princess[0] > prince[0])
		{
			if(princess[1] < prince[1])
			{
				findFrom(princess[1] + 1);
			}
			printf("%d\n", result);
		}
		else if (princess[0] > prince[1])
		{
			if (princess[1] > prince[1])
				findFrom(princess[0] + 1);
			else
				findFrom(princess[1] + 1);

			printf("%d\n", result);
		}
		else
		{
			findFrom(1);
			printf("%d\n", result);
		}
	}
}
