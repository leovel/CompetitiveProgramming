#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

using namespace std;

int T, l, Y;
char S[52];

int main()
{
    scanf("%d", &T);

    for (int X = 1; X <= T; X++)
    {
        scanf("%s", &S);
        l = strlen(S); Y = 0;

        for (int i = 0; i < l; i++)
        {
            if(S[i] == '-' &&
                (i - 1 < 0 || S[i - 1] != 'S') &&
                (i + 1 >= l || (S[i + 1] != 'S' && S[i + 1] != 'B')) &&
                (i + 2 >= l || (S[i + 2] != 'B')))
            {
                Y++;
            }
        }

        printf("Case %d: %d\n", X, Y);
    }
}
