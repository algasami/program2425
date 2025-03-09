#include <bits/stdc++.h>
#define DEBUG
using namespace std;

long long a[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }

    long long v = 0;
    for (int i = 0; i < n; i++) // smallest of the array
    {
        long long *pos = lower_bound(a + i + 1, a + n + 1, a[i] + x); // pre sum is monotonic
        if (pos != a + n + 1)
        {
            v += n + 1 - (pos - a);
        }
    }
    cout << v << '\n';

    return 0;
}
