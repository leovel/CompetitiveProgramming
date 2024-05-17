#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int request[100002], n, k, ti, lindex = 0, max_requests = 0, current = 0;

int main()
{
    while (scanf("%d %d", &n, &k) != EOF) {
        lindex = 0; max_requests = 0; current = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &request[i]);

            max_requests = max(max_requests, current);

            while (request[i] >= request[lindex] + 1000)
            {
                lindex++;
                if (current > 0) current--;
            };

            if (request[i] < request[lindex] + 1000)
                current++;
        }
        max_requests = max(max_requests, current);

        printf("%d\n", max_requests % k == 0 ? max_requests / k : max_requests / k + 1);
    }
}