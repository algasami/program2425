#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

void solve()
{
    long long int dataset_id;
    unsigned long long inputs[20];
    scanf("%lld", &dataset_id);
    for (int i = 0; i < 20; i++)
    {
        scanf("%llu", &inputs[i]);
    }

    unsigned long long steps = 0;

    for (int i = 1; i < 20; i++)
    {
        unsigned long long cur = inputs[i];
        for (int j = 0; j < i; j++)
        {
            if (cur < inputs[j])
            {
                for (int k = i - 1; k >= j; k--)
                {
                    steps++;
                    inputs[k + 1] = inputs[k];
                }
                inputs[j] = cur;
                break;
            }
        }
#ifdef DEBUG
        for (int i = 0; i < 20; i++)
        {
            printf("%llu ", inputs[i]);
        }
        putchar('\n');
#endif
    }
    printf("%lld %llu\n", dataset_id, steps);
}

int main()
{
    int p;
    scanf("%d", &p);
    while (p--)
        solve();
    return 0;
}