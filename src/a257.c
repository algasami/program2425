// Problem K Key People
#include <stdio.h>
#include <string.h>

#define min(a, b) (a > b) ? b : a

unsigned int n;
int hash[3001]; // hash[id] = exist or not
int ids[1001];
int adj[3001][3001]; // adj[id][id]
unsigned int adjlist[1001][1002];

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

// find articulation points (tarjan's algo)
void findAPs(unsigned int u, int visited[], unsigned int discovery[], unsigned int low[], unsigned int *time, unsigned int last, int isAP[])
{
    unsigned int children = 0;
    visited[u] = 1;
    discovery[u] = low[u] = ++(*time);
    for (size_t i = 0; i < adjlist[u][1001]; i++)
    {
        unsigned int v = adjlist[u][i];
        if (!visited[v])
        {
            ++children;
            findAPs(v, visited, discovery, low, time, u, isAP);
            low[u] = min(low[u], low[v]);
            if (last != -1 && low[v] >= discovery[u])
            {
                isAP[u] = 1;
            }
        }
        else if (v != last)
        {
            low[u] = min(low[u], discovery[v]);
        }
    }
    if (last == -1 && children >= 2)
    {
        isAP[u] = 1;
    }
}

void solve()
{
    memset(hash, 0, sizeof(hash));
    memset(adj, 0, sizeof(adj));
    memset(adjlist, 0, sizeof(adjlist));
    scanf("%u", &n);
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int id = 0;
        scanf("%u", &id);
        hash[id] = 1;
        ids[i] = id;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (gcd(ids[i], ids[j]) > 1)
            {
                adj[i][j] = adj[j][i] = 1;
                adjlist[i][adjlist[i][1001]++] = j;
                adjlist[j][adjlist[j][1001]++] = i;
            }
        }
    }
    int visited[1001] = {0}, isAP[1001] = {0};
    unsigned int discovery[1001] = {0}, low[1001] = {0};
    unsigned int time = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        findAPs(i, visited, discovery, low, &time, -1, isAP);
    }
    unsigned int aps = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        if (isAP[i])
        {
            ++aps;
        }
    }
    printf("%d\n", aps);
}

int main()
{
    unsigned int cases;
    scanf("%u", &cases);

    for (unsigned int i = 0; i < cases; i++)
    {
        solve();
    }
    return 0;
}