#include <bits/stdc++.h>

using namespace std;
int n;
long long int sum = 0;
set<int, greater<int>> dists;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
        dists.insert(x);
    }
    printf("%zu\n", dists.size());
    int space = 0;
    for (int x : dists)
    {
        if (!space)
        {
            space = 1;
        }
        else
        {
            putchar(' ');
        }
        printf("%lld", sum - x);
    }
    putchar('\n');
    return 0;
}