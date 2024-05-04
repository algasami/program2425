// counting tilings
#include <stdio.h>

#define MODULO 1000000007

size_t n, m;

// essentially just profile dp
unsigned long long int ways[12][1002][1 << 10] = {0}; // dp[i][j][s depending on i]
// ways[0][j][s] is reserved for the last one (to get the rolling array effect)
// go to https://usaco.guide/adv/dp-more?lang=cpp#dp-on-broken-profile
// for more info

// profiles in this one are pretty similar to the outlet one, but
// these profiles are grid-profiles instead of plug-profiles.
// 1 = something left to the profile is occupied, 0 = not

unsigned int solve()
{
    ways[n][0][(1 << n) - 1] = 1;
    for (size_t j = 1; j <= m; j++)
    {
        // i know this is shitty
        // compared to rolling arrays, but i can't be bothered lol
        for (size_t s = 0; s < (1 << n); s++)
        {
            ways[0][j][s] = ways[n][j - 1][s];
        }
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t s = 0; s < (1 << n); s++)
            {
                size_t x = 1 << (i - 1);
                if (s & x)
                {
                    // do it horizontal
                    ways[i][j][s] += ways[i - 1][j][s ^ x];
                    // do it vertical
                    size_t xshift;
                    if (i > 1 && (s & (xshift = 1 << (i - 2))))
                    {
                        ways[i][j][s] += ways[i - 1][j][s ^ xshift];
                    }
                }
                else
                {
                    ways[i][j][s] += ways[i - 1][j][s ^ x];
                }
                printf("%d %d %d %d \n", i, j, s, ways[i][j][s]);
            }
        }
    }
    return ways[n][m][(1 << n) - 1];
}

int main()
{
    scanf("%zu %zu", &n, &m);
    printf("%u", solve());
    return 0;
}