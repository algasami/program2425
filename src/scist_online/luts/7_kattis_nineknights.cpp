#include <bits/stdc++.h>
#define DEBUG
#define SZ 5
using namespace std;

bool mat[SZ][SZ] = {};
bool mov[SZ][SZ] = {};

inline bool is_oob(int ci, int cj)
{
    return ci < 0 || ci >= SZ || cj < 0 || cj >= SZ;
}

// false : OK, true : NOT OKAY
bool sub_vu(int i, int j) // helper function for validate update
{
    if (is_oob(i, j))
    {
        return false;
    }
    if (mat[i][j])
    {
        return true;
    }
    mov[i][j] = true;
    return false;
}

// false : OK, true : NOT OKAY
bool vu(int ci, int cj) // validate update
{
    // take advantage of short-circuit computation instead of return a || b || c...
    if (sub_vu(ci - 2, cj - 1) || sub_vu(ci - 1, cj - 2) || sub_vu(ci + 2, cj - 1) ||
        sub_vu(ci + 1, cj - 2) || sub_vu(ci - 2, cj + 1) || sub_vu(ci - 1, cj + 2) ||
        sub_vu(ci + 2, cj + 1) || sub_vu(ci + 1, cj + 2))
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int total = 0;

    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            if (cin.get() == '.')
            {
                continue;
            }
            mat[i][j] = true;
            if (vu(i, j) || mov[i][j])
            {
                cout << "invalid\n";
                return 0;
            }
            ++total;
        }
        cin.get(); // flush newline
    }
    if (total != 9)
    {
        cout << "invalid\n";
        return 0;
    }
    cout << "valid\n";

    return 0;
}
