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
	int L, p;
	map<pair<string, string>, const char*> nextMap =
	{
		{{"+x","No"}, "+x" }, {{"-x","No"}, "-x" }, {{"+y","No"}, "+y" }, {{"-y","No"}, "-y" }, {{"+z","No"}, "+z" }, {{"-z","No"}, "-z" },
		{{"+x","+y"}, "+y" }, {{"-x","+y"}, "-y" }, {{"+y","+y"}, "-x" }, {{"-y","+y"}, "+x" }, {{"+z","+y"}, "+z" }, {{"-z","+y"}, "-z" },
		{{"+x","-y"}, "-y" }, {{"-x","-y"}, "+y" }, {{"+y","-y"}, "+x" }, {{"-y","-y"}, "-x" }, {{"+z","-y"}, "+z" }, {{"-z","-y"}, "-z" },
		{{"+x","+z"}, "+z" }, {{"-x","+z"}, "-z" }, {{"+y","+z"}, "+y" }, {{"-y","+z"}, "-y" }, {{"+z","+z"}, "-x" }, {{"-z","+z"}, "+x" },
		{{"+x","-z"}, "-z" }, {{"-x","-z"}, "+z" }, {{"+y","-z"}, "+y" }, {{"-y","-z"}, "-y" }, {{"+z","-z"}, "+x" }, {{"-z","-z"}, "-x" }
	};
	string position, bend;
	char tmp[3];
	while (scanf("%d", &L), L)
	{
		L--;

		position = "+x";
		while (L--)
		{
			scanf("%s", &tmp);
			bend = tmp;
			position = nextMap[make_pair(position, bend)];
		}
		printf("%s\n", position.c_str());
	}
}
