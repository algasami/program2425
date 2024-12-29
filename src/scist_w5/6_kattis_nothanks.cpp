#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    set<int> cards; // b-tree auto sort
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cards.insert(x);
    }
    int last = -1;
    long long int sum = 0;
    for (auto n : cards) // invariance: n > last
    {
        if (n - last > 1)
        {
            sum += n;
        }
        last = n;
    }
    printf("%lld\n", sum);
    return 0;
}