#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int N, M;
int number_set[10001];

bool less_int(int n1, int n2)
{
    bool even1 = n1 % 2 == 0;
    bool even2 = n2 % 2 == 0;
    int mod1 = n1 % M;
    int mod2 = n2 % M;

    if (mod1 < mod2)
        return true;

    if (mod1 > mod2)
        return false;

    if (!even1 && even2)
        return true;

    if (even1 && !even2)
        return false;

    if (!even1 && !even2)
        return n1 > n2;

        return n1 < n2;
}

int main()
{
    while (scanf("%d %d", &N, &M) && N && M)
    {
        for (int i = 0; i < N; scanf("%d", &number_set[i++]));

        sort(number_set, number_set + N, less_int);

        printf("%d %d\n", N, M);
        for (int i = 0; i < N; printf("%d\n", number_set[i++]));  
    }
    printf("0 0\n");
}
