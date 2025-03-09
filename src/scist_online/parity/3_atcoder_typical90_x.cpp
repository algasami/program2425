#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int a[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long delta = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        delta += abs(a[i] - b);
    }

    if (delta <= k && ((k - delta) & 1) == 0)
    // cases where it works
    // 1. delta == k: just works
    // 2. delta < k: if the remaining actions is odd, we can pair G and G^(-1) together so it
    // cancels out.
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
