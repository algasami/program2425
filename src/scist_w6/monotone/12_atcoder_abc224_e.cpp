#include <bits/stdc++.h>
#define DEBUG
using namespace std;

#define MAXVAL 200000

int h, w, n;

struct tup
{
    int i, j, p;
};
map<int, vector<tup>, greater<int>> inc_points;

// build the max value from biggest to smallest point
// every new inc_point is the current minimum
// iterate through with dynamic programming, updating row and col
int row_max[MAXVAL] = {}, col_max[MAXVAL] = {}, p_max[MAXVAL] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w >> n;

    for (int p = 0; p < n; p++)
    {
        int i, j, a;
        cin >> i >> j >> a;
        inc_points[a].emplace_back(tup{i, j, p});
    }

    //
    for (auto const &p : inc_points)
    {
        for (auto const &coord : p.second)
        {
            // if i do this in the next for-loop, this will interfere with
            // other points with the same p
            p_max[coord.p] = max(row_max[coord.i], col_max[coord.j]);
        }
        for (auto const &coord : p.second)
        {
            int nval = p_max[coord.p] + 1;
            // keep finding maximum among all the points with weight a
            if (row_max[coord.i] < nval)
            {
                row_max[coord.i] = nval;
            }
            if (col_max[coord.j] < nval)
            {
                col_max[coord.j] = nval;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << p_max[i] << '\n';
    }

    return 0;
}
