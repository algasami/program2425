#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int n, q;

int parents[1000001] = {}, union_size[1000001] = {};

int get_root(int x)
{
    if (parents[x] == x)
    {
        return x;
    }

    return parents[x] = get_root(parents[x]);
}

int unionize(int a, int b)
{
    a = get_root(a);
    b = get_root(b);

    if (a == b)
    {
        return a;
    }
    // this ensures the stable sorting property (invariance)
    if (union_size[b] < union_size[a])
    {
        swap(a, b);
    }
    union_size[b] += union_size[a];
    return parents[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    cin.get(); // flush newline

    fill(union_size, union_size + n + 1, 1); // remember it is one byte
                                             // microcode optimization ftw
    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < q; i++)
    {
        char opcode;
        cin >> opcode;

        if (opcode == 't')
        {
            int guest_a, guest_b;
            cin >> guest_a >> guest_b;
            unionize(guest_a, guest_b);
        }
        else if (opcode == 's')
        {
            int guest;
            cin >> guest;
            cout << union_size[get_root(guest)] << '\n';
        }
    }

    return 0;
}
