#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char answer[100][5201], current[5201];
string question;
vector<string> answers[100];
int N, changes[100], minChanges, _count;

//static string trim(const string& line)
//{
//    const char* WhiteSpace = " \t\v\r\n";
//    size_t start = line.find_first_not_of(WhiteSpace);
//    size_t end = line.find_last_not_of(WhiteSpace);
//    return start == end ? string() : line.substr(start, end - start + 1);
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, question);
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++)
    {
        cin.getline(answer[i], 5201);
        strcpy(current, answer[i]);
        char* token = strtok(current, ",");
        answers[i].clear();
        while (token != NULL)
        {
            answers[i].push_back(token);
            token = strtok(NULL, ",");
        }
    }

    minChanges = 100000001;
    memset(&changes, 0, sizeof changes);
    for (int i = 0; i < N; i++)
    { 
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                _count = 0;
                for (int p = 0; p < answers[i].size(); p++)
                {
                    if (answers[i][p] != answers[j][p])
                        _count++;
                }

                if (changes[i] < _count)
                    changes[i] = _count;
            }
                
        }

        if (minChanges > changes[i])
            minChanges = changes[i];
        
    }

    for (int i = 0; i < N; i++)
        if (changes[i] == minChanges)
                cout << answer[i] << "\n";
}
