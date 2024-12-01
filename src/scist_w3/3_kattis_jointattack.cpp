#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%llu", &n);
	vector<unsigned long long> xs;
	xs.reserve(n);
	for (int i = 0; i < n; i++)
	{
		unsigned long long in;
		scanf("%llu", &in);
		xs.push_back(in);
	}

	unsigned long long numer = xs.back(), denom = 1;

	if (xs.size() > 1)
	{
		for (auto iter = ++xs.rbegin(); iter != xs.rend(); iter++)
		{
			unsigned long long swp = numer;
			numer = denom;
			denom = swp;
			// i + n/d = (n + di)/d
			numer += (*iter) * denom;
		}
	}
	printf("%llu/%llu\n", numer, denom);
	return 0;
}