#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, contestant, problem, rtime, solved_memo[102][11];
char L;
string line;
vector<tuple<int, int, int>> results;
unordered_map<int, tuple<int, int, int>> entries;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore(2);

    while (N--)
    {
        memset(&solved_memo, 0, sizeof solved_memo);
        results.clear();
        entries.clear();
        while (getline(cin, line))
        {
            if (line.empty())
                break;

            stringstream sline(line);
            sline >> contestant >> problem >> rtime >> L;

            if (solved_memo[contestant][problem] <= 0)
            {
                if (entries.find(contestant) == entries.end())
                    entries.emplace(contestant, make_tuple(0, 0, contestant));

                if (L == 'I')
                {
                    solved_memo[contestant][problem] -= 20;
                }
                else if (L == 'C')
                {
                    solved_memo[contestant][problem] = -solved_memo[contestant][problem] + rtime;
                    entries[contestant] = make_tuple(get<0>(entries[contestant]) - 1, get<1>(entries[contestant]) + solved_memo[contestant][problem], contestant);
                }

            }
            //if (feof(stdin)) break;
        }

        for (auto kv : entries)
        {
            results.push_back(kv.second);
        }

        sort(results.begin(), results.end(), less<tuple<int, int, int>>());

        for (auto t : results)
            std::cout << get<2>(t) << " " << -get<0>(t) << " " << get<1>(t) << '\n';

        if (N)
            std::cout << '\n';

    }

}
