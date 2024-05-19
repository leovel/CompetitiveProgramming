#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

string N, M, before_dot = "", after_dot = "";
bool zeros;

int main()
{

    while (cin >> N)
    {
        cin >> M;

        before_dot.clear();
        after_dot.clear();

        zeros = false;
        auto c = N.rbegin();
        for (auto d = M.rbegin(); d != M.rend(); d++)
        {
            
            if (*d != '1')
            {
                zeros = true;
                if (c != N.rend())
                {
                    after_dot += *c;
                    c++;
                }
                else
                {
                    after_dot += '0';
                }
            }
        }

        if (zeros)
        {
            if (c == N.rend())
            {
                cout << '0';
            }
            else
            {
                while (c != N.rend())
                {
                    before_dot += *c;
                    c++;
                }

                for (auto d = before_dot.rbegin(); d != before_dot.rend(); d++)
                    cout << *d;
            }

            auto tz = after_dot.begin();
            while (tz != after_dot.end() && *tz == '0')
                tz++;

            if (tz != after_dot.end())
            {
                cout << '.';
                for (auto d = after_dot.rbegin(); d.base() > tz; d++)
                    cout << *d;
            }
        }
        else
            cout << N;

        cout << '\n';
    }
}
