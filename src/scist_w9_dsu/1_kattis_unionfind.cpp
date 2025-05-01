#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int parents[1000000];

int find_set(int);
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parents[b] = a;
    }
}

int find_set(int v)
{
    if (v == parents[v])
        return v;
    return parents[v] = find_set(parents[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < q; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '=')
        {
            union_sets(a, b);
        }
        else if (c == '?')
        {
            cout << (find_set(a) == find_set(b) ? "yes\n" : "no\n");
        }
    }

    return 0;
}
