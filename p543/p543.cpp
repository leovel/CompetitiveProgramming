#define _CRT_SECURE_NO_DEPRECATE
#include <vector>
#include <cstdio>
#include <bitset>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
    _sieve_size = upperbound + 1;                    // to include upperbound
    bs.set();                                      // all 1s
    bs[0] = bs[1] = 0;                             // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        // cross out multiples of i starting from i*i
        for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);                              // add prime i to the list
    }
}

bool isPrime(ll N) {                             // good enough prime test
    if (N < _sieve_size) return bs[N];             // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
        if (N % p[i] == 0)
            return false;
    return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

ll n;
map<ll, ll> cache;


int main()
{
    sieve(1000000);

	while (scanf("%lld", &n), n)
	{
        bool find = false;
        for (ll i = 1, pi = p[i]; !find && pi <= n / 2; i++, pi = p[i])
        {
            if (isPrime(n - pi))
            {
                printf("%lld = %lld + %lld\n", n, pi, n - pi);
                find = true;
            }
        }

        if(!find)
            printf("Goldbach's conjecture is wrong.\n");
	}
}
