#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n, t, m, time, teamID;
char problem[2], verdict[4];
unordered_map<char, pair<int, int>> last_blood;
unordered_map<char, unordered_set<int>> accepted;
pair<int, int> *time_team;

int main()
{
	for (char p = 'A'; p <= 'L'; p++)
		last_blood[p] = { -1, -1 };

	scanf("%d %d %d", &n, &t, &m);

	while (m--)
	{
		scanf("%d %d %s %s", &time, &teamID, &problem, &verdict);
		if (verdict[0] == 'Y' && accepted[problem[0]].count(teamID) == 0)
		{
			accepted[problem[0]].insert(teamID);
			time_team = &last_blood[problem[0]];
			if (time_team->first <= time)
			{
				time_team->first = time;
				time_team->second = teamID;
			}
		}
	}

	char p = 'A';
	for (int i = 0; i < n; i++, p++)
	{
		time_team = &last_blood[p];
		if(time_team->first >= 0)
			printf("%c %d %d\n", p, time_team->first, time_team->second);
		else
			printf("%c - -\n", p);
	}
}
