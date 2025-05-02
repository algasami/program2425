#include <bits/stdc++.h>
#define DEBUG
using namespace std;

constexpr int BASIS = 500000;

int n, m, k;

int get_id(int i, int j)
{
    return i * m + j;
}

int parent[BASIS + 30] = {};

int get_root(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = get_root(parent[x]);
}

void unionize(int a, int b)
{
    a = get_root(a);
    b = get_root(b);

    if (a == b)
    {
        return;
    }
    parent[a] = b;
}

// traditional disjoint color

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int id = get_id(i, j);
            parent[id] = id;
        }
    }

    for (int i = 0; i <= k; i++)
    {
        parent[BASIS + i] = BASIS + i;
    }

    cin.get(); // flush
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = cin.get();
            unionize(get_id(i, j), BASIS + c - 'A');
        }
        cin.get(); // flush
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            unionize(get_id(i, j), get_id(i + 1, j));
        }
    }
    int count = 1, cur = get_root(get_id(0, 0));
    unordered_set<int> collector;
    for (int j = 0; j < m; j++)
    {
        collector.insert(get_root(get_id(0, j)));
    }

    cout << collector.size() << '\n';

    return 0;
}
