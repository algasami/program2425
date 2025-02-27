#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string c;
    c.reserve(3);
    int a, b;
    cin >> a >> b >> c;

    if (c[0] == '0')
    {
        cout << "0\n";
        return 0;
    }

    int base10 = 0;

    for (char ch : c)
    {
        // assume ch is digit
        base10 *= a;
        base10 += ch - '0';
    }

    string buf;
    buf.reserve(9);

    while (base10 > 0)
    {
        buf += (base10 % b) + '0';
        base10 /= b;
    }
    reverse(buf.begin(), buf.end());
    cout << buf << '\n';

    return 0;
}