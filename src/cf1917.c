#include <stdio.h>

unsigned int solve(char sliced, unsigned int n, char str[])
{
    // abS
    // aS (sliced) or bS
    // S or aS' (sliced)
    // S or bS' (sliced)
    // if remove second, then remove first or first then second just returns S
    // let second then first not affect the total number
    if (sliced > 0)
    {
        printf("%c", sliced);
    }
    for (unsigned int i = 0; i < n - (sliced > 0 ? 1 : 0); i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    if (n - (sliced > 0 ? 1 : 0) <= 1)
        return 1;
    unsigned int total = 0;
    // abS'
    if (sliced <= 0) // not sliced
    {
        if (sliced == -2) // bS'
        {
            total += solve(-1, n - 1, str + 1);     // remove first S'
            total += solve(str[0], n - 1, str + 2); // remove second bS''
        }
        else // abS'
        {
            total += solve(-2, n - 1, str + 1);     // remove first bS'
            total += solve(str[0], n - 1, str + 2); // remove second aS'
        }
    }
    else // sliced before aS'
    {
        // total += solve(-1, n - 1, str);         // remove first, just S'
        // total += solve(sliced, n - 1, str + 1); // remove second, become aS''
    }
    total += 1;
    return total;
}

int main()
{
    unsigned int t;
    scanf("%u", &t);
    for (unsigned int i = 0; i < t; i++)
    {
        unsigned int n;
        char str[100005];
        scanf("%u", &n);
        scanf("%100001s", str);
        unsigned int sol = solve(-1, n, str);
        printf("%u\n", sol);
    }
    return 0;
}