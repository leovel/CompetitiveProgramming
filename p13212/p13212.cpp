#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int n, A[1000002], L[500002], R[500002];

static long long mergelr(int p, int q, int r)
{
    long long ninv = 0;
    int nL = q - p + 1, nR = r - q;
    memcpy(L, A + p, nL * sizeof(int));
    memcpy(R, A + q + 1, nR * sizeof(int));
    int i = 0, j = 0, k = p;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
        {
            A[k++] = R[j++];
            ninv += nL - i;
        }
    }

    while (i < nL)
        A[k++] = L[i++];

    while (j < nR)
        A[k++] = R[j++];

    return ninv;
}

static long long inversion_index(int p, int r)
{
    if (p >= r)
        return 0;

    int q = (p + r) >> 1;

    return inversion_index(p, q) + inversion_index(q + 1, r) + mergelr(p, q, r);
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; scanf("%d", &A[i++]));
        printf("%lld\n", inversion_index(0, n - 1));
    }
}
