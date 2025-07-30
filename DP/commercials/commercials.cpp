#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

inline static int max_int(int a, int b) { return a > b ? a : b; }

int main()
{
	int N, P;
	scanf("%d %d", &N, &P);
	
	int max_profit = -100000000;
	int current_sum = 0;
	int value;
	
	while (N--)
	{
		scanf("%d", &value);
		current_sum += value - P;
		max_profit = max_int(max_profit, current_sum);
		current_sum = max_int(current_sum, 0);
	}

	printf("%d\n", max_profit);
	return 0;
}
