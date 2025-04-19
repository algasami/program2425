#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[100001] = {0};

    int last = 0, lastlast = 0, lastb = 0, lastlastb = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        int optimal = 0;
        if (i > 1)
        {
            optimal = min(lastlastb + abs(lastlast - h), lastb + abs(last - h));
        }
        else if (i == 1)
        {
            optimal = lastb + abs(last - h);
        }
        lastlast = last;
        last = h;
        lastlastb = lastb;
        lastb = optimal;
    }

    cout << lastb << '\n';

    return 0;
}
