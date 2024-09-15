#include <bits/stdc++.h>
using namespace std;

int T, n;
string person, pclass, sep = "-", middle = "middle", dummy;
vector<vector<string>> classes;


vector<string> split(string s, const string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

static bool highest_class(vector<string> c1n, vector<string> c2n)
{
    int l1 = c1n.size();
    int l2 = c2n.size();

    for (int i = 2; i < 12; i++)
    {
        string t1 = l1 - i < 0 ? middle : c1n[l1 - i];
        string t2 = l2 - i < 0 ? middle : c2n[l2 - i];

        if (t1.compare(t2) == 0)
            continue;

        return t1.compare(t2) > 0;
    }

    return c1n[l1 - 1].compare(c2n[l2 - 1]) < 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> n;
        classes.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> person >> pclass >> dummy;
            classes.push_back(split(pclass, sep));
            classes.back().push_back(person.substr(0, person.size() - 1));
        }

        sort(classes.begin(), classes.end(), highest_class);

        for (int i = 0; i < n; i++)
        {
            cout << classes[i].back() << "\n";
        }
        cout << "==============================" << "\n";
    }
}
