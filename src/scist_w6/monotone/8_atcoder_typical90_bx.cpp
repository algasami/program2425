#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// ! This one's also identical to the fifth question

int a[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    long long tsum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tsum += a[i];
    }
    if (tsum % 10)
    {
        cout << "No\n";
        return 0;
    }
    tsum /= 10;

    long long accu = 0;
    for (int i = 0, j = 0; i < min(2 * n, n + j) && j <= i; i++)
    {
        accu += a[i % n];
        // keep two indices
        // if accumulated is bigger than x, we sub tail becaues of monotonous quality
        while (accu > tsum)
            accu -= a[j++ % n];
        // cout << i << ' ' << j << ' ' << accu << '\n';
        if (accu == tsum)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}
