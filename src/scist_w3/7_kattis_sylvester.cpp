#include <bits/stdc++.h>

using namespace std;

int get_val(unsigned long long n, unsigned long long x, unsigned long long y)
{
	if (n == 1)
	{
		return 1;
	}
	unsigned long long hn = n >> 1;
	if (x < hn)
	{
		if (y < hn)
			return get_val(hn, x, y);
		return get_val(hn, x, y - hn);
	}
	else
	{
		if (y < hn)
			return get_val(hn, x - hn, y);
	}
	return -get_val(hn, x - hn, y - hn);
}

void solve()
{
	unsigned long long n, x, y, w, h;
	cin >> n >> x >> y >> w >> h;

	for (unsigned long long iy = y; iy < h + y; iy++)
	{
		for (unsigned long long ix = x; ix < w + x; ix++)
		{
			printf("%d ", get_val(n, ix, iy));
		}
		putchar('\n');
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}