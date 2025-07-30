#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char row[500002];

int main()
{
    

    while (scanf("%s", &row) != EOF) {
        int n = strlen(row), lastX = -1, max_dist = 0;
        for (int i = 0; i < n; i++)
        {
            if (row[i] == 'X')
            {
                if (lastX < 0)
                    max_dist = max(max_dist, i - 1);
                else
                {
                    max_dist = max(max_dist, (i - lastX - 2) / 2);
                }

                lastX = i;
            }
        }

        max_dist = max(max_dist, n - lastX - 2);
        printf("%d\n", max_dist);
    }
}