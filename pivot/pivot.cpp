#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>


using namespace std;

typedef long long ll;

ll trA[100001], max[100001], n, cmax, cmin, count;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        count = 0;
        cmax = -1; cmin = LLONG_MAX;
        for (ll i = 0; i < n; i++)
        {
            scanf("%d", &trA[i]);
            if (trA[i] > cmax)
                cmax = trA[i];
            max[i] = cmax;
        }

        for (ll i = 0; i < n; i++)
        {
            if (trA[n - 1 - i] < cmin)
                cmin = trA[n - 1 - i];
            
            if (trA[n - 1 - i] >= max[n - 1 - i] && trA[n - 1 - i] <= cmin)
                count++;
        }

        printf("%d\n", count);
    }
}
