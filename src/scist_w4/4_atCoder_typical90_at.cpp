#include <bits/stdc++.h>

#define MD 46

using namespace std;

typedef unsigned long long ull;

int N;
int a[MD], b[MD], c[MD];

inline void pc(int buffer[])
{
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        ++buffer[x % MD];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    pc(a);
    pc(b);
    pc(c);

    ull sum = 0;

    // (a + b + c) mod 46 = 0
    // c mod 46 = (-a -b) mod 46
    // assume c >= 0
    for (int ai = 0; ai < MD; ai++)
    {
        if (!a[ai])
            continue;
        for (int bi = 0; bi < MD; bi++)
        {
            if (!b[bi])
                continue;
            int ci = -((ai + bi) % MD);
            if (ci < 0)
            {
                ci += MD;
            }
            sum += static_cast<ull>(a[ai]) * static_cast<ull>(b[bi]) * static_cast<ull>(c[ci]);
            // sum += a[ai] * b[bi] * c[ci]; // doesn't work because of overflow
            // it doesn't perform implicit conversion!!
        }
    }
    cout << sum << '\n';

    return 0;
}