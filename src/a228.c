/**
 * 就少一個插座很不方便
 *
 * 插頭DP
 *
 * strategy: silhouette/plug DP (i will write a writeup soon...)
 */

#include <stdio.h>
#include <string.h>

#define MODULO 1000000007U

unsigned int n, m;
unsigned int map[12][12];
unsigned int combs[12][12][1 << 12];

unsigned int solve()
{
    memset(combs, 0, sizeof(combs));

    combs[0][m][0] = 1;
    // set the basic step
    // non-existent block (0, m) with blank state (zero plugs) has one solution

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t s = 0; s < (size_t)(1 << m); s++)
        {
            combs[i][0][s << 1] = combs[i - 1][m][s];
            // copy from last column's accumulated solutions
            // we only copy s till 1 << m because one byte has
            // to be open (the first part is always non-plugged)
        }

        for (size_t j = 1; j <= m; j++)
        {
            // get snake penetration in s (this part is confusing)
            size_t up = 1 << (j - 1);
            size_t left = 1 << (j + 1 - 1);
            // in the blog post, the bits are a 1-based array, but in real programming, it is 0-based
            // combined with our 1-based array for i,j, we get a 1-off problem, so need to minus one.
            for (size_t s = 0; s < (size_t)(1 << (m + 1)); s++)
            {
                if (map[i][j]) // safe, doesn't have outlet
                {
                    if ((up & s) && (left & s))
                    {
                        // two plugs, transfer from no plugs
                        combs[i][j][s] = combs[i][j - 1][s - up - left];
                    }
                    else if ((up & s) || (left & s))
                    {
                        // one of them up or left (exclusive or)
                        combs[i][j][s] = (combs[i][j - 1][s] + combs[i][j - 1][s ^ (up | left)]) % MODULO;
                        // s ^ (up | left)
                        // if the state has up, then we choose the state with left
                        // if the state has left, then we choose the state with up
                        // add the original solutions as well
                        // (remember the s does not represent the same thing in the last (i, j-1) tile!!!)
                    }
                    else
                    { // zero plugs
                        combs[i][j][s] = combs[i][j - 1][s + up + left];
                        // just add the one with plugs (make it valid)
                    }
                }
                else // outlet
                {
                    if (!(up & s) && !(left & s))
                    {
                        // valid config for outlet (zero plug)
                        combs[i][j][s] = combs[i][j - 1][s];
                    }
                    else
                    {
                        // invalid config, 0 ways
                        // no way there are plugs coming out of outlets smh
                        combs[i][j][s] = 0;
                    }
                }
            }
        }
    }
    // final accumulation happens at combs[n][m][0]

    return combs[n][m][0] % MODULO;
}

int main()
{
    unsigned int C;
    scanf("%u", &C);
    for (unsigned int i = 1; i <= C; i++)
    {
        scanf("%u %u", &n, &m);
        for (size_t i = 1; i <= n; i++)
            for (size_t j = 1; j <= m; j++)
                scanf("%u", &map[i][j]);

        printf("Case %u: %u\n", i, solve());
    }
    return 0;
}