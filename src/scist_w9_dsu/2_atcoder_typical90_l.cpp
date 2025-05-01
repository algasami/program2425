#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int h, w, q;
int colors[2002][2002] = {};

int parents[4000004];

int get_id(int i, int j)
{
    return i * w + j;
}

int find_root(int from)
{
    if (parents[from] == from)
    {
        return from;
    }
    return parents[from] = find_root(parents[from]);
}

void union_grid(int a, int b)
{
    int r1 = find_root(a);
    int r2 = find_root(b);
    if (r1 == r2)
    {
        return;
    }
    parents[r1] = r2;
}

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
            int id = get_id(i, j);
            parents[id] = id;
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
            int c = get_id(i, j);
            if (colors[i - 1][j])
            {
                union_grid(c, get_id(i - 1, j));
            }
            if (colors[i][j - 1])
            {
                union_grid(c, get_id(i, j - 1));
            }
            if (colors[i + 1][j])
            {
                union_grid(c, get_id(i + 1, j));
            }
            if (colors[i][j + 1])
            {
                union_grid(c, get_id(i, j + 1));
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
            cout << (find_root(get_id(ai, aj)) == find_root(get_id(bi, bj)) ? "Yes\n" : "No\n");
        }
    }

    return 0;
}
