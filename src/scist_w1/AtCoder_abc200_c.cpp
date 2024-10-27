#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	unsigned long long num = 0llu;
	map<int, unsigned long long> modmap;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		modmap[a % 200]++;
	}
	// (a_i - a_j) mod 200 = 0
	// then a_i mod 200 = a_j mod 200
	// store them in a map
	// modmap[i] = how many numbers in the array % 200 = i
	// then these numbers subtracted by one another should always
	// mod 200 = 0. so the pairs should be C(modmap[i], 2)
	for (auto const &kv : modmap)
	{
		num += kv.second * (kv.second - 1) / 2;
	}
	printf("%llu\n", num);
	return 0;
}