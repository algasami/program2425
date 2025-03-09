#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a == 0 || b == 0 || (a <= 0 && b >= 0))
    {
        cout << "Zero\n";
        return 0;
    }

    int delta = (b < 0 ? (b + 1) : 0) - (a < 0 ? a : 0);

    if (delta & 1)
    {
        cout << "Negative\n";
    }
    else
    {
        cout << "Positive\n";
    }

    return 0;
}
