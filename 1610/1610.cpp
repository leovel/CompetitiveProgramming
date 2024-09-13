#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
using namespace std;

int n;
char names[1001][32];
char name[33];
vector<char*> name_list(1002);

int main()
{
    while (scanf("%d", &n) && n)
    {
        memset(&names, 0, sizeof names);
        memset(&name, 0, sizeof name);
        name_list.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &names[i]);
            name_list.push_back(names[i]);
        }

        sort(name_list.begin(), name_list.begin() + n, [](const char* ptr1, const char* ptr2) { return strcmp(ptr1, ptr2) < 0; });

        char* left_name = name_list[n / 2 - 1];
        char* rigth_name = name_list[n / 2];
        
        int ncl = strlen(left_name);
        int ncr = strlen(rigth_name);
        int nc = min(ncl, ncr); int i;

        for (i = 0; i < nc && left_name[i] == rigth_name[i]; i++){ }
        if (i == nc || i == ncl - 1)
        {
            printf("%s\n", left_name);
        }
        else
        {
            memcpy(name, left_name, i + 1);
            bool reset;
            do
            {
                reset = false;
                if (left_name[i] != 'Z')
                    name[i] = (char)(left_name[i] + 1);
                else
                {
                    name[i] = 'Z';
                    reset = true;
                }

                name[i + 1] = '\0';

                if (strcmp(name, rigth_name) >= 0)
                {
                    name[i] = left_name[i];
                    reset = true;
                }

                if(reset)
                    i++;

            } while (reset);
            
            i >= ncl - 1 ? printf("%s\n", left_name) : printf("%s\n", name);
        }
    }
}
