#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

int N;
vi sequence, lis_len, lds_len;

void LIS(vi &len_data)
{

    int k = 0;
    vi L(N, 0);

    for (int i = 0; i < N; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, sequence[i]) - L.begin();
        L[pos] = sequence[i];
        
        if (pos == k) {
            k = pos + 1;
        }

        len_data[i] = pos + 1;
    }
}


int main()
{
    while(scanf("%d", &N) != EOF)
    {
		sequence.resize(N);
		lis_len.resize(N);
		lds_len.resize(N);

        for (int i = 0; i < N; i++)
			scanf("%d", &sequence[i]);

		LIS(lis_len);
		reverse(sequence.begin(), sequence.end());
		LIS(lds_len);

        int max_wavio = 1;
        for (int i = 0; i < N; i++)
        {
            int lowest = min(lis_len[i], lds_len[N - i - 1]);
            max_wavio = max(max_wavio, lowest * 2 - 1);
        }

        printf("%d\n", max_wavio);
    }
    return 0;
}