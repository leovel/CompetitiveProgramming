#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

using namespace std;

int popped[1000002], N, Hi, shoots;

int main()
{
    while (scanf("%d", &N) != EOF) {
        shoots = 0;
        memset(&popped, 0, sizeof(popped));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &Hi);

            popped[Hi]++;

            if (popped[Hi + 1] < 1)
            {
                shoots++;
            }
            else
                popped[Hi + 1]--;
        }
        printf("%d\n", shoots);
    }
}