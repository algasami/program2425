#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    s.reserve(100);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        long int sum = 0, current = 0;
        for (char c : s)
        {
            if (c == ',')
            {
                sum *= 60;
                sum += current;
                current = 0;
                continue;
            }
            current *= 10;
            current += c - '0';
        }
        sum *= 60;
        sum += current;
        cout << sum << '\n';
    }
    return 0;
}