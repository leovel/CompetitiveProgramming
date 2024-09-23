#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int n, A[1000001], L[500001], R[500001];

static int mergelr(int p, int q, int r)
{
    int ninv = 0, nL = q - p + 1, nR = r - q;
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

static int inversion_index(int p, int r)
{
    if (p >= r)
        return 0;

    int q = (p + r) / 2;

    return inversion_index(p, q) + inversion_index(q + 1, r) + mergelr(p, q, r);
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; scanf("%d", &A[i++]));
        printf("%d\n", inversion_index(0, n - 1));
    }
}
