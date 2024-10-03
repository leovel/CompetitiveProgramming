#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int N, weights[(1 << 15) + 1], potencies[(1 << 15) + 1], n, maxSum, maxTemp;

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        n = 1 << N;
        memset(&weights, 0, sizeof(weights));
        for (int i = 0; i < n; scanf("%d", &weights[i++]));

        maxSum = 0;
        memset(&potencies, 0, sizeof(potencies));
        for (int i = 0; i < n; i++)
        {
            for (int b = 0; b < N; b++)
                potencies[i] += weights[i ^ (1 << b)];
        }

        for (int i = 0; i < n; i++)
        {
            for (int b = 0; b < N; b++)
            {
                maxTemp = potencies[i] + potencies[i ^ (1 << b)];
                if (maxSum < maxTemp)
                    maxSum = maxTemp;
            }
        }

        printf("%d\n", maxSum);


    }
}
