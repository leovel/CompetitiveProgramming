#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int T, N, Q, x[100001], a, memo[231];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(&memo, -1, sizeof(memo));
        scanf("%d %d", &N, &Q);
        for (int i = 0; i < N; scanf("%d", &x[i++]));

        for (int i = 0; i < Q; i++)
        {
            scanf("%d", &a);
            if (memo[a] == -1)
            {
                for (int p = 0; p < N; p++)
                    memo[a] = max(memo[a], x[p] & a);
                
            }

            printf("%d\n", memo[a]);
        }
    }
}
