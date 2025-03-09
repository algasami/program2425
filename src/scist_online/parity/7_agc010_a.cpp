#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// 1. erase two odds, make one even
// 2. erase two even, make one even
// observe: as long as there are only even number of odds, we can reduce blackboard into one single
// even number
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n; // n >= 2
    int onum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            ++onum;
        }
    }
    if (onum & 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return 0;
}
