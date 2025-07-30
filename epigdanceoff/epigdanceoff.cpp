#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <bitset>

using namespace std;

int N, M, qtd;
bitset<2001> mask;
char line[2001];

int main()
{
    while (scanf("%d %d", &N, &M) != EOF)
    {
        mask.reset();
        qtd = 1;

        while(N--)
        {
            scanf("%s", &line);

            for (size_t i = 0; i < M; i++)
            {
                if (line[i] == '$')
                {
                    mask.set(i);
                }
            }
        }

        printf("%d\n", M - mask.count() + 1);
    }
}
