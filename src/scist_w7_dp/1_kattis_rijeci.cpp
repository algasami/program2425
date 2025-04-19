#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    int a_c = 1, b_c = 0;

    for (int i = 0; i < k; i++)
    {
        int tmp = b_c;
        b_c += a_c;
        a_c = tmp;
    }

    cout << a_c << ' ' << b_c << '\n';

    return 0;
}
