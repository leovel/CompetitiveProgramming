#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long m, k, p = 1000000007;

long long S;

//long long power(long long x, long long y, long long p)
//{
//    long long res = 1;     // Initialize result 
//
//    x = x % p; // Update x if it is more than or 
//    // equal to p
//
//    if (x == 0) return 0; // In case x is divisible by p;
//
//    while (y > 0)
//    {
//        // If y is odd, multiply x with result 
//        if (y & 1)
//            res = (res * x) % p;
//
//        // y must be even now 
//        y = y >> 1; // y = y/2 
//        x = (x * x) % p;
//    }
//    return res;
//}

typedef long long ll;
ll binary_exponent(ll x, ll y, ll mod) {
    ll res = 1;
    ll p = x % mod;
    while (y) {
        if (y & 1) {
            res = (res * p) % mod;
        }
        p = (p * p) % mod;
        y = y >> 1;
    }
    return res;
}

ll gp_sum(ll a, int n, ll mod) {
    ll A = 1;
    int num = 0;
    ll res = 0;
    ll degree = 1;
    while (n) {
        if (n & (1 << num)) {
            n &= (~(1 << num));
            res = (res + (A * binary_exponent(a, n, mod)) % mod) % mod;
        }
        A = (A + (A * binary_exponent(a, degree, mod)) % mod) % mod;
        degree *= 2;
        num++;
    }
    return res;
}

int main()
{
    S = 0;
    m = 97;
    k = 100000;

    printf("%lld\n", gp_sum(m, 1000000000, 1000000007));
}

