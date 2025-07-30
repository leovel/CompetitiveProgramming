#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <bitset>
#include <unordered_set>
#include <vector>

using namespace std;

string line, binary, empty_line;
int T;
bitset<9> bs[2], *g, *fg;

unordered_set<unsigned long> memo;
vector<unsigned long> history;

int main()
{
    cin >> T;
    size_t pos{};
    while (T--)
    {
        binary.clear();
        bs[0].reset(); bs[1].reset();
        memo.clear();
        history.clear();

        cin >> line;
        binary.append(line);
        cin >> line;
        binary.append(line);
        cin >> line;
        binary.append(line);

        bs[0] |= stoi(binary, &pos, 2);

        g = &bs[1]; fg = &bs[0];

        
        unsigned long lastfg;
        while (memo.count(lastfg = fg->to_ulong()) == 0)
        {
            memo.insert(lastfg);
            history.push_back(lastfg);

            swap(fg, g);
            fg->reset();

            (*fg)[0] = (*g)[1] ^ (*g)[3];
            (*fg)[1] = (*g)[0] ^ (*g)[2] ^ (*g)[4];
            (*fg)[2] = (*g)[1] ^ (*g)[5];
            (*fg)[3] = (*g)[0] ^ (*g)[4] ^ (*g)[6];
            (*fg)[4] = (*g)[1] ^ (*g)[3] ^ (*g)[5] ^ (*g)[7];
            (*fg)[5] = (*g)[2] ^ (*g)[4] ^ (*g)[8];
            (*fg)[6] = (*g)[3] ^ (*g)[7];
            (*fg)[7] = (*g)[4] ^ (*g)[6] ^ (*g)[8];
            (*fg)[8] = (*g)[5] ^ (*g)[7];
        }

        for (int i = 0; i < history.size(); i++)
        {
            if (history[i] == lastfg)
            {
                cout << i - 1 << endl;
                break;
            }
        }
    }
}
