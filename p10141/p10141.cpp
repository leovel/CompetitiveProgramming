#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string.h>
//#include <string>
//#include <map>
//#include <vector>
//#include <cmath>

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
	int n, p, rfpId = 0, numReq, maxNumReq;
	float price, bestPrice;
	char reqName[84], propName[84], bestName[84];
	while (scanf("%d %d\n", &n, &p), n || p)
	{
		while(n--){ scanf("%[^\n]\n", &reqName); }

		maxNumReq = -1; bestPrice = -1.0;
		while (p--)
		{
			scanf("%[^\n]\n", &propName);
			scanf("%f %d\n", &price, &numReq);
			if (numReq > maxNumReq || (numReq == maxNumReq && price < bestPrice))
			{
				maxNumReq = numReq;
				bestPrice = price;
				strcpy(bestName, propName);
			}

			while (numReq--) { scanf("%[^\n]\n", &reqName); }
		}

		if(rfpId)
			printf("\n");
		printf("RFP #%d\n%s\n", ++rfpId, bestName);
	}
}
