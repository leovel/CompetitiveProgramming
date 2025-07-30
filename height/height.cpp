#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int P, K, h, steps, pos;
vi heights(21);

int main()
{
    scanf("%d", &P);
    while (P--)
    {
        scanf("%d", &K);
        steps = 0;
        heights.clear();
        for (int i = 0; i < 20; i++)
        {
            scanf("%d", &h);
            pos = 0;

            while (pos < i && heights[pos] <= h)
                pos++;

            if (pos == i)
                heights.push_back(h);
            else
            {
                heights.insert(heights.begin() + pos, h);
                steps += i - pos;
            }
        }

        printf("%d %d\n", K, steps);
    }
}

