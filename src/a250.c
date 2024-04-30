#include <stdio.h>

// prefix sum (from i = 1)
long long int sum[100001] = {0};
long long int mods[100001] = {0};

int solve()
{
    size_t n;
    int k;

    scanf("%zu", &n);

    if (!n)
        return 0;

    for (size_t i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
    }

    scanf("%d", &k);

    for (size_t i = 0; i <= n; i++)
    {
        mods[i] = sum[i] % k;
    }

    // sum[b] - sum[a] = [a+1, b]
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j <= n; j++)
        {
            if (mods[j] == mods[i])
            {
                printf("%zu %zu\n", i + 1, j);
                return 1;
            }
        }
    }
    printf("no solutions\n");
    return 1;
}

int main()
{
    while (solve())
        ;
    return 0;
}