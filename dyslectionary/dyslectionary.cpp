#include <bits/stdc++.h>
using namespace std;

string word_group[101];
int n, max_width;

static bool less_string(const string& s1, const string& s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l = min(l1, l2);

    for (int i = 1; i <= l ; i++)
    {
        if (s1[l1 - i] == s2[l2 - i])
            continue;

        if (s1[l1 - i] < s2[l2 - i])
            return true;

        if (s1[l1 - i] > s2[l2 - i])
            return false;
    }

    return l1 < l2;
}

static void process(bool last)
{
    sort(word_group, word_group + n, less_string);

    for (int i = 0; i < n; cout.width(max_width), cout << right << word_group[i++] << "\n");

    if(!last)
        cout << "\n";

    n = 0;
    max_width = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n = 0;
    max_width = 0;
    while (getline(cin, word_group[n]))
    {
        if (word_group[n].empty())
        {
            process(false);
            continue;
        }

        max_width = max(max_width, (int)word_group[n].length());
        n++;
    }

    process(true);
}
