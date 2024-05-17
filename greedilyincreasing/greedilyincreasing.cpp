#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N, a, ai, lenght;
vi gis;

int main()
{
    gis.reserve(100002);
    while (scanf("%d", &N) != EOF) {        
        a = -1;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &ai);

            if (ai > a)
            {
                gis.push_back(ai);
                a = ai;
            }
        }

        lenght = gis.size();
        printf("%d\n", lenght);
        for (int i = 0; i < lenght; i++)
        {
            printf(i == 0 ? "%d" : " %d", gis[i]);
        }
        printf("\n");

        gis.clear();
    }
}