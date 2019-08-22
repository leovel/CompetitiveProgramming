#define _CRT_SECURE_NO_DEPRECATE
//#include <algorithm>
#include <cmath>
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
	int H, U, D, F;
	while (scanf("%d %d %d %d", &H, &U, &D, &F), H)
	{
		int n = 0; double Hn = 0.0, deltaU = F * U / 100.0;
		do
		{
			n++;
			Hn += fmaxl(U - (n - 1) * deltaU, 0.0) - D; // Up no negative
		} while (Hn + D <= H && Hn >= 0);
		{
			if(Hn + D > H)
				printf("success on day %d\n", n);
			else
				printf("failure on day %d\n", n);
		}
	}
}
