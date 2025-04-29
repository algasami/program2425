#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

constexpr int NMASK = 1;
constexpr int SMASK = 2;
constexpr int BMASK = NMASK | SMASK;

int tiles[1001][2] = {};

inline int get_mask(char c)
{
    return c == 'N' ? NMASK : (c == 'S' ? SMASK : BMASK);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    int n = static_cast<int>(str.size());
    tiles[0][0] = 0;
    tiles[0][1] = INT_MAX - 2;

    // skip first row since it's already determined
    for (int i = 1; i <= n; i++)
    {
        int mask = get_mask(str.at(i - 1));
        for (int j = 0; j < 2; j++)
        {
            int candidate = INT_MAX;
            if (mask & (1 << j)) // connected here
                candidate = min(candidate, tiles[i - 1][j] + 1);
            else // not here
                candidate = min(candidate, tiles[i - 1][j]);
            // how about move across the streets?
            int cmpl = !j;
            if (mask != BMASK)
                candidate = min(candidate, tiles[i - 1][cmpl] + 1);
            else
                candidate = min(candidate, tiles[i - 1][cmpl] + 2);
            tiles[i][j] = candidate;
        }
    }
#ifdef DEBUG
    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << tiles[i][j] << "\t";
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        cout << str.at(i) << '\t';
    }
    cout << '\n';
#endif

    cout << tiles[n][0] << '\n';

    return 0;
}
