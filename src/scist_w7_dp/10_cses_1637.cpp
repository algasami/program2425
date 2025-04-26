#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int p = 0;

    while (n > 0)
    {
        int maxdig = 0;
        int k = n;
        do
        {
            maxdig = max(k % 10, maxdig);
        } while (k /= 10);
        n -= maxdig;
        ++p;
    }

    cout << p << '\n';

    return 0;
}
