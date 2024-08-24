#define _CRT_SECURE_NO_DEPRECATE

#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>

typedef vector<int> vi;

int N, t, number_list[200001];
unordered_set<int> numbers_set;


int main()
{
    scanf("%d %d", &N, &t);
    if (t < 3)
    {
        numbers_set = unordered_set<int>();
        if (t == 1)
        {
            bool yes = false;
            for (int i = 0; i < N && !yes; i++)
            {
                int current;
                scanf("%d", &current);
                if (numbers_set.count(7777 - current))
                {
                    yes = true;
                    printf("Yes\n");
                    return 0;
                }
                numbers_set.insert(current);
            }
            printf("No\n");
        }
        else if (t == 2)
        {
            bool unique = true;
            for (int i = 0; i < N && unique; i++)
            {
                int current;
                scanf("%d", &current);
                if (numbers_set.count(current))
                {
                    unique = false;
                    printf("Contains duplicate\n");
                    return 0;
                }
                numbers_set.insert(current);
            }
            printf("Unique\n");
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &number_list[i]);
        }
        sort(number_list, number_list + N);

        if (t == 3)
        {
            int count = 1;
            int current = number_list[0];
            bool find = false;
            for (int i = 1; i < N && !find; i++)
            {
                if (number_list[i] == current)
                {
                    count++;
                    if (count > N / 2)
                    {
                        find = true;
                        printf("%d\n", current);
                        return 0;
                    }
                }
                else
                {
                    current = number_list[i];
                    count = 1;
                }
            }
            printf("-1\n");
        }
        else if (t == 4)
        {
            N % 2 == 0 ? printf("%d %d\n", number_list[N/2 - 1], number_list[N/2]) : printf("%d\n", number_list[N/2]);
        }
        else if (t == 5)
        {
            int count = 0;
            for (int i = 0; i < N && number_list[i] < 1000; i++)
            {
                if (number_list[i] >= 100)
                {
                    count++;
                    count == 1 ? printf("%d", number_list[i]) : printf(" %d", number_list[i]);
                    
                }
            }
            if(count > 0)
                printf("\n");
        }

    }

    return 0;
}

