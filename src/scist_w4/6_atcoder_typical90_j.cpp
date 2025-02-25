#include <bits/stdc++.h>

using namespace std;

int psums[2][100002] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, p;
        cin >> c >> p;
        psums[c - 1][i] += p;
        psums[0][i + 1] = psums[0][i];
        psums[1][i + 1] = psums[1][i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << (psums[0][r] - psums[0][l - 1]) << ' ' << (psums[1][r] - psums[1][l - 1]) << '\n';
    }

    return 0;
}