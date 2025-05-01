#include <bits/stdc++.h>
#define DEBUG
using namespace std;

typedef pair<int, int> coord;

int colors[2002][2002] = {};

map<coord, coord> parents;
// use map bc unordered_map is not guaranteed to be
// fast at serialized data

coord find_root(coord const &from)
{
    if (parents[from] == from)
    {
        return from;
    }
    return parents[from] = find_root(parents[from]);
}

void union_grid(coord const &a, coord const &b)
{
    coord r1 = find_root(a);
    coord r2 = find_root(b);
    if (r1 == r2)
    {
        return;
    }
    parents[r1] = r2;
}

int h, w, q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w >> q;

    // initialize disjoint

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            coord cd = make_pair(i, j);
            parents[cd] = cd;
        }

    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, j;
            cin >> i >> j;
            colors[i][j] = 1; // i >= 1, j>=1 so no OOB issue
            coord c = make_pair(i, j);
            if (colors[i - 1][j])
            {
                union_grid(c, make_pair(i - 1, j));
            }
            if (colors[i][j - 1])
            {
                union_grid(c, make_pair(i, j - 1));
            }
            if (colors[i + 1][j])
            {
                union_grid(c, make_pair(i + 1, j));
            }
            if (colors[i][j + 1])
            {
                union_grid(c, make_pair(i, j + 1));
            }
        }
        else if (t == 2)
        {
            int ai, aj, bi, bj;
            cin >> ai >> aj >> bi >> bj;
            if (!colors[ai][aj] || !colors[bi][bj])
            {
                cout << "No\n";
                continue;
            }
            cout << (find_root(make_pair(ai, aj)) == find_root(make_pair(bi, bj)) ? "Yes\n"
                                                                                  : "No\n");
        }
    }

    return 0;
}
