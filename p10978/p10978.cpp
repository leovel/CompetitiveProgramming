#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>

using namespace std;

int N;
char card[3], text[21], arrangement[53][3];

int main()
{
    while (scanf("%d", &N), N) {
        int pos = -1, tl;
        memset(&arrangement, 0, sizeof(arrangement));

        for (int i = 0; i < N; i++)
        {
            scanf("%s %s", card, text);
            tl = strlen(text);
            do
            {
                pos = (pos + 1) % N;
                if (strlen(arrangement[pos]) == 0)
                    tl--;

            } while (tl);

            memcpy(&arrangement[pos], &card, sizeof(card));
            
        }

        for (int i = 0; i < N; i++)
        {
            printf(i == 0 ? "%s" : " %s", arrangement[i]);
        }
        printf("\n");
    }
}