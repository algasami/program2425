#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int xs[200000], outs[200000] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }

    stack<pair<int, int>> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        int elem = xs[i];
        while (!stk.empty() && stk.top().first > elem)
        {
            outs[stk.top().second] = i + 1;
            stk.pop();
        }

        stk.emplace(make_pair(elem, i));
    }
    for (int i = 0, f = 1; i < n; i++)
    {
        if (f)
            f = 0;
        else
            cout << ' ';
        cout << outs[i];
    }
    cout << '\n';

    return 0;
}
