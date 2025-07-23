#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int pieces[6];
bool print_list;

int main()
{
	for (int i = 0; i < 5; i++)
		scanf("%d", &pieces[i]);

	do
	{
		print_list = false;
		for (int i = 0; i < 4; i++)
		{
			if (pieces[i] > pieces[i + 1])
			{
				swap(pieces[i], pieces[i + 1]);
				printf("%d %d %d %d %d\n", pieces[0], pieces[1], pieces[2], pieces[3], pieces[4]);
				print_list = true;
			}
		}
	} while (print_list);
}
