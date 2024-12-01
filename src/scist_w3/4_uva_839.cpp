#include <bits/stdc++.h>

using namespace std;

int read_mobile(int *wl, int *dl, int *wr, int *dr)
{
	int a, b, c, d, bad = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a == 0)
	{
		int w0, w1, e, f;
		if (read_mobile(&w0, &e, &w1, &f))
		{
			bad = 1;
		}
		a = w0 + w1;
	}
	if (c == 0)
	{
		int w0, w1, e, f;
		if (read_mobile(&w0, &e, &w1, &f))
		{
			bad = 1;
		}
		c = w0 + w1;
	}
	*wl = a;
	*dl = b;
	*wr = c;
	*dr = d;
	if (a * b != c * d || bad == 1)
	{
		return 1;
	}
	return 0;
}

int f = 1;

void solve()
{
	int wl, dl, wr, dr;
	if (f)
	{
		f = 0;
	}
	else
	{
		putchar('\n');
	}
	if (read_mobile(&wl, &dl, &wr, &dr) || wl * dl != wr * dr)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
}