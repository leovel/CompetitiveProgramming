#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <unordered_map>

using namespace std;

int n, r, s;
char code[51], guess[51];
unordered_map<char, int> code_not_r, guess_not_r;
int main()
{
    while(scanf("%d %s %s", &n, &code, &guess) != EOF)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            code_not_r[c] = 0;
            guess_not_r[c] = 0;
        }

        r = 0; s = 0;
        for (int i = 0; i < n; i++)
        {
            if (code[i] == guess[i])
                r++;
            else
            {
                code_not_r[code[i]] = code_not_r[code[i]] + 1;
                guess_not_r[guess[i]] = guess_not_r[guess[i]] + 1;
            }
        }

        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (code_not_r[c] > 0 && guess_not_r[c] > 0)
                s += min(code_not_r[c], guess_not_r[c]);
        }

        printf("%d %d\n", r, s);
    }
}

