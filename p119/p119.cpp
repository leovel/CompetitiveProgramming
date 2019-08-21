// p119.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_DEPRECATE
//#include <algorithm>
//#include <cmath>
#include <cstdio>
//#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

//typedef long long ll;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//typedef vector<int> vi;
//#define INF 1000000000

//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); // for rounding to nearest integer

int main()
{
	int N; bool first = true;
	while (scanf("%d", &N) != EOF) {

		vector<string> names; names.reserve(16);
		map<string, int> mapOfNames;

		int n = N; char name[16];
		while (n--)
		{
			scanf("%s", &name);
			string cname(name);
			names.push_back(cname);
			mapOfNames[cname] = 0;
		}

		int m, f;
		while (N--)
		{
			scanf("%s %d %d", &name, &m, &f);
			string cname(name);
			int sf = f == 0 ? 0 : m / f, st = sf * f;
			mapOfNames[cname] -= st;
			while (f--)
			{
				scanf("%s", &name);
				string fname(name);
				mapOfNames[fname] += sf;
			}
		}

		if (!first)
			printf("\n");
		for (string s : names)
		{
			printf("%s %d\n", s.c_str(), mapOfNames[s]);
		}
		first = false;
	}
}
