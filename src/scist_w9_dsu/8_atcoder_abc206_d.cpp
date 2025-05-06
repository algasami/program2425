#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int parents[200001];
int arr[200001];

int groot(int n)
{
    if (parents[n] == n)
    {
        return n;
    }
    return parents[n] = groot(parents[n]);
}

void unionize(int a, int b)
{
    a = groot(a);
    b = groot(b);
    if (a != b)
    {

        parents[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        parents[x] = x;
        arr[i] = x;
    }
    int ops = 0;
    for (int i = 0; i <= (n >> 1); i++)
    {
        int a = arr[i];
        int b = arr[n - i - 1];
        if (groot(a) != groot(b))
        {
            unionize(a, b);
            ++ops;
        }
    }
    cout << ops << '\n';

    return 0;
}
