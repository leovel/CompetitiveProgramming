#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ages[102], age, age_count;

int main()
{
    while (scanf("%d", &n) && n)
    {
        memset(&ages, 0, sizeof ages);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &age);
            ages[age]++;
        }

        age_count = 0;
        for (int i = 1; i < 101; i++)
        {
            if(ages[i])
            {
                for (int a = 0; a < ages[i]; a++)
                {
                    age_count == 0 ? printf("%d", i) : printf(" %d", i);
                    age_count++;
                }
            }
        }
        printf("\n");
    }
}
