// Problem K Key People
#include <stdio.h>
#include <string.h>

#define min(a, b) ((a > b) ? b : a)
#define max(a, b) ((a < b) ? b : a)

unsigned int n;
int ids[1002];
char adj[1002][1002];
unsigned int adjlist[1002][1002];

int is_relevant(int a, int b) // a > b
{
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a > 1;
}

// find articulation points (tarjan's algo)
void find_APs(unsigned int u, int visited[], unsigned int discovery[], unsigned int low[], unsigned int *time, unsigned int last, int isAP[])
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
            find_APs(v, visited, discovery, low, time, u, isAP);
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
    memset(adj, 0, sizeof(adj));
    memset(adjlist, 0, sizeof(adjlist));
    scanf("%u", &n);
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int id = 0;
        scanf("%u", &id);
        ids[i] = id;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (is_relevant(ids[i], ids[j]))
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
        find_APs(i, visited, discovery, low, &time, -1, isAP);
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