#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long int n, k;
    cin >> n >> k;
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }

    int sum = 1;
    long int det = k;
    while (det * det <= n)
    {
        det *= det;
        sum <<= 1;
    }
    while (det <= n)
    {
        det *= k;
        ++sum;
    }
    cout << sum << '\n';
    return 0;
}