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

int main() {
	int t;
	char r[2];
	int m, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%s %d %d", &r, &n, &m);
		switch (r[0]) {
		case 'r':
				printf("%d\n", min(m,n));
			break;
		case 'k':
			printf("%d\n", ((n * m) + 1) / 2);
			break;
		case 'K':
			printf("%d\n", ((n + 1) / 2) * ((m + 1) / 2));
			break;
		case 'Q':
			printf("%d\n", min(m, n));
			break;
		default:
			break;
		}
	}
	return 0;
}