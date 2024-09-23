#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int N, P[100001], L[50001], R[50001];

static int mergelr(int p, int q, int r)
{
    int ninv = 0, nL = q - p + 1, nR = r - q;
    memcpy(L, P + p, nL * sizeof(int));
    memcpy(R, P + q + 1, nR * sizeof(int));
    int i = 0, j = 0, k = p;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
            P[k++] = L[i++];
        else
        {
            P[k++] = R[j++];
            ninv += nL - i;
        }
    }

    while (i < nL)
        P[k++] = L[i++];

    while (j < nR)
        P[k++] = R[j++];

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
    while (scanf("%d", &N) && N)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &P[i]);
        }
        inversion_index(0, N - 1) % 2 == 0 ? printf("Carlos\n") : printf("Marcelo\n");
    }
}
