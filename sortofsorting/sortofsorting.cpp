#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
unordered_map<char, int> dict(54);
char last_names[201][22];
vector<char*> last_names_list(201);
int n;


bool comp_str(const char* ptr1, const char* ptr2)
{
    int n1 = strlen(ptr1);
    int n2 = strlen(ptr2);
    int n = min(2, min(n1, n2));

    for (int i = 0; i < n; i++)
    {
        if (dict[ptr1[i]] == dict[ptr2[i]])
            continue;

        if (dict[ptr1[i]] < dict[ptr2[i]])
            return true;
        else
            return false;
    }

    return false;

}

int main()
{
    dict.clear();
	for (int i = 0; i < 52; i++)
		dict.emplace(alphabet[i], i);

    while (scanf("%d", &n) && n)
    {
        memset(&last_names, 0, sizeof(last_names));
        last_names_list.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &last_names[i]);
            last_names_list.push_back(last_names[i]);
        }
            

        stable_sort(last_names_list.begin(), last_names_list.begin() + n, comp_str);

        for (int i = 0; i < n; i++)
            printf("%s\n", last_names_list[i]);
        printf("\n");
        
    }
}
