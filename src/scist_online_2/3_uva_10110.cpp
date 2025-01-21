#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        unsigned int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        // a perfect square number's distinct factors must be divisible by 2
        unsigned int st = round(sqrt(N));
        if (st * st == N)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}