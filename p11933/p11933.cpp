#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main()
{
    while (scanf("%d", &n) && n)
    {
        a = 0; b = 0;
        int bn = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                bn++ & 1 ? b |= (n & (1 << i)) : a |= (n & (1 << i));
            }
           
        }

        printf("%d %d\n", a, b);
    }
}
