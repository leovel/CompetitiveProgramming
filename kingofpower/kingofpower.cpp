#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

long long m, k, p = 1000000007;

long long S;

long long power(long long x, long long y, long long p)
{
    long long res = 1;     // Initialize result 

    x = x % p; // Update x if it is more than or 
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result 
        if (y & 1)
            res = (res * x) % p;

        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    S = 0;
    m = 3;
    k = 1000;

    for (int i = 1; i <= k; i++)
    {
        S += power(m, i, p) * power(i, m, p);
        S = S % p;

        printf("%lld\n", S);
    }
}

