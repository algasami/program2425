#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

int solve()
{
	int n, k;
	int disperse = 0, instore = disperse + 1;
	int remaining[25];
	queue<int> student;
	vector<int> leftorder;

	scanf("%d %d", &n, &k);
	if (!n && !k)
	{
		return 1;
	}
	leftorder.reserve(n);
	// setup loan
	for (int i = 0; i < n; i++)
	{
		remaining[i] = 40;
		student.push(i);
	}
	while (!student.empty())
	{
		int front = student.front();
		student.pop();
		if (remaining[front] >= instore)
		{
			remaining[front] -= instore;
			instore = (disperse = (disperse + 1) % k) + 1;
#ifdef DEBUG
			printf("instore: %d\n", instore);
#endif
			if (remaining[front])
			{
				student.push(front);
			}
			else
			{
				leftorder.push_back(front);
			}
		}
		else
		{
			instore -= remaining[front];
			leftorder.push_back(front);
		}
	}
	for (int x : leftorder)
	{
		printf("%3d", x + 1);
	}
	putchar('\n');
	return 0;
}

int main()
{
	while (!solve())
		;
	return 0;
}