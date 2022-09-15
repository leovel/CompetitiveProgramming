#define _CRT_SECURE_NO_DEPRECATE
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, Mx, My, Lx, Ly, NP, Px, Py;
vii massetoPath, leoporelloPath;

int main()
{
    massetoPath.reserve(1000001);
    leoporelloPath.reserve(1000001);

    scanf("%d", &N);
    
    while(N--)
    {
        scanf("\n%d %d", &Mx, &My);
        scanf("%d %d", &Lx, &Ly);

        massetoPath.push_back(make_pair(Mx, My));
        leoporelloPath.push_back(make_pair(Lx, Ly));

        scanf("%d", &NP);
        while (NP--)
        {
            scanf("%d %d", &Px, &Py);
            ii lastCorner = leoporelloPath.back();

            if (Px == lastCorner.first)
            {
                int step = lastCorner.second < Py ? 1 : lastCorner.second > Py ? -1 : 0;
                for (int y = lastCorner.second + step; step != 0 && y != Py; y += step)
                {
                    leoporelloPath.push_back(make_pair(Px, y));
                }
            }
            else if (Py == lastCorner.second)
            {
                int step = lastCorner.first < Px ? 1 : lastCorner.first > Px ? -1 : 0;
                for (int x = lastCorner.first + step; step != 0 && x != Px; x += step)
                {
                    leoporelloPath.push_back(make_pair(x, Py));
                }
            }

            leoporelloPath.push_back(make_pair(Px, Py));
        }

        scanf("%d", &NP);
        while (NP--)
        {
            scanf("%d %d", &Px, &Py);
            ii lastCorner = massetoPath.back();

            if (Px == lastCorner.first)
            {
                int step = lastCorner.second < Py ? 1 : lastCorner.second > Py ? -1 : 0;
                for (int y = lastCorner.second + step; step != 0 && y != Py; y += step)
                {
                    massetoPath.push_back(make_pair(Px, y));
                }
            }
            else if (Py == lastCorner.second)
            {
                int step = lastCorner.first < Px ? 1 : lastCorner.first > Px ? -1 : 0;
                for (int x = lastCorner.first + step; step != 0 && x != Px; x += step)
                {
                    massetoPath.push_back(make_pair(x, Py));
                }
            }

            massetoPath.push_back(make_pair(Px, Py));
        }

        bool secure = true;
        for (size_t i = 0; i < min(leoporelloPath.size(), massetoPath.size()) && secure; i++)
        {
            if(leoporelloPath[i] == massetoPath[i] && i != leoporelloPath.size() - 1)
            {
                secure = false;
            }
        }

        printf(secure ? "Yes\n" : "No\n");
        if(N) printf("\n");

        massetoPath.clear();
        leoporelloPath.clear();
    }
}
