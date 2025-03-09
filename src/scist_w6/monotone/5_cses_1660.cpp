#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int a[200000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long v = 0, accu = 0;
    for (int i = 0, j = 0; i < n && j <= i; i++)
    {
        accu += a[i];
        // keep two indices
        // if accumulated is bigger than x, we sub tail becaues of monotonous quality
        while (accu > x)
            accu -= a[j++];
        if (accu == x)
        {
            ++v;
        }
    }
    cout << v << '\n';

    return 0;
}
