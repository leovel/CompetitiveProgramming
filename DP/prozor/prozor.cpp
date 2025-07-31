//#define _CRT_SECURE_NO_WARNINGS
//
//#include "bits/stdc++.h"
//using namespace std;
//
//int R, S, K, memo[102][102];
//char window[102][102];
//
//int main()
//{
//	scanf("%d %d %d", &R, &S, &K);
//
//	memset(memo, 0, sizeof(memo));
//	memset(window, 0, sizeof(window));
//
//	for (int i = 0; i < R; i++) {
//		scanf("%s", window[i]);
//		if(i > 0 && i < R - 1) {
//			for (int j = 1, s = 0; j < S - 1; j++) {
//				s += window[i][j] == '*' ? 1 : 0;
//				memo[i][j] = memo[i - 1][j] + s;
//			}
//		}
//	}
//
//	int maxRangeSum = 0, currentSum = 0, rx = 1, ry = 1;
//	int wh = K - 3;
//	for (int x = 1 ; x + wh < S - 1; x++)
//		for (int y = 1; y + wh < R - 1; y++)
//		{
//			currentSum = memo[x + wh][y + wh] - memo[x + wh][y - 1] - memo[x - 1][y + wh] + memo[x - 1][y - 1];
//			if (currentSum > maxRangeSum)
//			{
//				maxRangeSum = currentSum;
//				rx = x, ry = y;
//			}
//		}
//
//	printf("%d\n", maxRangeSum);
//
//	window[rx - 1][ry - 1] = '+'; window[rx - 1][ry + wh + 1] = '+';
//	window[rx + wh + 1][ry - 1] = '+'; window[rx + wh + 1][ry + wh + 1] = '+';
//
//	for (int x = rx; x <= rx + wh; x++)
//	{
//		window[x][ry - 1] = '|'; window[x][ry + wh + 1] = '|';
//	}
//
//	for (int y = ry; y <= ry + wh; y++)
//	{
//		window[rx - 1][y] = '-'; window[rx + wh + 1][y] = '-';
//	}
//
//	for (int i = 0; i < R; i++)
//	{
//		printf("%s\n", window[i]);
//	}
//
//	return 0;
//}
