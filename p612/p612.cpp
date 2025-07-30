#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int M, n, m;
char sequences[101][52];
vector<char*> sequence_list;

static int unsortedness(char* sequence, int l)
{
    int counter = 0;
    for (int i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++)
        {
            if (sequence[j] < sequence[i])
                counter++;
        }

    return counter;
}

int main()
{
    scanf("%d", &M);
    while (M--)
    {
        memset(&sequences, 0, sizeof sequences);
        sequence_list.clear();

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s", &sequences[i]);
            sequence_list.push_back(sequences[i]);
        }

        stable_sort(sequence_list.begin(), sequence_list.end(),
            [](char* str1, char* str2){ return unsortedness(str1, n) < unsortedness(str2, n); });

        for (int i = 0; i < m; i++)
            printf("%s\n", sequence_list[i]);

        if (M)
            printf("\n");
    }
}
