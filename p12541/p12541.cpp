#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int n, dd, mm, yyyy;
char personNames[101][15];
vector<pair<int, char*>> persons(101);

int main()
{
    scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d %d", &personNames[i], &dd, &mm, &yyyy);

		persons.emplace_back(yyyy * 10000 + mm * 100 + dd, personNames[i]);
	}

	sort(persons.begin(), persons.end(), greater<pair<int, char*>>());

	printf("%s\n", persons[0].second);
	printf("%s\n", persons[n - 1].second);
}
