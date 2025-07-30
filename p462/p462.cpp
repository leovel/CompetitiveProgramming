#define _CRT_SECURE_NO_WARNINGS
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

//typedef long long ll;
typedef pair<int, int> ii;
//typedef vector<ii> vii;
//typedef vector<int> vi;
//#define INF 1000000000

//memset(memo, -1, sizeof memo); // initialize table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); // for rounding to nearest integer

pair<ii, bool> PS(vector<char> suiteCards)
{
	int ncards = suiteCards.size();
	pair<ii, bool> result = { { 0, 0 }, false };
	for(char c : suiteCards)
	{
		if (c == 'A')
		{
			result.first.first += 4;
			result.second = true;
		}
		else if (c == 'K')
		{
			if (ncards > 1)
			{
				result.first.first += 3;
				result.second = true;
			}
			else
			{
				result.first.first += 2;
			}
		}
		else if (c == 'Q')
		{
			if (ncards > 2)
			{
				result.first.first += 2;
				result.second = true;
			}
			else
			{
				result.first.first += 1;
			}
		}
		else if (c == 'J')
			result.first.first += ncards > 3 ? 1 : 0;
	}
	if (ncards < 3)
		result.first.second = ncards == 2 ? 1 : 2;

	return result;
}

char both[3], bigSuite;
vector<char> S, H, D, C;
pair<ii, bool> rS, rH, rD, rC;
int p14, p57, sizeS, sizeH, sizeD, sizeC, sizeMax;

void storeCard()
{
	if (both[1] == 'S')
		S.push_back(both[0]);
	else if (both[1] == 'H')
		H.push_back(both[0]);
	else if (both[1] == 'D')
		D.push_back(both[0]);
	else if (both[1] == 'C')
		C.push_back(both[0]);
}

int main()
{
	S.reserve(15); H.reserve(15); D.reserve(15); C.reserve(15);

	while (scanf("%s", &both) != EOF)
	{
		storeCard();
		for (int i = 0; i < 12; i++)
		{
			scanf("%s", &both);
			storeCard();
		}
		
		rS = PS(S); rH = PS(H); rD = PS(D); rC = PS(C);
		p14 = rS.first.first + rH.first.first + rD.first.first + rC.first.first;
		p57 = rS.first.second + rH.first.second + rD.first.second + rC.first.second;

		if(rS.second && rH.second && rD.second && rC.second && (p14 >= 16))
			printf("BID NO-TRUMP\n");
		else if (p14 + p57 >= 14)
		{
			sizeS = S.size(); sizeH = H.size(); sizeD = D.size(); sizeC = C.size();
			bigSuite = 'S'; sizeMax = sizeS;
			if (sizeH > sizeMax)
			{
				bigSuite = 'H'; sizeMax = sizeH;
			}
			if (sizeD > sizeMax)
			{
				bigSuite = 'D'; sizeMax = sizeD;
			}
			if (sizeC > sizeMax)
			{
				bigSuite = 'C';
			}
			printf("BID %c\n", bigSuite);
		}
		else
			printf("PASS\n");

		S.clear(); H.clear(); D.clear(); C.clear();
	}
}
