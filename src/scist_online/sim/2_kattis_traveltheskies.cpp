#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

int k, n, m;
struct flight
{
	int start, end, capacity;
};

int customers[10][13] = {0}; // [day][airports]
vector<flight> flights[9];

int main()
{
	scanf("%d %d %d", &k, &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v, d, z; // u: start, v: end, d: day, z: capacity
		scanf("%d %d %d %d", &u, &v, &d, &z);
		flights[d].push_back(flight{.start = u, .end = v, .capacity = z});
	}
	for (int i = 1; i <= k * n; i++)
	{
		int a, b, c; // a: airport, b: day, c: customers
		scanf("%d %d %d", &a, &b, &c);
		customers[b][a] += c;
	}
	for (int day = 1; day <= n; day++)
	{
		for (const auto &flight : flights[day])
		{
			int sum = 0;
			for (int before = 1; before <= day; before++)
			{
				sum += customers[before][flight.start];
			}
#ifdef DEBUG
			printf("day %d | flight capacity %d | customers %d\n", day, flight.capacity, sum);
#endif
			if (flight.capacity <= sum)
			{
				customers[day + 1][flight.end] += flight.capacity;
				customers[day][flight.start] -= flight.capacity;
			}
			else
			{
				puts("suboptimal");
				return 0;
			}
		}
	}
	puts("optimal");
	return 0;
}