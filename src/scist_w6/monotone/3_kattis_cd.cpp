#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int a[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (1)
    {
        int n, m, ovl = 0;
        cin >> n >> m;
        if (!n || !m)
        {
            break;
        }
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0, j = 0; i < m; i++)
        {
            int x;
            cin >> x;
            while (a[j] < x) // monotone, if a[j] > x then everything after it is also bigger
                ++j;
            if (a[j] == x)
            {
                ovl++;
            }
        }
        cout << ovl << '\n';
    }
    return 0;
}
