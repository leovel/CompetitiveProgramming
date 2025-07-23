#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int T, L, W, H;
vector<pair<double, int>> downAccData(101);

int main()
{
    while (scanf("%d", &T) && T)
    {
        downAccData.clear();
        while (T--)
        {
            scanf("%d %d %d", &L, &W, &H);
            downAccData.emplace_back(1.0 - 0.5 / H, L * W * H);
        }
        sort(downAccData.begin(), downAccData.end(), greater<pair<double, int>>());

        printf("%d\n", downAccData[0].second);
    }
}
