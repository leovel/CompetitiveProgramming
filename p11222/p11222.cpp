#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int T, S1, problems1[1001], S2, problems2[1001], S3, problems3[1001], m1, m2, m3, m;
vi unique1, unique2, unique3;

static void check(int* l, int n, int* l1, int n1, int* l2, int n2, vi *result)
{
    bool present; result->clear();
    for (int i = 0; i < n; i++)
    {
        present = false;
        for (int j = 0; j < n1 + n2; j++)
        {
            if ((j < n1 ? l1[j] : l2[j - n1]) == l[i])
            {
                present = true;
                break;
            }
        }

        if (!present)
            result->push_back(l[i]);
    }

    sort(result->begin(), result->end());
}

int main()
{
    unique1.reserve(1000); unique2.reserve(1000); unique3.reserve(1000);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &S1);
        for (int i = 0; i < S1; i++)
        {
            scanf("%d", &problems1[i]);
        }

        scanf("%d", &S2);
        for (int i = 0; i < S2; i++)
        {
            scanf("%d", &problems2[i]);
        }

        scanf("%d", &S3);
        for (int i = 0; i < S3; i++)
        {
            scanf("%d", &problems3[i]);
        }

        check(problems1, S1, problems2, S2, problems3, S3, &unique1);
        check(problems2, S2, problems3, S3, problems1, S1, &unique2);
        check(problems3, S3, problems1, S1, problems2, S2, &unique3);

        m1 = unique1.size(); m2 = unique2.size(); m3 = unique3.size();
        m = max(max(m1, m2), m3);

        printf("Case #%d:\n", t);
        if (m1 == m)
        {
            printf("1 %d", m);
            for (int p: unique1)
            {
                printf(" %d", p);
            }
            printf("\n");
        }

        if (m2 == m)
        {
            printf("2 %d", m);
            for (int p : unique2)
            {
                printf(" %d", p);
            }
            printf("\n");
        }

        if (m3 == m)
        {
            printf("3 %d", m);
            for (int p : unique3)
            {
                printf(" %d", p);
            }
            printf("\n");
        }
    }
}
