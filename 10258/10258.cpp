#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, contestant, problem, rtime, solved_memo[102][11];
char L, line[256], dummy[5];
vector<tuple<int, int, int>> results;
unordered_map<int, tuple<int, int, int>> entries;

int main()
{
    scanf("%d", &N);
    fgets(dummy, 5, stdin);
    fgets(dummy, 5, stdin);
    
    while (N--)
    {
        memset(&solved_memo, 0, sizeof solved_memo);
        results.clear();
        entries.clear();
        bool first = true;
        while (fgets(line, 256, stdin))
        {
            if (strcmp(line,"\n") == 0)
                break;

            line[strcspn(line, "\n")] = '\0';
            sscanf(line, "%d %d %d %c", &contestant, &problem, &rtime, &L);
           
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
        }

        for (auto kv : entries)
        {
            results.push_back(kv.second);
        }

        sort(results.begin(), results.end(), less<tuple<int, int, int>>());

        for (auto &t : results)
            printf("%d %d %d\n", get<2>(t), -get<0>(t), get<1>(t));

        if (N)
            printf("\n");
        
    }

}

