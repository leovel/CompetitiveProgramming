#include <bits/stdc++.h>
using namespace std;

int n;
string results[9]{
    " was preserved.\n",
    " was rotated 90 degrees.\n",
    " was rotated 180 degrees.\n",
    " was rotated 270 degrees.\n",
    " was reflected vertically.\n",
    " was reflected vertically and rotated 90 degrees.\n",
    " was reflected vertically and rotated 180 degrees.\n",
    " was reflected vertically and rotated 270 degrees.\n",
    " was improperly transformed.\n"};
string original_line, transformed_line;

static void rotate90Clockwise(char** mat, int& N)
{
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = temp;
        }
    }
}

static void verticalReflection(char** mat, int& N)
{
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[N - i - 1][j];
            mat[N - i - 1][j] = temp;
        }
    }
}

static bool compare_matrix(char** original, char** transformed, int& N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (original[i][j] != transformed[i][j])
                return false;
        }
    }
    return true;
}

static int check_matrix(char** original, char** transformed, int& N)
{
    int op = 0;

    while (!compare_matrix(original, transformed, N) && op < 8)
    {
        op++;
        rotate90Clockwise(original, N);
        if (op == 4)
            verticalReflection(original, N);
    }

    return op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nro = 0;
    while (cin >> n)
    {
        char** first_mat = new char*[n];
        char** second_mat = new char*[n];
        
        for (int i = 0; i < n; i++)
        {
            first_mat[i] = new char[n + 1];
            second_mat[i] = new char[n + 1];
            cin >> first_mat[i] >> second_mat[i];
        }
            

        int op = check_matrix(first_mat, second_mat, n);

        cout << "Pattern " << ++nro <<  results[op];
    }
}

