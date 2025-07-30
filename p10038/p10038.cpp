#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

typedef vector<int> vi;


int main()
{
    int N;
    vi sequence; sequence.reserve(3001);
    bitset<3001> used_values;
    while (scanf("%d", &N) != EOF) {
        sequence.clear();
        int k = N, v;
        while (k--) { scanf("%d", &v); sequence.push_back(v); }

        bool jolly = true;
        if(N == 0)
            jolly = false;
        else if(N == 1)
            jolly = true;
        else
        {
            used_values.reset();
            for (int i = 0; i < N - 1; i++)
            {
                int diff = abs(sequence[i + 1] - sequence[i]);
                if(diff == 0 || diff >= N || used_values.test(diff))
                {
                    jolly = false;
                    break;
                }
                used_values.set(diff);
            }
        }

        printf(jolly ? "Jolly\n" : "Not jolly\n");
    }
}