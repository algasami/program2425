#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

int a[200001], b[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << ' ';
    }
    cout << '\n';
#endif

    int i = 0, j = 0, diff = INT_MAX;
    while (i < n && j < m)
    {
        int d = abs(a[i] - b[j]);
        if (d < diff)
        {
            diff = d;
        }
        if (a[i] > b[j])
        {
            j++; // we try to make them as close as possible
            // since both are sorted
        }
        else
        {
            i++; // same reasoning as above
        }
    }
    cout << diff << '\n';

    return 0;
}
