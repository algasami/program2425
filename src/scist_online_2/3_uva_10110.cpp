#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<unsigned int, int> bkt;
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
        int odd = 0;
        unsigned int i = 1;
        unsigned int sn = sqrt(N);
        for (auto iter = bkt.rbegin(); iter != bkt.rend(); iter++)
        {
            if (iter->first < sn)
            {
                i = iter->first + 1;
                odd = iter->second;
                break;
            }
        }
        for (; i <= sn; i++)
        {
            if (N % i == 0)
            {
                odd = !odd;
            }
        }
        bkt[N] = odd;
        if (odd)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }
    return 0;
}