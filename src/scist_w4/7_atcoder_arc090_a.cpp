#include <bits/stdc++.h>

using namespace std;

int mat[2][100] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // first row
    for (int i = 1; i < n; i++)
    {
        mat[0][i] += mat[0][i - 1];
    }
    // second row
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            // first
            mat[1][i] += mat[0][i];
            continue;
        }
        // compare left and top
        mat[1][i] += max(mat[1][i - 1], mat[0][i]);
    }
    cout << mat[1][n - 1] << '\n';

    return 0;
}