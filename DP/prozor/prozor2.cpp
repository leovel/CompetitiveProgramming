#define _CRT_SECURE_NO_WARNINGS

#include "bits/stdc++.h"
using namespace std;

int R, S, K, memo[101][101];
char window[102][102];

int main()
{
	scanf("%d %d %d", &R, &S, &K);

	memset(memo, 0, sizeof(memo));
	memset(window, 0, sizeof(window));

	for (int i = 0; i < R; i++) {
		scanf("%s", window[i]);
	}

	// Build 2D prefix sum array
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= S; j++) {
			int val = (window[i - 1][j - 1] == '*') ? 1 : 0;
			memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + val;
		}
	}

	int maxRangeSum = 0, currentSum = 0, best_r = 1, best_c = 1;
	int interior_size = K - 2; // Interior size of the racket

	// Try all possible positions for the top-left corner of the racket
	for (int r = 0; r + K - 1 < R; r++) {
		for (int c = 0; c + K - 1 < S; c++) {
			// Calculate sum of flies strictly inside the racket (excluding the border)
			int top = r + 1;        // First row inside racket
			int left = c + 1;       // First column inside racket  
			int bottom = r + K - 2; // Last row inside racket
			int right = c + K - 2;  // Last column inside racket

			// Use 2D prefix sum to get sum in rectangle [top, bottom] x [left, right]
			currentSum = memo[bottom + 1][right + 1]
				- memo[top][right + 1]
				- memo[bottom + 1][left]
				+ memo[top][left];

			if (currentSum > maxRangeSum) {
				maxRangeSum = currentSum;
				best_r = r;
				best_c = c;
			}
		}
	}

	printf("%d\n", maxRangeSum);

	// Draw the racket border
	// Top and bottom borders
	for (int j = best_c; j < best_c + K; j++) {
		window[best_r][j] = '-';
		window[best_r + K - 1][j] = '-';
	}

	// Left and right borders  
	for (int i = best_r; i < best_r + K; i++) {
		window[i][best_c] = '|';
		window[i][best_c + K - 1] = '|';
	}

	// Corners
	window[best_r][best_c] = '+';
	window[best_r][best_c + K - 1] = '+';
	window[best_r + K - 1][best_c] = '+';
	window[best_r + K - 1][best_c + K - 1] = '+';

	for (int i = 0; i < R; i++) {
		printf("%s\n", window[i]);
	}

	return 0;
}
