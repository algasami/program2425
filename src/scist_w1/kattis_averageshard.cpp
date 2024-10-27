#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int ncs, ne;
	int acs[200001], ae[200001];
	unsigned long long cssum = 0, esum = 0;
	scanf("%d %d", &ncs, &ne);
	for (int i = 0; i < ncs; i++)
	{
		scanf("%d", acs + i);
		cssum += acs[i];
	}
	for (int i = 0; i < ne; i++)
	{
		scanf("%d", ae + i);
		esum += ae[i];
	}

	double csavg = (double)cssum / (double)ncs;
	double eavg = (double)esum / (double)ne;
	// ! There might be precision issues but so far so good.

	int num = 0;

	for (int i = 0; i < ncs; i++)
	{
		double ncsavg = (double)(cssum - acs[i]) / (double)(ncs - 1);
		double neavg = (double)(esum + acs[i]) / (double)(ne + 1);
		if (ncsavg > csavg && neavg > eavg)
		{
			++num;
		}
	}
	printf("%d\n", num);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}