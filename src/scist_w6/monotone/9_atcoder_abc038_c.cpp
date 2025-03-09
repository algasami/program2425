#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// ! almost a hundred percent identical to fifth

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int last;
    cin >> last;

    long long wgap = 1;
    long long subs = n;
    for (int i = 1; i < n; i++, wgap++)
    {
        int v;
        cin >> v;
        if (v <= last)
        {
            subs += wgap * (wgap - 1) / 2;
            wgap = 0;
        }
        last = v;
    }
    subs += wgap * (wgap - 1) / 2;
    cout << subs << '\n';

    return 0;
}
