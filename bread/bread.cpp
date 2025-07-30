#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, first_order[100001], A[100001], L[50001], R[50001], b;
unordered_map<int, int> required_order;

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
    scanf("%d", &N);

	for (int i = 0; i < N; scanf("%d", &first_order[i++]));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &b);
		required_order.emplace(b, i);
	}

	for (int i = 0; i < N; i++)
	{
		A[i] = required_order[first_order[i]];
	}

    inversion_index(0, N - 1) % 2 == 0 ? printf("Possible\n") : printf("Impossible\n");
}
