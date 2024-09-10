#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<string> columns(17);
int r, c;
char row[17];

unordered_map<char, int> dict =
{
    {'a', 1}, {'A', 1}, {'b', 2}, {'B', 2}, {'c', 3}, {'C', 3}, {'d', 4}, {'D', 4}, {'e', 5}, {'E', 5}, {'f', 6}, {'F', 6},
    {'g', 7}, {'G', 7}, {'h', 8}, {'H', 8}, {'i', 9}, {'I', 9}, {'j', 10}, {'J', 10}, {'k', 11}, {'K', 11}, {'l', 12}, {'L', 12},
    {'m', 13}, {'M', 13}, {'n', 14}, {'N', 14}, {'o', 15}, {'O', 15}, {'p', 16}, {'P', 16}, {'q', 17}, {'Q', 17}, {'r', 18}, {'R', 18},
    {'s', 19}, {'S', 19}, {'t', 20}, {'T', 20}, {'u', 21}, {'U', 21}, {'v', 22}, {'V', 22}, {'w', 23}, {'W', 23}, {'x', 24}, {'X', 24},
    {'y', 25}, {'Y', 25},{'z', 26}, {'Z', 26}

};

bool comp_str(string ptr1, string ptr2)
{
    int n1 = ptr1.length();
    int n2 = ptr2.length();
    int n = min(n1, n2);

    for (int i = 0; i < n; i++)
    {
        if (dict[ptr1[i]] == dict[ptr2[i]])
            continue;

        if (dict[ptr1[i]] < dict[ptr2[i]])
            return true;
        else
            return false;
    }

    return n1 < n2;

}

int main()
{
    bool first = true;
    while (scanf("%d %d", &r, &c) && r && c)
    {
        if(!first)
            printf("\n");

        columns.clear();
        for (int j = 0; j < c; j++)
        {
            columns.push_back("");
        }

        for (int i = 0; i < r; i++)
        {
            scanf("%s", &row);
            for (int j = 0; j < c; j++)
            {
                columns[j] += row[j];
            }
        }

        stable_sort(columns.begin(), columns.begin() + c, comp_str);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("%c", columns[j][i]);
            }
            printf("\n");
        }
        
        first = false;
    }
}
