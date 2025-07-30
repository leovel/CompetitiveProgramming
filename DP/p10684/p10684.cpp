#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

int N, bets[10001];

int main()
{
    while (scanf("%d", &N), N)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &bets[i]);
        }

		int max_sum = 0, current_sum = 0;
        for (int i = 0; i < N; i++)
        {
            current_sum += bets[i];
            if (current_sum < 0)
                current_sum = 0;
            max_sum = max(max_sum, current_sum);
        }
        if (max_sum > 0)
            printf("The maximum winning streak is %d.\n", max_sum);
        else
			printf("Losing streak.\n");
    }
}

