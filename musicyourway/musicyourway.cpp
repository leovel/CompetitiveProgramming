#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

string line, attributes[21], songs[101][21], command;
vector<string*> song_list;
unordered_map<string, int> attributes_map;
int attr_n, m, n;

static bool less_song(string* s1, string* s2, int index)
{
    return s1[index].compare(s2[index]) < 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attr_n = 0;

    attributes_map.clear();
    song_list.clear();

    getline(cin, line);
    stringstream attrs(line);
    while (getline(attrs, attributes[attr_n], ' '))
    {
        attributes_map.emplace(attributes[attr_n], attr_n);
        attr_n++;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < attr_n; j++)
        {
            cin >> songs[i][j];
        }
        song_list.push_back(songs[i]);
    }



    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        stable_sort(song_list.begin(), song_list.end(), [](string* s1, string* s2) { return less_song(s1, s2, attributes_map[command]); });

        for (int a = 0; a < attr_n - 1; a++)
            cout << attributes[a] << " ";
        cout << attributes[attr_n - 1] << "\n";

        for (int s = 0; s < m; s++)
        {
            for (int a = 0; a < attr_n - 1; a++)
                cout << song_list[s][a] << " ";
            cout << song_list[s][attr_n - 1] << "\n";
        }

        if (i != n - 1)
            cout << "\n";
    }
}

