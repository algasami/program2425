#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// these questions can be solved by representing the basic atomic
// actions in the solution instead of the state space.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if ((a * b) % 2)
    {
        cout << "Beata";
    }
    else
    {
        cout << "Alf";
    }
    cout << '\n';

    return 0;
}
