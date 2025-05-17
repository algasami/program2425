#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int n;

map<string, int> pool;

int parents[200000] = {}, union_size[200000] = {};

int get_root(int x)
{
    if (parents[x] == x)
    {
        return x;
    }

    return parents[x] = get_root(parents[x]);
}

int unionize(int a, int b)
{
    a = get_root(a);
    b = get_root(b);

    if (a == b)
    {
        return a;
    }
    union_size[b] += union_size[a];
    return parents[a] = b;
}

int gid(string const &str)
{
    if (!pool.count(str))
    {
        int val = static_cast<int>(pool.size());
        pool[str] = val;
        parents[val] = val;
        union_size[val] = 1;
    }
    return pool[str];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string b1, b2;
        cin >> b1 >> b2;

        int a = gid(b1), b = gid(b2);

        int nroot = unionize(a, b);
        cout << union_size[nroot] << '\n';
    }

    return 0;
}
