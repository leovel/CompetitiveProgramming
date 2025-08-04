#include <stdio.h>

int main() {
    int t, cases = 0, n, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int h[10000], w[10000];
        int dp1[10000], dp2[10000];
        for (i = 0; i < n; i++)
            scanf("%d", &h[i]);
        for (i = 0; i < n; i++) {
            scanf("%d", &w[i]);
            dp1[i] = dp2[i] = w[i];
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (h[i] < h[j] && dp1[i] + w[j] > dp1[j]) {
                    dp1[j] = dp1[i] + w[j];
                }
                if (h[i] > h[j] && dp2[i] + w[j] > dp2[j]) {
                    dp2[j] = dp2[i] + w[j];
                }
            }
        }
        int ans1 = 0, ans2 = 0;
        for (i = 0; i < n; i++) {
            if (dp1[i] > ans1)   ans1 = dp1[i];
            if (dp2[i] > ans2)   ans2 = dp2[i];
        }
        if (ans2 <= ans1)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++cases, ans1, ans2);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++cases, ans2, ans1);
    }
    return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main(void)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int testCases;
//	cin >> testCases;
//
//	for (int t = 1; t <= testCases; ++t)
//	{
//		int n;
//		cin >> n;
//
//		vector<int> lis(n);
//		vector<int> lds(n);
//		vector<int> width(n);
//		vector<int> height(n);
//
//		for (int i = 0; i < n; ++i)
//			cin >> height[i];
//		for (int i = 0; i < n; ++i)
//			cin >> width[i];
//
//		int maxWidthIncreasing = 0;
//		int maxWidthDecreasing = 0;
//
//		for (int i = 0; i < n; ++i)
//		{
//			int w = width[i];
//			lis[i] = w;
//			lds[i] = w;
//
//			for (int j = 0; j < i; ++j)
//			{
//				if (height[j] < height[i])
//					lis[i] = max(lis[i], lis[j] + w);
//				if (height[i] < height[j])
//					lds[i] = max(lds[i], lds[j] + w);
//			}
//
//			maxWidthIncreasing = max(maxWidthIncreasing, lis[i]);
//			maxWidthDecreasing = max(maxWidthDecreasing, lds[i]);
//		}
//
//		if (maxWidthDecreasing <= maxWidthIncreasing)
//			cout << "Case " << t << ". Increasing (" << maxWidthIncreasing << "). Decreasing (" << maxWidthDecreasing << ").\n";
//		else
//			cout << "Case " << t << ". Decreasing (" << maxWidthDecreasing << "). Increasing (" << maxWidthIncreasing << ").\n";
//	}
//
//	return 0;
//}