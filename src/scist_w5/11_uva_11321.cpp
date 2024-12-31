#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            cout << "0 0\n";
            break;
        }
        vector<int> vec;
        vec.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        // pass int is faster than reference
        sort(vec.begin(), vec.end(), [](int a, int b) {
            int am = a % m, bm = b % m;
            if (am != bm)
            {
                return am < bm;
            }
            bool ao = a & 1, bo = b & 1;
            if (ao != bo)
            {
                return ao;
            }
            if (ao)
            {
                return a > b;
            }
            return a < b;
        });
        cout << n << ' ' << m << '\n';
        for (int x : vec)
        {
            cout << x << '\n';
        }
    }

    return 0;
}