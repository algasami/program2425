#include <bits/stdc++.h>

using namespace std;

unsigned long long psum[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    psum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        psum[i] = psum[i - 1] + x;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) // the question didn't say if a < b or not so...
        {
            swap(a, b);
        }
        cout << (psum[b] - psum[a - 1]) << '\n';
    }

    return 0;
}