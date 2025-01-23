#include <bits/stdc++.h>

// classic 1D spatial search via binary search

using namespace std;

long int cansize[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> cansize[i];
    }
    sort(cansize, cansize + n);
    long int sum = 0;
    for (int i = 0; i < m; i++)
    {
        long int tg;
        cin >> tg;
        int l = 0, r = n;
        while (l < r - 1)
        {
            int m = (l + r) >> 1;
            // cout << l << ' ' << r << ' ' << cansize[m] << '\n';
            if (cansize[m] > tg)
            {
                r = m;
            }
            else if (cansize[m] < tg)
            {
                l = m;
            }
            else
            {
                l = r = m;
                break;
            }
        }
        long int waste = cansize[r] - tg;
        sum += waste;
    }
    cout << sum << '\n';
    return 0;
}