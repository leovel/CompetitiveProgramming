#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>

using namespace std;

int n, q, p, left_dist[101], right_dist[101], counter;
char name[4], names[101][4];

int main()
{
    memset(&names, 0, sizeof(names));
    scanf("%d", &n);
    
    counter = 100;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &names[i]);
        if (names[i][0] == '?')
            counter++;
        else
            counter = 0;

        left_dist[i] = counter;
    }

    counter = 100;
    for (int i = 0; i < n; i++)
    {
        if (names[n - 1 - i][0] == '?')
            counter++;
        else
            counter = 0;

        right_dist[n - 1 - i] = counter;
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &p);
        if (left_dist[p - 1] == 0)
            printf("%s\n", names[p - 1]);
        else
        {
            if (left_dist[p - 1] < right_dist[p - 1])
            {
                for (int d = 0; d < left_dist[p - 1]; d++)
                {
                    printf("right of ");
                }
                printf("%s\n", names[p - 1 - left_dist[p - 1]]);
            }
            else if (left_dist[p - 1] > right_dist[p - 1])
            {
                for (int d = 0; d < right_dist[p - 1]; d++)
                {
                    printf("left of ");
                }
                printf("%s\n", names[p - 1 + right_dist[p - 1]]);
            }
            else
                printf("middle of %s and %s\n", names[p - 1 - left_dist[p - 1]], names[p - 1 + right_dist[p - 1]]);
        }
    }
}
