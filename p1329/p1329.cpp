#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi p, setLength;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        setLength.assign(N, 0);
    }

    int lengthOfSet(int i) { return p[i] == i ? 0 : setLength[i] + lengthOfSet(p[i]); }

    void unionSet(int i, int j) {
        p[i] = j; 
        setLength[i] += abs(i - j) % 1000;
    }
};

int T, N, I, J;
char command[2];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        UnionFind UF(N);

        while (scanf("%s", &command), command[0] != 'O')
        {
            if (command[0] == 'E')
            {
                scanf("%d", &I);
                printf("%d\n", UF.lengthOfSet(I - 1));
            }
            else
            {
                scanf("%d %d", &I, &J);
                UF.unionSet(I - 1, J - 1);
            }
        }
    }
}

