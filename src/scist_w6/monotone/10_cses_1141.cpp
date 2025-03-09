#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// ! 100% identical to fifth...

int a[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> uset;
    int blen = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (uset.find(a[i]) != uset.end() && j < i)
        {
            uset.erase(a[j++]);
        }
        uset.insert(a[i]);

        if (blen < (i - j + 1))
        {
            blen = i - j + 1;
        }
    }

    cout << blen << '\n';

    return 0;
}
