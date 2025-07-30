#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct {
    int id;
    int left;
    int rigth;
} soldier;

soldier attack_line[100003];

int main()
{
    int S, B;
    
    while (scanf("%d %d", &S, &B), S, B) {
        int k = B, L, R;
        for (int i = 0; i < S + 2; i++)
        {
            attack_line[i].id = i;
            attack_line[i].left = i - 1;
            attack_line[i].rigth = i + 1;
        }
        while (k--)
        {
            scanf("%d %d", &L, &R);

            soldier *left_survivor = &attack_line[attack_line[L].left];
            soldier *right_survivor = &attack_line[attack_line[R].rigth];

            left_survivor->rigth = right_survivor->id;
            right_survivor->left = left_survivor->id;

            left_survivor->id < 1 ? printf("* ") : printf("%d ", left_survivor->id);
            right_survivor->id > S ? printf("*\n") : printf("%d\n", right_survivor->id);
        }
        printf("-\n");
    }
}