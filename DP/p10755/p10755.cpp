#define _CRT_SECURE_NO_DEPRECATE

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int T, A, B, C;
ll gheap[24][24][24];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ll maxSum = 0;
		scanf("%d %d %d", &A, &B, &C);
		memset(gheap, 0, sizeof gheap);
		for (int i = 1; i <= A; ++i)
			for (int j = 1; j <= B; ++j)
				for (int k = 1; k <= C; ++k)
				{
					scanf("%lld", &gheap[i][j][k]);
					maxSum += gheap[i][j][k];
					gheap[i][j][k] += (gheap[i - 1][j][k] + gheap[i][j - 1][k] - gheap[i - 1][j - 1][k]);
				}
					
		
		for (int x1 = 1; x1 <= A; ++x1)
			for (int y1 = 1; y1 <= B; ++y1)
				for (int x2 = x1; x2 <= A; ++x2)
					for (int y2 = y1; y2 <= B; ++y2)
					{
						ll currSum = 0;
						for (int z = 1; z <= C; z++)
						{
							currSum += gheap[x2][y2][z] - gheap[x1 - 1][y2][z] - gheap[x2][y1 - 1][z] + gheap[x1 - 1][y1 - 1][z];
							maxSum = max(maxSum, currSum);
							if (currSum < 0) currSum = 0;
						}
					}

		printf("%lld\n", maxSum);
		if (T) printf("\n");
	}
}

